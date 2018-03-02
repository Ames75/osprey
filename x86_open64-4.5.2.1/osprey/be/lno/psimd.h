
/*
 * Copyright (C) 2008-2012 Advanced Micro Devices, Inc.  All Rights Reserved.
 */

/*

  Copyright (C) 2000, 2001 Silicon Graphics, Inc.  All Rights Reserved.

  This program is free software; you can redistribute it and/or modify it
  under the terms of version 2 of the GNU General Public License as
  published by the Free Software Foundation.

  This program is distributed in the hope that it would be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  Further, this software is distributed without any warranty that it is
  free of the rightful claim of any third person regarding infringement
  or the like.  Any license provided herein, whether implied or
  otherwise, applies only to this software file.  Patent licenses, if
  any, provided herein do not apply to combinations of this program with
  other software, or any other product whatsoever.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write the Free Software Foundation, Inc., 59
  Temple Place - Suite 330, Boston MA 02111-1307, USA.

  Contact information:  Silicon Graphics, Inc., 1600 Amphitheatre Pky,
  Mountain View, CA 94043, or:

  http://www.sgi.com

  For further information regarding this notice, see:

  http://oss.sgi.com/projects/GenInfo/NoticeExplan

*/

#ifdef TARG_X8664
#include "opt_alias_mgr.h"
#include "glob.h"		    /* Irb_File_Name, Cur_PU_Name */
#include "const.h"
#include <sstream>
#include "mtypes.h"
#include "access_vector.h"
#include "ir_reader.h"
#include "opt_du.h"			/* Du_Built() */
#include "lwn_util.h"
#include "lnoutils.h"
#include "reduc.h"
#include "lnopt_main.h"
#include "defs.h"
#include "wn_simp.h"
#include <map>
#include <utility>
#include <set>

extern void Do_Unroll_Walk(WN *wn);
class Unroll_For_Psimd_Walker {
public:
    int unroll_factor;
    std::map<WN *, std::pair<WN *,WN *> > my_unroll;
    std::set<WN *> deleted_loop;
    std::map<WN*, std::pair<int,int> > iter_map;
    void Do_Unroll(WN* loop);
    int Determine_Unroll_Factor(WN *doloop);
    void Do_Unroll_Walk (WN* wn);
    bool Sanity_Unroll (WN* wn);
    void Fix_Def_List_Loop_Stmt(WN* func_nd, std::set<WN *>&deleted_loop);
    explicit Unroll_For_Psimd_Walker () {
        unroll_factor = 0;
    };
};

class Unroll_For_Psimd {
private:
    WN *orig_loop,*rem_loop,*store_loop;
    WN *trips;
    int step_amt,abs_step_amt;
    int unroll_factor;
    TYPE_ID rtype;
    SYMBOL index_sym;
    Unroll_For_Psimd_Walker& unroll_walker;
public:
    Unroll_For_Psimd(Unroll_For_Psimd_Walker& unroll_wlk, WN *doloop,int unroll_times)
        : unroll_walker (unroll_wlk),  orig_loop(doloop),unroll_factor(unroll_times),
          rtype(WN_rtype(WN_kid0(WN_step(doloop)))) {
        index_sym = SYMBOL((WN_index(orig_loop)));
        index_sym.Type = Do_Wtype(orig_loop);
    }
    void Create_Unroll_Rem_Loop();
    bool Compute_Trips();
    void Adjust_Start_Cond_Init();
    void wn_to_iter (WN* , int& ,int );
    void get_ldids (WN* in_tree, std::set<WN*>& leaves);
    void Transfer_DU (WN *from_tree, WN *to_tree);
    ~Unroll_For_Psimd() { }
};

void Copy_Def_Use (WN *from_tree, WN *to_tree ) {
    FmtAssert(WN_operator(from_tree) == WN_operator(to_tree),
              ("from_tree and to_tree not in synch"));

    if (WN_operator(from_tree) == OPR_LDID) {
        SYMBOL currsym = SYMBOL(from_tree);
        FmtAssert(SYMBOL(to_tree) == currsym,
                  ("from_tree and to_tree have different symbols"));
        DEF_LIST *def_list = Du_Mgr->Ud_Get_Def(from_tree);
        DEF_LIST_ITER iter(def_list);
        const DU_NODE *node = iter.First();
        for(; !iter.Is_Empty(); node=iter.Next()) {
            WN *def = (WN *) node->Wn();
            Du_Mgr->Add_Def_Use(def, to_tree);
        }
    }
    for (INT i = 0; i < WN_kid_count(from_tree); i ++) {
        Copy_Def_Use(WN_kid(from_tree, i), WN_kid(to_tree, i));
    }
}

extern void Delete_Def_Use (WN *wn_tree);

void print_a_vector_of_wns (const std::vector<WN*>& wnsd) {
    for(std::vector<WN*>::const_iterator wnit = wnsd.begin();
            wnit != wnsd.end(); ++wnit) {
        dump_tree (*wnit);
    }
}

void tree_pattern (WN* in_tree, std::stringstream& strstrm) {
    strstrm << "(";
    strstrm << OPCODE_name(WN_opcode(in_tree));
    if (WN_operator(in_tree) != OPR_ILOAD) {
        for (int i = 0; i < WN_kid_count(in_tree); ++i) {
            tree_pattern(WN_kid(in_tree,i), strstrm);
        }
    }
    strstrm << ")";
}

bool is_same_as (WN* first, WN* second, ALIAS_MANAGER* _alias_mgr) {
    if (WN_opcode(first) != WN_opcode(second)) {
        return false;
    } else {
        if (WN_operator(first) == OPR_INTCONST) {
            if (WN_const_val(first) != WN_const_val(second)) {
                return false;
            } else return true;
        } else if (WN_operator(first) == OPR_LDID ||
                   WN_operator(first) == OPR_ILOAD) {
            if (Aliased(_alias_mgr, first, second, TRUE) == SAME_LOCATION)
                return true;
            else return false;
        } else if (WN_operator(first) == OPR_STID ||
                   WN_operator(first) == OPR_ISTORE) {
            return false;
        } else {
            if (WN_kid_count(first) != WN_kid_count(second))
                return false;
            for (int mi = 0; mi < WN_kid_count(first); ++mi)
                if (is_same_as(WN_kid(first,mi), WN_kid(second,mi), _alias_mgr) == false)
                    return false;
            return true;
        }
    }
}

enum arr_elem_dist {NOMATCH,SOMEMATCH};
std::pair <arr_elem_dist, std::pair<INT, INT> > array_elements_distance_v2 (WN* input_wn1,
        WN* input_wn2, ALIAS_MANAGER* _alias_mgr) {
    int offset;
    offset = WN_offset(input_wn2) - WN_offset(input_wn1);
    WN* wn1 = WN_kid1(input_wn1);
    WN* wn2 = WN_kid1(input_wn2);
    if (offset != 0) {
        if (is_same_as(wn1,wn2, _alias_mgr)) {
            return std::make_pair(SOMEMATCH,
                                  std::make_pair(WN_offset(input_wn1), WN_offset(input_wn2)));
        }
    } else {
        if (WN_operator(wn1) == OPR_ARRAY
                && WN_operator(wn2) == OPR_ARRAY) {
            if (WN_num_dim(wn1) == WN_num_dim(wn2) &&
                    WN_element_size(wn1) == WN_element_size(wn2)) {
                if (WN_kid_count (wn1) == 3 &&
                        WN_kid_count (wn2) == 3 &&
                        is_same_as (WN_kid(wn1,0), WN_kid(wn2,0), _alias_mgr) &&
                        is_same_as (WN_kid(wn1,1), WN_kid(wn2,1), _alias_mgr) &&
                        WN_operator(WN_kid(wn1, 2)) == OPR_INTCONST &&
                        WN_operator(WN_kid(wn2, 2)) == OPR_INTCONST) {
                    return std::make_pair(SOMEMATCH,
                                          std::make_pair(WN_const_val(WN_kid(wn1, 2)),
                                                         WN_const_val(WN_kid(wn2, 2))));
                }
            }
        }
    }
    return std::make_pair(NOMATCH, std::make_pair(0,0));
}

std::pair<arr_elem_dist, INT> array_elements_distance (WN *input_wn1,
        WN *input_wn2, ALIAS_MANAGER* _alias_mgr) {
    int offset;
    WN *wn1;
    WN *wn2;
    int  index;

    offset = WN_offset(input_wn2) - WN_offset(input_wn1);

    if ( WN_operator(input_wn1) == OPR_ILOAD) {
        wn1 = WN_kid(input_wn1, 0);
        wn2 = WN_kid(input_wn2, 0);
    }
    if (is_same_as(wn1,wn2, _alias_mgr)) {
        return std::make_pair(SOMEMATCH, offset);
    } else {
        return std::make_pair(NOMATCH, -1);
    }
}

bool needs_swap (WN* input_wn1,
                 WN *input_wn2,
                 ALIAS_MANAGER* _alias_mgr,
                 INT Type_Size) {
    int offset;
    WN *wn1;
    WN *wn2;

    FmtAssert ((WN_operator(input_wn1) == OPR_ILOAD &&
                WN_operator(input_wn2) == OPR_ILOAD),
               ("non iloads provided\n"));
    offset = WN_offset(input_wn2) - WN_offset(input_wn1);
    if (offset == 0) {
        if ( WN_operator(input_wn1) == OPR_ILOAD) {
            wn1 = WN_kid(input_wn1, 0);
            wn2 = WN_kid(input_wn2, 0);
        }
        if (WN_operator(wn1) == OPR_ARRAY
                && WN_operator(wn2) == OPR_ARRAY) {
            if (WN_num_dim(wn1) == WN_num_dim(wn2) &&
                    WN_element_size(wn1) == WN_element_size(wn2)) {
                if (WN_kid_count (wn1) == 3 &&
                        WN_kid_count (wn2) == 3 &&
                        is_same_as (WN_kid(wn1,0), WN_kid(wn2,0), _alias_mgr) &&
                        is_same_as (WN_kid(wn1,1), WN_kid(wn2,1), _alias_mgr) &&
                        WN_operator(WN_kid(wn1, 2)) == OPR_INTCONST &&
                        WN_operator(WN_kid(wn2, 2)) == OPR_INTCONST) {
                    if ((WN_const_val(WN_kid(wn2, 2))
                            - WN_const_val(WN_kid(wn1, 2)))*WN_element_size(wn1) == -Type_Size)
                        return true;
                }
            }
        }
    }
    return false;
}

std::pair<arr_elem_dist, INT> array_elements_distance (WN *input_wn1,
        WN *input_wn2, ALIAS_MANAGER* _alias_mgr, INT Type_Size) {
    int offset;
    WN *wn1;
    WN *wn2;

    FmtAssert (((WN_operator(input_wn1) == OPR_ILOAD &&
                 WN_operator(input_wn2) == OPR_ILOAD) ||
                (WN_operator(input_wn1) == OPR_ISTORE &&
                 WN_operator(input_wn2) == OPR_ISTORE)),
               ("non iloads provided\n"));

    offset = WN_offset(input_wn2) - WN_offset(input_wn1);
    if ( WN_operator(input_wn1) == OPR_ILOAD) {
        wn1 = WN_kid(input_wn1, 0);
        wn2 = WN_kid(input_wn2, 0);
    } else {
        wn1 = WN_kid(input_wn1, 1);
        wn2 = WN_kid(input_wn2, 1);
    }
    if (offset == Type_Size) {
        if (is_same_as(wn1,wn2, _alias_mgr)) {
            return std::make_pair(SOMEMATCH, offset);
        } else {
            return std::make_pair(NOMATCH, -1);
        }
    } else {
        return std::make_pair(NOMATCH, -1);
    }
}

int count_iloads (WN* in_tree) {
    if (WN_opcode(in_tree) == OPC_F8F8ILOAD ||
            WN_opcode(in_tree) == OPC_F4F4ILOAD) {
        return 1;
    } else {
        int cou = 0;
        for (int ci = 0; ci < WN_kid_count(in_tree); ++ci) {
            cou += count_iloads(WN_kid(in_tree,ci));
        }
        return cou;
    }
}

void num_nodes (WN* in_tree, int& inpcost) {
    if (WN_operator(in_tree) == OPR_CONSTRUCTOR) {
        inpcost+=(WN_kid_count(in_tree)-1);
    } else if (WN_operator(in_tree) != OPR_LDID &&
               WN_operator(in_tree) != OPR_CONST &&
               WN_operator(in_tree) != OPR_INTCONST &&
               WN_operator(in_tree) != OPR_REPLICATE &&
               WN_operator(in_tree) != OPR_ISTORE &&
               WN_operator(in_tree) != OPR_PARM &&
               WN_operator(in_tree) != OPR_PAREN &&
               WN_operator(in_tree) != OPR_STID)
        inpcost++;
    if (WN_operator(in_tree) == OPR_ISTORE)
        num_nodes(WN_kid0(in_tree), inpcost);
    else if (WN_operator(in_tree) != OPR_ILOAD)
        for (int i = 0; i < WN_kid_count(in_tree); ++i)
            num_nodes(WN_kid(in_tree,i), inpcost);
}

void num_nodes_v1 (WN* in_tree, int& inpcost) {
    if (WN_operator(in_tree) != OPR_LDID &&
            WN_operator(in_tree) != OPR_CONST &&
            WN_operator(in_tree) != OPR_ILOAD &&
            WN_operator(in_tree) != OPR_INTCONST &&
            WN_operator(in_tree) != OPR_REPLICATE &&
            WN_operator(in_tree) != OPR_ISTORE &&
            WN_operator(in_tree) != OPR_PARM &&
            WN_operator(in_tree) != OPR_PAREN &&
            WN_operator(in_tree) != OPR_STID)
        inpcost++;
    if (WN_operator(in_tree) == OPR_ISTORE)
        num_nodes_v1(WN_kid0(in_tree), inpcost);
    else if (WN_operator(in_tree) != OPR_ILOAD)
        for (int i = 0; i < WN_kid_count(in_tree); ++i)
            num_nodes_v1 (WN_kid(in_tree,i), inpcost);
}

void get_ldids (WN* in_tree, std::vector<WN*>& leaves) {
    if (WN_operator(in_tree) == OPR_LDID) {
        leaves.push_back (in_tree);
        return;
    } else {
        for (int i = 0; i < WN_kid_count(in_tree); ++i)
            get_ldids(WN_kid(in_tree,i), leaves);
        return;
    }
}

void get_ldids (WN* in_tree, std::set<WN*>& leaves) {
    if (WN_operator(in_tree) == OPR_LDID) {
        leaves.insert (in_tree);
        return;
    } else {
        if(WN_operator(in_tree) == OPR_BLOCK)   {
            for(WN *wn_temp=WN_first(in_tree); wn_temp; wn_temp=WN_next(wn_temp))
                get_ldids(wn_temp, leaves);
        }
        for (int i = 0; i < WN_kid_count(in_tree); ++i)
            get_ldids(WN_kid(in_tree,i), leaves);
        return;
    }
}

class VECTORTY {
public:
    std::vector<WN*>& myvecs;
    bool trace_it;
    bool is_a_reduc;
    bool is_invariant;
    const TYPE_ID vect_dtyp;
    const TYPE_ID scal_dtyp;
    bool useful;
    ALIAS_MANAGER* _alias_mgr;
    std::vector<WN*> cons;
    std::vector<WN*> shuffles;
    std::vector<WN*>& prefix;
    WN* red_stid;
    WN* vect;
    bool store_packing;

    void mark_invalid () {
        useful = false;
    }

    void mark_valid () {
        useful = true;
    }

    bool is_valid() const {
        return useful;
    }

    const std::vector<WN*>& get_myvecs() {
        return myvecs;
    }

    TYPE_ID get_vdtyp() {
        return vect_dtyp;
    }

    TYPE_ID get_sdtyp() {
        return scal_dtyp;
    }

    WN* LDID_of_vect () ;

    explicit VECTORTY (TYPE_ID vdtyp, TYPE_ID sctyp,
                       std::vector<WN*>& myvec,
                       std::vector<WN*>& outl, ALIAS_MANAGER* alis) :
        vect_dtyp (vdtyp), scal_dtyp (sctyp),
        myvecs(myvec), prefix(outl),
        trace_it(false), _alias_mgr(alis),
        vect(NULL), is_a_reduc (false),is_invariant(false), useful(true),
        red_stid(NULL), store_packing(false) { }

    WN* convert_to_simd (WN* in_tree, int& start_it) ;

    void convert_to_simd () ;

    void create_shifts () ;

    bool are_loads_of_vectys_elems (const std::vector<WN*>& myld) const ;

    void set_reduc (bool value) {
        is_a_reduc = value;
    }

    void set_invariant (bool value) {
        is_invariant = value;
    }

    WN* check_constructors_for_packing (
        const std::vector<WN*>& myld) ;

    WN* check_replicates_for_packing (
        const std::vector<WN*>& myld) ;
};

class VECTORBUILDER {
public:
    WN* current_block;
    std::set<WN*>& StmtSet;
    const std::set<WN*>& costs_skip;
    std::vector<VECTORTY*> existing_vect;
    std::vector<WN*> reduction_prefix;
    std::vector<WN*> reduction_suffix;
    std::vector<WN*> constant_prefix;
    std::vector<WN*> invariant_prefix;
    std::set<WN*> dontdo;
    bool trace_it;
    int count;
    ALIAS_MANAGER* _alias_mgr;

    void get_stids (WN* in_tree, std::set<WN*>& stids) {
        if (WN_operator(in_tree) == OPR_STID) {
            stids.insert (in_tree);
            return;
        } else if(WN_operator(in_tree) == OPR_BLOCK) {
            for (WN* wn_temp=WN_first(in_tree); wn_temp; wn_temp=WN_next(wn_temp))
                get_stids(wn_temp, stids);
            return;
        }
    }

    void get_leaves (WN* in_tree, std::vector<WN*>& leaves) {
        if (WN_operator(in_tree) == OPR_LDID ||
                WN_operator (in_tree) == OPR_ILOAD ||
                WN_operator (in_tree) == OPR_ARRAY ||
                WN_operator (in_tree) == OPR_CONST ||
                WN_operator (in_tree) == OPR_INTCONST) {
            leaves.push_back (in_tree);
            return;
        } else {
            for (int i = 0; i < WN_kid_count(in_tree); ++i)
                get_leaves(WN_kid(in_tree,i), leaves);
            return;
        }
    }

    void get_leaves (std::vector<std::vector<WN*> >& out_leaves,
                     const std::vector<WN*>& myvecs) {
        for (int blih = 0; blih < myvecs.size(); ++blih) {
            std::vector<WN*> leaves;
            if (WN_operator(myvecs[blih]) == OPR_ISTORE) {
                get_leaves(WN_kid0(myvecs[blih]), leaves);
            } else {
                get_leaves(myvecs[blih], leaves);
            }
            out_leaves.push_back(leaves);
        }
    }

    void get_stores (std::vector<WN*>& out_stores,
                     const std::vector<WN*>& myvecs) {
        for (std::vector<WN*>::const_iterator myvi =
                    myvecs.begin(); myvi != myvecs.end();
                ++myvi) {
            out_stores.push_back(*myvi);
        }
    }

    bool check_for_invariance (WN **wn_array,int length) ;
    bool check_for_invariance (WN *wn) ;
    bool is_a_reduction (WN* mywn) ; 
    bool check_if_reduction (const std::vector<WN*>& mystores,
                             const std::vector<WN*>& myleaves) ;

    WN* check_existing_reductions_for_packing (const std::vector<WN*>& myld) ;

    WN* check_existing_constructors_for_packing (
        const std::vector<WN*>& check_these) ;

    WN* check_existing_replicates_for_packing (
        const std::vector<WN*>& check_these) ;

    void build_constructor_reduction (VECTORTY* myve,
                                      const std::vector<WN*>& loadli) ;

    void build_constructor (VECTORTY* myve,
                            const std::vector<WN*>& loadli) ;

    void build_constant (VECTORTY* vec, const std::vector<WN*>& consts) ;

    void build_iloads (VECTORTY* myve, const std::vector<WN*>& myleaves) ;


    void build_replicate (VECTORTY* myve,
                          const std::vector<WN*>& replic) ;

    bool is_istore_packing (const std::vector<WN*>& myleaves) ;

    bool is_iload_packing (const std::vector<WN*>& myleaves) ;

    bool is_constant_packing (const std::vector<WN*>& myleaves) ;

    bool is_replicate_packing (const std::vector<WN*>& myleaves) ;

    VECTORTY* check_existing_vectors_for_packing (
        VECTORTY* vect, const std::vector<WN*>& check_these) ;

    void build_by_leaftype (VECTORTY* myve);

    void update_existing_vectors (VECTORTY* myvec);
    void update_existing_vectors (WN *mywn);

    explicit VECTORBUILDER (ALIAS_MANAGER* alis, std::set<WN*>& mystms,
                            std::set<WN*>& costs_kip, WN* current_bl):
        _alias_mgr(alis), trace_it(false), StmtSet(mystms),
        costs_skip(costs_kip), current_block(current_bl) { }

    void buildvect_for_stmt (VECTORTY* myvec, WN* myroot) ;
};

class PARTIAL_SIMD_ESTIMATOR {
    //TODO: iload->istore dependence serialization
public:
    Unroll_For_Psimd_Walker& unroll_walker;
    float vector_to_block_ratio;
    int stmt_count;
    std::map<WN*,std::set<int> > node_adj;
    std::map<WN*,std::set<int> > adj_psuedo;
    std::map<WN*,std::set<int> > true_adj;
    std::map<WN*,std::set<int> > output_dep;
    std::map<WN*,std::set<int> > anti_dep;
    std::map<WN*,std::vector<WN*> > VectorXMap;
    std::set<WN*> costs_skip;
    std::vector<WN*> StmtVector;
    std::set<WN*> StmtSet;
    std::map<WN*, int> StmtNumWn;
    std::map<int,WN*> StmtWnNum;
    std::map<WN*,int> DepthWN;
    std::map<int, std::list<WN*> > WNByDepth;
    std::map<int, std::map<std::string, std::list<WN*> > > WNByDepthAndSig;
    std::map<WN*,std::string> WNTreeSig;
    std::vector<WN*> graph_stids;
    std::vector<WN*> depth_stid;
    std::vector<WN*> depth_istore;
    std::vector<WN*> depth_iload;
    WN* lastnode_processed;
    WN* current_block;
    WN* current_loop;
    bool trace_it;
    int lastnum;
    int num_vector_nodes;
    ALIAS_MANAGER *_alias_mgr;
    std::vector<WN*> layout_order;
    std::map<WN*, std::set<int> >& get_anti_dep () {
        return anti_dep;
    }
    std::map<WN*, std::set<int> >& get_output_dep () {
        return output_dep;
    }
    std::map<WN*, std::set<int> >& get_node_adj () {
        return node_adj;
    }
    bool is_std_store(WN* beg) {
        if (WN_operator(beg) == OPR_STID
                || WN_operator(beg) ==  OPR_ISTORE
                || WN_operator(beg) == OPR_STBITS
                || WN_operator(beg) == OPR_ISTBITS
                || WN_operator(beg) == OPR_ISTOREX
                || WN_operator(beg) == OPR_MSTORE
                || WN_operator(beg) == OPR_OPT_CHI)
            return true;
        else return false;
    }

    void set_current_block (WN* curblk) {
        current_block = curblk;
    }
    void set_current_loop (WN* loop) {
        current_loop = loop;
    }
    void set_lastnode_processed (WN* lnp) {
        lastnode_processed = lnp;
    }

    explicit PARTIAL_SIMD_ESTIMATOR (ALIAS_MANAGER* alis, Unroll_For_Psimd_Walker& unroll_wlk, bool trace_is) :
        trace_it(trace_is),_alias_mgr(alis), lastnum(0),
        current_block(NULL), lastnode_processed(NULL),
        stmt_count(0), num_vector_nodes(0),
        vector_to_block_ratio(0.75), unroll_walker(unroll_wlk) { }

    void set_trace (bool torf) {
        trace_it = true;
    }

    bool are_we_tracing () {
        return trace_it;
    }

    void AddToStmtVect (WN* in_tree) {
        // book-keeping.
        StmtVector.push_back(in_tree);
        StmtSet.insert(in_tree);
        StmtNumWn[in_tree] = stmt_count;
        StmtWnNum[stmt_count] = in_tree;
        stmt_count++;
    }
    
    void mark_visited (WN* myv, std::set<WN*>& myvisited) {
        for (int kc = 0; kc < WN_kid_count(myv); ++kc)
            mark_visited(WN_kid(myv,kc), myvisited);
        myvisited.insert(myv);
    }
    
    void compute_packing_cost (WN* in_tree, int& inpcost) ;
    
    void get_leaves (WN* in_tree, std::vector<WN*>& leaves) {
        if (WN_operator(in_tree) == OPR_LDID ||
                WN_operator (in_tree) == OPR_ILOAD ||
                WN_operator (in_tree) == OPR_ARRAY ||
                WN_operator (in_tree) == OPR_CONST ||
                WN_operator (in_tree) == OPR_INTCONST) {
            leaves.push_back (in_tree);
            return;
        } else {
            for (int i = 0; i < WN_kid_count(in_tree); ++i)
                get_leaves(WN_kid(in_tree,i), leaves);
            return;
        }
    }
    
    bool sanitize_stmts (WN* beg) {
        WN* wn_temp = WN_first(beg);
        while (wn_temp) {
            WN* in_tree = wn_temp;
            OPERATOR opr = WN_operator(in_tree);
            if ((opr != OPR_ISTORE && opr != OPR_STID && opr != OPR_COMMENT
                    && opr != OPR_PRAGMA && opr != OPR_TRUEBR && opr != OPR_FALSEBR
                    && opr != OPR_PREFETCH)) {
                return false;
            }
            wn_temp = WN_next(wn_temp);
        }
        return true;
    }
    
    bool sanitize_opcodes (WN* in_tree) {
        OPERATOR opr = WN_operator(in_tree);
        if ((opr != OPR_ADD && opr != OPR_SUB && opr != OPR_MPY && opr != OPR_DIV
                && opr != OPR_SQRT && opr != OPR_RSQRT && opr != OPR_NEG && opr != OPR_RECIP
                && opr != OPR_NEG && opr != OPR_LDID && opr != OPR_ILOAD && opr != OPR_STID
                && opr != OPR_ARRAY && opr != OPR_CONST && opr != OPR_INTCONST && opr != OPR_ISTORE
                && opr != OPR_PAREN)) {
            return false;
        } else {
            if (opr == OPR_ILOAD) return true;
            if (opr == OPR_ISTORE)
                return sanitize_opcodes(WN_kid0(in_tree));
            bool retval = true;
            for (int i = 0; i < WN_kid_count(in_tree) && retval ; ++i) {
                retval &= (sanitize_opcodes(WN_kid(in_tree,i)));
            }
            return retval;
        }
    }
    
    void print_stmts (FILE* fp) {
        if (StmtVector.size() == 0) return;
        for (std::vector<WN*>::iterator stmit = StmtVector.begin();
                stmit != StmtVector.end(); ++stmit) {
            fprintf(fp,"0x%x\n",*stmit);
        }
    }

    void print_layout (FILE* fp) {
        if (layout_order.size() == 0) return;
        for (std::vector<WN*>::iterator stmit = layout_order.begin();
                stmit != layout_order.end(); ++stmit) {
            fprintf(fp,"0x%x\n",*stmit);
        }
    }
    void fixin_reductions(VECTORBUILDER& vecbuil) ;
    void fixin_constants(VECTORBUILDER& vecbuil) ;
    void fixin_invariants(VECTORBUILDER& vecbuil) ;

    int get_block_size(WN *blk) {
        WN *wn=WN_first(blk);
        int n=0;
        while(wn) {
            n++;
            wn=WN_next(wn);
        }
        return n;
    }
    
    void add_partial_vectors_to_block () ;
    void estimate_per_stmt(WN* beg) ;
    
    void print_of_node_adj (FILE* fp) {
        fprintf (fp, "node_adj ... \n");
        for (std::map<WN*, std::set<int> >::iterator myit = get_node_adj().begin();
                myit != get_node_adj().end()   ; ++myit) {
            fprintf (fp,"%x <- ", myit->first);
            for (std::set<int>::const_iterator myde_it = myit->second.begin();
                    myde_it != myit->second.end(); ) {
                fprintf (fp,"%x", StmtVector[*myde_it]);
                if ((++myde_it) == myit->second.end()) {
                    fprintf (fp, "\n");
                    break;
                } else {
                    fprintf (fp, " ");
                }
            }
        }
        fprintf (fp, "done\n");
    }
    
    void print_of_anti_dep (FILE* fp) {
        fprintf (fp, "antidependencies\n");
        for (std::map<WN*, std::set<int> >::iterator myit = get_anti_dep().begin();
                myit != get_anti_dep().end()   ; ++myit) {
            fprintf (fp,"%x <- ", myit->first);
            for (std::set<int>::const_iterator myde_it = myit->second.begin();
                    myde_it != myit->second.end(); ) {
                fprintf (fp,"%x", StmtVector[*myde_it]);
                if ((++myde_it) == myit->second.end()) {
                    fprintf (fp, "\n");
                    break;
                } else {
                    fprintf (fp, " ");
                }
            }
        }
        fprintf (fp, "done\n");
    }
    
    void print_of_output_dep (FILE* fp) {
        for (std::map<WN*, std::set<int> >::iterator myit = get_output_dep().begin();
                myit != get_output_dep().end()   ; ++myit) {
            fprintf (fp,"%x <- ", myit->first);
            for (std::set<int>::const_iterator myde_it = myit->second.begin();
                    myde_it != myit->second.end(); ) {
                fprintf (fp,"%x", StmtVector[*myde_it]);
                if ((++myde_it) == myit->second.end()) {
                    fprintf (fp, "\n");
                    break;
                } else {
                    fprintf (fp, " ");
                }
            }
        }
    }
    void finalize_it () ;
    void GraphOfBlock (WN* in_tree);
    int Depth (WN* in_tree);
    void dfs_topo_sort (WN* myvi, std::set<WN*>& visited, std::vector<WN*>& blk);
    void topological_reordering_of_block ();
    void generate_constructors_and_patch_block (std::vector<WN*>& layout_order);
    bool find_partial_vectors_in_block ();
    void add_psuedo_edges_for_topo_sort ();
};

class PARTIAL_SIMD_WALKER {
public:
    Unroll_For_Psimd_Walker& unroll_walker;
    ALIAS_MANAGER* _alias_mgr;
    WN* lastnode_processed;
    std::set<WN*> visited;
    bool is_serializing_node (WN* beg) {
        if (WN_operator(beg) == OPR_AGOTO
                || WN_operator(beg) == OPR_ALTENTRY
                || WN_operator(beg) == OPR_FUNC_ENTRY
                || WN_operator(beg) == OPR_ASSERT
                || WN_operator(beg) == OPR_BACKWARD_BARRIER
                || WN_operator(beg) == OPR_CALL
                || WN_operator(beg) == OPR_CASEGOTO
                || WN_operator(beg) == OPR_COMPGOTO
                || WN_operator(beg) == OPR_EVAL
                || WN_operator(beg) == OPR_EXC_SCOPE_BEGIN
                || WN_operator(beg) == OPR_EXC_SCOPE_END
                || WN_operator(beg) == OPR_FALSEBR
                || WN_operator(beg) == OPR_TRUEBR
                || WN_operator(beg) == OPR_FORWARD_BARRIER
                || WN_operator(beg) == OPR_GOTO
                || WN_operator(beg) == OPR_ICALL
                || WN_operator(beg) == OPR_INTRINSIC_CALL
                || WN_operator(beg) == OPR_IO
                || WN_operator(beg) == OPR_OPT_RESERVE2
                || WN_operator(beg) == OPR_PICCALL
                || WN_operator(beg) == OPR_REGION_EXIT
                || WN_operator(beg) == OPR_RETURN
                || WN_operator(beg) == OPR_RETURN_VAL
                || WN_operator(beg) == OPR_SWITCH
                || WN_operator(beg) == OPR_TRAP
                || WN_operator(beg) == OPR_VFCALL
                || WN_operator(beg) == OPR_GOTO_OUTER_BLOCK
                || WN_operator(beg) == OPR_XGOTO
                || WN_operator(beg) == OPR_AFFIRM
                || WN_operator(beg) == OPR_DEALLOCA
                || WN_operator(beg) == OPR_ASM_STMT
                || WN_operator(beg) == OPR_DO_LOOP
                || WN_operator(beg) == OPR_DO_WHILE
                || WN_operator(beg) == OPR_WHILE_DO
                || WN_operator(beg) == OPR_IF
                || WN_operator(beg) == OPR_FUNC_ENTRY
                || WN_operator(beg) == OPR_REGION
                || WN_operator(beg) == OPR_ZDLBR)
            return true;
        else return false;
    }

    void collect_wns (WN* beg, std::set<WN*>& allinblock) {
        allinblock.insert (beg);
        for (int k = 0; k < WN_kid_count(beg); ++k) {
            collect_wns (WN_kid (beg, k), allinblock);
        }
    }

    bool compare_b4_aft (WN* b4, WN* aft) {
        if (WN_opcode(b4) != WN_opcode(aft)) {
            return false;
        } else {
            bool allkids = true;
            for (int k = 0; k < WN_kid_count(b4) && allkids; ++k) {
                allkids = allkids && compare_b4_aft(WN_kid(b4,k), WN_kid(aft,k));
            }
            return allkids;
        }
    }

    explicit PARTIAL_SIMD_WALKER (ALIAS_MANAGER *alis, Unroll_For_Psimd_Walker& unroll_wlk) :
        _alias_mgr(alis), unroll_walker(unroll_wlk) {}
    void check_statement_naming (WN* beg,
                                 std::set<WN*>& seen_loads,
                                 std::vector<WN*>& seen_stids,
                                 std::set<WN*>& exposed_ldids,
                                 std::set<WN*>& exposed_stids,
                                 std::map<WN*, WN*>& valu_num,
                                 const std::set<WN*>& allinblock);
    void rename_vars (WN* beg);
    void Walk_helper  (WN* beg, PARTIAL_SIMD_ESTIMATOR& part_simd);
    void Walk (WN* beg);
    void start_psimd(WN* beg);
};
#endif

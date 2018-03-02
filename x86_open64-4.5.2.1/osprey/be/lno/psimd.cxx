
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
#include "psimd.h"
//collect all LDIDs within in_tree into a set
void Unroll_For_Psimd::get_ldids (WN* in_tree, std::set<WN*>& leaves) {
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

// transfer du info from all LDIDs in from_tree to the LDIDs in to_tree
void Unroll_For_Psimd::Transfer_DU (WN *from_tree, WN *to_tree ) {
    std::set<WN *> ldids;
    get_ldids(from_tree,ldids);
    for(int i=0; i<WN_kid_count(to_tree); i++) {
        if(WN_operator(WN_kid(to_tree,i)) == OPR_LDID) {
            for (std::set<WN*>::iterator li = ldids.begin();
                    li != ldids.end(); ++li) {
                if(SYMBOL(WN_kid(to_tree,i)) == SYMBOL(*li)) {
                    DEF_LIST *def_list = Du_Mgr->Ud_Get_Def(*li);
                    DEF_LIST_ITER iter(def_list);
                    const DU_NODE *node = iter.First();
                    for(; !iter.Is_Empty(); node=iter.Next()) {
                        WN *def = (WN *) node->Wn();
                        Du_Mgr->Add_Def_Use(def, *li);
                    }
                }
            }
        }
    }
}

// change the 'loop_stmt' field in the def_list of LDIDs from old_loop to new_loop
static void Update_Def_List_Loop_Stmt(WN* old_loop, WN* new_loop) {
    std::set<WN*>  ldids;
    get_ldids(old_loop,ldids);
    for (std::set<WN*>::iterator ldi_it = ldids.begin();
            ldi_it != ldids.end(); ++ldi_it) {
        DEF_LIST *def_list = Du_Mgr->Ud_Get_Def(*ldi_it);
        if (def_list) {
            if (def_list->Loop_stmt() == old_loop) {
                def_list->Set_loop_stmt(new_loop);
            }
        }
    }
}

// change the 'loop_stmt' field in the def_list of LDIDs from old_loop to new_loop
void Unroll_For_Psimd_Walker::Fix_Def_List_Loop_Stmt(WN* func_nd, std::set<WN *>& deleted_loop) {
    std::set<WN*>  ldids;
    get_ldids(func_nd,ldids);
    for (std::set<WN*>::iterator ldi_it = ldids.begin();
            ldi_it != ldids.end(); ++ldi_it) {
        DEF_LIST *def_list = Du_Mgr->Ud_Get_Def(*ldi_it);
        if (def_list) {
            if (deleted_loop.find(def_list->Loop_stmt()) != deleted_loop.end() ) {
                def_list->Set_loop_stmt((WN *)NULL);
            }
        }
    }
}

/* compute trip count of loops
 * 3 kinds - non-const (needs remainder loop)
 *         - constant, multiple of unroll factor (no remainder loop)
 *         - constant, not divisible by unroll factor (needs remainder loop)
 */
bool Unroll_For_Psimd::Compute_Trips() {
    // if index var is on rhs of end_cond, swap it
    if (WN_operator(WN_kid1(WN_end(orig_loop))) == OPR_LDID &&
            WN_st_idx(WN_kid1(WN_end(orig_loop))) == WN_st_idx(WN_index(orig_loop)) &&
            WN_offset(WN_kid1(WN_end(orig_loop))) == WN_offset(WN_index(orig_loop))) {
        WN  *temp = WN_kid0(WN_end(orig_loop));
        WN_kid0(WN_end(orig_loop))  = WN_kid1(WN_end(orig_loop));
        WN_kid1(WN_end(orig_loop))  = temp;
        switch  (WN_operator(WN_end(orig_loop))) {
        case  OPR_LT:
            WN_set_operator(WN_end(orig_loop), OPR_GT);
            break;
        case  OPR_LE:
            WN_set_operator(WN_end(orig_loop), OPR_GE);
            break;
        case  OPR_GT:
            WN_set_operator(WN_end(orig_loop), OPR_LT);
            break;
        case  OPR_GE:
            WN_set_operator(WN_end(orig_loop), OPR_LE);
            break;
        default:
            FmtAssert(FALSE, ("Unroll_For_Psimd:Handle this case\n"));
        }
    }

    WN *end;
    if (WN_operator(WN_kid0(WN_end(orig_loop))) == OPR_LDID &&
            WN_st_idx(WN_kid0(WN_end(orig_loop))) == WN_st_idx(WN_index(orig_loop)) &&
            WN_offset(WN_kid0(WN_end(orig_loop))) == WN_offset(WN_index(orig_loop))) {
        end = LWN_Copy_Tree(WN_kid1(WN_end(orig_loop)), TRUE, LNO_Info_Map);
        Copy_Def_Use(WN_kid1(WN_end(orig_loop)),end);
    } else end = NULL;

    WN *incr_expr = WN_kid0(WN_step(orig_loop));
    if (WN_operator(incr_expr) != OPR_ADD)
        step_amt = 0;
    else if (WN_operator(WN_kid1(incr_expr)) != OPR_INTCONST)
        step_amt = 0;
    else step_amt =  WN_const_val(WN_kid1(incr_expr));
    if (! (step_amt > 0 && (WN_operator(WN_end(orig_loop)) == OPR_LT ||
                            WN_operator(WN_end(orig_loop)) == OPR_LE) ||
            step_amt < 0 && (WN_operator(WN_end(orig_loop)) == OPR_GT ||
                             WN_operator(WN_end(orig_loop)) == OPR_GE)))
        end = NULL;

    // adjust _end for convert LE and GE
    if (end)
        if (WN_operator(WN_end(orig_loop)) == OPR_LE ||
                WN_operator(WN_end(orig_loop)) == OPR_GE)
            end = WN_Add(rtype, end, WN_Intconst(rtype, step_amt));

    abs_step_amt = step_amt >= 0 ? step_amt : -step_amt;
    WN *start = WN_kid0(WN_start(orig_loop));
    if (end) {
        WN *start_copy = LWN_Copy_Tree(start, TRUE, LNO_Info_Map);
        if (step_amt > 0)
            trips = WN_Sub(rtype, end, start_copy);
        else trips = WN_Sub(rtype, start_copy, end);
        Transfer_DU(start,trips);
        // if not already adjusted for LE/GE, and has remainder, then adjust
        // e.g. for (i = 0; i < 5; i+=2) has 5/2+1 trips
        if (! (WN_operator(WN_end(orig_loop)) == OPR_LE ||
                WN_operator(WN_end(orig_loop)) == OPR_GE)) {
            WN *trips_copy = LWN_Copy_Tree(trips, TRUE, LNO_Info_Map);
            WN *tmp = WN_Binary(OPR_MOD, rtype, trips_copy,
                                WN_Intconst(rtype, abs_step_amt));
            tmp = WN_Select(rtype, WN_EQ(rtype, tmp, WN_Intconst(rtype, 0)),
                            WN_Intconst(rtype, 0),
                            WN_Intconst(rtype, 1));
            // trips should be number of trips actually needed, so divide by step
            trips = WN_Div(rtype, trips, WN_Intconst(rtype, abs_step_amt));
            trips = WN_Add(rtype, trips, tmp);
        } else {
            // trips should be number of trips actually needed, so divide by step
            trips = WN_Div(rtype, trips, WN_Intconst(rtype, abs_step_amt));
        }
    }
    //not a well formed loop, can't unroll
    if(end == NULL || step_amt == 0)
        return false;
    return true;
}

void  Unroll_For_Psimd::Create_Unroll_Rem_Loop() {
    // create rem loop
    rem_loop = LWN_Copy_Tree(orig_loop, TRUE, LNO_Info_Map);
    // create store loop, which we shall store in a map, and use in psimd for rerolling
    store_loop = LWN_Copy_Tree(orig_loop,  TRUE, LNO_Info_Map);
    LWN_Parentize(store_loop);
    // if original loop had non zero trip count,
    // doesnt mean unroll loop and rem loop will also have non zero trip count,reset it
    if(WN_kid_count(rem_loop) == 6)
        WN_Reset_Loop_Nz_Trip(WN_kid(rem_loop,5));
    if(WN_kid_count(orig_loop) == 6)
        WN_Reset_Loop_Nz_Trip(WN_kid(orig_loop,5));

    WN **du_update_holder = CXX_NEW_ARRAY(WN *, unroll_factor+2, &LNO_local_pool);;
    du_update_holder[0] = orig_loop;
    //create unroll loop bodies
    for (int i = 1; i < unroll_factor ; i++) {
        du_update_holder[i] = LWN_Copy_Tree(orig_loop, TRUE, LNO_Info_Map);
        LWN_Scale_Frequency_Tree(du_update_holder[i], 1.0/unroll_factor);
    }
    du_update_holder[unroll_factor] = rem_loop;
    du_update_holder[unroll_factor+1] = store_loop;
    // update du chain of unrolled,remainder and store loops
    Unrolled_DU_Update(du_update_holder,unroll_factor+2,0,
                       TRUE,TRUE);
    // to every LDID of the induction variable in unrolled body, add the iteration number
    for (int i = 1; i < unroll_factor; i++) {
        Add_To_Symbol(du_update_holder[i], i*step_amt, index_sym, TRUE);
    }
    for (int i = 0; i < unroll_factor; i++) {
        int next=0;
        wn_to_iter(WN_first(WN_do_body(du_update_holder[i])),next, i);
    }
    for (int i = 1; i < unroll_factor; i++) {
        Update_Def_List_Loop_Stmt(du_update_holder[i], orig_loop);
        LWN_Update_Def_Use_Delete_Tree(WN_start(du_update_holder[i]));
        LWN_Update_Def_Use_Delete_Tree(WN_end(du_update_holder[i]));
        LWN_Update_Def_Use_Delete_Tree(WN_step(du_update_holder[i]));
        LWN_Delete_Tree(WN_start(du_update_holder[i]));
        LWN_Delete_Tree(WN_end(du_update_holder[i]));
        LWN_Delete_Tree(WN_step(du_update_holder[i]));
    }
    Update_Def_List_Loop_Stmt(du_update_holder[unroll_factor], rem_loop);
    Update_Def_List_Loop_Stmt(du_update_holder[unroll_factor+1], store_loop);
    for (int i = 1; i < unroll_factor; i++) {
        LWN_Insert_Block_After(WN_do_body(orig_loop),
                               WN_last(WN_do_body(orig_loop)),
                               WN_do_body(du_update_holder[i]));
    }
    CXX_DELETE(du_update_holder,&LNO_local_pool);

}

// adjust loop initializers for unrolled loop and remainder loop
void Unroll_For_Psimd::Adjust_Start_Cond_Init() {
    WN *unrolled_incr_stmt = WN_step(orig_loop);
    Add_To_Symbol(WN_kid0(unrolled_incr_stmt), (unroll_factor - 1) * step_amt,
                  index_sym, TRUE);

    WN *unrolled_trips;
    int const_trips = 0; // if constant trip count, value is trip count
    if (WN_operator(trips) == OPR_INTCONST)
        const_trips = WN_const_val(trips);
    if (const_trips)
        unrolled_trips = WN_Intconst(rtype, (const_trips / unroll_factor ) *
                                     (unroll_factor * abs_step_amt));
    else {
        unrolled_trips = WN_Div(rtype, trips, WN_Intconst(rtype, unroll_factor));
        unrolled_trips = WN_Mpy(rtype,unrolled_trips,
                                WN_Intconst(rtype,unroll_factor*abs_step_amt));
    }

    WN *start = WN_kid0(WN_start(rem_loop));
    WN *start_copy = LWN_Copy_Tree(start, TRUE, LNO_Info_Map);
    WN *unrolled_end_cond = WN_Relational(step_amt > 0 ? OPR_LT : OPR_GT, rtype,
                                          WN_kid0(WN_end(orig_loop)),
                                          WN_Binary(step_amt > 0 ? OPR_ADD : OPR_SUB, rtype,
                                                  start_copy, unrolled_trips));
    Transfer_DU(start,unrolled_end_cond);
    WN *handle =  WN_end(orig_loop);
    LWN_Delete_Tree(WN_kid1(handle));
    WN_end(orig_loop) = unrolled_end_cond;
    WN_step(orig_loop) = unrolled_incr_stmt;

    if(const_trips && const_trips % unroll_factor == 0) {
        LWN_Update_Def_Use_Delete_Tree(rem_loop);
        LWN_Delete_Tree(rem_loop);
        rem_loop = NULL;
        unroll_walker.my_unroll[orig_loop] = std::make_pair(rem_loop,store_loop);
        return;
    }
    if (const_trips) {
        WN *start_copy = LWN_Copy_Tree(WN_kid0(WN_start(rem_loop)), TRUE, LNO_Info_Map);
        WN *temp = WN_Binary(step_amt > 0 ? OPR_ADD : OPR_SUB,
                             rtype, start_copy, WN_Intconst(rtype, (const_trips / unroll_factor) *
                                     (unroll_factor * abs_step_amt)));
        Transfer_DU(WN_kid0(WN_start(rem_loop)),temp);
        WN_kid0(WN_start(rem_loop)) = temp;
    } else {
        WN *old_wn = WN_kid0(WN_start(rem_loop));
        WN *my_copy = LWN_Copy_Tree(WN_kid0(WN_end(rem_loop)),TRUE, LNO_Info_Map);
        LWN_Copy_Def_Use(WN_kid0(WN_end(rem_loop)), my_copy, Du_Mgr);
        WN_kid0(WN_start(rem_loop)) = my_copy;
        LWN_Update_Def_Use_Delete_Tree(old_wn);
        LWN_Delete_Tree(old_wn);
    }
    WN *parent = LWN_Get_Parent(orig_loop);
    LWN_Insert_Block_Before(parent, WN_next(orig_loop), rem_loop);
    unroll_walker.my_unroll[orig_loop] = std::make_pair(rem_loop,store_loop);
}

/* Maintain a mapping between whirl nodes in the unrolled loop to,
 * statement number of the whirl node in the loop and iteration number of the whirl node
 */
void Unroll_For_Psimd::wn_to_iter (WN* wn,int &stmt_num,int iter) {
    if(!wn) return;
    unroll_walker.iter_map[wn] = std::make_pair(iter,stmt_num);
    stmt_num++;
    wn = WN_next(wn);
    wn_to_iter (wn,stmt_num,iter);
}

/* Group STIDs within the loop body by their type,
 * unroll factor is determined by the largest group
 * unroll factor = vector_register_length / type_size_of_largest_group
 */
int Unroll_For_Psimd_Walker::Determine_Unroll_Factor(WN *doloop) {
    std::map<unsigned short,std::vector<WN*> > stid_type_map;
    WN *loop_block = WN_kid(doloop,4);
    for(WN *wn = WN_first(loop_block); wn; wn = WN_next(wn)) {
        if( OPERATOR_is_scalar_store(WN_operator(wn))) {
            unsigned short  stid_type =  MTYPE_bit_size(WN_desc(wn));
            stid_type_map[stid_type].push_back(wn);
        }
    }
    unsigned int max = 0, size = 0;
    for (std::map<unsigned short,std::vector<WN*> >::iterator type_it =
                stid_type_map.begin();
            type_it != stid_type_map.end(); ++type_it) {
        if(type_it->second.size() > max) {
            max = type_it->second.size();
            size = type_it->first;
        }
    }
    int unroll_factor;
    if(size && size <= 64) {
        unroll_factor = 128/size;
        return unroll_factor;
    } else {
        return 0;
    }
}

/* ====================================================================
 * original:
 * 	for (i = start; i < end; i += step)
 *	  body(i)
 * unrolled:
 *      trips = (end - start);
 * 	for (i = start; i < start + (trips / 4) * 4;  i += step*4) {
 *	  body(i)
 *	  body(i+step)
 *	  body(i+2*step)
 *	  body(i+3*step)
 *      }
 * remainder:
 *	for (i = i; i < end; i += step)
 *	  body(i)
 * ==================================================================== */
void Unroll_For_Psimd_Walker::Do_Unroll(WN *loop) {
    WN *parent = LWN_Get_Parent(loop);
    int ufactor = Determine_Unroll_Factor(loop) ;
    if(ufactor == 0)
        return;
    unroll_factor = ufactor;
    Unroll_For_Psimd my_obj(*this, loop,ufactor);
    if(my_obj.Compute_Trips() == false)
        return;
    my_obj.Create_Unroll_Rem_Loop();
    my_obj.Adjust_Start_Cond_Init();
    if(red_manager) {
        red_manager->Build(loop, TRUE, FALSE);//scalar
        DOLOOP_STACK *loop_stack=CXX_NEW(DOLOOP_STACK(&LNO_local_pool),
                                         &LNO_local_pool);
        LNO_Build_Access(loop, loop_stack, &LNO_default_pool);
    }
}

//Check if loop is suitable for unroll
bool Unroll_For_Psimd_Walker::Sanity_Unroll(WN *wn) {
    WN* wn_temp = WN_first(wn);
    while (wn_temp) {
        OPERATOR opr = WN_operator(wn_temp);
        //unroll loops with only assignment stmts,comments,pragmas,prefetches
        if ((opr != OPR_ISTORE && opr != OPR_STID && opr != OPR_COMMENT
                && opr != OPR_PRAGMA && opr != OPR_TRUEBR && opr != OPR_FALSEBR
                && opr != OPR_PREFETCH)) {
            return false;
        }
        wn_temp = WN_next(wn_temp);
    }

    //if a loop has union, unroll only if fields of union are of the same size
    for(WN *tmp = WN_first(wn); tmp; tmp=WN_next(tmp)) {
        if(WN_operator(tmp)==OPR_STID) {
            TY_IDX type = ST_type (WN_st(tmp));
            TY& ty = Ty_Table[type];
            if (TY_kind(ty) == KIND_STRUCT) {
                if (TY_is_union(ty) ) {
                    bool dontdo = false;
                    FLD_ITER fld_iter = Make_fld_iter(TY_fld(ty));
                    INT tysize  = -1;
                    do {
                        TY_IDX field_ty = (*fld_iter).type;
                        if (tysize == -1) {
                            tysize = TY_size(field_ty);
                        } else {
                            if (TY_size(field_ty) != tysize)
                                dontdo = true;
                        }
                    } while(!FLD_last_field(fld_iter++));
                    if (dontdo == true)
                        return false;
                } else return false;
            }
        }
        std::set<WN*> leaves;
        get_ldids(tmp,leaves);
        for (std::set<WN*>::iterator cli = leaves.begin();
                cli != leaves.end(); ++cli) {
            TY_IDX type = ST_type (WN_st(*cli));
            TY& ty = Ty_Table[type];
            if (TY_kind(ty) == KIND_STRUCT) {
                if (TY_is_union(ty) ) {
                    bool dontdo = false;
                    FLD_ITER fld_iter = Make_fld_iter(TY_fld(ty));
                    INT tysize  = -1;
                    do {
                        TY_IDX field_ty = (*fld_iter).type;
                        if (tysize == -1) {
                            tysize = TY_size(field_ty);
                        } else {
                            if (TY_size(field_ty) != tysize)
                                dontdo = true;
                        }
                    } while(!FLD_last_field(fld_iter++));
                    if (dontdo == true)
                        return false;
                } else return false;
            }
        }
    }
    return true;
}

void Unroll_For_Psimd_Walker::Do_Unroll_Walk(WN *wn) {
    if(OPCODE_is_leaf(WN_opcode(wn))) {
        return;
    } else if (WN_operator(wn) == OPR_DO_LOOP) {
        if(Sanity_Unroll(WN_do_body(wn))) {
            Do_Unroll(wn);
        } else {
            Do_Unroll_Walk (WN_do_body(wn));
        }
    } else if(WN_operator(wn) == OPR_BLOCK) {
        WN *wn_temp = WN_first(wn);
        while(wn_temp) {
            WN *next = WN_next(wn_temp);
            Do_Unroll_Walk(wn_temp);
            wn_temp = next;
        }
    } else {
        for(INT kidno=0; kidno<WN_kid_count(wn); kidno++) {
            Do_Unroll_Walk(WN_kid(wn,kidno));
        }
    }
}

bool VECTORBUILDER::check_for_invariance (WN **wn_array,int length) {
    bool invariant = false;
    for (int i=0; i<length; i++) {
        invariant = check_for_invariance (wn_array[i]);
        if (invariant == false)
            break;
    }
    return invariant;
}

WN* VECTORTY::convert_to_simd (WN* in_tree, int& start_it) {
    OPCODE myopc = WN_opcode (in_tree);
    if (WN_operator(in_tree) == OPR_LDID ||
            WN_operator (in_tree) == OPR_ILOAD ||
            WN_operator (in_tree) == OPR_CONST) {
        WN* rwn = cons[start_it];
        TYPE_ID vecty;
        if (WN_rtype(in_tree) == MTYPE_F8) {
            vecty = MTYPE_V16F8;
        } else vecty = MTYPE_V16F4;
        WN* constructor = NULL;
        if (WN_operator(rwn) == OPR_STID) {
            constructor =
                LWN_CreateLdid( OPCODE_make_op (
                                    OPR_LDID,vecty,vecty),
                                rwn);
            Du_Mgr->Add_Def_Use (rwn, constructor);
        } else constructor = rwn;
        ++start_it;
        return constructor;
    } else if (myopc == OPC_F4ADD || myopc == OPC_F4SUB || myopc == OPC_F4MPY
               || myopc == OPC_F4DIV || myopc == OPC_F4SQRT || myopc == OPC_F4RSQRT
               || myopc == OPC_F4RSQRT || myopc == OPC_F4RECIP || myopc == OPC_F4NEG
               || myopc == OPC_F4MIN || myopc == OPC_F4MAX
               || myopc == OPC_F4PAREN ) {
        WN_set_rtype(in_tree, MTYPE_V16F4);
    } else if (myopc == OPC_F8ADD || myopc == OPC_F8SUB || myopc == OPC_F8MPY
               || myopc == OPC_F8DIV || myopc == OPC_F8SQRT || myopc == OPC_F8RSQRT
               || myopc == OPC_F8RSQRT || myopc == OPC_F8RECIP || myopc == OPC_F8NEG
               || myopc == OPC_F8MIN || myopc == OPC_F8MAX
               || myopc == OPC_F8PAREN ) {
        WN_set_rtype(in_tree, MTYPE_V16F8);
    } else if ( myopc == OPC_F4F8CVT) {
        WN_set_desc(in_tree, MTYPE_V16F8);
        WN_set_rtype(in_tree, MTYPE_V16F4);
    } else if ( myopc == OPC_F8F4CVT) {
        WN_set_desc(in_tree, MTYPE_V16F4);
        WN_set_rtype(in_tree, MTYPE_V16F8);
    } else {
        FmtAssert((0), ("Unsupported partial vectorization opcode\n"));
    }
    for (int i = 0; i < WN_kid_count(in_tree); ++i) {
        LWN_Update_Dg_Delete_Tree(WN_kid(in_tree,i),Array_Dependence_Graph);
        LWN_Delete_CG_dep_graph(WN_kid(in_tree,i));
        WN_kid(in_tree,i) =  convert_to_simd (WN_kid(in_tree,i), start_it);
    }
    return in_tree;
}

WN* VECTORTY::LDID_of_vect () {
    TYPE_ID myty = WN_desc(vect);
    OPCODE ld_opc = OPCODE_make_op (OPR_LDID, myty, myty);
    WN* arg0 = LWN_CreateLdid(ld_opc, vect);
    Du_Mgr->Add_Def_Use(vect, arg0);
    return arg0;
}

void VECTORTY::convert_to_simd () {
    WN* first_one = LWN_Copy_Tree (WN_kid0(myvecs[0]), TRUE, LNO_Info_Map);
    int start_it = 0;
    WN* vecy = convert_to_simd(first_one, start_it);
    WN* rwn = NULL;
    if (is_a_reduc == false) {
        SYMBOL preg;
        preg = Create_Preg_Symbol("result_of_simd_version",get_vdtyp());
        rwn = WN_StidIntoPreg (preg.Type, preg.WN_Offset(),
                               preg.St(), vecy);
        Create_alias(_alias_mgr, rwn);
    } else {
        OPCODE opc = OPCODE_make_op (OPR_STID, MTYPE_V, get_vdtyp());
        rwn = LWN_CreateStid (opc, red_stid, vecy);
        Create_alias(_alias_mgr, rwn);

    }
    vect = rwn;
}

bool VECTORTY::are_loads_of_vectys_elems (const std::vector<WN*>& myld) const {
    std::vector<WN*>::const_iterator myld_i = myld.begin();
    std::vector<WN*>::const_iterator myv_it = myvecs.begin();
    for (; myld_i != myld.end() && myv_it != myvecs.end(); ++myld_i, ++myv_it) {
        if (Aliased (_alias_mgr, *myld_i, *myv_it) != SAME_LOCATION) {
            return false;
        }
    }
    return true;
}

void VECTORTY::create_shifts () {
    if (store_packing) {
        for (int myvi = 0; myvi < myvecs.size(); ++myvi) {
            LWN_Update_Dg_Delete_Tree(myvecs[myvi],Array_Dependence_Graph);
            LWN_Delete_CG_dep_graph(myvecs[myvi]);
        }
        if (WN_desc(myvecs[0]) == MTYPE_F8)
            WN_set_desc(myvecs[0], MTYPE_V16F8);
        else WN_set_desc (myvecs[0], MTYPE_V16F4);
        TYPE_ID vecty = get_vdtyp();
        OPCODE opcod_ldid;
        if (vecty == MTYPE_V16F4)
            opcod_ldid = OPC_V16F4V16F4LDID;
        else
            opcod_ldid = OPC_V16F8V16F8LDID;
        WN* arg0 =
            LWN_CreateLdid(opcod_ldid,vect);
        Du_Mgr->Add_Def_Use(vect, arg0);
        {
            std::set<WN*> leaves;
            get_ldids(WN_kid0(myvecs[0]), leaves);
            for (std::set<WN*>::iterator cli = leaves.begin();
                    cli != leaves.end(); ++cli)
                LWN_Delete_DU (*cli);
            LWN_Delete_Tree (WN_kid0(myvecs[0]));
        }
        WN_kid0(myvecs[0]) = arg0;

        shuffles.push_back (myvecs[0]);
    } else {
        for (int vecfi = 0; vecfi < myvecs.size(); ++vecfi) {
            WN * args[2];
            WN* wn;
            WN* arg0;
            TYPE_ID vecty = get_vdtyp();
            OPCODE opcod_ldid;
            if (vecty == MTYPE_V16F4)
                opcod_ldid = OPC_V16F4V16F4LDID;
            else
                opcod_ldid = OPC_V16F8V16F8LDID;
            arg0 =
                LWN_CreateLdid(opcod_ldid,vect);
            Du_Mgr->Add_Def_Use(vect, arg0);
            TY_IDX arg_ty_idx = MTYPE_TO_TY_array[WN_rtype (arg0)];
            TYPE_ID arg_mtype = WN_rtype (arg0);
            WN* arg0copy = arg0;
            args[0] = WN_CreateParm (arg_mtype, arg0copy,
                                     arg_ty_idx, WN_PARM_BY_VALUE);

            SYMBOL pregs;
            ST* preg_sts;
            if (vecty == MTYPE_V16F8) {
                WN * num_bits = WN_Intconst(MTYPE_I8, vecfi*8*8);
                arg_ty_idx = MTYPE_TO_TY_array[MTYPE_I8];
                arg_mtype = MTYPE_I8;
                args[1] = WN_CreateParm (arg_mtype, num_bits,
                                         arg_ty_idx, WN_PARM_BY_VALUE);
                wn = WN_Create_Intrinsic (OPR_INTRINSIC_OP,
                                          MTYPE_F8, MTYPE_V, INTRN_PSRLDQ, 2, args);


                if (WN_operator( myvecs[vecfi]) == OPR_STID) {
                    {
                        std::set<WN*> leaves;
                        get_ldids(WN_kid0(myvecs[vecfi]), leaves);
                        for (std::set<WN*>::iterator cli = leaves.begin();
                                cli != leaves.end(); ++cli) {
                            LWN_Delete_DU (*cli);
                        }
                        LWN_Update_Dg_Delete_Tree(WN_kid0(myvecs[vecfi]),Array_Dependence_Graph);
                        LWN_Delete_CG_dep_graph(WN_kid0(myvecs[vecfi]));
                        LWN_Delete_Tree (WN_kid0(myvecs[vecfi]));
                    }
                    WN_kid0(myvecs[vecfi]) = wn;
                    shuffles.push_back(wn);
                } else {
                    std::set<WN*> leaves;
                    get_ldids(WN_kid0(myvecs[vecfi]), leaves);
                    for (std::set<WN*>::iterator cli = leaves.begin();
                            cli != leaves.end(); ++cli) {
                        LWN_Delete_DU (*cli);
                    }
                    LWN_Update_Dg_Delete_Tree(WN_kid0(myvecs[vecfi]),Array_Dependence_Graph);
                    LWN_Delete_CG_dep_graph(WN_kid0(myvecs[vecfi]));
                    LWN_Delete_Tree (WN_kid0(myvecs[vecfi]));
                    WN_kid0(myvecs[vecfi]) = wn;
                }
            } else {
                WN* argu[3];
                argu[0] = argu[1] = argu[2] = NULL;
                WN * num_shuf = WN_Intconst(MTYPE_U4, vecfi);
                arg_ty_idx = MTYPE_TO_TY_array[MTYPE_I4];
                arg_mtype = MTYPE_I4;
                argu[0] = args[0];
                argu[1] = LWN_Copy_Tree(args[0], TRUE, LNO_Info_Map);
                LWN_Copy_Def_Use(argu[0], argu[1], Du_Mgr);
                argu[2] = WN_CreateParm (arg_mtype, num_shuf,
                                         arg_ty_idx, WN_PARM_BY_VALUE);
                OPCODE op = OPCODE_make_op(OPR_INTRINSIC_OP, MTYPE_F4, MTYPE_V);
                wn = WN_Create_Intrinsic(op, INTRN_SHUFPS, 3, argu);
                if (trace_it) dump_tree(wn);

                if (WN_operator( myvecs[vecfi]) == OPR_STID) {
                    std::set<WN*> leaves;
                    get_ldids(WN_kid0(myvecs[vecfi]), leaves);
                    for (std::set<WN*>::iterator cli = leaves.begin();
                            cli != leaves.end(); ++cli) {
                        LWN_Delete_DU (*cli);
                    }
                    LWN_Update_Dg_Delete_Tree(WN_kid0(myvecs[vecfi]),Array_Dependence_Graph);
                    LWN_Delete_CG_dep_graph(WN_kid0(myvecs[vecfi]));
                    LWN_Delete_Tree (WN_kid0(myvecs[vecfi]));
                    WN_kid0(myvecs[vecfi]) = wn;
                    shuffles.push_back(wn);
                } else {
                    {
                        std::set<WN*> leaves;
                        get_ldids(WN_kid0(myvecs[vecfi]), leaves);
                        for (std::set<WN*>::iterator cli = leaves.begin();
                                cli != leaves.end(); ++cli) {
                            LWN_Delete_DU (*cli);
                        }
                        LWN_Update_Dg_Delete_Tree(WN_kid0(myvecs[vecfi]),Array_Dependence_Graph);
                        LWN_Delete_CG_dep_graph(WN_kid0(myvecs[vecfi]));
                        LWN_Delete_Tree (WN_kid0(myvecs[vecfi]));
                    }
                    WN_kid0(myvecs[vecfi]) = wn;
                }
            }
        }
    }
}

WN* VECTORTY::check_constructors_for_packing (
    const std::vector<WN*>& myld) {
    for (std::vector<WN*>::iterator cons_it = cons.begin();
            cons_it != cons.end(); ++cons_it) {
        if (WN_operator(*cons_it) == OPR_STID &&
                WN_operator(WN_kid0(*cons_it)) == OPR_CONSTRUCTOR) {
            WN* conse = NULL;
            conse = WN_kid0(*cons_it);
            bool same = true;
            if (WN_kid_count(conse) != myld.size()) same = false;
            for ( int ki = 0; ki < WN_kid_count(conse) && same; ++ki ) {
                if (WN_operator(WN_kid(conse, ki)) == WN_operator(myld[ki])) {
                    if (Aliased (_alias_mgr, WN_kid(conse, ki), myld[ki], TRUE)
                            != SAME_LOCATION)
                        same = false;
                } else {
                    same = false;
                }
            }
            if (same == true) {
                OPCODE opc = OPCODE_make_op (OPR_LDID, WN_desc(*cons_it), WN_desc(*cons_it));
                WN* retval = LWN_CreateLdid (opc, *cons_it);
                Du_Mgr->Add_Def_Use(*cons_it, retval);
                return retval;
            }
        }
    }
    return NULL;
}

WN* VECTORTY::check_replicates_for_packing (
    const std::vector<WN*>& myld) {
    for (std::vector<WN*>::iterator repli_it = cons.begin();
            repli_it != cons.end(); ++repli_it) {
        if (WN_operator(*repli_it) == OPR_STID &&
                WN_operator(WN_kid0(*repli_it)) == OPR_REPLICATE) {
            WN* conse = NULL;
            conse = WN_kid0(*repli_it);
            bool same = true;
            int ki = 0;
            if (Aliased (_alias_mgr, myld[0], WN_kid0(conse), TRUE) == SAME_LOCATION) {
                OPCODE opc = OPCODE_make_op (OPR_LDID, WN_desc(*repli_it), WN_desc(*repli_it));
                WN* retval = LWN_CreateLdid (opc, *repli_it);
                Du_Mgr->Add_Def_Use(*repli_it, retval);
                return retval;
            }
        }
    }
    return NULL;
}

bool VECTORBUILDER::check_for_invariance (WN *wn) {
    bool invariant = false;
    WN *parent = LWN_Get_Parent(current_block);
    if(WN_operator(parent) == OPR_DO_LOOP) {
        DO_LOOP_INFO *dli = Get_Do_Loop_Info(parent);
        if(dli->Is_Inner) {
            std::set<WN*>  stids;
            get_stids(current_block,stids);
            DEF_LIST * dlis = Du_Mgr->Ud_Get_Def(wn);
            DEF_LIST_ITER iter(dlis);
            const DU_NODE *tmp = NULL;
            for (tmp = iter.First(); !iter.Is_Empty(); tmp = iter.Next()) {
                if ( (stids.find(tmp->Wn()) == stids.end())) {
                    invariant = true;
                    break;
                }
            }
        }
    }
    return invariant;
}

void VECTORBUILDER::build_constructor (VECTORTY* myve,
                                       const std::vector<WN*>& loadli) {
    TYPE_ID vecty =  myve->get_vdtyp();
    TYPE_ID scalty = myve->get_sdtyp();
    WN* constructor = NULL;
    WN* rwn = check_existing_constructors_for_packing (loadli);
    bool invariant = false;
    if (rwn == NULL) {
        if (vecty == MTYPE_V16F8) {
            WN* kids[2];
            kids[0] = LWN_Copy_Tree (loadli[0], TRUE, LNO_Info_Map);
            kids[1] = LWN_Copy_Tree (loadli[1], TRUE, LNO_Info_Map);
            LWN_Copy_Def_Use(loadli[0], kids[0], Du_Mgr);
            LWN_Copy_Def_Use(loadli[1], kids[1], Du_Mgr);
            constructor = WN_Create_Constructor (
                              OPR_CONSTRUCTOR,
                              MTYPE_V16F8, MTYPE_F8, 2, kids);
            invariant = check_for_invariance(kids,2);
        } else {
            WN* kids[4];
            kids[0] = kids[1] = kids[2] = kids[3] = NULL;
            TCON f4_zero = Host_To_Targ_Float_4(MTYPE_F4,0.0);
            ST* csym = New_Const_Sym (Enter_tcon (f4_zero),
                                      Be_Type_Tbl(TCON_ty(f4_zero)));
            WN* zerof4w;
            zerof4w = WN_CreateConst(OPC_F4CONST, csym );
            for (int vecfi = 0; vecfi < 4; ++vecfi) {
                kids[vecfi] = LWN_Copy_Tree (zerof4w, TRUE, LNO_Info_Map);
            }
            for (int vecfi = 0; vecfi < loadli.size();
                    ++vecfi) {
                kids[vecfi] = LWN_Copy_Tree (
                                  loadli[vecfi],TRUE, LNO_Info_Map);
                LWN_Copy_Def_Use(loadli[vecfi],
                                 kids[vecfi], Du_Mgr);
            }
            constructor = WN_Create_Constructor (
                              OPR_CONSTRUCTOR,
                              MTYPE_V16F4, MTYPE_F4, 4, kids);
            invariant = check_for_invariance(kids,4);
        }
        SYMBOL preg = Create_Preg_Symbol("std_simd_part",vecty);
        ST *preg_st = MTYPE_To_PREG(vecty);
        rwn = WN_StidIntoPreg (preg.Type, preg.WN_Offset(),
                               preg.St(), constructor);
        Create_alias(_alias_mgr, rwn);
        if(invariant) {
            invariant_prefix.push_back(rwn);
            myve->set_invariant(true);
        } else
            myve->prefix.push_back(rwn);
    }
    myve->cons.push_back(rwn);
}

void VECTORBUILDER::build_constructor_reduction (VECTORTY* myve,
        const std::vector<WN*>& loadli) {
    TYPE_ID vecty =  myve->get_vdtyp();
    TYPE_ID scalty = myve->get_sdtyp();
    WN* constructor = NULL;
    WN* rwn = check_existing_reductions_for_packing (loadli);

    if (rwn == NULL) {
        if (vecty == MTYPE_V16F8) {
            WN* kids[2];
            kids[0] = LWN_Copy_Tree (loadli[0], TRUE, LNO_Info_Map);
            kids[1] = LWN_Copy_Tree (loadli[1], TRUE, LNO_Info_Map);
            LWN_Copy_Def_Use(loadli[0], kids[0], Du_Mgr);
            LWN_Copy_Def_Use(loadli[1], kids[1], Du_Mgr);
            constructor = WN_Create_Constructor (
                              OPR_CONSTRUCTOR,
                              MTYPE_V16F8, MTYPE_F8, 2, kids);
        } else {
            WN* kids[4];
            kids[0] = kids[1] = kids[2] = kids[3] = NULL;
            TCON f4_zero = Host_To_Targ_Float_4(MTYPE_F4,0.0);
            ST* csym = New_Const_Sym (Enter_tcon (f4_zero),
                                      Be_Type_Tbl(TCON_ty(f4_zero)));
            WN* zerof4w;
            zerof4w = WN_CreateConst(OPC_F4CONST, csym );
            for (int vecfi = 0; vecfi < 4; ++vecfi) {
                kids[vecfi] = LWN_Copy_Tree (zerof4w, TRUE, LNO_Info_Map);
            }
            for (int vecfi = 0; vecfi < loadli.size();
                    ++vecfi) {
                kids[vecfi] = LWN_Copy_Tree (
                                  loadli[vecfi],TRUE,LNO_Info_Map);
                LWN_Copy_Def_Use(loadli[vecfi],
                                 kids[vecfi], Du_Mgr);
            }
            constructor = WN_Create_Constructor (
                              OPR_CONSTRUCTOR,
                              MTYPE_V16F4, MTYPE_F4, 4, kids);
        }
        SYMBOL preg = Create_Preg_Symbol("reduction_simd_part",vecty);
        ST *preg_st = MTYPE_To_PREG(vecty);
        rwn = WN_StidIntoPreg (preg.Type, preg.WN_Offset(),
                               preg.St(), constructor);
        Create_alias(_alias_mgr, rwn);
        reduction_prefix.push_back(rwn);
        myve->red_stid = rwn;
        WN* ldi = LWN_CreateLdid (OPCODE_make_op(OPR_LDID, WN_desc(rwn),
                                  WN_desc(rwn)), rwn);
        Du_Mgr->Add_Def_Use (rwn, ldi);
        rwn = ldi;
    } else {
        WN* ldi = LWN_CreateLdid (OPCODE_make_op(OPR_LDID, WN_desc(rwn),
                                  WN_desc(rwn)), rwn);
        Du_Mgr->Add_Def_Use (rwn, ldi);
        myve->red_stid = rwn;
        rwn = ldi;
    }
    myve->cons.push_back(rwn);
    myve->set_reduc(true);
}

WN* VECTORBUILDER::check_existing_reductions_for_packing (const std::vector<WN*>& myld) {
    for (std::vector<WN*>::iterator cons_it = reduction_prefix.begin();
            cons_it != reduction_prefix.end(); ++cons_it) {
        if (WN_operator(*cons_it) == OPR_STID &&
                WN_operator(WN_kid0(*cons_it)) == OPR_CONSTRUCTOR) {
            WN* conse = NULL;
            conse = WN_kid0(*cons_it);
            bool same = true;
            if (WN_kid_count(conse) != myld.size()) same = false;
            for ( int ki = 0; ki < WN_kid_count(conse) && same; ++ki ) {
                if (WN_operator(WN_kid(conse, ki)) == WN_operator(myld[ki])) {
                    if (Aliased (_alias_mgr, WN_kid(conse, ki), myld[ki], TRUE)
                            != SAME_LOCATION)
                        same = false;
                } else {
                    same = false;
                }
            }
            if (same == true) {
                return *cons_it;
            }
        }
    }
    return NULL;
}

bool VECTORBUILDER::check_if_reduction (const std::vector<WN*>& mystores,
                                        const std::vector<WN*>& myleaves) {
    for (int cou = 0; cou < mystores.size(); ++cou)
        if (WN_operator(mystores[cou]) != OPR_STID) return false;
    for (int cou = 0; cou < mystores.size(); ++cou)
        if (Aliased (_alias_mgr, mystores[cou], myleaves[cou], TRUE) != SAME_LOCATION)
            return false;

    for (int cou = 0; cou < mystores.size(); cou++)
        if (!is_a_reduction(mystores[cou])) return false;

    return true;
}

bool VECTORBUILDER::is_a_reduction (WN* mywn) {
    if (red_manager) {
        if (red_manager->Which_Reduction(mywn) == RED_NONE)
            return false;
        else {
            std::set<WN*> myleaves;
            get_ldids(mywn,myleaves);
            WN *wn_temp = NULL;
            for(std::set<WN *>::iterator lit = myleaves.begin(); lit != myleaves.end(); lit++) {
                if(Aliased(_alias_mgr,*lit,mywn,TRUE) == SAME_LOCATION) {
                    wn_temp = *lit;
                }
            }
            DEF_LIST *defli = Du_Mgr->Ud_Get_Def (wn_temp);
            DEF_LIST_ITER iter(defli);
            for (const DU_NODE *node=iter.First();
                    !iter.Is_Empty(); node = iter.Next()) {
                WN *def = (WN *) node->Wn();
                if(red_manager->Which_Reduction(def) == RED_NONE &&
                        StmtSet.find(def) != StmtSet.end())
                    return false;
            }
            return true;
        }
    } else return false;
}

WN* VECTORBUILDER::check_existing_constructors_for_packing (
    const std::vector<WN*>& check_these) {
    for (std::vector<VECTORTY*>::const_iterator ex_vit = existing_vect.begin();
            ex_vit != existing_vect.end(); ++ex_vit) {
        VECTORTY* cons_ex_vit  = *ex_vit;
        if (cons_ex_vit->is_valid()) {
            WN* retval =
                cons_ex_vit->check_constructors_for_packing(check_these);
            if (retval != NULL) return retval;
        }
    }
    return NULL;
}

WN* VECTORBUILDER::check_existing_replicates_for_packing (
    const std::vector<WN*>& check_these) {
    for (std::vector<VECTORTY*>::const_iterator ex_vit = existing_vect.begin();
            ex_vit != existing_vect.end(); ++ex_vit) {
        VECTORTY* cons_ex_vit  = *ex_vit;
        if (cons_ex_vit->is_valid()) {
            WN* retval =
                cons_ex_vit->check_replicates_for_packing(check_these);
            if (retval != NULL) return retval;
        }
    }
    return NULL;
}

void VECTORBUILDER::build_constant (VECTORTY* vec, const std::vector<WN*>& consts) {
    TYPE_ID vecty = vec->get_vdtyp();
    SYMBOL preg = Create_Preg_Symbol("const_simd_part",vecty);
    ST *preg_st = MTYPE_To_PREG(vecty);
    WN* constructor;
    if (vecty == MTYPE_V16F8) {
        WN* kids[2];
        kids[0] = LWN_Copy_Tree (consts[0], TRUE, LNO_Info_Map);
        kids[1] = LWN_Copy_Tree (consts[1], TRUE, LNO_Info_Map);
        LWN_Copy_Def_Use(consts[0], kids[0], Du_Mgr);
        LWN_Copy_Def_Use(consts[1], kids[1], Du_Mgr);
        constructor = WN_Create_Constructor (
                          OPR_CONSTRUCTOR,
                          MTYPE_V16F8, MTYPE_F8, 2, kids);
    } else {
        WN* kids[4];
        kids[0] = kids[1] = kids[2] = kids[3] = NULL;
        TCON f4_zero = Host_To_Targ_Float_4(MTYPE_F4,0.0);
        ST* csym = New_Const_Sym (Enter_tcon (f4_zero),
                                  Be_Type_Tbl(TCON_ty(f4_zero)));
        WN* zerof4w;
        zerof4w = WN_CreateConst(OPC_F4CONST, csym );

        for (int vecfi = 0; vecfi < 4; ++vecfi) {
            kids[vecfi] = LWN_Copy_Tree (zerof4w, TRUE, LNO_Info_Map);
        }
        for (int vecfi = 0; vecfi < consts.size();
                ++vecfi) {
            kids[vecfi] = LWN_Copy_Tree (
                              consts[vecfi],TRUE, LNO_Info_Map);
            LWN_Copy_Def_Use(consts[vecfi], kids[vecfi], Du_Mgr);
        }
        constructor = WN_Create_Constructor (
                          OPR_CONSTRUCTOR,
                          MTYPE_V16F4, MTYPE_F4, 4, kids);
    }
    WN* rwn = WN_StidIntoPreg (preg.Type, preg.WN_Offset(),
                               preg.St(), constructor);
    Create_alias(_alias_mgr, rwn);
    constant_prefix.push_back(rwn);
    vec->cons.push_back(rwn);
}

void VECTORBUILDER::build_iloads (VECTORTY* myve, const std::vector<WN*>& myleaves) {
    WN* constructor = LWN_Copy_Tree(myleaves[0], TRUE, LNO_Info_Map);
    LWN_Copy_Def_Use(myleaves[0],constructor,Du_Mgr);
    WN_set_rtype(constructor, myve->get_vdtyp());
    WN_set_desc(constructor, myve->get_vdtyp());
    myve->cons.push_back(constructor);
}

bool VECTORBUILDER::is_istore_packing (const std::vector<WN*>& myleaves) {
    if (myleaves.size() == 2
            && WN_desc(myleaves[0]) == MTYPE_F8
            && WN_desc(myleaves[1]) == MTYPE_F8) {
        if (WN_operator(myleaves[0]) == OPR_ISTORE &&
                WN_operator(myleaves[1]) == OPR_ISTORE) {
            INT Type_Size = MTYPE_byte_size(WN_desc(myleaves[0]));
            std::pair<arr_elem_dist, INT> outval =
                array_elements_distance(myleaves[0], myleaves[1],
                                        _alias_mgr, Type_Size);
            if (outval.first == SOMEMATCH && outval.second == Type_Size) {
                return true;
            }
        }
    } else if (myleaves.size() == 4) {
        if (WN_desc(myleaves[0]) == MTYPE_F4 &&
                WN_desc(myleaves[1]) == MTYPE_F4 &&
                WN_desc(myleaves[2]) == MTYPE_F4 &&
                WN_desc(myleaves[3]) == MTYPE_F4) {
            if (WN_operator(myleaves[0]) == OPR_ISTORE &&
                    WN_operator(myleaves[1]) == OPR_ISTORE &&
                    WN_operator(myleaves[2]) == OPR_ISTORE &&
                    WN_operator(myleaves[3]) == OPR_ISTORE) {
                INT Type_Size = MTYPE_byte_size(WN_desc(myleaves[0]));
                std::pair<arr_elem_dist, INT> outval1 =
                    array_elements_distance(myleaves[0], myleaves[1],
                                            _alias_mgr, Type_Size);
                std::pair<arr_elem_dist, INT> outval2 =
                    array_elements_distance(myleaves[1], myleaves[2],
                                            _alias_mgr, Type_Size);
                std::pair<arr_elem_dist, INT> outval3 =
                    array_elements_distance(myleaves[2], myleaves[3],
                                            _alias_mgr, Type_Size);
                if (outval1.first == SOMEMATCH && outval2.first == SOMEMATCH &&
                        outval3.first == SOMEMATCH) {
                    if (outval1.second == Type_Size &&
                            outval2.second == Type_Size &&
                            outval3.second == Type_Size) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void VECTORBUILDER::build_replicate (VECTORTY* myve,
                                     const std::vector<WN*>& replic) {
    TYPE_ID vecty =  myve->get_vdtyp();
    TYPE_ID scalty = myve->get_sdtyp();
    WN* rwn = check_existing_replicates_for_packing(replic);
    if (rwn == NULL) {
        WN* which_kid = LWN_Copy_Tree (replic[0], TRUE, LNO_Info_Map);
        LWN_Copy_Def_Use(replic[0], which_kid, Du_Mgr);
        WN* constructor = LWN_CreateExp1 (OPCODE_make_op(
                                              OPR_REPLICATE, vecty, scalty), which_kid);
        SYMBOL preg = Create_Preg_Symbol("psimd_replicate",vecty);
        ST *preg_st = MTYPE_To_PREG(vecty);
        rwn = WN_StidIntoPreg (preg.Type, preg.WN_Offset(),
                               preg.St(), constructor);
        Create_alias(_alias_mgr, rwn);
        bool invariant = check_for_invariance(which_kid);
        if(invariant) {
            invariant_prefix.push_back(rwn);
            myve->set_invariant(true);
        } else
            myve->prefix.push_back(rwn);
    }
    myve->cons.push_back(rwn);
}

bool VECTORBUILDER::is_iload_packing (const std::vector<WN*>& myleaves) {
    if (myleaves.size() == 2
            && WN_rtype(myleaves[0]) == MTYPE_F8
            && WN_rtype(myleaves[1]) == MTYPE_F8) {
        if (WN_operator(myleaves[0]) == OPR_ILOAD &&
                WN_operator(myleaves[1]) == OPR_ILOAD) {
            INT Type_Size = MTYPE_byte_size(WN_rtype(myleaves[0]));
            std::pair<arr_elem_dist, INT> outval =
                array_elements_distance(myleaves[0], myleaves[1],
                                        _alias_mgr, Type_Size);
            if (outval.first == SOMEMATCH && outval.second == Type_Size) {
                return true;
            }
        }
    } else if (myleaves.size() == 4) {
        if (WN_rtype(myleaves[0]) == MTYPE_F4 &&
                WN_rtype(myleaves[1]) == MTYPE_F4 &&
                WN_rtype(myleaves[2]) == MTYPE_F4 &&
                WN_rtype(myleaves[3]) == MTYPE_F4) {
            if (WN_operator(myleaves[0]) == OPR_ILOAD &&
                    WN_operator(myleaves[1]) == OPR_ILOAD &&
                    WN_operator(myleaves[2]) == OPR_ILOAD &&
                    WN_operator(myleaves[3]) == OPR_ILOAD) {
                INT Type_Size = MTYPE_byte_size(WN_rtype(myleaves[0]));
                std::pair<arr_elem_dist, INT> outval1 =
                    array_elements_distance(myleaves[0], myleaves[1],
                                            _alias_mgr, Type_Size);
                std::pair<arr_elem_dist, INT> outval2 =
                    array_elements_distance(myleaves[1], myleaves[2],
                                            _alias_mgr, Type_Size);
                std::pair<arr_elem_dist, INT> outval3 =
                    array_elements_distance(myleaves[2], myleaves[3],
                                            _alias_mgr, Type_Size);
                if (outval1.first == SOMEMATCH && outval2.first == SOMEMATCH &&
                        outval3.first == SOMEMATCH) {
                    if (outval1.second == Type_Size &&
                            outval2.second == Type_Size &&
                            outval3.second == Type_Size) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool VECTORBUILDER::is_constant_packing (const std::vector<WN*>& myleaves) {
    for (int il = 0; il < myleaves.size(); ++il) {
        if (WN_operator(myleaves[il]) != OPR_CONST) return false;
    }
    return true;
}

bool VECTORBUILDER::is_replicate_packing (const std::vector<WN*>& myleaves) {
    if (myleaves.size () == 2) {
        if (Aliased(_alias_mgr, myleaves[0],
                    myleaves[1], TRUE) ==
                SAME_LOCATION) {
            return true;
        }
    } else if (myleaves.size () == 3) {
        if (Aliased(_alias_mgr, myleaves[0],
                    myleaves[1], TRUE) ==
                SAME_LOCATION) {
            if (Aliased(_alias_mgr, myleaves[1],
                        myleaves[2], TRUE) ==
                    SAME_LOCATION) {
                return true;
            }
        }
    } else if (myleaves.size () == 4) {
        if (Aliased(_alias_mgr, myleaves[0],
                    myleaves[1], TRUE) ==
                SAME_LOCATION) {
            if (Aliased(_alias_mgr, myleaves[1],
                        myleaves[2], TRUE) ==
                    SAME_LOCATION) {
                if (Aliased(_alias_mgr, myleaves[2],
                            myleaves[3], TRUE) ==
                        SAME_LOCATION) {
                    return true;
                }
            }
        }
    }
    return false;
}

VECTORTY* VECTORBUILDER::check_existing_vectors_for_packing (
    VECTORTY* vect, const std::vector<WN*>& check_these) {
    for (int li = 0; li < check_these.size(); ++li) {
        if (!(WN_operator(check_these[li]) == OPR_LDID)) {
            return NULL;
        }
    }

    for (std::vector<VECTORTY*>::const_iterator ex_vit = existing_vect.begin();
            ex_vit != existing_vect.end(); ++ex_vit) {
        VECTORTY* cons_ex_vit  = *ex_vit;
        if (cons_ex_vit->is_valid() && cons_ex_vit != vect &&
                cons_ex_vit->are_loads_of_vectys_elems (check_these)) {
            return cons_ex_vit;
        }
    }
    return NULL;
}

void VECTORBUILDER::build_by_leaftype (VECTORTY* myve) {
    const std::vector<WN*>& myvecs =  myve->myvecs;
    std::vector<std::vector<WN*> > leaves;
    get_leaves(leaves, myvecs);
    std::vector<WN*> stores;
    get_stores(stores, myvecs);
    const std::vector<std::vector<WN*> >& myleaves = leaves;
    const std::vector<WN*>& mystores = stores;

    for (int inli = 0; inli < myleaves[0].size(); ++inli) {
        std::vector<WN*> myleav;
        for (int vecfi = 0; vecfi < myve->get_myvecs().size(); ++vecfi)
            myleav.push_back(myleaves[vecfi][inli]);

        if (check_if_reduction (mystores, myleav) == false) {
            VECTORTY* exists_pck_elem =
                check_existing_vectors_for_packing (myve, myleav);
            if (exists_pck_elem == NULL) {
                if (is_constant_packing (myleav) == false) {
                    if (is_replicate_packing (myleav) == false) {
                        if (is_iload_packing (myleav) == false) {
                            build_constructor (myve, myleav);
                        } else { /*create a iload packing here */
                            build_iloads (myve, myleav);
                        }
                    } else { /* create a replicate packing here */
                        build_replicate (myve, myleav);
                    }
                } else { /* create_a_constant packing*/
                    build_constant (myve, myleav);
                }
            } else { /* use exiting packing */
                WN* ofvect = exists_pck_elem->LDID_of_vect();
                myve->cons.push_back(ofvect);
            }
        } else { /* reduction constructor */
            build_constructor_reduction (myve, myleav);
        }
    }
}

void VECTORBUILDER::update_existing_vectors (VECTORTY* myvec) {
    std::vector<WN*> stores;
    get_stores(stores, myvec->myvecs);
    for (std::vector<VECTORTY*>::iterator evit = existing_vect.begin();
            evit != existing_vect.end(); ++evit) {
        VECTORTY* myeiv = *evit;
        if (myvec != myeiv) {
            const std::vector<WN*>& evstores = myeiv->get_myvecs();
            for (int cou_i = 0; cou_i < stores.size(); ++cou_i) {
                for (int cou = 0; cou < evstores.size(); ++cou) {
                    if (!(Aliased(_alias_mgr, stores[cou_i], evstores[cou], TRUE)
                            == NOT_ALIASED)) {
                        myeiv->mark_invalid();
                    }
                }
            }
        }
    }
}

void VECTORBUILDER::update_existing_vectors (WN* mywn) {
    if(WN_operator(mywn) != OPR_STID)
        return;
    for (std::vector<VECTORTY*>::iterator evit = existing_vect.begin();
            evit != existing_vect.end(); ++evit) {
        VECTORTY* myeiv = *evit;
        const std::vector<WN*>& evstores = myeiv->get_myvecs();
        for (int cou = 0; cou < evstores.size(); ++cou) {
            if (!(Aliased(_alias_mgr, mywn, evstores[cou], TRUE)
                    == NOT_ALIASED)) {
                myeiv->mark_invalid();
            }
        }
    }
}

void VECTORBUILDER::buildvect_for_stmt (VECTORTY* myvec, WN* myroot) {
    build_by_leaftype (myvec);
    int num_nodes_ori = 0;
    num_nodes(myvec->myvecs[0], num_nodes_ori);
    myvec->convert_to_simd ();

    int num_nodes_vec = 0;
    num_nodes_v1 (myvec->vect, num_nodes_vec);
    for (int ci = 0; ci < myvec->cons.size(); ++ci) {
        num_nodes (myvec->cons[ci], num_nodes_vec);
    }

    myvec->store_packing = is_istore_packing (myvec->myvecs);
    if (myvec->store_packing == false && myvec->is_a_reduc == false) {
        num_nodes_vec += ((int)(myvec->myvecs.size()))-1;
    }
    trace_it = false;
    if (trace_it) {
        printf ("WN:0x%x costs: num_nodes_ori = %d num_nodes_vec = %d %s\n",
                myvec->myvecs[0], num_nodes_ori* ((int)(myvec->myvecs.size())),
                num_nodes_vec,
                (num_nodes_vec <= num_nodes_ori*((int)(myvec->myvecs.size())))?
                "not_skipped" : "skipped");
    }
    trace_it = false;

    if ((costs_skip.find(myvec->myvecs[0]) != costs_skip.end()) ||
            (num_nodes_vec <=
             num_nodes_ori*((int)(myvec->myvecs.size())))) {
        for (std::vector<WN*>::const_iterator outi = myvec->prefix.begin();
                outi != myvec->prefix.end(); ++outi) {
            LWN_Insert_Block_Before (current_block, myroot, *outi);
        }
        LWN_Insert_Block_Before (current_block, myroot, myvec->vect);
        myvec->create_shifts ();

        if (myvec->shuffles.size()  == 1) {
            // This is for store_packing
            WN* extr = LWN_Extract_From_Block(myvec->myvecs[0]);
            LWN_Insert_Block_After (current_block, myvec->vect, extr);
            LWN_Set_Parent(extr, current_block);
            for (int myi = 1; myi< myvec->myvecs.size(); ++myi) {
                std::set<WN*> leaves;
                get_ldids(myvec->myvecs[myi], leaves);
                for (std::set<WN*>::iterator cli = leaves.begin();
                        cli != leaves.end(); ++cli)
                    LWN_Delete_DU (*cli);
                WN* iter = LWN_Extract_From_Block(myvec->myvecs[myi]);
            }
        } else  {
            for (int pari = 0; pari < myvec->shuffles.size(); ++pari) {
                if (myvec->is_a_reduc) {
                    FmtAssert((WN_operator(myvec->myvecs[0]) == OPR_STID),
                              ("shuffle not a STID\n"));
                    reduction_suffix.push_back(myvec->myvecs[pari]);
                } else {
                    WN* extr = LWN_Extract_From_Block(myvec->myvecs[pari]);
                    LWN_Insert_Block_After (current_block, myvec->vect, extr);
                    LWN_Set_Parent(extr, current_block);
                }
            }
        }

        for (int myvi = 0; myvi < myvec->myvecs.size(); ++myvi) {
            LWN_Update_Dg_Delete_Tree(WN_kid0(myvec->myvecs[myvi]),
                                      Array_Dependence_Graph);
            LWN_Delete_CG_dep_graph(WN_kid0(myvec->myvecs[myvi]));
        }
        update_existing_vectors (myvec);
    } else {
        std::set<WN*> cldids;
        get_ldids (myvec->vect, cldids);
        for (std::set<WN*>::iterator cli = cldids.begin();
                cli != cldids.end(); ++cli) {
            LWN_Delete_DU (*cli);
        }

        LWN_Update_Dg_Delete_Tree(myvec->vect, Array_Dependence_Graph);
        LWN_Delete_CG_dep_graph(myvec->vect);
        for (int bac = 0; bac < myvec->cons.size(); ++bac) {
            std::set<WN*> constrle;
            get_ldids (myvec->cons[bac], constrle);
            for (std::set<WN*>::iterator sli = constrle.begin();
                    sli != constrle.end(); ++sli) {
                LWN_Delete_DU (*sli);
            }
            LWN_Update_Dg_Delete_Tree(myvec->cons[bac],
                                      Array_Dependence_Graph);
            LWN_Delete_CG_dep_graph(myvec->cons[bac]);
            dontdo.insert(myvec->cons[bac]);
        }
        myvec->mark_invalid();
        existing_vect.pop_back();
    }
}

void PARTIAL_SIMD_ESTIMATOR::compute_packing_cost (WN* in_tree, int& inpcost) {
    if (WN_operator(in_tree) == OPR_LDID ||
            WN_operator (in_tree) == OPR_ILOAD ||
            WN_operator (in_tree) == OPR_CONST ||
            WN_operator (in_tree) == OPR_INTCONST) {
        inpcost++;
        return;
    } else {
        for (int i = 0; i < WN_kid_count(in_tree); ++i) {
            compute_packing_cost(WN_kid(in_tree,i), inpcost);
        }
        return;
    }
}

void PARTIAL_SIMD_ESTIMATOR::fixin_reductions(VECTORBUILDER& vecbuil) {
    for (int rei = 0; rei < vecbuil.reduction_prefix.size(); ++rei) {
        if (vecbuil.dontdo.find(vecbuil.reduction_prefix[rei]) == vecbuil.dontdo.end()) {
            LWN_Insert_Block_Before (LWN_Get_Parent(LWN_Get_Parent(current_block)),
                                     LWN_Get_Parent(current_block), vecbuil.reduction_prefix[rei]);
        }
    }
    std::vector<WN*>& myshufs =  vecbuil.reduction_suffix;
    for (int shi = myshufs.size()-1; shi >= 0; shi--) {
        WN* myshu_bit = myshufs[shi];
        WN* extr = LWN_Extract_From_Block(myshu_bit);
        LWN_Insert_Block_After (LWN_Get_Parent(LWN_Get_Parent(current_block)),
                                LWN_Get_Parent(current_block), extr);
    }
}

void PARTIAL_SIMD_ESTIMATOR::fixin_constants(VECTORBUILDER& vecbuil) {
    std::vector<WN*>& consts = vecbuil.constant_prefix;
    for (int consi = 0; consi < consts.size(); ++consi) {
        if (vecbuil.dontdo.find(consts[consi]) == vecbuil.dontdo.end()) {
            LWN_Insert_Block_Before (LWN_Get_Parent(LWN_Get_Parent(current_block)),
                                     LWN_Get_Parent(current_block), consts[consi]);
        }
    }
}

void PARTIAL_SIMD_ESTIMATOR::fixin_invariants(VECTORBUILDER& vecbuil) {
    std::vector<WN*>& consts = vecbuil.invariant_prefix;
    for (int consi = 0; consi < consts.size(); ++consi) {
        if (vecbuil.dontdo.find(consts[consi]) == vecbuil.dontdo.end()) {
            LWN_Insert_Block_Before (LWN_Get_Parent(LWN_Get_Parent(current_block)),
                                     LWN_Get_Parent(current_block), consts[consi]);
        }
    }
}

void PARTIAL_SIMD_ESTIMATOR::add_partial_vectors_to_block () {
    topological_reordering_of_block();
    generate_constructors_and_patch_block (layout_order);
}

void PARTIAL_SIMD_ESTIMATOR::estimate_per_stmt(WN* beg) {
    Depth (beg);
    GraphOfBlock (beg);
    AddToStmtVect (beg);
}

void PARTIAL_SIMD_ESTIMATOR::finalize_it () {
    if (StmtSet.size() > 0) {
        if(find_partial_vectors_in_block())
            add_partial_vectors_to_block();
    }
}

void PARTIAL_SIMD_ESTIMATOR::GraphOfBlock (WN* in_tree) {
    if (WN_operator(in_tree) == OPR_STID ||
            WN_operator(in_tree) == OPR_PREFETCH ||
            WN_operator(in_tree) == OPR_FALSEBR ||
            WN_operator(in_tree) == OPR_TRUEBR ||
            WN_operator(in_tree) == OPR_ISTORE) {
        if (WN_operator(in_tree) == OPR_STID) {
            std::vector<WN*>::const_iterator istid = graph_stids.begin();
            for (; istid != graph_stids.end(); ++istid) {
                if (Aliased (_alias_mgr, *istid, in_tree, TRUE)
                        != NOT_ALIASED) {
                    if (in_tree != *istid) {
                        node_adj[in_tree].insert(StmtNumWn[*istid]);
                        output_dep[in_tree].insert(StmtNumWn[*istid]);
                    }
                }
            }
            {
                std::vector<WN*>::const_iterator ildid = StmtVector.begin();
                for (; ildid != StmtVector.end(); ++ildid) {
                    // StmtVector only contains up to the last in_tree not htis one
                    {
                        std::set<WN*> leaves;
                        get_ldids(*ildid,leaves);
                        for (std::set<WN*>::iterator leaves_it = leaves.begin();
                                leaves_it != leaves.end(); ++leaves_it) {
                            if (Aliased(_alias_mgr, *leaves_it, in_tree, TRUE)
                                    != NOT_ALIASED) {
                                anti_dep[in_tree].insert(StmtNumWn[*ildid]);
                                node_adj[in_tree].insert(StmtNumWn[*ildid]);
                            }
                        }
                    }
                }
            }
        }
        {
            std::set<WN*> leaves;
            get_ldids(in_tree,leaves);
            for (std::set<WN*>::iterator leaves_it = leaves.begin();
                    leaves_it != leaves.end(); ++leaves_it) {
                for (std::vector<WN*>::const_iterator istid = graph_stids.begin();
                        istid != graph_stids.end(); ++istid) {
                    if (Aliased (_alias_mgr, *istid, *leaves_it, TRUE)
                            != NOT_ALIASED) {
                        node_adj[in_tree].insert(StmtNumWn[*istid]);
                        true_adj[in_tree].insert(StmtNumWn[*istid]);
                    }
                }
            }
        }
        if (WN_operator(in_tree) == OPR_STID)
            graph_stids.push_back(in_tree);
    }
}

int PARTIAL_SIMD_ESTIMATOR::Depth (WN* in_tree) {
    if (WN_operator (in_tree) == OPR_LDID) {
        int loc_cyc = 0;
        std::vector<WN*>::const_iterator istid = depth_stid.begin();
        for (; istid != depth_stid.end(); ++istid) {
            if (Aliased (_alias_mgr, *istid,in_tree,TRUE) != NOT_ALIASED) {
                loc_cyc = std::max(loc_cyc, DepthWN[*istid]);
            }
        }
        istid = depth_istore.begin();
        for (; istid != depth_istore.end(); ++istid) {
            if (Aliased (_alias_mgr, *istid,in_tree,TRUE) != NOT_ALIASED) {
                loc_cyc = std::max(loc_cyc, DepthWN[*istid]);
            }
        }
        DepthWN[in_tree] = loc_cyc;
        lastnum = std::max(lastnum, loc_cyc);
        WNByDepth[loc_cyc].push_back(in_tree);
        std::stringstream mysrm;
        tree_pattern (in_tree, mysrm);
        WNTreeSig[in_tree] = mysrm.str();
        WNByDepthAndSig[loc_cyc][mysrm.str()].push_back(in_tree);
        return loc_cyc;
    } else if (WN_operator(in_tree) == OPR_ILOAD) {
        int loc_cyc = 0;
        depth_iload.push_back(in_tree);
        std::vector<WN*>::const_iterator ist = depth_istore.begin();
        for (; ist != depth_istore.end(); ++ist) {
            if (Aliased (_alias_mgr, *ist, in_tree, TRUE) != NOT_ALIASED) {
                loc_cyc = std::max(loc_cyc, DepthWN[*ist]);
            }
        }
        if (!Alias_Pointer_Disjoint) {
            for (int myki = 0; myki < WN_kid_count(in_tree); myki++) {
                loc_cyc = std::max (loc_cyc, Depth(WN_kid(in_tree, myki)));
            }
        }
        DepthWN[in_tree] = loc_cyc;
        lastnum = std::max(lastnum, loc_cyc);
        WNByDepth[loc_cyc].push_back(in_tree);
        std::stringstream mysrm;
        tree_pattern (in_tree, mysrm);
        WNTreeSig[in_tree] = mysrm.str();
        WNByDepthAndSig[loc_cyc][mysrm.str()].push_back(in_tree);
        return loc_cyc;
    } else {
        int loc_cyc = 0;
        if (WN_operator(in_tree) == OPR_ISTORE) {
            std::vector<WN*>::const_iterator ist = depth_istore.begin();
            for (; ist != depth_istore.end(); ++ist) {
                if (Aliased (_alias_mgr, *ist, in_tree, TRUE) != NOT_ALIASED) {
                    loc_cyc = std::max(loc_cyc, DepthWN[*ist]);
                }
            }
            std::vector<WN*>::const_iterator ild = depth_iload.begin();
            for (; ild != depth_iload.end(); ++ild) {
                if (Aliased (_alias_mgr, *ild, in_tree, TRUE) != NOT_ALIASED) {
                    loc_cyc = std::max(loc_cyc, DepthWN[*ild]);
                }
            }
        } else if (WN_operator(in_tree) == OPR_STID) {
            std::vector<WN*>::const_iterator istid = depth_stid.begin();
            for (; istid != depth_stid.end(); ++istid) {
                if (Aliased (_alias_mgr, *istid,in_tree,TRUE) != NOT_ALIASED) {
                    loc_cyc = std::max(loc_cyc, DepthWN[*istid]);
                }
            }
            {
                std::vector<WN*>::const_iterator ildid = StmtVector.begin();
                for (; ildid != StmtVector.end(); ++ildid) {
                    if (WN_operator(*ildid) == OPR_STID ||
                            WN_operator(*ildid) == OPR_ISTORE) {
                        std::set<WN*> leaves;
                        get_ldids(*ildid,leaves);
                        for (std::set<WN*>::iterator leaves_it = leaves.begin();
                                leaves_it != leaves.end(); ++leaves_it) {
                            if (Aliased(_alias_mgr, *leaves_it, in_tree, TRUE)
                                    != NOT_ALIASED) {
                                loc_cyc = std::max(loc_cyc, DepthWN[*ildid]);
                            }
                        }
                    }
                }
            }
        }

        if (WN_operator(in_tree) != OPR_ISTORE) {
            for (int kidc = 0; kidc != WN_kid_count(in_tree); ++kidc) {
                loc_cyc = std::max (loc_cyc, Depth(WN_kid(in_tree,kidc)));
            }
        } else {
            if (Alias_Pointer_Disjoint) {
                loc_cyc = std::max (loc_cyc, Depth(WN_kid0(in_tree)));
            } else {
                for (int myki = 0; myki < WN_kid_count(in_tree); myki++) {
                    loc_cyc = std::max (loc_cyc, Depth(WN_kid(in_tree, myki)));
                }
            }
        }

        loc_cyc++;

        if (WN_operator(in_tree) == OPR_RETURN) {
            loc_cyc = INT_MAX;
        }

        DepthWN[in_tree] = loc_cyc;
        if (!(WN_operator(in_tree) == OPR_RETURN)) {
            lastnum = std::max(lastnum, loc_cyc);
            WNByDepth[loc_cyc].push_back(in_tree);
        }
        std::stringstream mysrm;
        tree_pattern (in_tree, mysrm);
        WNTreeSig[in_tree] = mysrm.str();

        WNByDepthAndSig[loc_cyc][mysrm.str()].push_back(in_tree);
        if (WN_operator(in_tree) == OPR_STID)
            depth_stid.push_back(in_tree);
        if (WN_operator(in_tree) == OPR_ISTORE)
            depth_istore.push_back(in_tree);
        return loc_cyc;
    }
}

void PARTIAL_SIMD_ESTIMATOR::dfs_topo_sort (WN* myvi, std::set<WN*>& visited, std::vector<WN*>& blk) {
    visited.insert(myvi);
    if (VectorXMap.find(myvi) != VectorXMap.end()) { //<a,b>, visiting a
        std::vector<int> all_adj;
        std::vector<WN*>& myvecs = VectorXMap[myvi]; // <a,b>
        // for element in myvecs
        for (std::vector<WN*>::iterator myvit = myvecs.begin();
                myvit != myvecs.end(); ++myvit) {
            //get adj list
            if (node_adj.find(*myvit) != node_adj.end()) {
                //add adj list to new vector
                for(std::set<int>::iterator node_adj_it = node_adj[*myvit].begin();
                        node_adj_it != node_adj[*myvit].end(); ++node_adj_it) {
                    all_adj.push_back(*node_adj_it);
                }
            }
        }
        // all_adj = <all inputs of a,b>
        for (std::vector<int>::iterator alladj_it = all_adj.begin();
                alladj_it != all_adj.end(); ++alladj_it) {
            if (visited.find(StmtWnNum[*alladj_it]) == visited.end()) {
                dfs_topo_sort (StmtWnNum[*alladj_it], visited, blk);
            }
        }
    } else {
        for (std::set<int>::iterator nodeadj_it = node_adj[myvi].begin();
                nodeadj_it != node_adj[myvi].end(); ++nodeadj_it) {
            if (visited.find(StmtWnNum[*nodeadj_it]) == visited.end()) {
                dfs_topo_sort (StmtWnNum[*nodeadj_it], visited, blk);
            }
        }
    }

    if (StmtSet.find(myvi) != StmtSet.end()) {
        blk.push_back(myvi);
    } else {
        FmtAssert ((FALSE), ("got interior nodes"));
    }
}

void PARTIAL_SIMD_ESTIMATOR::topological_reordering_of_block () {
    if (StmtVector.size() > 0) {
        std::set<WN*> visited;
        std::vector<WN*> blk;
        for (std::vector<WN*>::iterator wnit =
                    StmtVector.begin(); wnit != StmtVector.end();
                ++wnit) {
            WN* wn_temp = *wnit;
            if (visited.find(wn_temp) == visited.end())
                dfs_topo_sort (wn_temp,visited,layout_order);
        }
        FmtAssert ((layout_order.size() == StmtVector.size()),
                   ("sizes are not the same after topological reorder layoutsize:%d stmtsize:%d\n",
                    layout_order.size(), StmtVector.size()));
        WN_first(current_block) = layout_order[0];
        WN_last(current_block) = layout_order[layout_order.size()-1];
        for (int lyit = 0; lyit < layout_order.size(); ++lyit) {
            WN_prev(layout_order[lyit]) = NULL;
            WN_next(layout_order[lyit]) = lastnode_processed;
            if (lyit > 0) {
                WN_prev(layout_order[lyit]) = layout_order[lyit-1];
                WN_next(layout_order[lyit-1]) = layout_order[lyit];
            }
        }
        LWN_Parentize(current_block);
    }
}

void PARTIAL_SIMD_ESTIMATOR::generate_constructors_and_patch_block (std::vector<WN*>& layout_order) {
    if (layout_order.size() == 0) return;
    else {
        // we have a VECTORBUILDER... which helps in the code generation
        VECTORBUILDER vecbuil(_alias_mgr, StmtSet, costs_skip, current_block);
        std::set<WN*> visited;
        for(std::vector<WN*>::iterator myvec_it = layout_order.begin();
                myvec_it != layout_order.end(); ++myvec_it) {
            if (visited.find(*myvec_it) == visited.end()) {
                visited.insert(*myvec_it);
                if (VectorXMap.find(*myvec_it) != VectorXMap.end()) {
                    std::vector<WN*>& myvecs = VectorXMap[*myvec_it];
                    for (std::vector<WN*>::const_iterator myvect_it = myvecs.begin();
                            myvect_it != myvecs.end(); ++myvect_it) {
                        visited.insert(*myvect_it);
                    }
                    {
                        if (myvecs.size() > 1) {
                            std::vector<WN*> outord;
                            WN* first_one = myvecs[0];
                            TYPE_ID myty = (WN_operator(first_one) == OPR_STID ||
                                            WN_operator(first_one) == OPR_ISTORE)?
                                           WN_desc(first_one) : WN_rtype(first_one);
                            TYPE_ID dtyp; /* the vector data type */
                            if (MTYPE_is_float(myty) && MTYPE_bit_size(myty) == 64) {
                                dtyp = MTYPE_V16F8;
                            } else if (MTYPE_is_float(myty) && MTYPE_bit_size(myty) == 32) {
                                dtyp = MTYPE_V16F4;
                            } else return;

                            // create a VECTORTY for each vector
                            VECTORTY* myvec = new VECTORTY(dtyp, myty, myvecs, outord, _alias_mgr);
                            myvec->mark_valid();
                            // add this to VECTORBUILDER
                            vecbuil.existing_vect.push_back (myvec);
                            // this does the backoffice work for  vectorization i.e
                            // constructing vector arguments... among other things
                            vecbuil.buildvect_for_stmt (myvec,*myvec_it);
                        } else {
                            vecbuil.update_existing_vectors (*myvec_it);
                        }
                    }
                } else {
                    vecbuil.update_existing_vectors (*myvec_it);
                }
            }
        }

        fixin_invariants(vecbuil);
        fixin_constants(vecbuil);
        fixin_reductions(vecbuil);
    }
}

bool PARTIAL_SIMD_ESTIMATOR::find_partial_vectors_in_block () {
    // look at the depth table from bottom to top and
    // vectorize the ones are that same at the same depth
    std::set<WN*> visited;
    int across_iters=0;
    num_vector_nodes=0;
    // lastnum is the deepest row in the depth table...
    for (int depth_i = lastnum; depth_i >= 0; depth_i--) {
        if (WNByDepth.find(depth_i) != WNByDepth.end()) {
            std::map<std::string, std::list<WN*> > &mydepth_sig = WNByDepthAndSig[depth_i];
            for (std::map<std::string,std::list<WN*> >::iterator mylit = mydepth_sig.begin();
                    mylit != mydepth_sig.end();
                    ++mylit) {
                for (std::map<std::string,std::list<WN*> >::iterator
                        mylit = mydepth_sig.begin();
                        mylit != mydepth_sig.end();
                        ++mylit) {
                    // for each signature at this depth... nodes that share the same dept and have
                    // the same signature are vectorization candidates
                    if (mylit->second.size() > 1) {
                        // there has to be at least 2 at the same depth with the same signature
                        std::vector<WN*>pruned_vec;
                        std::ostringstream pruned_put;
                        for (std::list<WN*>::iterator
                                myliti = mylit->second.begin();
                                myliti != mylit->second.end(); ++myliti) {
                            TYPE_ID myty = (WN_operator(*myliti) == OPR_STID ||
                                            WN_operator(*myliti) == OPR_ISTORE)?
                                           WN_desc(*myliti) : WN_rtype(*myliti);
                            if (MTYPE_is_float(myty) && !MTYPE_is_vector(myty)) {
                                //make sure that this node has not been visited before
                                if (visited.find(*myliti) == visited.end()) {
                                    mark_visited (*myliti, visited);
                                    if (((WN_operator(*myliti) == OPR_STID )
                                            || (WN_operator(*myliti) == OPR_ISTORE))
                                            && sanitize_opcodes(*myliti)) {
                                        // only pick LDID/STIDs containing interior nodes that we can
                                        // vectorize
                                        pruned_vec.push_back(*myliti);
                                    } else {
                                        if ((WN_operator(*myliti) == OPR_STID )
                                                || (WN_operator(*myliti) == OPR_ISTORE)) {
                                            if (are_we_tracing())
                                                fprintf (TFile,"not for: %s\n",
                                                         mylit->first.c_str());
                                        }
                                    }
                                }
                            }
                        }
                        if (pruned_vec.size() > 1) {
                            {
                                // ok, we got more than one expr that can be vectorized
                                // now we will like to shuffle them based on their
                                // iteration number first... suppose we unrolled twice...
                                // before the shuffing we may have 0,0,...,1,1...
                                // after the shuffling, we will have 0,1,0,1...
                                // this enables us to make vectors with nodes from adjacent
                                // iterations...
                                // in the event that there are nodes from only one iteration
                                // we still try to vectorize...
                                std::vector<WN*> reordered_vect;
                                std::vector<std::vector<WN*> > unfo;
                                int numel = 0;
                                if (are_we_tracing()) {
                                    printf ("depth:%d unroll factor = %d\n", depth_i, unroll_walker.unroll_factor);
                                    for (int unr = 0; unr < pruned_vec.size(); ++unr)
                                        std::cout << pruned_vec[unr] <<" ";
                                    std::cout << "\n";
                                }
                                for (int unf = 0; unf < unroll_walker.unroll_factor; unf++) {
                                    std::vector<WN*> unfi;
                                    for (int unr = 0; unr != pruned_vec.size(); ++unr) {
                                        if (unroll_walker.iter_map.find(pruned_vec[unr]) != unroll_walker.iter_map.end()) {
                                            std::pair<int,int> mynum = unroll_walker.iter_map[pruned_vec[unr]];
                                            if (mynum.first == unf) {
                                                unfi.push_back(pruned_vec[unr]);
                                            }
                                        }
                                    }
                                    unfo.push_back(unfi);
                                    if (numel == 0) numel = unfi.size();
                                }
                                std::set<WN*> zero_set;
                                for (int uni = 0; uni < numel; ++uni) {
                                    for (int uno = 0; uno < unfo.size(); uno++) {
                                        if (unfo[uno].size() > uni) {
                                            zero_set.insert(unfo[uno][uni]);
                                            reordered_vect.push_back(unfo[uno][uni]);
                                        }
                                    }
                                }
                                for (int unr = 0; unr != pruned_vec.size(); ++unr) {
                                    if (zero_set.find(pruned_vec[unr]) == zero_set.end()) {
                                        reordered_vect.push_back(pruned_vec[unr]);
                                    }
                                }
                                FmtAssert((reordered_vect.size() == pruned_vec.size()),
                                          ("reordered vect != pruned_vec\n"));
                                pruned_vec = reordered_vect;
                            }
                            for (int unr = 0; unr < pruned_vec.size(); unr++) {
                                pruned_put << std::hex << pruned_vec[unr] << " ";
                                if (unroll_walker.iter_map.find (pruned_vec[unr]) != unroll_walker.iter_map.end()) {
                                    const std::pair<int,int>& iterinfo = unroll_walker.iter_map[pruned_vec[unr]];
                                    pruned_put << std::dec << "(" << iterinfo.first << "," << iterinfo.second << ") ";
                                }
                            }
                            if (pruned_vec.size() > 1) {
                                std::vector<WN*> out_vect;
                                WN* first_one = *(pruned_vec.begin());
                                int pckcost = 0;
                                compute_packing_cost (first_one, pckcost);
                                int numnode = 0;
                                // num_nodes get a count of the number of
                                // nodes in the selected vectorization candidates...
                                // we need to have at least one useful node... look at num_ndes function...
                                num_nodes (first_one, numnode);
                                int vect_factor = 0;
                                TYPE_ID myty = (WN_operator(first_one) == OPR_STID ||
                                                WN_operator(first_one) == OPR_ISTORE)?
                                               WN_desc(first_one) : WN_rtype(first_one);
                                // For SSE2/AVX128
                                // in case it is a double precision we use a vector of size 2
                                // in case it is a single precision we use a vector of size 4
                                if (MTYPE_bit_size(myty) == 64)
                                    vect_factor = std::min(2,(int)pruned_vec.size());
                                else
                                    vect_factor = std::min(4,(int)pruned_vec.size());

                                for (int mygi = 0; mygi < (int)pruned_vec.size();
                                        mygi+=vect_factor) {
                                    // now we split out the pruned vectors to bite sized parts
                                    // and each part is going to be vectorized
                                    std::vector<WN*> myvecs;
                                    for (int mygij = mygi;
                                            (mygij < mygi + vect_factor) &&
                                            (mygij < (int)pruned_vec.size());
                                            mygij++) {
                                        myvecs.push_back(pruned_vec[mygij]);
                                    }
                                    if (numnode > 0) {
                                        {
                                            if (myvecs.size() == 2) {
                                                // try to swap vector contents to align loads to enable
                                                // a wide iload... if the vectors are not aligned we may have
                                                // two iloads *(a+1), *a instead of *a, *(a+1). In the
                                                // second case we can issue a wide load, like movapd/movupd
                                                // in one shot. In the first case we can get two movsd.
                                                // we have a support for vector of size 2 by swapping...
                                                // for float vectors instead of swapping we need to sort the
                                                // list(TBD).
                                                std::vector<std::vector<WN*> > out_leaves;
                                                std::vector<WN*> leaves1, leaves2;
                                                get_leaves ( myvecs[0], leaves1);
                                                out_leaves.push_back(leaves1);
                                                get_leaves ( myvecs[1], leaves2);
                                                out_leaves.push_back(leaves2);
                                                int sizeofleaves = out_leaves[0].size();
                                                bool neswap = false;
                                                for (int inli = 0; inli < sizeofleaves; ++inli) {
                                                    if (WN_operator(out_leaves[0][inli]) == OPR_ILOAD &&
                                                            WN_operator(out_leaves[1][inli]) == OPR_ILOAD &&
                                                            WN_opcode(out_leaves[0][inli]) == WN_opcode(out_leaves[1][inli])) {
                                                        INT Type_Size = MTYPE_byte_size(WN_rtype(out_leaves[0][inli]));
                                                        neswap = needs_swap (out_leaves[0][inli],
                                                                             out_leaves[1][inli], _alias_mgr, Type_Size);
                                                        break;
                                                    }
                                                }
                                                if (neswap) {
                                                    WN* swa = myvecs[1];
                                                    myvecs[1] = myvecs[0];
                                                    myvecs[0] = swa;
                                                }
                                            }
                                            bool doit = false;
                                            if (LNO_Run_Psimd_Iso_Unroll) {
                                                doit = true;
                                                for (int myi = 0; myi < myvecs.size(); ++myi) {
                                                    if (unroll_walker.iter_map.find(myvecs[myi]) != unroll_walker.iter_map.end()) {
                                                        if (unroll_walker.iter_map[myvecs[myi]].first != myi) doit = false;
                                                    } else doit = false;
                                                }
                                            }
                                            if (LNO_Run_Psimd_Iso_Unroll) {
                                                if (unroll_walker.iter_map.find (myvecs[0]) != unroll_walker.iter_map.end() &&
                                                        unroll_walker.iter_map.find (myvecs[1]) != unroll_walker.iter_map.end()) {
                                                    if (unroll_walker.iter_map[myvecs[0]].first != unroll_walker.iter_map[myvecs[1]].first)
                                                        across_iters+=myvecs.size();
                                                }
                                            }
                                            num_vector_nodes+=myvecs.size();
                                            {
                                                pruned_put << "\n" << (doit ? "adj-iter: " : "same-iter: ");
                                                for (int myi = 0; myi < myvecs.size(); ++myi) {
                                                    if (unroll_walker.iter_map.find(myvecs[myi]) != unroll_walker.iter_map.end()) {
                                                        pruned_put <<  "(" << unroll_walker.iter_map[myvecs[myi]].first << "," <<
                                                                   unroll_walker.iter_map[myvecs[myi]].second << ")";
                                                    }
                                                }
                                                if (pruned_put.str().size() > 0) {
                                                    if (are_we_tracing())
                                                        fprintf (TFile, "%s\n", pruned_put.str().c_str());
                                                }
                                                for (int mygij = mygi;
                                                        (mygij < mygi + vect_factor) &&
                                                        (mygij < (int)pruned_vec.size());
                                                        mygij++) {
                                                    if (doit) costs_skip.insert(pruned_vec[mygij]);
                                                    VectorXMap[pruned_vec[mygij]] = myvecs;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (LNO_Run_Psimd_Iso_Unroll) {
        int block_size=  get_block_size(WN_do_body(current_loop));
        if(((float)(num_vector_nodes)/(float)block_size < vector_to_block_ratio)) {
            //reroll
            // we see that most of the vector candidates are not from
            // adjacent iterations... or the vectorization is too low
            // in these cases we dont want to unroll.
            if(unroll_walker.my_unroll.find(current_loop) != unroll_walker.my_unroll.end()) {
                const std::pair<WN *,WN *> unroll_info = unroll_walker.my_unroll[current_loop];
                WN *rem_loop = unroll_info.first;
                WN *store_loop = unroll_info.second;
                WN *parent = LWN_Get_Parent(current_loop);
                unroll_walker.deleted_loop.insert(current_loop);
                LWN_Insert_Block_After(parent, WN_prev(current_loop),store_loop);
                Update_Def_List_Loop_Stmt(current_loop, store_loop);
                LWN_Update_Def_Use_Delete_Tree(current_loop);
                LWN_Delete_Tree(current_loop);
                if(rem_loop) {
                    unroll_walker.deleted_loop.insert(rem_loop);
                    Update_Def_List_Loop_Stmt(rem_loop, store_loop);
                    LWN_Update_Def_Use_Delete_Tree(rem_loop);
                    LWN_Delete_Tree(rem_loop);
                }
                LWN_Parentize(parent);
                return false;
            }
        } else {
            if(unroll_walker.my_unroll.find(current_loop) != unroll_walker.my_unroll.end()) {
                const std::pair<WN *,WN *> unroll_info = unroll_walker.my_unroll[current_loop];
                WN *store_loop = unroll_info.second;
                unroll_walker.deleted_loop.insert(store_loop);
                Update_Def_List_Loop_Stmt(store_loop, NULL);
                LWN_Update_Def_Use_Delete_Tree(store_loop);
                LWN_Delete_Tree(store_loop);
            }
        }
    }
    return true;
}

void PARTIAL_SIMD_WALKER::check_statement_naming (WN* beg,
        std::set<WN*>& seen_loads,
        std::vector<WN*>& seen_stids,
        std::set<WN*>& exposed_ldids,
        std::set<WN*>& exposed_stids,
        std::map<WN*, WN*>& valu_num,
        const std::set<WN*>& allinblock) {
    // for this statement, get leaves
    // replace leaves with renamed names
    // make entry to table, valu_num
    // if variable is not stored bfore reading
    // it is upward exposed or live-in...
    // if a variable is stored and is used
    // outside the loop it is exposed too or live-out...
    // insert moves for the copies
    // which are live-out.
    // we do not like to rename reductions... we have
    // other ways of handling them
    LWN_Parentize(beg);
    std::vector<WN*> leaves;
    get_ldids (beg, leaves);

    for (int li = 0; li < leaves.size(); ++li) {
        TY_IDX ldid_type = ST_type (WN_st(leaves[li]));
        TY& ty = Ty_Table[ldid_type];
        DEF_LIST *defli = Du_Mgr->Ud_Get_Def (leaves[li]);
        DEF_LIST_ITER iter(defli);
        for (const DU_NODE *node=iter.First();
                !iter.Is_Empty(); node = iter.Next()) {
            WN *def = (WN *) node->Wn();
            if (valu_num.find(def) == valu_num.end()) {
                if (red_manager && red_manager->Which_Reduction(def) == RED_NONE ) {
                    exposed_ldids.insert(leaves[li]);
                } else if (Aliased(_alias_mgr, beg,
                                   leaves[li], TRUE) != SAME_LOCATION)  {
                    exposed_ldids.insert(leaves[li]);
                }
            }
        }
        seen_loads.insert(leaves[li]);
        SYMBOL leavesi(leaves[li]);
        for (int si = seen_stids.size() -1; si >= 0; --si) {
            SYMBOL stmtsym(seen_stids[si]);
            if (stmtsym == leavesi) {
                if (valu_num[seen_stids[si]] != seen_stids[si]) {
                    // now we have a LDID which has to renamed to
                    // the new name which is in the valu_num map
                    WN* renamed = WN_CreateLdid(OPCODE_make_op(OPR_LDID,
                                                WN_rtype(leaves[li]), WN_desc(leaves[li])),
                                                WN_offset(valu_num[seen_stids[si]]),
                                                WN_st(valu_num[seen_stids[si]]),
                                                WN_ty(leaves[li]), WN_field_id(leaves[li]));

                    FmtAssert ((compare_b4_aft(renamed, leaves[li])),
                               ("type check for renaming fails:1\n"));
                    Copy_alias_info (_alias_mgr,
                                     valu_num[seen_stids[si]], renamed);
                    Du_Mgr->Add_Def_Use (valu_num[seen_stids[si]], renamed);
                    for (int k = 0; k < WN_kid_count(LWN_Get_Parent(leaves[li])); ++k) {
                        if (WN_kid(LWN_Get_Parent(leaves[li]), k) == leaves[li]) {
                            FmtAssert ((compare_b4_aft (WN_kid (LWN_Get_Parent(leaves[li]),
                                                                k), renamed)),
                                       ("type check for renaming fails:2\n"));
                            LWN_Update_Dg_Delete_Tree(WN_kid(LWN_Get_Parent(leaves[li]), k),
                                                      Array_Dependence_Graph);
                            LWN_Delete_CG_dep_graph(WN_kid(LWN_Get_Parent(leaves[li]), k));
                            WN_kid(LWN_Get_Parent(leaves[li]), k) = renamed;
                        }
                    }
                    LWN_Delete_DU(leaves[li]);
                }
                break;
            }
        }
    }

    if (WN_operator(beg) == OPR_STID ) {
        valu_num[beg] = beg;
        seen_stids.push_back(beg);
        {
            TY_IDX stid_type = ST_type (WN_st(beg));
            TY& ty = Ty_Table[stid_type];
            {
                if (red_manager && red_manager->Which_Reduction(beg) == RED_NONE) {
                    WN* foundit = NULL;
                    SYMBOL begsi(beg);
                    for (std::vector<WN*>::iterator svit = seen_stids.begin();
                            svit != seen_stids.end(); ++svit) {
                        SYMBOL svisym (*svit);
                        if (svisym == begsi) {
                            foundit = *svit;
                            break;
                        }
                    }
                    if (foundit == NULL) {
                        // there is no definition for the STID yet
                        WN* foundit2 = NULL;
                        for (std::set<WN*>::iterator lit = seen_loads.begin();
                                lit != seen_loads.end(); ++lit) {
                            SYMBOL lisym (*lit);
                            if (lisym == begsi) {
                                foundit2 = *lit;
                                break;
                            }
                        }
                        if (foundit2 == NULL) {
                            // also there is no use for the STID yet
                            valu_num[beg] = beg;
                        } else {
                            // found an earlier use of the STID... antidep!
                            {
                                std::ostringstream name;
                                name << "AA_";// << ((long)beg);
                                WN* replaced;
                                if (ST_class (WN_st(beg)) == CLASS_PREG) {
                                    SYMBOL preg = Create_Preg_Symbol(name.str().c_str(),WN_desc(beg));
                                    replaced = WN_StidIntoPreg (preg.Type, preg.WN_Offset(),
                                                                preg.St(), WN_kid0(beg));
                                } else {
                                    const char* stnam = ST_name(WN_st(beg));
                                    name << "_" << stnam;
                                    ST* newst = New_ST(CURRENT_SYMTAB);
                                    ST_Init (newst,
                                             Save_Str(name.str().c_str()),
                                             ST_class (WN_st(beg)),
                                             ST_sclass (WN_st(beg)),
                                             ST_export (WN_st(beg)),
                                             ST_type (WN_st(beg)));

                                    replaced = WN_CreateStid(WN_opcode(beg), WN_offset(beg),
                                                             newst, WN_ty(beg),WN_kid0(beg), WN_field_id(beg));
                                }
                                Create_alias(_alias_mgr, replaced);
                                valu_num[beg] = replaced;
                                FmtAssert ((compare_b4_aft(beg, replaced)), ("type check for renaming fails:3"));
                            }
                        }
                    } else {
                        // found an earlier def for the STID, i.e. output dep
                        std::ostringstream name;
                        name << "OO_";// << ((long)beg & 0xFFF);
                        WN* replaced;
                        if (ST_class (WN_st(beg)) == CLASS_PREG) {
                            SYMBOL preg = Create_Preg_Symbol(name.str().c_str(),WN_desc(beg));
                            replaced = WN_StidIntoPreg (preg.Type, preg.WN_Offset(),
                                                        preg.St(), WN_kid0(beg));
                        } else {
                            const char* stnam = ST_name(WN_st(beg));
                            name << "_" << stnam;
                            ST* newst = New_ST(CURRENT_SYMTAB);
                            ST_Init (newst,
                                     Save_Str(name.str().c_str()),
                                     ST_class (WN_st(beg)),
                                     ST_sclass (WN_st(beg)),
                                     ST_export (WN_st(beg)),
                                     ST_type(WN_st(beg)));

                            replaced = WN_CreateStid(WN_opcode(beg), WN_offset(beg),
                                                     newst, WN_ty(beg),WN_kid0(beg), WN_field_id(beg));
                        }

                        Create_alias(_alias_mgr, replaced);
                        valu_num[beg] = replaced;
                        FmtAssert ((compare_b4_aft(beg, replaced)), ("type check for renaming fails:4"));
                    }
                    if (beg != valu_num[beg]) {
                        // in case it is a rename candidate, check if it is an exposed_stid...
                        USE_LIST* useli = Du_Mgr->Du_Get_Use (beg);
                        USE_LIST_ITER iter(useli);
                        for (const DU_NODE *node=iter.First();
                                !iter.Is_Empty(); node = iter.Next()) {
                            WN *use = (WN *) node->Wn();
                            if (allinblock.find(use) == allinblock.end()) {
                                exposed_stids.insert(beg);
                            }
                        }
                    }
                }
            }
        }
    }
}

void PARTIAL_SIMD_WALKER::rename_vars (WN* beg) {
    WN *wn_temp = WN_first(beg);
    wn_temp = WN_first(beg);
    std::set<WN*> allinblock;
    while(wn_temp) {
        // get all the WN* in the block in allinblock set, useful to proce
        // membership in the do loop
        collect_wns(wn_temp, allinblock);
        wn_temp = WN_next(wn_temp);
    }
    std::map<WN*, WN*> valu_num;
    std::set<WN*> exposed_stids;
    std::set<WN*> exposed_ldids;
    std::set<WN*> seen_loads;
    std::vector<WN*> seen_stids;
    wn_temp = WN_first(beg);
    while(wn_temp) {
        // go over each stmt in the body and check if its name was
        // used before... if so choose a new name, build a new statment
        // and bind it with the original stmt in valu_num map. Rename is
        // only done for STIDs/LDIDs
        check_statement_naming (wn_temp, seen_loads, seen_stids, exposed_ldids,
                                exposed_stids, valu_num, allinblock);
        if (WN_operator (wn_temp) == OPR_STID) {
            if (wn_temp != valu_num[wn_temp]) {
                // if there was a renaming, replace the original
                // stid with the new one
                LWN_Insert_Block_Before (beg, wn_temp, valu_num[wn_temp]);
                LWN_Update_Dg_Delete_Tree(wn_temp,Array_Dependence_Graph);
                LWN_Delete_CG_dep_graph(wn_temp);
                LWN_Extract_From_Block (wn_temp);
                FmtAssert ((compare_b4_aft (wn_temp, valu_num[wn_temp])),
                           ("type check for renaming fails:5"));
                // retain the iteration numbering as well

                if (unroll_walker.iter_map.find(wn_temp) != unroll_walker.iter_map.end())
                    unroll_walker.iter_map[valu_num[wn_temp]] = unroll_walker.iter_map[wn_temp];
                wn_temp = valu_num[wn_temp];
            }
        }
        wn_temp = WN_next(wn_temp);
    }
    for (std::vector<WN*>::iterator stit = seen_stids.begin();
            stit != seen_stids.end(); ++stit) {
        // throw out hte DU chains of STIDs which have
        // been renamed
        if (valu_num[*stit] == *stit) continue;
        std::set<WN*> to_remov;
        USE_LIST* uselin = Du_Mgr->Du_Get_Use (*stit);
        USE_LIST_ITER iter(uselin);
        for (const DU_NODE *node=iter.First();
                !iter.Is_Empty(); node = iter.Next()) {
            WN *use = (WN *) node->Wn();
            // be careful with the removing of edges that leave the block
            if (allinblock.find (use) != allinblock.end()) {
                to_remov.insert (use);
            }
        }
        for (std::set<WN*>::iterator uslit = to_remov.begin();
                uslit != to_remov.end(); ++uslit) {
            Du_Mgr->Delete_Def_Use (*stit, *uslit);
        }
    }
    std::set<WN*> done_so_far;
    for (std::set<WN*>::iterator stit = exposed_stids.begin();
            stit != exposed_stids.end(); ++stit) {
        // retain the names for stids which escape the block
        bool doit = true;
        SYMBOL olst(*stit);
        for (std::set<WN*>::iterator donei = done_so_far.begin();
                donei != done_so_far.end(); ++donei) {
            SYMBOL newst(*donei);
            if (olst == newst) {
                doit = false;
                break;
            }
        }

        if (doit == false) continue;
        // this is the first time we see the escape variable's stid
        WN* whichstid = NULL;
        int sti = 0;
        for (sti = seen_stids.size() -1; sti >=0; --sti) {
            SYMBOL mysym(seen_stids[sti]);
            if (olst == mysym) {
                whichstid = valu_num[seen_stids[sti]];
                break;
            }
        }
        if (valu_num[seen_stids[sti]] != seen_stids[sti]
                && done_so_far.find(*stit) == done_so_far.end()) {
            // reconnect Old named STID with a LDID from the new name
            done_so_far.insert(*stit);
            WN* append = WN_CreateLdid(OPCODE_make_op(OPR_LDID,
                                       WN_desc(whichstid),
                                       WN_desc(whichstid)),
                                       WN_offset(whichstid),
                                       WN_st(whichstid),
                                       WN_ty(whichstid),
                                       WN_field_id(*stit));

            Create_alias (_alias_mgr, append);
            Du_Mgr->Add_Def_Use (whichstid, append);
            append = LWN_CreateStid (WN_opcode(whichstid), *stit, append);
            Create_alias (_alias_mgr, append);
            WN_set_field_id(append,WN_field_id(*stit));
            LWN_Insert_Block_After (beg, whichstid, append);
            USE_LIST *useli = Du_Mgr->Du_Get_Use (*stit);
            USE_LIST_ITER iter(useli);
            for (const DU_NODE *node = iter.First();
                    !iter.Is_Empty(); node = iter.Next()) {
                WN *use = (WN *) node->Wn();
                if (allinblock.find (use) == allinblock.end()) {
                    Du_Mgr->Add_Def_Use (append,use);
                }
            }
        }
    }
    for (std::set<WN*>::iterator ldit = exposed_ldids.begin();
            ldit != exposed_ldids.end(); ++ldit) {
        // Do likewise for exposed LDIDs like we did for exposed
        // STIDs unless not done yet...
        bool doit = true;
        SYMBOL olst(*ldit);
        for (std::set<WN*>::iterator donei = done_so_far.begin();
                donei != done_so_far.end(); ++donei) {
            SYMBOL newst(*donei);
            if (olst == newst) {
                doit = false;
                break;
            }
        }
        if (doit == false) continue;
        WN* whichstid = NULL;
        for (int sti = seen_stids.size() -1; sti >=0; --sti) {
            SYMBOL mysym(seen_stids[sti]);
            if (olst == mysym) {
                whichstid = seen_stids[sti];
                break;
            }
        }
        if (whichstid != NULL && valu_num[whichstid] != whichstid) {
            if (done_so_far.find(whichstid) == done_so_far.end()) {
                done_so_far.insert(whichstid);
                WN* def = whichstid;
                WN* append = WN_CreateLdid(OPCODE_make_op(OPR_LDID,
                                           WN_desc(valu_num[def]),
                                           WN_desc(valu_num[def])),
                                           WN_offset(valu_num[def]),
                                           WN_st(valu_num[def]),
                                           WN_ty(valu_num[def]),
                                           WN_field_id(valu_num[def]));
                Du_Mgr->Add_Def_Use (valu_num[def], append);
                Copy_alias_info (_alias_mgr, valu_num[def], append);
                WN* append1 = LWN_CreateStid (WN_opcode(valu_num[def]), def, append);
                Copy_alias_info (_alias_mgr, append, append1);
                LWN_Insert_Block_After (beg, valu_num[def], append1);
                Du_Mgr->Add_Def_Use (append1,*ldit);
            }
        }
    }

    std::set<WN*> newallinblock;
    wn_temp = WN_first(beg);
    while(wn_temp) {
        // get all ldid members of the renamed block
        get_ldids(wn_temp, newallinblock);
        wn_temp = WN_next(wn_temp);
    }
    for (std::set<WN*>::iterator oris = allinblock.begin();
            oris != allinblock.end(); ++oris) {
        // cleanups ... LDIDs that got replaced needs to be
        // remvoved from the DU chains
        if (WN_operator(*oris) == OPR_LDID &&
                newallinblock.find(*oris) == newallinblock.end()) {
            LWN_Delete_DU (*oris);
        }
    }

    for (std::map<WN*, WN*>::iterator myvl_it = valu_num.begin();
            myvl_it != valu_num.end(); ++myvl_it) {
        // newly entered LDIDs, and their dependent STIDs need to be
        // bound up in DU chains
        if (myvl_it->first != myvl_it->second) {
            USE_LIST *useli = Du_Mgr->Du_Get_Use(myvl_it->first);
            if (useli && useli->Incomplete()) {
                USE_LIST *rem_use_list = Du_Mgr->Du_Get_Use(myvl_it->second);
                if (rem_use_list == NULL) {
                    Du_Mgr->Create_Use_List(myvl_it->second);
                    rem_use_list = Du_Mgr->Du_Get_Use(myvl_it->second);
                }
                rem_use_list->Set_Incomplete();
            }
            LWN_Delete_DU(myvl_it->first);
        }
    }
}

void PARTIAL_SIMD_WALKER::Walk_helper  (WN* beg, PARTIAL_SIMD_ESTIMATOR& part_simd) {
    // the body of the selected do loop is a block... go over the block
    // and build the depth table and the dependency graph...
    // after a bit of a back tracking pass over the body, do a finalize pass to
    // analyze the body for partial simd candidates and
    // vectorization...
    if(WN_operator(beg) == OPR_BLOCK) {
        part_simd.set_current_block(beg);
        // rename the contents of the block... to clean up anti/output deps
        if (LNO_Run_Psimd_Iso_Unroll) rename_vars(beg);
        WN* wn_temp = WN_first(beg);
        while(wn_temp) {
            Walk_helper(wn_temp, part_simd);
            wn_temp = WN_next(wn_temp);
        }
        part_simd.set_lastnode_processed( wn_temp );
        part_simd.finalize_it();
    } else {
        if  (is_serializing_node(beg)) {
            // whole block work... after the per stmt estimations...
            // whole function analysis
            part_simd.set_lastnode_processed( beg );
            part_simd.finalize_it();
            Walk (beg);
        } else if (OPERATOR_is_stmt(WN_operator(beg))) {
            // per statemnt estimations... depth of a stmt
            // dependency graph... and book keeping
            part_simd.estimate_per_stmt(beg);
        }
    }
}

static WN* Get_Block_Member(WN *wn,int kid) {
    int i;
    WN *wn_temp = WN_first(wn);
    for(i=0; wn_temp && i<kid; i++)
        wn_temp=WN_next(wn_temp);
    if(wn_temp)
        return wn_temp;
    else
        return NULL;
}

void PARTIAL_SIMD_WALKER::Walk (WN *wn) {
    if(OPCODE_is_leaf(WN_opcode(wn))) {
        return;
    } else if (WN_operator(wn) == OPR_DO_LOOP) {
        PARTIAL_SIMD_ESTIMATOR part_simd(_alias_mgr, unroll_walker, false);
        if (part_simd.sanitize_stmts (WN_do_body(wn)) == true) {
            // selected a DO loop for psimd!
            part_simd.set_current_block(WN_do_body(wn));
            part_simd.set_current_loop(wn);
            // do the psimd work!
            if(visited.find(wn) == visited.end()) {
                Walk_helper(WN_do_body(wn), part_simd);
                visited.insert(wn);
            }
        } else {
            Walk (WN_do_body (wn));
        }
    } else if(WN_operator(wn) == OPR_BLOCK) {
        WN *wn_temp = WN_first(wn);
        int kid = 0;
        while(wn_temp) {
            Walk(wn_temp);
            kid++;
            wn_temp = Get_Block_Member(wn,kid);
        }
    } else {
        for(INT kidno=0; kidno<WN_kid_count(wn); kidno++) {
            Walk(WN_kid(wn,kidno));
        }
    }
}

void PARTIAL_SIMD_WALKER::start_psimd(WN* beg) {
    // set up the parents of the function's WHIRL
    LWN_Parentize(beg);
    bool trace_it = false;
    if (trace_it) {
        std::ostringstream myname;
        myname << Cur_PU_Name << ".b4";
        FILE *fp = fopen(myname.str().c_str(), "w");
        fdump_tree(fp,beg);
        fclose(fp);
    }
    trace_it = false;
    // start the process
    Walk(beg);
    // set up the parents again
    LWN_Parentize(beg);
    // fix DU def list bindings if loop was unrolled and rerolled
    unroll_walker.Fix_Def_List_Loop_Stmt(beg,unroll_walker.deleted_loop);
    FmtAssert((Du_Mgr->Verify() == TRUE), (" DU MGR BUG AFTER PSIMD\n"));
    trace_it = false;
}

void Partial_Simd (WN* func_nd) {
    FmtAssert((Du_Mgr->Verify() == TRUE), (" DU MGR BUG B4 PSIMD\n"));
    Unroll_For_Psimd_Walker unroll_walker;
    if (LNO_Run_Psimd_Iso_Unroll) {
        unroll_walker.Do_Unroll_Walk(func_nd);
    }
    if(red_manager) {
        red_manager->Erase(func_nd);
        red_manager->Build(func_nd, TRUE, FALSE);//scalar
    }
    if (Array_Dependence_Graph) {
        Array_Dependence_Graph->Erase_Graph();
        Array_Dependence_Graph = NULL;
        Build_Array_Dependence_Graph(func_nd);
#ifdef Is_True_On
        LNO_Check_Graph(Array_Dependence_Graph);
#endif
    }
    if (Current_Dep_Graph) {
        Current_Dep_Graph->Erase_Graph();
        Current_Dep_Graph =  NULL;
        Build_CG_Dependence_Graph (func_nd);
    }

    PARTIAL_SIMD_WALKER psim_walker (Alias_Mgr, unroll_walker);
    LWN_Parentize(func_nd);
    psim_walker.start_psimd(func_nd);
    LWN_Parentize(func_nd);
    Du_Sanity_Check(func_nd);
    if (Array_Dependence_Graph) {
        Array_Dependence_Graph->Erase_Graph();
        Array_Dependence_Graph = NULL;
        Build_Array_Dependence_Graph(func_nd);
#ifdef Is_True_On
        LNO_Check_Graph(Array_Dependence_Graph);
#endif
    }
    if(red_manager) {
        red_manager->Erase(func_nd);
        red_manager->Build(func_nd, TRUE, FALSE);//scalar
    }

    if (Current_Dep_Graph) {
        Current_Dep_Graph->Erase_Graph();
        Current_Dep_Graph =  NULL;
        Build_CG_Dependence_Graph (func_nd);
    }

    bool trace_it = false;
    if (trace_it) {
        std::ostringstream myname;
        myname << Cur_PU_Name << ".aft";
        FILE *fp = fopen(myname.str().c_str(), "w");
        fdump_tree(fp,func_nd);
        fclose(fp);
    }
    trace_it = false;
}
#endif

/*-------------------------------------------------------------------------------
 * FILE  : ipo_miv_exp.h  [Helper class for METHOD_INVARIANCE]
 * AUTHOR: JAVED ABSAR. Date 29th December 2011.
 * THE ALGORITHM:
 *  Please refer to ipo_miv_exp.cxx
 -------------------------------------------------------------------------------*/

#ifndef MIV_EXP_H_
#define MIV_EXP_H_

#include <iostream>
#include <fstream>
#include <time.h>
#include <map>
#include <vector>

#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
#include <ctype.h>
#include <limits.h>

#include "wn.h"
#include "wn_util.h"            // WN_ITER
#include "pu_info.h"			// PU_Info
#include "wn_map.h"
#include "wn_util.h"
#include "wb_util.h"
#include "ir_reader.h"
#include "ipa_cg.h"

using namespace std;

class MIV_EXP{
public:
	// enum and type definitions
	typedef struct Product{
		vector<int> prod;                        //product of basic nodes
	}Product;

	typedef struct SumOfProduct{
		vector<Product> sum;                     //sum of products of basic nodes
	}SumOfProduct;

	typedef enum NODE_KIND{
		NODE_KIND_INVALID=0,
		NODE_KIND_BASIC, NODE_KIND_ADD, NODE_KIND_MPY
	}NODE_KIND;

	enum LOAD_TYPE{ LOAD_TYPE_LDID, LOAD_TYPE_ILOAD };

	typedef struct NODE{
		NODE_KIND   kind;
		union{
			struct{                              //these refer to information from the whirl
				int         vlevel;              //variance level of this node
				LOAD_TYPE   ltype;               //value or pointer
				WN          *iload, *ldid;       //reference to whirl expression tree
				int          call_id;            //use _call_data[call_id] to access call info
			}bi;//basic node info
			struct{                              //left and right indices to _nodes
				int         lhs_index;
				int         rhs_index;
			}ii;//intermediate node info
		}info;
		WN *iload(){ return info.bi.iload;}
		WN *ldid(){ return info.bi.ldid;}
		LOAD_TYPE ltype(){
			FmtAssert((kind==NODE_KIND_BASIC),("invalid access of ltype")); return info.bi.ltype;
		}
		int variance(){
			FmtAssert((kind==NODE_KIND_BASIC),("invalid access of vlevel")); return info.bi.vlevel;
		}
		int left(){ FmtAssert((kind==NODE_KIND_ADD || kind==NODE_KIND_MPY),("invalid access"));
			return info.ii.lhs_index;
		}
		int right(){ FmtAssert((kind==NODE_KIND_ADD || kind==NODE_KIND_MPY),("invalid access"));
			return info.ii.rhs_index;
		}
	}NODE;


	// data members
	SumOfProduct _sop;
	vector<NODE> _nodes;


	int Create_basic_node(int vlevel, LOAD_TYPE ltype, WN *iload, WN* ldid, int call_id);
	int Create_node(NODE_KIND k, int lhs_index, int rhs_index );
	int Create_add_node( int lhs_index, int rhs_index);
	int Create_mpy_node( int lhs_index, int rhs_index);


	BOOL Transform( int index);
	BOOL Change( int i);
	BOOL Verify_canonical_form( int i);
	BOOL Verify_cform( int i, int form);
	void Flatten(int index);
	void Flatten_recur(int index, int sum_index);
	void Sort();

	void Pretty_print_basic( NODE &n);
	void Pretty_print_exp_tree( int index);
	void Pretty_print_exp_recur(int index);
	void Pretty_print_sop();

};

#endif /* MIV_EXP_H_ */

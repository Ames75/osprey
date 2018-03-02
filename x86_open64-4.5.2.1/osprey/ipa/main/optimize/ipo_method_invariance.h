/*-------------------------------------------------------------------------------
 * FILE  : ipo_method_invariance.h [Hoisting loop-invariant- calls & expressions]
 * AUTHOR: JAVED ABSAR. Date 29th December 2011.
 *
 * THE ALGORITHM: Please refer to ipo_method_invariance.cxx header
 -------------------------------------------------------------------------------*/


#ifndef METHOD_INVARIANCE_H_
#define METHOD_INVARIANCE_H_
#include <iostream>
#include <fstream>
#include <time.h>
#include <map>

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

#include "ipo_miv_exp.h"

using namespace std;

class METHOD_INVARIANCE
{
public:
	void Search_Optimize(IPA_NODE *node, IPA_CALL_GRAPH *cg);//external API for optimizer

private:
	// definitions ///////////////////////////////////////////////////////////////
	typedef enum _MIV_DEBUG_MSG_LEVEL {
		MIV_MSG_LEVEL_SILENT = 0,
		MIV_MSG_LEVEL_LITTLE,
		MIV_MSG_LEVEL_SOME,
		MIV_MSG_LEVEL_MANY,
		MIV_MSG_LEVEL_ALL
	}MIV_DEBUG_MSG_LEVEL;

	typedef enum MIV_LOOP_KIND{
		MIV_LOOP_KIND_DO,
		MIV_LOOP_KIND_WHILE,
		MIV_LOOP_KIND_NONE
	}MIV_LOOP_TYPE;

	typedef struct LOOP_DATA{
		WN *wn_loop;                   //the while or for-do loop
		WN *wn_iter;                   //iterator instance. e.g. i=0
	}LOOP_DATA;

	typedef struct CALL_DATA{
		WN   *wn_call;
		WN   *wn_store;
		BOOL hoistable;
		int  variance_level;           //0: dependent on outermost iterator
	};


	// data (state) members //////////////////////////////////////////////////////
	IPA_NODE            *_ipa_node;
	IPA_CALL_GRAPH      *_cg;

	int                 _loop_nest_limit;                  //ridiculously large
	MIV_LOOP_KIND       _loop_nest_kind;                   //do,while or none
	int                 _loop_nest_depth;                  //0: single loop
	WN*                 _loop_nest_parent;                 //enclosing block
	WN*                 _loop_nest_body;                   //innermost body

	int                 _no_of_calls;
	WN*                 _final_exp;
	TYPE_ID             _final_exp_rtype;
	INT64               _final_exp_lineno;

	LOOP_DATA           _loop_data[10];
	CALL_DATA           _call_data[10];
	WN*                 _hoist_block[10];                  //created to keep hoisted codes

	MIV_EXP             *_miv_exp;                         //create in optimizer and attach

	MIV_DEBUG_MSG_LEVEL miv_msg_level;
	char                _var_name[100];


	// function (methods) members ////////////////////////////////////////////////
	void Search_to_Optimize(WN *wn );   //top level recursive search and optimize
	BOOL Optimize_do_loop( WN* wn);     //top level do loop optimizer


	//DO-LOOP identification related
	BOOL Is_doLoop_perfect_nest(WN *in_loop);    //perfectly nested do loops
	BOOL Is_doLoop_header_perfect( WN *in_loop, WN **wn_iter );//increments by one
	BOOL Is_doLoop_body_doLoop(WN *in_loop);
	BOOL Is_doLoop_body_clean( );

	// LOOP BODY checks
	BOOL Is_doLoop_body_good( );
	BOOL Analyze_calls( );

	BOOL Verify_final_expression( );
	BOOL Verify_exp_tree(WN *wn);
	BOOL Match_call_value(WN *wn, int *call_index );

	//Preprocessing before the hoisting
	int Build_final_miv_exp( );
	int Build_miv_exp(WN *wn);

	void Create_blks_for_hoisting( );
	void Insert_last_into_hoist_block( WN *wn, int level );
	void Integrate_hoisting_blocks();

	//hoists
	void Hoist_calls( );
	BOOL Hoist_call(int index );
	void Hoist_expression();


	// other support functions
	char *Get_symbol_name(WN *wn);
	BOOL Are_variables_same(WN *wn1, WN *wn2 );
	BOOL Is_argument_iter(WN *arg, int *iter);
	BOOL Is_call_invariant(WN *wn, int *dep_depth);
	void Adjust_ipa_node_data(WN *old_call_wn, WN *new_call_wn);

	void Pretty_print_loop_nest_info();
	void Pretty_print_call_analysis();
	void Pretty_print_expression_analysis();
};
#endif


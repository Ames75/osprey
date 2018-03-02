#include "ipo_method_invariance.h"
#include "ipo_defs.h"
#include "ipo_parent.h"

/*-------------------------------------------------------------------------------
 * FILE  : ipo_method_invariance.cxx
 * AUTHOR: JAVED ABSAR. Date 29th December 2011.
 *
 * THE ALGORITHM [LIMPEH: Loop invariant method partial expression hoister]
 *
 * Identify a perfect loop nest [Is_doLoop_perfect_nest & others]
 *   A perfect loop nest has a nesting of loops with no other statement except for
 *   innermost body. The iterators are initialized to 0, the increments are by 1
 *   and the end condition is a comparison with a loop invariant. Since this optim-
 *   ization is operating at IPA, without assistance of LNO, it is replicating in a
 *   simpler way the loop-detection mechanism. Some of the constraints can be removed
 *   easily, but is not seen necessary currently.
 *
 * Analyze Calls [Analyze_calls, Is_call_invariant, Is_argument_iter]
 *   The inner-most loop body is series of calls to methods. Apart from 'this' pointer
 *   the methods are passed loop iterators. From the set of loop iterators passed to
 *   functions, one can infer the loop invariance of the function calls.
 *
 * Analyze Expression [Verify_final_expression, Match_call_value]
 *   There is a final expression in the loop body that takes the return value of the
 *   function call and combines them linearly. There is an accumulation of the result.
 *
 * Convert to Canonical Form [Build_miv_exp, miv_exp.Transform]
 *   The expression tree is converted to a sum of product canonical form. This requires
 *   a step of distributing the multiplications across additions. The canonical form is
 *   sorted according to the variance. For example, if a variable is a return value of a
 *   call that is variant to the innermost loop, it will appear last in the sorted sum of
 *   product listing. For more description see ipo_miv_exp.cxx header.
 *
 * Hoist Calls [Hoist_calls, Adjust_ipa_node_data]
 *   Hoist call depending on their invariance to the loop.
 *
 * Hoist expression [Hoist_expression & others]
 *   Here we do a sophisticated partial expression hoisting. Put simply, it takes those
 *   computations that can be hoisted, hoists them and stores the intermediate values into
 *   temporary variables. This partial expression and temporary creation occurs at each
 *   loop-nest level. The totally variant part of the expression is then done in the
 *   innermost loop using the temporary variables created.
 *
 * Notes:
 * 1. Another type of whirl is possible for the case above where the loop body
 *    is just one expression statement and the calls are embedded using the
 *    comma operator. It may be coupled with generation of while loop instead of do.
 *
 -------------------------------------------------------------------------------*/



/*-------------------------------------------------------------------------------
 *External API. Receives an IPA_NODE (function node) in which it looks for
 * optimization opportunity and, if found, performs the transformation.
 * The context object copies / restores CONTEXT during creation/deletion, so
 * this is the right place for it (DO NOT MOVE IT TO ELSEWHERE).
 --------------------------------------------------------------------------------*/
 void METHOD_INVARIANCE::Search_Optimize(IPA_NODE *node, IPA_CALL_GRAPH *cg)
 {
	 _loop_nest_limit  = 10;
	 miv_msg_level     = MIV_MSG_LEVEL_SILENT;

	 _ipa_node         = node;
	 _cg               = cg;

	 FmtAssert( _ipa_node, ("NULL ipa_node supplied to method invariance "));
	 FmtAssert( _cg,       ("NULL call graph node supplied to method invariance "));

	IPA_NODE_CONTEXT context (node);             //set SCOPE etc for this IPA_NODE

 	if(miv_msg_level >= MIV_MSG_LEVEL_ALL ){
 		cout << "METHOD_INVARIANCE::Search_Optimize(" << node->Name() << ")" << endl;
 	}

 	Search_to_Optimize(_ipa_node->Whirl_Tree());
}


 /*-------------------------------------------------------------------------------
  *Performs recursive depth first  search for a perfectly nested loops that could be
  * optimized by loop invariant hoisting of calls + computation.
  --------------------------------------------------------------------------------*/
 void METHOD_INVARIANCE::Search_to_Optimize(WN *wn )
 {
 	if (!wn) 		return;

 	switch (WN_opcode(wn)){
 	case OPC_FUNC_ENTRY: Search_to_Optimize( WN_func_body(wn) );
 	    break;

 	case OPC_BLOCK:
 		for (WN *stmt = WN_first(wn); stmt != NULL; stmt = WN_next(stmt))
 			Search_to_Optimize(stmt);
 		break;

 	case OPC_IF:
 		Search_to_Optimize(WN_then(wn));
 		Search_to_Optimize(WN_else(wn));
 		break;

 	case OPC_WHILE_DO:
 	case OPC_DO_WHILE:
 		Search_to_Optimize(WN_while_body(wn));
 		break;

 	case OPC_DO_LOOP:
 		if( Optimize_do_loop(wn) == TRUE ) return;    //opt. done, retrace
 		else Search_to_Optimize(WN_do_body(wn));      //else search within loop
 		break;

 	case OPC_REGION: 	                                         //exploring into default?
 		for (int i = 0; i < WN_kid_count(wn); i++)
 			Search_to_Optimize(WN_kid(wn, i));
 		break;
 	default: /*do not go to dark corners*/;
 	}
 }

 /*-------------------------------------------------------------------------------
   *This is the main optimization control function.  It checks if the do loop
   * is a perfectly nested loop with a clean body [ refer:Is_doLoop_perfect_nest].
   *Next it marks and stores if the inner body is series of calls followed by an
   * expression [refer:Is_doLoop_body_good]. Next [Analyze_calls] marks calls as
   * hoistable with the invariance level. [Analyze_final_expression] checks
   * compliance of expression (uses return values). [Optimize_Calls] and
   * [Optimize_Expression] perform the hoisting. They rely on canonical form.
   --------------------------------------------------------------------------------*/
  BOOL METHOD_INVARIANCE::Optimize_do_loop( WN* wn)
  {
 	 if(!wn || WN_operator(wn) != OPR_DO_LOOP) return FALSE;

 	 _loop_nest_parent  = NULL;
 	 _loop_nest_body    = NULL;
 	 _loop_nest_depth   = -1;
 	 _no_of_calls       = -1;
 	 _final_exp         = NULL;


 	_loop_nest_parent = WN_Get_Parent( wn, Parent_Map, Current_Map_Tab);
 	if( !_loop_nest_parent || WN_operator(_loop_nest_parent) != OPR_BLOCK ) return FALSE;

  	if( Is_doLoop_perfect_nest(wn) == FALSE )return FALSE; //no guarantee on body yet

  	//some sanity checks
 	FmtAssert( ( (_loop_nest_depth >= 0) && (_loop_nest_depth < _loop_nest_limit) ),
  			                                ("_loop_nest_depth in error") );
  	FmtAssert( (WN_operator( _loop_data[_loop_nest_depth].wn_loop) == OPR_DO_LOOP),
  			                                ("inconsistent information in _loop_data"));
  	FmtAssert( (_loop_nest_body == WN_do_body(_loop_data[_loop_nest_depth].wn_loop)),
  			                                ("inconsistent information on loop nest body"));


  	if( (_loop_nest_depth !=2) ) return FALSE;
  	_loop_nest_kind = MIV_LOOP_KIND_DO;

  	if(miv_msg_level >= MIV_MSG_LEVEL_SOME ){
  		cout << "found a perfect loop-nest in function:" << _ipa_node->Name()  << endl;
  		Pretty_print_loop_nest_info();
  		cout << "checking if Is_doLoop_body_good: ";
  	}

  	if( Is_doLoop_body_good( ) == FALSE){
  		if(miv_msg_level >= MIV_MSG_LEVEL_SOME ) cout << " NO" << endl;
  		return FALSE;
  	}
  	if(miv_msg_level >= MIV_MSG_LEVEL_SOME ) cout << "Is_doLoop_body_good == TRUE " << endl;

 	FmtAssert( (_no_of_calls > 0 ),           ("inconsistent information on calls "));
 	if( ( _no_of_calls < 3  || _no_of_calls > 9 ) ) return FALSE;

  	if( Analyze_calls( ) == FALSE){
  		if(miv_msg_level >= MIV_MSG_LEVEL_SOME ) cout << "Analyze_calls == FALSE " << endl;
  		return FALSE;
  	}

  	if(miv_msg_level >= MIV_MSG_LEVEL_SOME ){
  		cout << "Analyse_calls  == TRUE " << endl;
  		Pretty_print_call_analysis();
  	}

  	if( Verify_final_expression( )  == FALSE)return FALSE;
  	if(miv_msg_level >= MIV_MSG_LEVEL_SOME ) cout << "Verify_final_expression  == TRUE" << endl;


  	MIV_EXP m;                                          //create the MIV_Exp object
  	_miv_exp = &m;
  	int met_root = Build_final_miv_exp( );              //root of the constructed miv_exp tree

  	if(miv_msg_level >= MIV_MSG_LEVEL_SOME ) _miv_exp->Pretty_print_exp_tree(met_root);
  	if(miv_msg_level >= MIV_MSG_LEVEL_SOME ) cout << "all loop and body checks complete " << endl;

  	_miv_exp->Transform(met_root);                         //transform to canonical form. root nodes remains same
  	FmtAssert( _miv_exp->Verify_canonical_form(met_root),
  			                                    ("canonization verification failed!"));

  	if(miv_msg_level >= MIV_MSG_LEVEL_SOME ){
  		cout << "miv_exp post canonization & verification: ";
  		_miv_exp->Pretty_print_exp_tree(met_root);
  	}

  	_miv_exp->Flatten(met_root);
  	if(miv_msg_level >= MIV_MSG_LEVEL_SOME ){
  		cout << " SOP before sorting: " ;_miv_exp->Pretty_print_sop();
  	}
  	_miv_exp->Sort( );
  	if(miv_msg_level >= MIV_MSG_LEVEL_SOME ){
  		cout << " SOP after sorting: "; _miv_exp->Pretty_print_sop();
  	}

   	if(0 && miv_msg_level >= MIV_MSG_LEVEL_SOME ){
  		cout << "WHIRL before call hoisting."  << endl;
  		fdump_tree(stdout, _loop_data[0].wn_loop);
  	}

    _final_exp_lineno = WN_Get_Linenum(_final_exp);
   	Create_blks_for_hoisting();

   	Hoist_calls( );


  	if(miv_msg_level >= MIV_MSG_LEVEL_SOME ){
  		cout << "WHIRL after call hoisting."  << endl;
  		fdump_tree(stdout, _loop_data[0].wn_loop);
  	}

  	Hoist_expression();
   	Integrate_hoisting_blocks();
  	if(miv_msg_level >= MIV_MSG_LEVEL_SOME ){
  		cout << "WHIRL after expression hoisting."  << endl;
  		fdump_tree(stdout, _loop_data[0].wn_loop);
  	}
  	//cout << "version 1.0 " << endl;
   	return TRUE;
 }

/*-------------------------------------------------------------------------------
 * If the call-arguments is composed of only iterators, then mark it as hoist-able.
 * e.g. a.foo(i,j) in loop [i,j,k] marked 'variance_level=1'. a.f(i) v_level = 0.
 * Sets or clears _call_data[.].hoistable, depending on analysis.
 *--------------------------------------------------------------------------------*/
BOOL METHOD_INVARIANCE::Analyze_calls( )
{
	 for( int i = 0; i < _no_of_calls; i++ )
	 {
		 WN *call_wn  = _call_data[i].wn_call;
		 WN *store_wn = _call_data[i].wn_store;

		 if(!call_wn  || WN_operator(call_wn)!=OPR_CALL )FmtAssert(0,("call_data call incorrect"));
		 if(!store_wn || WN_operator(store_wn)!=OPR_STID)FmtAssert(0,("call_data store incorrect"));
		 _call_data[i].hoistable = FALSE;

		 if( WN_kid_count(call_wn) < 2 )continue; //this call cannot be hoisted currently

		 //first argument is special as it could be a object-this pointer
		 WN *obj = WN_kid0(call_wn);
		 if(!obj || WN_operator(obj)!= OPR_PARM ) continue;
		 if(WN_kid_count(obj) != 1 || !WN_kid0(obj) || WN_operator(WN_kid0(obj))!=OPR_LDA ) continue;

		 int highest_dep = -1;
		 BOOL hoistable = TRUE;                   //innocent till proven guilty

		 for(int k = 1; k < WN_kid_count(call_wn); k++)
		 {
			 int iter_no;
			 WN *parm = WN_kid(call_wn,k);
			 if(Is_argument_iter(parm,&iter_no) == FALSE ){//returns iter_no, if TRUE
				 hoistable = FALSE; break;
			 }
			 if(iter_no > highest_dep )highest_dep = iter_no;
		 }
		 if( hoistable && highest_dep >= 0 ){     //so completely invariant is not handled presently
			 FmtAssert( (highest_dep <= _loop_nest_depth),
					 ("there is logical error in invariance determination") );

			 _call_data[i].variance_level = highest_dep;
			 _call_data[i].hoistable      = TRUE;//finally award the certificate
		 }
	 }
	 return TRUE;
}

/*-------------------------------------------------------------------------------
  *This function certifies that the expression  is a binary tree formed by
  * additions and multiplications of previously stored call return values.
  *The final istore is to call return location (accumulation of results).
  *It DOES NOT build the connection between expression and the call return values
  --------------------------------------------------------------------------------*/
BOOL METHOD_INVARIANCE::Verify_final_expression( )
{
	 WN *wn = _final_exp;
	 if(!wn || WN_operator(_final_exp)!= OPR_ISTORE ) return FALSE;
	 if(WN_kid_count(wn)!=2 ) return FALSE;

	 _final_exp_rtype = WN_desc(_final_exp);

	 if( miv_msg_level >= MIV_MSG_LEVEL_LITTLE ){
		 if(_final_exp_rtype == MTYPE_F8) cout << "final_exp_rtype is MTYPE_F8" << endl;
		 else cout << "final_exp_rtype is NOT MTYPE_F8" << endl;
	 }
	 if( _final_exp_rtype != MTYPE_F8)return FALSE;

	 WN *exp              = WN_kid0(wn);
	 WN *final_store_loc = WN_kid1(wn);

	 if(!final_store_loc || WN_operator(final_store_loc)!= OPR_LDID ) return FALSE;
	 if(!exp || WN_operator(exp)!= OPR_ADD ) return FALSE;

	 if( WN_rtype(exp) != _final_exp_rtype)return FALSE;

	 int call_index;
	 if( Match_call_value(final_store_loc, &call_index) == FALSE )
		 return FALSE; //final store location is return value

	 return Verify_exp_tree(exp);
}
/*-------------------------------------------------------------------------------
 *Recursive helper function for Verify_final_expression to certify expression
 *Note that effectively this is an ANDING of all leaf node match_call return values
 --------------------------------------------------------------------------------*/
BOOL METHOD_INVARIANCE::Verify_exp_tree(WN *wn)
{
	if(!wn) return FALSE;
	OPERATOR opr = WN_operator(wn);
    int si;                  //_call_data[si].store_wn matching supplied symbol
	switch(opr){
		case OPR_LDID:
			if( Match_call_value(wn, &si) == FALSE ) return FALSE;
			if( WN_rtype(wn) != _final_exp_rtype)return FALSE;
		    return TRUE;
		case OPR_ILOAD:
		{
			if(WN_kid_count(wn)!=1)return FALSE;
			WN *kid0 = WN_kid0(wn);
			if(!kid0 || WN_operator(kid0)!= OPR_LDID)return FALSE;
			if( Match_call_value(kid0, &si) == FALSE ) return FALSE;
			return TRUE;
		}
		case OPR_ADD:
		case OPR_MPY:
			if(WN_kid_count(wn)!=2 || !WN_kid0(wn) || !WN_kid1(wn) ) return FALSE;
			if( WN_rtype(wn) != _final_exp_rtype)return FALSE;
			return ( Verify_exp_tree(WN_kid0(wn))
					             && Verify_exp_tree(WN_kid1(wn)) );//key part is &&
		default: return FALSE;
	}
	return FALSE;
}

/*-------------------------------------------------------------------------------
 *Checks if the symbol(wn) matches a store to a return stored value
 --------------------------------------------------------------------------------*/
BOOL METHOD_INVARIANCE::Match_call_value(WN *wn, int *call_index )
{
	for(int i = 0; i < _no_of_calls ; i++ ){
		if( Are_variables_same(wn, _call_data[i].wn_store) ){
			*call_index = i; return TRUE;
		}
	}
	return FALSE;
}
/*-------------------------------------------------------------------------------
 *The certification has happened, so no repeats. This procedure prepares the MIV_EXP
 * data-structure - basic nodes and intermediate nodes which mimic the _final_exp,
 * with proper connections to _call_data[] and ldid/iload.
 * Notice that the calls return the MIV_EXP node indices to use in building expression
 --------------------------------------------------------------------------------*/
 int METHOD_INVARIANCE::Build_final_miv_exp( ){
	 return Build_miv_exp(WN_kid0(_final_exp)); //rhs of final_expression
 }

 //..recursive helper of above Build_final_miv_exp
 int METHOD_INVARIANCE::Build_miv_exp(WN *wn)
 {
 	int si;                    //tracked returned store index;
 	int basic_idx;             //basic node index

 	switch(WN_operator(wn))
 	{
 		case OPR_LDID:
 			Match_call_value(wn, &si);
 			//Create_basic_node(int vlevel, LOAD_TYPE ltype, WN *iload, WN* ldid, int call_id);
 			return _miv_exp->Create_basic_node(_call_data[si].variance_level,
 					                                        MIV_EXP::LOAD_TYPE_LDID, 0, wn, si);
 		case OPR_ILOAD:
 		{
 			WN *kid0 = WN_kid0(wn);
 			Match_call_value(kid0, &si) ;
 			return _miv_exp->Create_basic_node(_call_data[si].variance_level,
 					                                      MIV_EXP::LOAD_TYPE_ILOAD, wn, kid0, si);
 		}
 		case OPR_ADD:
 			return _miv_exp->Create_add_node( Build_miv_exp(WN_kid0(wn)), Build_miv_exp(WN_kid1(wn)) );
 		case OPR_MPY:
 			return _miv_exp->Create_mpy_node( Build_miv_exp(WN_kid0(wn)), Build_miv_exp(WN_kid1(wn)) );

 		default: FmtAssert((0), ("Sorry, but Mr. Certifier has not done his job properly"));
 	}
}



 /*-------------------------------------------------------------------------------
  *Create empty BLOCKS and insert them at each loop level before the inner loop,
  * save the innermost, where the block is inserted after all statements.
  --------------------------------------------------------------------------------*/
 void METHOD_INVARIANCE::Create_blks_for_hoisting( ){
 	for( int i = 0; i <= _loop_nest_depth; i++ ){
 		_hoist_block[i] = WN_CreateBlock();
 		FmtAssert((_hoist_block[i] &&  WN_operator(_hoist_block[i])==OPR_BLOCK), ("created is not block"));
 	}
 }

 /*-------------------------------------------------------------------------------
  *Insert 'wn' into _hoist_block[level] at last position
  --------------------------------------------------------------------------------*/
 void METHOD_INVARIANCE::Insert_last_into_hoist_block( WN *wn, int level )
 {
	 FmtAssert(((level >=0) && (level <= _loop_nest_depth)), ("cannot hoist outside loop"));

	 WN *target_wn = _hoist_block[level];
	 FmtAssert((target_wn && WN_operator(target_wn)==OPR_BLOCK), ("_hoist_block not set to OPR_BLOCK"));

	 /*WN_INSERT_BlockAfter(WN *blck, WN *wn, WN *in);  //Insert  "in" into BLOCK after  "wn"*/
	 WN_INSERT_BlockAfter(target_wn, WN_last(target_wn), wn );
 }

 /*-------------------------------------------------------------------------------
  *Insert hoist_block[] into loop-nest. Note that inserting place-holders blocks
  * before populating any instruction inside leads to they being deleted.
  --------------------------------------------------------------------------------*/
 void METHOD_INVARIANCE::Integrate_hoisting_blocks( )
 {
	 for( int i = 0; i <= _loop_nest_depth; i++ )
	 {
		 FmtAssert((_hoist_block[i] &&  WN_operator(_hoist_block[i])==OPR_BLOCK),
	 				                                              ("created blk is not a block"));

		 WN *loop_body = WN_do_body( _loop_data[i].wn_loop );
		 FmtAssert((loop_body && WN_operator(loop_body) == OPR_BLOCK),("loop body incorrect"));

		 if(i != _loop_nest_depth)
			 WN_INSERT_BlockBefore(loop_body, WN_first(loop_body), _hoist_block[i]);//insert before next loop
		 else
			 WN_INSERT_BlockAfter(loop_body, WN_last(loop_body), _hoist_block[i]);  //insert before next loop
	 }
 	 WN_Parentize (_loop_data[0].wn_loop, Parent_Map, Current_Map_Tab );
}




/*-------------------------------------------------------------------------------
 *Hoist expressions following the canonical sum of product form.
 *Note: extension to hoisting out of loop is future implementation.
 * Algorithm:
 *   After analysis of each product, there is generated partial whirl
 *    (a) a whirl portion for value load
 *    (b) a partial expression computed
 *   The summing part takes the partials and stitches them together into a OPR_ADD
 --------------------------------------------------------------------------------*/
 void METHOD_INVARIANCE::Hoist_expression( )
 {

	 vector<MIV_EXP::Product> &sum   = _miv_exp->_sop.sum;
	 vector<MIV_EXP::NODE>   &nodes = _miv_exp->_nodes;
     int tcounter = 0;                           //temporary variable counter

	 WN *res_wn=0;                               //whirl node that carries partial '+' to completion
	 WN *store_JXq = _call_data[_no_of_calls-1].wn_store;

	 TY_IDX dbl_ty_idx = 0;
	 TY &new_ty = New_TY(dbl_ty_idx);
	 TY_Init(new_ty, TY_size(WN_ty(store_JXq)), KIND_SCALAR, WN_desc(store_JXq), Save_Str("J_F8_type"));


	 TYPE_ID  dbl_rtype = _final_exp_rtype; //WN_rtype(store_JXq);


	 for( int i = 0; i < sum.size(); i++ )
	 {
		 vector<int> &prod = sum[i].prod;
		 WN   *prod_wn = 0;                      //whirl node that carries partial products to completion

		 for( int j = 0; j < prod.size(); j++ )
		 {//key here is: prepare (...*val[j]) loaded and ready for * by val[j+1] */
			 MIV_EXP::NODE &n = nodes[ prod[j] ];

			 if(j == 0 )
			 {//this is the first term handling
				 if(j == prod.size()-1)
				 {//this is first and last term, load it to prod_wn and let it be strung to res_wn
					 prod_wn = WN_COPY_Tree((n.ltype() == MIV_EXP::LOAD_TYPE_ILOAD)? n.iload() : n.ldid());
				 }else
				 {//first but not only term, load it and wait for next one to take it and multiply
					 prod_wn = WN_COPY_Tree((n.ltype() == MIV_EXP::LOAD_TYPE_ILOAD)? n.iload() : n.ldid());
				 }
			 }else
			 {//intermediate or last term handling.
				 if(j != prod.size()-1)
				 {/*pure intermediate. Load it, multiply with prod_wn. If the next is same level
				    do nothing more. If next is different level, store it here and load at lower*/
					 MIV_EXP::NODE &nnext = nodes[ prod[j+1] ];

					 WN* t   = WN_COPY_Tree((n.ltype() == MIV_EXP::LOAD_TYPE_ILOAD)? n.iload() : n.ldid());
					 prod_wn = WN_CreateExp2(OPR_MPY, dbl_rtype, MTYPE_V, prod_wn, t);

					 FmtAssert( (nnext.variance() >= n.variance()),("error in variance sorting"));

					 if(nnext.variance() >  n.variance() ){
						 //store it here and load at lower
						 ST *tmp_var  = New_ST(CURRENT_SYMTAB);

						 char var_name[200], *prefix = "Jtmp";
						 sprintf(var_name,"%s%dL%d_2_L%d",prefix,tcounter++, n.variance(),nnext.variance());

						 ST_Init(tmp_var, Save_Str(var_name), CLASS_VAR, SCLASS_AUTO, EXPORT_LOCAL, dbl_ty_idx);
						 WN * tt =  WN_Stid(dbl_rtype,0, tmp_var, dbl_ty_idx, prod_wn, 0);
						 WN_Set_Linenum(tt, _final_exp_lineno);
						 Insert_last_into_hoist_block(tt, n.variance());

						 prod_wn = WN_Ldid(dbl_rtype, 0, WN_st_idx(tt), dbl_ty_idx,0);
					 }
				 }else
				 {/*last term handling.load it, multiply. If current level is inner do nothing
				    more, else store to temporary and reload the temporary in inner body     */
					 WN* t   = WN_COPY_Tree((n.ltype() == MIV_EXP::LOAD_TYPE_ILOAD)? n.iload() : n.ldid());
					 prod_wn = WN_CreateExp2(OPR_MPY, dbl_rtype, MTYPE_V, prod_wn, t);
				 }
			 }
		 }/*for j*/

		 if(prod_wn != 0){
			 if(res_wn == 0)
				 res_wn = prod_wn;                         //nothing to string with + , res<-prod
			 else
				 res_wn = WN_CreateExp2(OPR_ADD, dbl_rtype, MTYPE_V,res_wn, prod_wn);//string it: res = res + prod
		 }else {/*nothing to do for this empty product */}

	 }/* for i*/

	 //res_wn is the whirl of the new optimized expression
	 WN *fexp = _final_exp;
	 WN *cm_ptr      = WN_COPY_Tree(WN_kid1(fexp));//address or ldid of aggregate pointer
	 WN *store_wn    = WN_Istore(WN_desc(fexp), WN_offset(fexp), WN_ty(fexp),cm_ptr, res_wn,0);

	 WN_Set_Linenum(store_wn, _final_exp_lineno);
	 Insert_last_into_hoist_block(store_wn, _loop_nest_depth);

	 WN_EXTRACT_FromBlock(_loop_nest_body, _final_exp);  //thanks, but we dont need u anymore, so "let go"

 }


/*-------------------------------------------------------------------------------
 *Identify which calls are loop-invariant and can be hoisted to what level
 --------------------------------------------------------------------------------*/
 void METHOD_INVARIANCE::Hoist_calls( )
 {
	 for( int i = 0; i < _no_of_calls; i++ ){
		 if(miv_msg_level >= MIV_MSG_LEVEL_MANY){
			 cout << "call: " << Get_symbol_name(_call_data[i].wn_call) << endl;
		 }

		 BOOL t = Hoist_call(i);

		 if( t && (miv_msg_level >= MIV_MSG_LEVEL_MANY) ) cout << "  HOISTED"     << endl;
		 if(!t & (miv_msg_level >= MIV_MSG_LEVEL_MANY)  ) cout << "  NOT HOISTED" << endl;
	 }
}

BOOL METHOD_INVARIANCE::Hoist_call(int index )
  {
	 WN* call_wn  = _call_data[index].wn_call;
	 WN* store_wn = _call_data[index].wn_store;

	 BOOL hoistable = _call_data[index].hoistable;
	 int  vlevel    = _call_data[index].variance_level;

	 if(!hoistable) return FALSE;

	 if( vlevel < 0 )return FALSE;                         //we dont handle out of loop yet
	 if( vlevel >= _loop_nest_depth) return FALSE;         //its already where it belongs

	 WN *new_call  =  WN_COPY_Tree(call_wn);
	 WN *new_store =  WN_COPY_Tree(store_wn);
	 Adjust_ipa_node_data(call_wn, new_call);

	 Insert_last_into_hoist_block(new_call, vlevel );      //hoist to hoist_block at top of loop_body of loop vlevel
	 Insert_last_into_hoist_block(new_store, vlevel );

	 WN *call_parent = WN_do_body( _loop_data[_loop_nest_depth].wn_loop);

	 WN_EXTRACT_FromBlock(call_parent, call_wn);
	 WN_EXTRACT_FromBlock(call_parent, store_wn);

	 return TRUE;
 }



/*-------------------------------------------------------------------------------
 * Updates the information in _cg _ipa_node to reflect change in call position
 --------------------------------------------------------------------------------*/
 void METHOD_INVARIANCE::Adjust_ipa_node_data(WN *old_call_wn, WN *new_call_wn)
 {
	BOOL found = FALSE;

	if(miv_msg_level >= MIV_MSG_LEVEL_ALL ){
		cout << " Adjusting IPA_NODE info. old-called:" << Get_symbol_name(old_call_wn) << endl;
		cout << "   new-called: " << Get_symbol_name(new_call_wn) << endl;
		cout << "   scanning though calls of " << IPA_Node_Name(_ipa_node) << " ...";
	}

	IPA_SUCC_ITER succ_iter (_ipa_node);
	_cg->Map_Callsites (_ipa_node);           // map callsites to WN nodes

	for (succ_iter.First(); !succ_iter.Is_Empty(); succ_iter.Next())
	{
		IPA_EDGE *edge = succ_iter.Current_Edge();

		IPA_NODE* caller = IPA_Call_Graph->Caller (edge);
		IPA_NODE* callee = IPA_Call_Graph->Callee (edge);
		//cout << "caller: " << IPA_Node_Name(caller) << " callee:" << IPA_Node_Name(callee) << endl;

		WN *eWN = edge->Whirl_Node();
		FmtAssert( eWN != NULL, ("eWN is NULL! "));
		FmtAssert(WN_operator(eWN) == OPR_CALL, ("edge->Whirl_Node should  be OPR_CALL"));

		//cout << "edge->WN name " << Get_symbol_name( edge->Whirl_Node()) << endl ;

		if( old_call_wn == edge->Whirl_Node()){
			if(miv_msg_level >= MIV_MSG_LEVEL_MANY ){
				cout << "  found call-site to update through whirl pointer " << endl;
			}
			edge->Set_Whirl_Node(new_call_wn);
			return ;
		}
	}

	FmtAssert(FALSE, ("   could not find hoisted  call site in IPA_NODE->EDGE whirl listing "));
 }


 /*-------------------------------------------------------------------------------
  * Compares two whirl nodes for name equivalance. Probably this way is not the
  * best and one needs a better approach. But this takes care of PREG as well.
  --------------------------------------------------------------------------------*/
 BOOL METHOD_INVARIANCE::Are_variables_same(WN *wn1, WN *wn2) {
 	if (!wn1 || !OPCODE_has_sym(WN_opcode(wn1)))
 		return FALSE;
 	if (!wn2 || !OPCODE_has_sym(WN_opcode(wn2)))
 		return FALSE;

 	if (WN_operator(wn1) != OPR_LDID && WN_operator(wn1) != OPR_STID)
 		return FALSE;
 	if (WN_operator(wn2) != OPR_LDID && WN_operator(wn2) != OPR_STID)
 		return FALSE;

 	ST *st_wn1 = WN_st(wn1);
 	ST *st_wn2 = WN_st(wn2);

 	if (ST_class(WN_st_idx(wn1)) == CLASS_PREG && ST_class(WN_st_idx(wn2)) == CLASS_PREG)
 	{// the preg number is in the WHIRL node, not in the ST
 		if (WN_offset(wn1) == WN_offset(wn2)) return TRUE;	else return FALSE;
 	}
 	else if (ST_class(WN_st_idx(wn1)) == CLASS_VAR && ST_class(WN_st_idx(wn2)) == CLASS_VAR)
 	{
 		if (WN_st_idx(wn1) == WN_st_idx(wn2) && WN_offset(wn1)== WN_offset(wn2))
 			return TRUE;	else	return FALSE;
 	}
 	return FALSE;
 }


 /*-----------------------------------------------------------------------------
  * consider a loop-nest {i, j, k }. i is at depth 0.
  * If arg is k, return 2. If arg is j, return 1.
  * If arg is not i,j,k then return FALSE.
  */
 BOOL METHOD_INVARIANCE::Is_argument_iter(WN *arg, int *iter)
 {
 	if( WN_operator(arg)!=OPR_PARM  || WN_kid_count(arg)!=1 )return FALSE;
     WN *kid = WN_kid0(arg);

     if(WN_operator(kid) != OPR_LDID) return FALSE;

     for( int i = 0; i <= _loop_nest_depth; i++ )
     {
     	if(Are_variables_same(kid,_loop_data[i].wn_iter) ){
     		*iter = i;
     		if( miv_msg_level >= MIV_MSG_LEVEL_ALL){
     			cout << "    argument matches " << Get_symbol_name(kid) << ":" << Get_symbol_name(_loop_data[i].wn_iter) << endl;
     		}
     		return TRUE;
     	}
     }
     //cout << "  argument [ " << Get_symbol_name(kid) << " ] has no match in iterators " << endl;
     return FALSE;  //no match with any iterator.
 }




 /////////////////////////////////////////////////////////////////////////////////
 //Pretty Printers

 /*-------------------------------------------------------------------------------
  * Returns the symbol name as a string (uses class' _var_name for storage)
  --------------------------------------------------------------------------------*/
 char *METHOD_INVARIANCE::Get_symbol_name(WN *wn) {

 	if (!wn) {
 		sprintf(_var_name, "NULL-WHIRL");
 	}
 	else if(!OPCODE_has_sym(WN_opcode(wn))){
 		sprintf(_var_name, "-no symbol- ");
 	}
 	else if(ST_class(WN_st_idx(wn)) == CLASS_PREG)
 		sprintf(_var_name, "PREG<%d>", WN_offset(wn));

 	else if (ST_class(WN_st_idx(wn)) == CLASS_VAR)
 		sprintf(_var_name, "VAR<%s>.offset=%d", ST_name(St_Table[WN_st_idx(wn)]),
 				WN_offset(wn));
 	else{
 		sprintf(_var_name, "%s.offset=%d", ST_name(St_Table[WN_st_idx(wn)]),
 				WN_offset(wn));
  	}
 	return _var_name;
 }

 /*-------------------------------------------------------------------------------
  *Prints the information gathered about the perfect loop nest
  --------------------------------------------------------------------------------*/
 void METHOD_INVARIANCE::Pretty_print_loop_nest_info( )
 {

 	if(_loop_nest_kind == MIV_LOOP_KIND_DO) cout << "do_loop ";
 	else if(_loop_nest_kind == MIV_LOOP_KIND_WHILE) cout << "while_loop ";
 	else FmtAssert( 0, ("invalid loop type "));

 	cout << " with iterators [";

 	for( int i = 0; i <= _loop_nest_depth ; i++ ){
 		if( i > 0) cout << ", "; cout << Get_symbol_name(_loop_data[i].wn_iter);
 	}
 	cout << endl;
 }

/*-------------------------------------------------------------------------------
 *Print result of call analysis
 --------------------------------------------------------------------------------*/
void METHOD_INVARIANCE::Pretty_print_call_analysis( )
{
	cout << "Loop body has the  following calls: " << endl;

	for( int i = 0; i < _no_of_calls; i++ )
	{
		WN *call_wn = _call_data[i].wn_call;
		cout << "     " << Get_symbol_name(call_wn) << ": ";

		if( _call_data[i].hoistable == TRUE)
		{
			cout << "hoistable." ;
			cout << " Variant at " << _call_data[i].variance_level
		    		<< " i.e. iterator " << Get_symbol_name( _loop_data[_call_data[i].variance_level].wn_iter);
		}else
			cout << "CANNOT be hoisted.";
		cout << endl;
	}
}

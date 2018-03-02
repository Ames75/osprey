/*-------------------------------------------------------------------------------
 * FILE  : ipo_mi_loop_det.cxx [Loop detection - simple LNO at IPA]
 * AUTHOR: JAVED ABSAR. Date 29th December 2011.
 *
 * THE ALGORITHM:
 *Certify that given do-loop is a perfect loop-nest. This means...
 *   1. loop headers are perfect
 *                                         [please refer: Is_doLoop_header_perfect]
 *   2. loop bodies are just one statement which is another do-loop
 *                                         [please refer:Is_doLoop_body_doLoop]
 *  3. innermost loop body is not inspected here.
 *Return  TRUE: if header is perfect and body (save innermost) is  just another
 *          do loop. Along with _loop_data info, _loop_depth, _loop_nest_body
 *Return FALSE: otherwise
  --------------------------------------------------------------------------------*/
#include "ipo_method_invariance.h"

 BOOL METHOD_INVARIANCE::Is_doLoop_perfect_nest(WN *in_loop)
 {
 	WN *loop = in_loop;
 	WN *wn_iter;

 	for( int i = 0; i < _loop_nest_limit; i++ )
 	{
 		if( Is_doLoop_header_perfect(loop, &wn_iter) == FALSE ) return FALSE;

 		_loop_data[i].wn_iter = wn_iter;
 		_loop_data[i].wn_loop = loop;

 		if( Is_doLoop_body_doLoop(loop) == FALSE ){
 			_loop_nest_body  = WN_do_body(loop);
 			_loop_nest_depth = i;

 			if( !Is_doLoop_body_clean()) return FALSE;    //no early exits or ifs
 			return TRUE;                                   //validity of body not checked here
 		}
 		loop = WN_first(WN_do_body(loop));                 //first & only statement in the loop
 	}
 	return FALSE;                                          //too deep - get lower
 }


/*-------------------------------------------------------------------------------
 *Certify do-loop header is perfect: [initialize:0, increment:1, compare:OPR_GT]
 *Need to add checks that i & N are not changed in the loop
 *Need to add check to ensure loop runs at least once (otherwise hoisting is wrong)
 *<other option is to have a single hoisted check - solution pursued here>
 *May make perfection-definition bit loose e.g. OPR_GE ?
 *RETURN : TRUE if header perfect, along with iterator in wn_iter
 --------------------------------------------------------------------------------*/
BOOL METHOD_INVARIANCE::Is_doLoop_header_perfect(WN *in_loop, WN **wn_iter){
	if (!in_loop || WN_operator(in_loop) != OPR_DO_LOOP)
		return FALSE;

	//INIT: i = 0
	WN *wn_start = WN_start(in_loop);
	if (!wn_start || WN_operator(wn_start) != OPR_STID || WN_kid_count(wn_start)!= 1 )
		return FALSE;

	WN *wn_const = WN_kid0(wn_start);
	if (!wn_const || WN_operator(wn_const) != OPR_INTCONST || WN_const_val(
			wn_const) != 0)
		return FALSE;

	*wn_iter = wn_start;                             //remember the iterator


	//INCREMENT i = i+1
	WN *wn_step = WN_step(in_loop);
	if (!wn_step || WN_operator(wn_step) != OPR_STID || !Are_variables_same(
			wn_step, *wn_iter) || WN_kid_count(wn_step) != 1)
		return FALSE;

	WN *wn_add = WN_kid0(wn_step);
	if (WN_operator(wn_add) != OPR_ADD || WN_kid_count(wn_add) != 2)
		return FALSE;

	WN *wn_ldid_i = WN_kid0(wn_add);
	wn_const      = WN_kid1(wn_add);
	if (WN_operator(wn_ldid_i) != OPR_LDID || !Are_variables_same(wn_ldid_i,
			*wn_iter) || WN_operator(wn_const) != OPR_INTCONST || WN_const_val(
			wn_const) != 1)
		return FALSE;

	//END COMPARATOR N > i
	WN *end_cond = WN_end(in_loop);
	if (!end_cond || WN_operator(end_cond) != OPR_GT  || WN_kid_count(end_cond) != 2 )
		return FALSE;

	WN *lhs = WN_kid(end_cond, 0);
	WN *rhs = WN_kid(end_cond, 1);

	if (!lhs || WN_operator(lhs) != OPR_LDID)
		return FALSE;//N
	if (!rhs || WN_operator(rhs) != OPR_LDID)
		return FALSE;//i

	if (Are_variables_same(rhs, *wn_iter) == FALSE)
		return FALSE;

	if (miv_msg_level >= MIV_MSG_LEVEL_ALL)
		cout << "do-loop header of " << Get_symbol_name(*wn_iter)  << " is good." << endl;
	return TRUE;
}


/*-------------------------------------------------------------------------------
 *Certify if do-loop-body is a single statement which is also do-loop
 *Why? This is requirement for do-loop perfect loop-nest definition
 *RETURN :  TRUE if body of do-loop is do-loop (no side effects for a change)
 --------------------------------------------------------------------------------*/
BOOL METHOD_INVARIANCE::Is_doLoop_body_doLoop(WN *in_loop)
{
	if( !in_loop || WN_operator(in_loop)!= OPR_DO_LOOP ) return FALSE;

	WN *wn_do_body = WN_do_body(in_loop);
	if (!wn_do_body || WN_operator(wn_do_body) != OPR_BLOCK)
		return FALSE;

	if (WN_first(wn_do_body) != WN_last(wn_do_body)) return FALSE;

	WN *stmt = WN_first(wn_do_body);
	if( !stmt || WN_operator(stmt)!= OPR_DO_LOOP )return FALSE;

	return TRUE;
}

/*-------------------------------------------------------------------------------
 * No labels or gotos. Probably this function needs enhancement/ more rigor.
 --------------------------------------------------------------------------------*/
BOOL METHOD_INVARIANCE::Is_doLoop_body_clean( )
{
	if(!_loop_nest_body || WN_operator(_loop_nest_body)!=OPR_BLOCK ) return FALSE;

	for (WN *stmt = WN_first(_loop_nest_body); stmt != NULL; stmt = WN_next(stmt)){
		switch(WN_operator(stmt)){
			case OPR_GOTO:
			case OPR_LABEL: return FALSE;
		}
	}
	return TRUE;
}


/*-------------------------------------------------------------------------------
  *The body should be series of calls followed by an expression. The details of
  * the calls and expression are not checked here.
  --------------------------------------------------------------------------------*/
 BOOL METHOD_INVARIANCE::Is_doLoop_body_good( )
 {
	 if(!_loop_nest_body || WN_operator(_loop_nest_body)!= OPR_BLOCK ) return FALSE;

	 WN *stmt, *first, *last;
	 stmt = first = WN_first(_loop_nest_body);
	 last = WN_last(_loop_nest_body);

	 if(!first || !last || (first == last))return FALSE; //must have at least 2 statements

	 _no_of_calls = 0;
	 while( stmt && (stmt!=last))
	 {
		 if( WN_operator(stmt) != OPR_CALL )return FALSE;
		 _call_data[_no_of_calls].wn_call = stmt;

		 stmt = WN_next(stmt);
		 if(!stmt || WN_operator(stmt)!= OPR_STID ) return FALSE;
		 if( WN_kid_count(stmt)!=1 || !WN_kid0(stmt) || WN_operator(WN_kid0(stmt)) != OPR_LDID ) return FALSE;

		 //check if the store is storing the return value (CLASS_PREG and PREG offset -1)
		 if ( (ST_class(WN_st_idx(WN_kid0(stmt)))!=CLASS_PREG) || (WN_offset(WN_kid0(stmt))!=-1) ){
                     if (miv_msg_level >= MIV_MSG_LEVEL_ALL)
			 cout << "STORE is not storing PREG -1 " << endl; 
                     return FALSE;
		 }

		 //check for return value missing
		 _call_data[_no_of_calls].wn_store = stmt;

		 _no_of_calls++;
		 stmt = WN_next(stmt);
	 }

	 if(!stmt || (stmt != last) || WN_operator(stmt) != OPR_ISTORE ) return FALSE;
	 _final_exp = stmt;
	 return TRUE;
}


/*-------------------------------------------------------------------------------
 * FILE  : ipo_miv_exp.cxx  [Helper class for METHOD_INVARIANCE]
 * AUTHOR: JAVED ABSAR. Date 29th December 2011.
 *
 * THE ALGORITHM:
 *  Converts a given expression to a canonical sum of product form. The expression
 *  is built from the equivalent whirl nodes. Each whirl variable in the original
 *  expression translates to a NODE_KIND_BASIC. The operators (MPY, ADD) translate
 *  to equivalent NODE_KIND.  The conversion to canonical form occurs through a
 *  process of distribution of multiplications. This is followed by sorting of the
 *  SOP using the variance as comparator. For example, in a loop nest [i,j,k]
 *  Original expression tree   : (a[i,j]*b[k]   + c[j]) * d[i] * e[k]
 *  After canonical translation: a[i,j]*b[k]*d[i]*e[k] + c[j]*d[i]*e[k]
 *  After sorting of canonical : d[i]*a[i,j]*b[k]*e[k] + d[i]*c[j]*e[k].
 *
 *  We use an interesting fixed-point algorithm for the canonical form conversion
 *  [please see Transform & Change]. The flattening [Flatten] rewrites the tree
 *  of nodes as an array of sum-of-product. This simplifies sorting and final
 *  generation of the expression tree.
 -------------------------------------------------------------------------------*/

#include "ipo_miv_exp.h"

/*-------------------------------------------------------------------------------
 *The leaves of the expression tree _nodes are all basic nodes. The basic
 * node has an equivalent WHIRL value or pointer used to reference a value.
 --------------------------------------------------------------------------------*/
int MIV_EXP::Create_basic_node(int vlevel, LOAD_TYPE ltype, WN *iload, WN* ldid, int call_id)
{
	NODE n;
	n.kind         				= NODE_KIND_BASIC;
	n.info.bi.vlevel            = vlevel;
	n.info.bi.ltype             = ltype;
	n.info.bi.iload             = iload;
	n.info.bi.ldid              = ldid;
	n.info.bi.call_id           = call_id;

	FmtAssert( (vlevel >=0), ("lhs_index is not in range") ); //random check

	_nodes.push_back(n);
	return _nodes.size()-1;
}

/*-------------------------------------------------------------------------------
 *For intermediate (arithmetic operations) nodes.
 --------------------------------------------------------------------------------*/
int MIV_EXP::Create_node(NODE_KIND k, int lhs_index, int rhs_index )
{
	FmtAssert( (lhs_index < _nodes.size()), ("lhs_index is not in range") ); //paranoia checks
	FmtAssert( (rhs_index < _nodes.size()), ("rhs_index is not in range") ); //prevents cycles too

	NODE n;
	n.kind         = k;
	n.info.ii.lhs_index    = lhs_index;
	n.info.ii.rhs_index    = rhs_index;

	_nodes.push_back(n);
	return _nodes.size()-1;
}

int MIV_EXP::Create_add_node( int lhs_index, int rhs_index){
	return Create_node(NODE_KIND_ADD, lhs_index, rhs_index);
}

int MIV_EXP::Create_mpy_node( int lhs_index, int rhs_index){
	return Create_node(NODE_KIND_MPY, lhs_index, rhs_index);
}



/*---------------------------------------------------------------
 * Keeps calling Change (which does the canonical transformation
 * till no change was applied (i.e. fixed point reached). This is
 * not most efficient way of SOP but for small sets its nice n easy.
 *--------------------------------------------------------------*/
BOOL MIV_EXP::Transform( int index){
	int i = 0;
	while(Change(index) == TRUE){ //fixed point iterator
		if(false){
			cout << "Transform step[" << i++ << "]: "; Pretty_print_exp_tree(index); cout << endl;
		}
	}
}
/*---------------------------------------------------------------
 * return TRUE if a (U+V)*X has been replaced by UX+VX
 *--------------------------------------------------------------*/
BOOL MIV_EXP::Change( int i)
{
	FmtAssert( (i <_nodes.size()), ("possibly logical error in exp transform") ); //paranoid about safety

	if(_nodes[i].kind == NODE_KIND_BASIC) return FALSE;             //report no change

	if(_nodes[i].kind == NODE_KIND_ADD ){
		if(Change(_nodes[i].left())) return TRUE;   //if changed, go back and iterate
		if(Change(_nodes[i].right())) return TRUE;   //if changed, go back and iterate
		return FALSE;
	}

	if(_nodes[i].kind == NODE_KIND_MPY ){
		int i_lhs = _nodes[i].left();
		int i_rhs = _nodes[i].right();
		if(_nodes[i_lhs].kind == NODE_KIND_ADD)
		{// (.A.+.B.) * i_rhs  ===> [(.A.)*i_rhs] + [(.B.)*i_rhs]
			int A = _nodes[i_lhs].left();
			int B = _nodes[i_lhs].right();

			int new_lhs = Create_mpy_node(A,i_rhs);
			int new_rhs = Create_mpy_node(B,i_rhs);

			_nodes[i].info.ii.lhs_index = new_lhs;
			_nodes[i].info.ii.rhs_index = new_rhs;
			_nodes[i].kind      = NODE_KIND_ADD;
			return TRUE;
		}
		else if(_nodes[i_rhs].kind == NODE_KIND_ADD)
		{// i_lhs*(.A.+.B.)  ===> [i_lhs*(.A.)] + [i_lhs*(.B.)]
			int A = _nodes[i_rhs].left();
			int B = _nodes[i_rhs].right();

			int new_lhs = Create_mpy_node(i_lhs,A);
			int new_rhs = Create_mpy_node(i_lhs,B);

			_nodes[i].info.ii.lhs_index = new_lhs;
			_nodes[i].info.ii.rhs_index = new_rhs;
			_nodes[i].kind      = NODE_KIND_ADD;
			return TRUE;
		}

		if(Change(i_lhs))return TRUE;              //something has changed, quit here for now
		if(Change(i_rhs))return TRUE;
		return FALSE;
	}
	FmtAssert( 0, ("corrupted logic in expression tree transformation") ); //paranoid about safety
}

/*---------------------------------------------------------------
 * Verify if the expression tree is in canonical SOP form
 * form:0 add, form:1 mpy. Only the transition 0 to 1 is valid
 *--------------------------------------------------------------*/
BOOL MIV_EXP::Verify_canonical_form( int i ){

	return Verify_cform(i, ((_nodes[i].kind == NODE_KIND_ADD )? 0: 1) );
}
BOOL MIV_EXP::Verify_cform( int i,int form )
{
	FmtAssert( (i <_nodes.size()), ("possibly logical error in exp transform") ); //paranoid about safety

	if(_nodes[i].kind == NODE_KIND_BASIC) return TRUE;             //no problem at leaves

	if(_nodes[i].kind == NODE_KIND_ADD ){
		if(form == 1)return FALSE;           // ADD after a MPY
		if(Verify_cform(_nodes[i].left(),0)  == FALSE) return FALSE;
		if(Verify_cform(_nodes[i].right(),0) == FALSE) return FALSE;
		return TRUE;
	}
	if(_nodes[i].kind == NODE_KIND_MPY ){
		if(Verify_cform(_nodes[i].left(),1 ) == FALSE) return FALSE;
		if(Verify_cform(_nodes[i].right(),1) == FALSE) return FALSE;
		return TRUE;
	}
	FmtAssert( 0, ("corrupted value in NODE_KIND") );
}


/*---------------------------------------------------------------
 *Copy the canonical tree, _nodes, as a sum of products
 *--------------------------------------------------------------*/
void MIV_EXP::Flatten(int index){
	Product p;
	FmtAssert((_sop.sum.size() == 0),("_sop.sum is stale"));
	_sop.sum.push_back(p);
	Flatten_recur(index,0);

}
void MIV_EXP::Flatten_recur(int index, int sum_index)
{
	NODE &n = _nodes[index];

	switch( n.kind )
	{
		case NODE_KIND_BASIC:
			_sop.sum[sum_index].prod.push_back(index);
			break;

		case NODE_KIND_MPY:
			Flatten_recur(n.left(), sum_index);
			Flatten_recur(n.right(), sum_index);
			break;
		case NODE_KIND_ADD:
		{	Product p;
		Flatten_recur(n.left(), sum_index);//reuse the sum_index
			_sop.sum.push_back(p);
			Flatten_recur(n.right(), _sop.sum.size()-1);
		}break;
		default: FmtAssert(0, ("error in logic of Flatten"));
	}
}

/*---------------------------------------------------------------
 *Sort the products by dependence level.
 *--------------------------------------------------------------*/
void MIV_EXP::Sort( )
{
	vector<Product> &sum = _sop.sum;
	for( int i = 0; i < sum.size(); i++){
		int j, k;
		vector<int> &prod = sum[i].prod;

		for( j = 0; j < prod.size(); j++)
			FmtAssert( (_nodes[ prod[j]].kind == NODE_KIND_BASIC), ("Can compare only basic nodes"));

		for( int j = 0; j < prod.size(); j++){
			for(  k = 0; k < prod.size(); k++ ){
				if( _nodes[ prod[j]].variance() < _nodes[ prod[k]].variance() ){
					int t = prod[j]; prod[j] = prod[k]; prod[k]=t;
				}
			}
		}
	}
}


/*---------------------------------------------------------------
 * Bit cryptic display to make long expressions readable
 *--------------------------------------------------------------*/
void MIV_EXP::Pretty_print_basic( NODE &n)
{
	FmtAssert( (n.kind == NODE_KIND_BASIC ), ("invalid index"));

	cout << "<" << n.info.bi.call_id << ".VL:" <<  n.variance();
	if(n.info.bi.ltype == LOAD_TYPE_LDID) cout << ",ld," ; else cout << ",il,";
	cout << "cid:" << n.info.bi.call_id << ">";
}

/*---------------------------------------------------------------
 * Convert the logical tree of "vector<NODE> _nodes" to tree info,
 * relying on basic node information to retrieve names of symbols
 *--------------------------------------------------------------*/
void MIV_EXP::Pretty_print_exp_tree( int index){
	 cout << " MIV_EXP expr-tree: "; Pretty_print_exp_recur(index); cout << endl;
}
void MIV_EXP::Pretty_print_exp_recur( int index)
{
	FmtAssert( (index < _nodes.size()), ("index out of bound"));
	NODE& n = _nodes[index];

	cout << "(";
	switch(n.kind){
		case NODE_KIND_BASIC: Pretty_print_basic(n);
		 	 break;
		case NODE_KIND_ADD:
			Pretty_print_exp_recur(n.left()); cout << " + ";
			Pretty_print_exp_recur(n.right());
			break;
		case NODE_KIND_MPY:
			Pretty_print_exp_recur(n.left()); cout << " * ";
			Pretty_print_exp_recur(n.right());
			break;
		default: FmtAssert( (0), ("invalid node type"));
	}
	cout << ")" ;
}

/*---------------------------------------------------------------
 * Pretty print the _sop sum of products information
 *--------------------------------------------------------------*/
void MIV_EXP::Pretty_print_sop()
{
	cout << "sum of products: ";
	vector<Product> &sum = _sop.sum;
	for( int i = 0; i < sum.size(); i++){
		vector<int> &prod = sum[i].prod;
		if( i>0) cout << " + ";
		for( int j = 0; j < prod.size(); j++) {
			Pretty_print_basic( _nodes[ prod[j]] );
			cout << "*";
		}
	}cout << endl;
}



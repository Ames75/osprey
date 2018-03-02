/* 
  Copyright (C) 2010 Advanced Micro Devices, Inc.  All Rights Reserved.

  Open64 is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License,
  or (at your option) any later version.

  Open64 is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
  02110-1301, USA.
*/

#ifndef simd_util_INCLUDED
#define simd_util_INCLUDED

#ifndef mempool_INCLUDED
#include "mempool.h"
#endif

#include <list>
// Forward declaration
//
class SIMD_EXPR;
class SIMD_EXPR_MGR;
class SIMD_VECTOR_CONF_BASE;
class SIMD_VECTOR_CONF;

/////////////////////////////////////////////////////////////////////////////////
//
//   Arch specific stuff are encapsulated by SIMD_VECTOR_CONF_BASE and 
//  SIMD_VECTOR_CONF.
//
//   TODO: it would be better to place these stuff in a separate header file
//
/////////////////////////////////////////////////////////////////////////////////
//
class SIMD_VECTOR_CONF_BASE {
public:
    // Does H.W support vectorization
    BOOL Arch_Has_Vect (void) const { return FALSE; } 

    // About SSE 
    //
    BOOL Is_SSE_Family (void)   const { return FALSE; }
    BOOL Is_MMX (void)   const { return FALSE; }
    BOOL Is_SSE (void)   const { return FALSE; }
    BOOL Is_SSE2 (void)  const { return FALSE; }
    BOOL Is_SSE3 (void)  const { return FALSE; }
    BOOL Is_SSE4a (void) const { return FALSE; }
    BOOL Is_SSSE3 (void) const { return FALSE; }
    BOOL Is_SSE41 (void) const { return FALSE; }
    BOOL Is_SSE42 (void) const { return FALSE; }

    INT Get_Vect_Byte_Size (void) const { return -1; }
    INT Get_Vect_Len_Given_Elem_Ty (TYPE_ID) const { -1; }
};

#ifdef TARG_X8664

class SIMD_VECTOR_CONF : public SIMD_VECTOR_CONF_BASE {
public:
    BOOL Arch_Has_Vect (void) const { return TRUE; }

    BOOL Is_MMX (void)   const { return Is_Target_MMX (); }
    BOOL Is_SSE (void)   const { return Is_Target_SSE (); }
    BOOL Is_SSE2 (void)  const { return Is_Target_SSE2 (); }
    BOOL Is_SSE3 (void)  const { return Is_Target_SSE3 (); }
    BOOL Is_SSE4a (void) const { return Is_Target_SSE4a (); }
    BOOL Is_SSSE3 (void) const { return Is_Target_SSSE3 (); }
    BOOL Is_SSE41 (void) const { return Is_Target_SSE41 (); }
    BOOL Is_SSE42 (void) const { return Is_Target_SSE42 (); }
    BOOL Is_SSE_Family (void) const {
        return Is_SSE () || Is_SSE2 () || Is_SSE3 () || 
               Is_SSE4a () || Is_SSSE3 () || Is_SSE41 () ||
               Is_SSE42 ();
    }

    INT Get_Vect_Byte_Size (void) const { return 16; }
    INT Get_Vect_Len_Given_Elem_Ty (TYPE_ID t) const 
        { return 16/MTYPE_byte_size(t);}
};

#else 

class SIMD_VECTOR_CONF : public SIMD_VECTOR_CONF_BASE;

#endif

extern SIMD_VECTOR_CONF Simd_vect_conf;

/////////////////////////////////////////////////////////////////////////////////
//
//   First of all, SIMD_EXPR is a container hosting vectorization related 
// informations. Among all these information, some can be derived directly from 
// the given WN expression itself; some need context. For instance, in 
// the following snippet, the vectorizable expression "(x * (INT32)sa2[i])" doesn't
// need to have 32 significant bits. However, the expression per se cannot reveal 
// this info, but the "contex" will help.
//
//    INT16 sa1[], sa2[]; INT32 x;
//    for (i = 0; i < N; i++) { sa1[i] = (INT16)(x * (INT32)sa2[i])
//
//   Since a SIMD_EXPR is not aware of the "context" it is in, it has to "derive" 
// information blindly, and imprecisely. The objects who have better knowledge 
// of the context should correct them properly.
//
//   Second, SIMD_EXPR is responsible for physically converting its corresponding
// scalar expression into vectorized form.
//
//////////////////////////////////////////////////////////////////////////////////
// 
class SIMD_EXPR {
public:
    friend class SIMD_EXPR_MGR;

    INT32 Get_Misalignment (void) { Is_True (FALSE, ("TBD")); return -1; } 

    INT32 Get_Vect_Len (void) const { return _vect_len; }
    INT32 Get_Vect_Elem_Byte_Sz (void) const { return _elem_sz; }

    BOOL Is_Invar (void) const { return _is_invar; }
    WN* Get_Wn (void) const { return _expr; } 

private:
    SIMD_EXPR (WN* expr);

    void Set_Elem_Sz (INT sz);

    WN* _expr;

    INT16 _vect_len;
    INT16 _elem_sz;
    INT16 _mis_align;

    BOOL _is_invar;
};

typedef mempool_allocator<SIMD_EXPR*> SIMD_EXPR_ALLOC;
typedef std::list<SIMD_EXPR*, SIMD_EXPR_ALLOC> SIMD_EXPR_LIST;


//////////////////////////////////////////////////////////////////////////////
//
//   SIMD_EXPR_MGR is to manage all SIMD_EXPRs of the loop being vectorized.
// Its duty includes:
//
//   - identify vectorizable expressions.
//   - allocate/free a SIMD_EXPR.
//   - collect statistical information of the SIMD_EXPRs under management
//
/////////////////////////////////////////////////////////////////////////////
//
class SIMD_EXPR_MGR {
public:
    SIMD_EXPR_MGR (WN* loop, MEM_POOL*);
    const SIMD_EXPR_LIST& Get_Expr_List (void) const { return _exprs; }

    // This func is provided for the time being.
    //
    void Convert_From_Lagacy_Expr_List (SCALAR_REF_STACK*); 

    inline UINT Get_Max_Vect_Len (void) const;
    inline UINT Get_Min_Vect_Len (void) const; 

private:
    MEM_POOL* _mp;
    WN* _loop;
    SIMD_EXPR_LIST _exprs;
    
    UINT16 _min_vect_len;
    UINT16 _max_vect_len;
};


//////////////////////////////////////////////////////////////////////////////
//     
//          Inline functions are defined here 
//
//////////////////////////////////////////////////////////////////////////////
//
inline UINT
SIMD_EXPR_MGR::Get_Max_Vect_Len (void) const {
    Is_True (_max_vect_len != 0, ("_max_vect_len isn't set properly"));
    return _max_vect_len; 
}

inline UINT
SIMD_EXPR_MGR::Get_Min_Vect_Len (void) const {
    Is_True (_min_vect_len != 0, ("_min_vect_len isn't set properly"));
    return _min_vect_len; 
}

//---------------------------------------------------------------------
// Graph Utility copied from ip_graph.h
//---------------------------------------------------------------------

/* ====================================================================
 *
 * VERTEX / EDGE / GRAPH : Directed graph implementation
 *
 * A GRAPH is a set of VERTEX objects, connected by a set of EDGE
 * objects.  These sets are implemented as a vector of VERTEXes and a
 * vector of EDGEs, with all references being indices into these
 * vectors.  The sets are allowed to grow (by adding VERTEXes or EDGEs)
 * or to shrink (by deleting them).  Growth may cause reallocation of
 * the vector.  To minimize reallocation cost, it is done in larger
 * chunks than necessary.  To avoid rearrangement of the data upon
 * deletion, the deleted VERTEX/EDGE is simply marked invalid.
 *
 * ====================================================================
 */

/* EDGE/VERTEX index types, and reserved index values: */
typedef mINT32 NODE_INDEX;
typedef mINT32 EDGE_INDEX;
#define INVALID_NODE_INDEX -1
#define INVALID_EDGE_INDEX -1

/* ====================================================================
 *
 * A VERTEX contains two singly-linked lists of EDGEs, one of EDGEs
 * starting at that VERTEX, and one of EDGEs ending at that VERTEX.  
 * Each list is represented in the VERTEX by the index of its first
 * element (NODE_from and NODE_to) and a count of its elements
 * (NODE_fcnt and NODE_tcnt).  An invalid (i.e. unused) VERTEX is
 * indicated by NODE_fcnt == INVALID_EDGE_INDEX.  The VERTEX also
 * contains a pointer NODE_user to additional data required by the
 * client derived graph. The level of a vertex is defined as the (max level
 * of the immediate successors of the vertex) + 1
 * ====================================================================
 */

template <class T>
struct NODE 
{
  typedef T USER_TYPE;

  USER_TYPE user;       /* user information */
  EDGE_INDEX from, to;  /* first edge from and to this vertex */
  EDGE_INDEX fcnt, tcnt;/* from/to counts                     */
  INT32 level;          /* level of the vertex                */
};

/* Field access macros: */
#define NODE_user(vertex)     ((vertex)->user)
#define NODE_from(vertex)     ((vertex)->from)
#define NODE_to(vertex)       ((vertex)->to)
#define NODE_fcnt(vertex)     ((vertex)->fcnt)
#define NODE_tcnt(vertex)     ((vertex)->tcnt)
#define NODE_level(vertex)    ((vertex)->level)

/* ====================================================================
 *
 * A EDGE contains two VERTEXes, its from VERTEX (EDGE_from) and its
 * to vertex (EDGE_to).  It contains links (indices) to the next edges
 * in the NODE_from list for its from VERTEX (EDGE_nfrom), and in the
 * NODE_to list for its to VERTEX (EDGE_nto).  It contains a flag
 * word containing attributes, and a pointer EDGE_user to additional
 * data required by the client derived graph.
 *
 * ====================================================================
 */

/* EDGE data structure: */

template <class T>
struct EDGE 
{
  typedef T USER_TYPE;
  typedef mUINT8 ETYPEX;

  USER_TYPE user;       /* user information     */
  NODE_INDEX from, to;  /* from and to vertices */
  EDGE_INDEX nfrom;     /* next edge from the from vertex */
  EDGE_INDEX nto;       /* next edge to the to vertex */
  ETYPEX etype;         /* edge type, i.e. is it a back edge resulting */
                        /* in a cycle: used to locate recursion  */
};

/* Field access macros: */
#define EDGE_user(edge)         ((edge)->user)
#define EDGE_from(edge)         ((edge)->from)
#define EDGE_to(edge)           ((edge)->to)
#define EDGE_nfrom(edge)        ((edge)->nfrom)
#define EDGE_nto(edge)          ((edge)->nto)
#define EDGE_etype(edge)        ((edge)->etype)

/* Flag access: */
#define EDGE_RECURSIVE 1
#define Set_EDGE_recursive(edge) (EDGE_etype(edge) |= EDGE_RECURSIVE)
#define EDGE_recursive(edge)     (EDGE_etype(edge) & EDGE_RECURSIVE)

/* ====================================================================
 *
 * A GRAPH is the top-level directed graph data structure.  For both
 * vertices and edges, it contains the number of VERTEX/EDGE structures
 * actually allocated (GRAPH_vmax, GRAPH_emax), the number of actual
 * VERTEX/EDGE components of the graph (GRAPH_vcnt, GRAPH_ecnt), the
 * number of free VERTEX/EDGE structures that are allocated and
 * available for use (GRAPH_vfree, GRAPH_efree), and the vector of
 * NODE_EDGE components (GRAPH_v, GRAPH_e).  It also contains the
 * root of the graph (GRAPH_root) and the memory pool to use for
 * allocation (GRAPH_m).
 *
 * ====================================================================
 */

struct GRAPH 
{
  typedef NODE<void*> NODE_TYPE;
  typedef EDGE<void*> EDGE_TYPE;

  NODE_INDEX vcnt;  /* NODE count              */
  NODE_INDEX vmax;  /* max vertices            */
  NODE_INDEX vfree; /* number of free vertices */

  EDGE_INDEX ecnt;  /* edge count              */
  EDGE_INDEX emax;  /* max edges               */
  EDGE_INDEX efree; /* number of free edges    */
 
  NODE_INDEX root;  /* root of the graph       */
  NODE_TYPE* v;	    /* list of vertices        */
  EDGE_TYPE* e;	    /* list of edges           */
  MEM_POOL *m;      /* mem pool                */

  GRAPH (MEM_POOL *pool) :
    vcnt(0), vmax(0), vfree(-1),
    ecnt(0), emax(0), efree(-1),
    root(INVALID_NODE_INDEX), v(0), e(0), m(pool)
  {}

  GRAPH (NODE_INDEX num_nodes, EDGE_INDEX num_edges, MEM_POOL* pool) :
    vcnt(0), vmax(num_nodes), vfree(0),
    ecnt(0), emax(num_edges), efree(0),
    root(INVALID_NODE_INDEX), m(pool)
  {
    Build();
  }

  void Build ();

  void Grow_Node_Array ();
  void Grow_Edge_Array ();

  NODE_INDEX Add_Node (void*);
  EDGE_INDEX Add_Edge (NODE_INDEX, NODE_INDEX, void*);

  void* Delete_Node (NODE_INDEX);
  void  Delete_Edge (EDGE_INDEX);

  BOOL Is_Node (NODE_INDEX node_index) const
  {
    return (node_index < vmax && 
            NODE_fcnt(&v[node_index]) != INVALID_NODE_INDEX);
  }

  INT32 Num_Preds (NODE_INDEX node_index) const 
  {
    return NODE_tcnt(&v[node_index]);
  }
  
  INT32 Num_Succs (NODE_INDEX node_index) const
  {
    return NODE_fcnt(&v[node_index]);
  }

  BOOL Is_Recursive_Edge (EDGE_INDEX edge_index) const
  {
    return EDGE_recursive(&e[edge_index]);
  }
    
  void Set_Edge_User (EDGE_INDEX edge_index, void *user)
  {
    EDGE_user(&e[edge_index]) = user;
  }

  void Set_Node_Level (NODE_INDEX idx, INT32 level) 
  {
    NODE_level(&v[idx]) = level;
  }

  INT32 Node_Level (NODE_INDEX idx) const
  {
    return NODE_level(&v[idx]);
  }

  NODE_TYPE *Nodes () const { return v; }
  EDGE_TYPE *Edges () const { return e; }
};


template <class NODE_USER, class EDGE_USER>
struct GRAPH_TEMPLATE : public GRAPH
{
  typedef NODE<NODE_USER> NODE_TYPE;
  typedef EDGE<EDGE_USER> EDGE_TYPE;

  GRAPH_TEMPLATE (MEM_POOL *p) : GRAPH (p) {}

  NODE_TYPE *Nodes () const { return (NODE_TYPE *) v; }
  EDGE_TYPE *Edges () const { return (EDGE_TYPE *) e; }

  NODE_USER Node_User (NODE_INDEX node_index) const 
  {
    FmtAssert(node_index != INVALID_NODE_INDEX, ("invalid node_index"));
    return NODE_user(&(Nodes()[node_index]));
  }

  EDGE_USER Edge_User (EDGE_INDEX edge_index) const
  {
    FmtAssert(edge_index != INVALID_EDGE_INDEX, ("invalid edge_index"));
    return EDGE_user(&(Edges()[edge_index]));
  }
};

/* Field access macros: */
#define GRAPH_vcnt(g)      ((g)->vcnt)
#define GRAPH_vmax(g)      ((g)->vmax)
#define GRAPH_vfree(g)     ((g)->vfree)
#define GRAPH_ecnt(g)      ((g)->ecnt)
#define GRAPH_emax(g)      ((g)->emax)
#define GRAPH_efree(g)     ((g)->efree)
#define GRAPH_root(g)      ((g)->root)
#define GRAPH_m(g)         ((g)->m)
#define GRAPH_v(g)         ((g)->Nodes())
#define GRAPH_v_i(g,index) ((g)->Nodes()[index])
#define GRAPH_e(g)         ((g)->Edges())
#define GRAPH_e_i(g,index) ((g)->Edges()[index])

/* Walk all the valid vertices in the graph g, using NODE_INDEX v: */
#define FOR_EACH_NODE(g,v)	\
	for ( v = 0; v < GRAPH_vmax(g); v++ )	\
	  if ( NODE_fcnt (&GRAPH_v_i(g,v)) != INVALID_NODE_INDEX )


/* ====================================================================
 *
 * NODE_ITER: Vertex iterator control struct
 *
 * This struct is used to control an iterator over vertices.
 *
 * ====================================================================
 */

class NODE_ITER 
{
private:
  GRAPH *g;             /* the graph */
  NODE_INDEX c_v;       /* the current vertex */
  EDGE_INDEX from_e;    /* from edge   */
  EDGE_INDEX to_e;      /* to edge     */
  EDGE_INDEX fcnt;      /* from count  */
  EDGE_INDEX nfrom;     /* next from edge */
  EDGE_INDEX tcnt;      /* to count      */
  EDGE_INDEX nto;       /* next to edges */
  EDGE_INDEX c_e;       /* current edge  */

public:
  NODE_ITER (GRAPH* graph, NODE_INDEX node_index) :
    g      (graph),
    c_v    (node_index),
    from_e (NODE_from(&(GRAPH_v(graph)[node_index]))),
    to_e   (NODE_to(&(GRAPH_v(graph)[node_index]))),
    fcnt   (NODE_fcnt(&(GRAPH_v(graph)[node_index]))),
    nfrom  (-1),
    tcnt   (NODE_tcnt(&(GRAPH_v(graph)[node_index]))),
    nto    (-1),
    c_e    (INVALID_EDGE_INDEX)
  {}

  NODE_INDEX First_Pred ();
  NODE_INDEX Next_Pred ();

  NODE_INDEX First_Succ ();
  NODE_INDEX Next_Succ ();
  
  EDGE_INDEX Current_Edge_Index() const { return c_e; }

};


/* ====================================================================
 *
 * DFN: Depth-first numbering graph traversal control struct
 *
 * This struct is used to store an ordering of the nodes in a graph, to
 * control traversal in a particular order.  It contains a vector of
 * the graph vertices in the traversal order (DFN_v_list), and the
 * indices of the first useful index in the vector (GRAV_first) and of
 * the index after the last useful index in the vector (DFN_end).
 *
 * ====================================================================
 */

struct DFN {
  INT32 first;
  INT32 end;
  NODE_INDEX* v_list;
};

/* Field access macros: */
#define DFN_first(d)      ((d)->first)
#define DFN_end(d)        ((d)->end)
#define DFN_v_list(d)     ((d)->v_list)
#define DFN_v_list_i(d,i) ((d)->v_list[i])

/* Trace a DFN ordering: */
extern void Print_DFN ( const FILE *, DFN * );

/* Construct a depth-first numbering of the given graph: */
extern DFN* Depth_First_Ordering ( GRAPH*, MEM_POOL * );

/* De-allocate a DFN ordering: */
extern void Free_DFN ( DFN *, MEM_POOL * );

#endif /* simd_util_INCLUDED */

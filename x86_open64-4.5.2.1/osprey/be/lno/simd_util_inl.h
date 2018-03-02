#ifndef simd_util_inl_INCLUDED
    #error simd_util_inl.h should be inclued only by simd_util.h
#endif

//////////////////////////////////////////////////////////////////////////////
//
//          Implementation of SIMD_EXPR_MGR
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

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
#ifndef if_conv_INCLUDED
#define if_conv_INCLUDED
#include "wn.h"
#include "lwn_util.h"
#include "lnoutils.h"
#include "lnopt_main.h"
#include "opt_du.h"
#include "glob.h"
#include "ir_reader.h"             // for fdump_tree
#include "config_lno.h"
#include "symtab_access.h"
#include "opt_points_to.h"
#include <map>
extern void If_Convert_Walk(WN* );

typedef std::map<TY_IDX,SYMBOL > DummyMapType;
typedef DummyMapType::iterator DummyMapIteratorType;
typedef std::string DummyNameType;

class If_Conversion{
private:    
    DummyMapType *_dummyMap;
    DummyNameType *_dummyName;
    MEM_POOL* _pool;
    bool _trace;
    bool If_Convertible_Store(WN *);
    bool If_Convertible_Store_Rhs(WN *);
    WN * Convert_To_Safe_Expr(WN *,WN *,WN *);
public:    
    If_Conversion(MEM_POOL *pool):_pool(pool){
        _dummyMap = CXX_NEW (DummyMapType, _pool);
        _dummyName = CXX_NEW (DummyNameType, _pool);
        _trace = Get_Trace(TP_LNOPT, TT_LNO_VERBOSE); 
    }
    ~If_Conversion(){ 
    }
    SYMBOL* FindDummyVarInMap(TYPE_ID type){ 
        if ( _dummyMap->empty())
            return NULL;
        DummyMapIteratorType dmapItr = _dummyMap->find(type);
        if ( dmapItr != _dummyMap->end() )
            return &((*dmapItr).second);
        else
            return NULL;
    }
    void CreateDummyVarInMap(TYPE_ID type){
        SYMBOL sym = Create_Stack_Symbol(GetDummyName(type),type);
        _dummyMap->insert(std::make_pair(type,sym));
    }    
    const char* GetDummyName(TYPE_ID type){
        char namestr[21];
        sprintf(namestr, "%s%d","_if_conv_dummy_var",type); 
        _dummyName->assign(namestr);
        return _dummyName->c_str();
    }   
    bool Tracing(){
        return _trace;
    }    
    void If_Convert(WN *);
    bool If_Convertible(WN *);
};    

#endif /* if_conv_INCLUDED */

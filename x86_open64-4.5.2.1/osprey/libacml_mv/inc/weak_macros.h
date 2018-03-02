
/*
*  (C) 2008-2009 Advanced Micro Devices, Inc. All Rights Reserved.
*
*  This file is part of AMD LibM 3.0.
*
*  AMD LibM 3.0 is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*
*  AMD LibM 3.0 is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public
*  License along with AMD LibM 3.0.  If not, see
*  <http://www.gnu.org/licenses/>.
*
*/

#ifndef __WEAK_MACROS_H__
#define __WEAK_MACROS_H__
.macro WEAK_MATH_LIB_ALIAS x,y
#   .weak \x
#   .set \x,\y
   .endm

.macro WEAK_ACML_LIB_ALIAS x,y
   .weak \x
   .set \x,\y
   .endm
#endif


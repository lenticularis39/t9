/*
 * --- GSMP-COPYRIGHT-NOTE-BEGIN ---
 * 
 * This copyright note is auto-generated by ./scripts/Create-CopyPatch.
 * Please add additional copyright information _after_ the line containing
 * the GSMP-COPYRIGHT-NOTE-END tag. Otherwise it might get removed by
 * the ./scripts/Create-CopyPatch script. Do not edit this copyright text!
 * 
 * GSMP: utility/include/TypeInformation.hh
 * General Sound Manipulation Program is Copyright (C) 2000 - 2004
 *   Valentin Ziegler and René Rebe
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2. A copy of the GNU General
 * Public License can be found in the file LICENSE.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANT-
 * ABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 * 
 * --- GSMP-COPYRIGHT-NOTE-END ---
 */


#ifndef UTILITY__TYPEINFORMATION_HH__
#define UTILITY__TYPEINFORMATION_HH__

#include <typeinfo>
#include <string>

namespace Utility
{
  // mangled typename, for typechecking use
  template <typename T>
  const char* SysTypeName ();

  // demangled Typename , for logging purposes
  template <typename T>
  std::string FilteredTypeName ();

  std::string FilteredName (const char* tname);
  std::string FilteredName (std::string& tname);
  
} // end namespace UTILITY


/* include template implementation */
#define UTILITY__TYPEINFORMATION_TMPL__
#include "template/TypeInformation.tcc"
#undef UTILITY__TYPEINFORMATION_TMPL__

#endif // UTILITY__TYPEINFORMATION_HH__

/*
 * --- GSMP-COPYRIGHT-NOTE-BEGIN ---
 * 
 * This copyright note is auto-generated by ./scripts/Create-CopyPatch.
 * Please add additional copyright information _after_ the line containing
 * the GSMP-COPYRIGHT-NOTE-END tag. Otherwise it might get removed by
 * the ./scripts/Create-CopyPatch script. Do not edit this copyright text!
 * 
 * GSMP: utility/include/Delete.hh
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

/* Short Description:
 *   Object delete function and functor - to help deleting objects e.g.
 *   with STL algorithms.
 */

#ifndef UTILITY__DELETE_HH__
#define UTILITY__DELETE_HH__

namespace Utility
{

  template <typename T>
  void DelFunction (T& del_obj) {
    delete del_obj;
    del_obj = 0;
  }

// to delete container of objects via for_each ...
  template <typename T>
  class DelFunctor
  {
  public:
    void operator () (T& del_obj) {
      DelFunction <T> (del_obj);
    }
  };
  
} // end namespace utility

#endif // UTILITY__DELETE_HH__

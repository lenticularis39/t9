/*
 * --- GSMP-COPYRIGHT-NOTE-BEGIN ---
 * 
 * This copyright note is auto-generated by ./scripts/Create-CopyPatch.
 * Please add additional copyright information _after_ the line containing
 * the GSMP-COPYRIGHT-NOTE-END tag. Otherwise it might get removed by
 * the ./scripts/Create-CopyPatch script. Do not edit this copyright text!
 * 
 * GSMP: utility/include/Limits.hh
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
 *   Numeric limit templates.
 */

#ifndef UTILITY__LIMITS_HH__
#define UTILITY__LIMITS_HH__

namespace Utility
{
  template <class U, class V>
  inline const U limit_min (const U& value, const V& min)
  {
    if (value < min) //__attribute__((unlikely))
      return min;
    else
      return value;
  };
  
  template <class U, class V>
  inline const U limit_max (const U& value, const V& max)
  {
    if (value > max) //__attribute__((unlikely))
      return max;
    else
      return value;
  };
  
  // should only be used when min < max ... !!
  template <class U, class V, class W>
  inline const U limit_min_max (const U& value, const V& min, const W& max)
  {
    // TODO: warn if debug and min > max !!
    if (value < min) //__attribute__((unlikely))
      return min;
    else if (value > max) //__attribute__((unlikely))
      return max;
    else
      return value;
  };
  
} // end namespace utility

#endif // UTILITY__LIMITS_HH__

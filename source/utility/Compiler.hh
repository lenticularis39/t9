/*
 * --- GSMP-COPYRIGHT-NOTE-BEGIN ---
 * 
 * This copyright note is auto-generated by ./scripts/Create-CopyPatch.
 * Please add additional copyright information _after_ the line containing
 * the GSMP-COPYRIGHT-NOTE-END tag. Otherwise it might get removed by
 * the ./scripts/Create-CopyPatch script. Do not edit this copyright text!
 * 
 * GSMP: utility/include/Compiler.hh
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
 *   Some compiler support stuff (e.g. macros) due to the limited
 *   and ongoing changing compilers ...
 */

#define GCC_VERSION (__GNUC__ * 10000 \
                              + __GNUC_MINOR__ * 100 \
                              + __GNUC_PATCHLEVEL__)

#define HAVE_GCC_VERSION(MAJOR, MINOR) \
  (__GNUC__ > (MAJOR) || (__GNUC__ == (MAJOR) && __GNUC_MINOR__ >= (MINOR)))


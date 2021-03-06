/*
 * --- GSMP-COPYRIGHT-NOTE-BEGIN ---
 * 
 * This copyright note is auto-generated by ./scripts/Create-CopyPatch.
 * Please add additional copyright information _after_ the line containing
 * the GSMP-COPYRIGHT-NOTE-END tag. Otherwise it might get removed by
 * the ./scripts/Create-CopyPatch script. Do not edit this copyright text!
 * 
 * GSMP: utility/include/Timer.hh
 * General Sound Manipulation Program is Copyright (C) 2000 - 2008
 *   Valentin Ziegler and René Rebe
 * Copyright (C) 2015 - 2016, Ren\xc3\xa9 Rebe, ExactCODE GmbH
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

/*
 * Alternatively, commercial licensing options are available from the
 * copyright holder ExactCODE GmbH Germany.
 */


/* Short Description:
 *   Some basic timer classes.
 */

#ifndef UTILITY__TIMER_HH__
#define UTILITY__TIMER_HH__

#ifndef _WIN32
#include <sys/time.h> // used by Timer
#include <sys/times.h> // used by TickTimer
#else
#include <sys/types.h>
#include <sys/timeb.h>
#endif

#include <stdint.h>

#include <iostream>
#include <string>

namespace Utility
{
  class Timer
  {
  public:
    Timer () { Reset (); }
    
    void Reset () { m_start = Value(); }
    uint64_t Delta () const { return Value() - m_start; }
    inline uint64_t PerSecond () const { return 1000000; }
    
    uint64_t Value () const {
#if !defined(_MSC_VER)
      timeval t_time;
      gettimeofday (&t_time, NULL);
      
      return (t_time.tv_sec * PerSecond()) + t_time.tv_usec;
#else
      struct timeb tb;
      ftime(&tb);
      return (uint64_t)tb.time * PerSecond() + tb.millitm * 1000;
#endif
    }
    
    const char* Unit () const { return "us"; }
  
  private:
    uint64_t m_start;
  };

#ifndef _WIN32
  class TickTimer
  {
  public:
    TickTimer ();
    
    void Reset ();
    uint64_t Delta () const;
    uint64_t PerSecond () const;
    
    uint64_t Value () const;
    
    const char* Unit () const { return "us"; }
    
  private:
    struct tms m_times;
  };
#endif
  
  class TimebaseTimer
  {
  public:
    TimebaseTimer ();
    
    void Reset ();
    uint64_t Delta () const;
    uint64_t PerSecond () const;
    
    uint64_t Value () const;

    const char* Unit () const { return "cycles"; }
    
  private:
    uint64_t start_tick;
  };

  template <typename T>
  class AutoTimer
  {
  public:
    AutoTimer (const std::string& i_text) {
      m_text = i_text;
    }
    ~AutoTimer () {
      std::cout << ">> AutoTimer: \"" << m_text
		<< "\" took: " << m_timer.Delta () << " " << m_timer.Unit () << std::endl;
    }
    
    uint64_t Delta () const {
      return m_timer.Delta ();
    }
    uint64_t PerSecond () const {
      return m_timer.PerSecond ();
    }
    
  private:
    T m_timer;
    std::string m_text;
  };
  
} // end namespace utility

#endif // UTILITY__TIMER_HH__

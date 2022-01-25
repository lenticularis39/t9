/*
 * --- GSMP-COPYRIGHT-NOTE-BEGIN ---
 * 
 * This copyright note is auto-generated by ./scripts/Create-CopyPatch.
 * Please add additional copyright information _after_ the line containing
 * the GSMP-COPYRIGHT-NOTE-END tag. Otherwise it might get removed by
 * the ./scripts/Create-CopyPatch script. Do not edit this copyright text!
 * 
 * GSMP: utility/src/Storage.cc
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

#include "Storage.hh"
#include "template/Storage.tcc"

#include <sstream>

using namespace Utility;

void Serializer::Add (BasicStorage* storage) {
  content [storage->name] = storage;
}

std::istream& Serializer::Read (std::istream& is, bool verbose) {
  char seperator = '=';
  
  std::vector<char> comments;
  comments.push_back (';');
  comments.push_back ('#');
    
  // TODO: error handling
  std::string line;
  while (std::getline (is, line)) {
      
    // strip comments
    for (std::vector<char>::iterator comment = comments.begin ();
	 comment != comments.end ();
	 ++comment)
      {
	std::string::size_type it = line.find (*comment);
	if (it != std::string::npos) {
	  line.erase (it, line.size () );
	}
      }
      
    // s.th. left to parse?
    if (line.size() > 0)
      {
	std::stringstream streamline (line);
	std::string key, sep, value;
	  
	streamline >> key >> sep;
	if (sep.size() == 1 && sep[0] == seperator) {
	    
	  std::map<std::string, BasicStorage*>::iterator it
	    = content.find (key);

	  if (it != content.end () ) {
	    it->second->Read(streamline);
	  }
	  else {
	    if (verbose)
	      std::cout << "Key " << key << " not registered!" << std::endl;
	  }
	}
	else {
	  if (verbose)
	    std::cout << "Parse error - no key found in line!" << std::endl;
	}
      }
  } // end while
    
    /* debug
       std::map<std::string, BasicStorage*>::iterator it;
       for (it = content.begin (); it != content.end(); ++it) {
       std::cout << "-> " << it->second->name << ": ";
       it->second->Write(std::cout) << std::endl;
       } */
  return is;
}

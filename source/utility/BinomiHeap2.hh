/*
 * --- GSMP-COPYRIGHT-NOTE-BEGIN ---
 * 
 * This copyright note is auto-generated by ./scripts/Create-CopyPatch.
 * Please add additional copyright information _after_ the line containing
 * the GSMP-COPYRIGHT-NOTE-END tag. Otherwise it might get removed by
 * the ./scripts/Create-CopyPatch script. Do not edit this copyright text!
 * 
 * GSMP: utility/include/BinomiHeap.hh
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

#ifndef BIN_HEAP_HH
#define BIN_HEAP_HH

#include <vector>

/************************************************************
 *
 * Binary heap of variable size
 *
 * Template with parameters
 *
 * ITEM_T         :   element type (references recommended)
 * KEY_T          :   key type
 * RANGE_CHECKING :   set to true to enable range checking etc.
 *
 * KEY_T has to provide following operators:
 * operator <
 * operator >
 * operator =
 * KEY_T (const KEY_T&)
 *
 * For easy element access, an ID handle of id_t will be
 * returned for each element inserted
 * 
 ***********************************************************/

// Exceptions (thrown when using range checking)

class InvalidIdException {};      // invalid ID handle
class HeapEmptyException {};      // ExtractMin called on emtpy heap
class InvalidKeyException {};     // DecreaseKey called with new key > old key


template <typename ITEM_T, typename KEY_T, bool RANGE_CHECKING>
class BinomiHeap
{
public:
  typedef unsigned int id_t;

  BinomiHeap ();
  ~BinomiHeap ();

  //******************* Heap operations ************************/

  id_t Insert (ITEM_T item, KEY_T key);

  // Extracts element with minimal key. Corresponding key will be
  // written to <val>.
  // may throw HeapEmtpyException if range checking enabled
  ITEM_T ExtractMin (KEY_T& val);

  // Decrease key of element with ID <id>.
  // will throw InvalidKeyException if range checking enabled and
  // new key > old key.
  // will throw InvalidIDException if element not in heap anymore
  void DecreaseKey (KEY_T new_key, id_t id);

  //********************* Information **************************/

  // return number of elements ever inserted.
  inline unsigned int TotalIDs ();

  // returns number of elements within the heap.
  inline unsigned int CurrentElements ();

  // maximum number of elements that have been in heap
  // simultaneously.
  inline unsigned int MaxElements ();

  // Heap empty ?
  inline bool Empty ();

  // current key of element with ID <id>
  // may throw InvalidKeyException if range checking enabled
  KEY_T GetKey (id_t id);

  // returns element with ID <id>
  // may throw InvalidKeyException if range checking enabled
  ITEM_T GetItem (id_t id);

  // tells wether element with ID <id> is still in heap
  // may throw InvalidKeyException if range checking enabled
  inline bool InHeap (id_t id);

  // ************************************************************/

private:

  class Node
  { // represents element entry
  public:
    ITEM_T item;
    KEY_T key;
    unsigned int map_position;  // associated with heap positions. equals to 0
                                // for elements not in heap anymore

    Node (ITEM_T i_item, KEY_T i_key, unsigned int insert_position)
    {
      item = i_item;
      key = i_key;
      map_position = insert_position;
    }
  };

  std::vector <Node> node_data; // contains node data;
  std::vector <unsigned int> heap; // binomical element ordering
  unsigned int cur_size;    // current heap usage (+1 for pseudo element at position 0)

  inline void DrownElement (unsigned int pos, KEY_T key);

  inline void ExchangeNodes (int i, int j);

  inline unsigned int LeftChildIndex (int index);
  inline unsigned int RightChildIndex (int index);
  inline unsigned int SmallestChildIndex (int index);
  inline unsigned int  MotherIndex (int index);

  inline void CheckId (id_t id);
  inline void CheckInQ (id_t id);

#ifdef HEAP_TESTING
public:
  void PrintHeap (unsigned int pos=1, unsigned int spaces=0);
#endif
};

// Implementationsschablone einbinden
#define BIN_HEAP_HH__
#include "template/BinomiHeap2.tcc"
#undef BIN_HEAP_HH__

#endif // BIN_HEAP_HH


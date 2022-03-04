//----------------------------------------------------------------------------
// HASHTABLE_H_
//----------------------------------------------------------------------------
// HashTable class is a class that will store a value connected 
// to a key making it easy to retrieve data
// The class:
// -- allows to insert data/books in the list with a key value
// -- allows to remove data from the list
// -- allows to find and retrieve data/object from the list 
// -- allows to check if it is empty
// -- allows to insert and remove as much as it is needed
//
// Implementation and Assumptions:
// -- The key value will be the index in the list
// -- The data will be the books or patrons and the key value its ID
//----------------------------------------------------------------------------
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <list>
//#include "media.h"

class HashTable
{
public:
  HashTable();
  bool Insert(int&);
  bool Remove(int&);        //these ints were nodeData, come change this later
  bool Retrieve(int*&, int&);
  bool isEmpty() const;
private:
  //list<Media*> hashTable;
};
#endif

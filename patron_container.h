//----------------------------------------------------------------------------
// PATRONCONTAINER_H_
//----------------------------------------------------------------------------
// PatronContainer class is a class that is used to store all patrons
// in a hashtable
// The class:
// -- allows to add a patron  in the hashtable
// -- allows to remove a patron from the hashtable
// -- allows to display one patron information
// -- allows to display all patron information stored
// 
// Implementation and Assumptions:
// -- Every patrons will have a name and an id
// -- There will not be any duplicates
//----------------------------------------------------------------------------
#ifndef PATRON_CONTAINER_H_
#define PATRON_CONTAINER_H_

#include "patron.h"
const int kMaxHashTableSize = 10;
class Patron;
class PatronContainer {
public:
  PatronContainer();
  //bool Remove(Patron* removePatron);  //return false if not in the hashTable 
  bool Insert(Patron* insertPatron); //return false for duplicate
  void displayPatron(Patron&) const;
  void displayAll() const;
  bool retrievePatron(int patronID, Patron*& retrievedPatron);

  private:
  //HashTable allPatrons;
	  struct Node {
		  Patron* patron = nullptr;//stored data in each node
		  Node* next = nullptr;// pointer to next node in list
	  };
	  /*Hashtable of all the patrons who are currently
	registered in the libraries system*/
	  Node* patrons[kMaxHashTableSize];
	  //Returns the table index of the patron
	  int hash(int patronID);
};
#endif

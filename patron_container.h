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
private:
    struct Node {
        Patron* patron = nullptr;//stored data in each node
        Node* next = nullptr;// pointer to next node in list
    };
public:
    PatronContainer();
    ~PatronContainer();
    bool Insert(Patron* insert_patron); //return false for duplicate
    bool retrievePatron(int patron_ID, Patron*& retrieved_patron);

private:
    void RemoveFront(Node* remove_node);

    /*Hashtable of all the patrons who are currently
  registered in the libraries system*/
    Node* patrons_[kMaxHashTableSize];
    //Returns the table index of the patron
    int hash(int patron_ID);
};
#endif

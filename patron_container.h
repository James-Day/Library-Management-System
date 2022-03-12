//----------------------------------------------------------------------------
// class
// PatronContainer: This class is a class that is used to store all patrons
//                  in a hashtable. allows for adding new patrons to the
//                  hashtable, and retrieving a patron from the hashtable.
// Implementation and Assumptions:
//      -- Every patrons will have a name and an ID
//      -- Patrons with duplicate ID's can not be created.
//      -- This class uses the Node struct to use chaining for the hashtable.
//      -- While this classes hashtable is still an amortized O(1) insert
//         and recieve, this hashtable will lose efficiency over time since
//         the chains will only grow. This could be made better in future work
//         by increasing the size of the array that the hashtable uses, and
//         rehashing stored patrons.
//----------------------------------------------------------------------------

#ifndef PATRON_CONTAINER_H_
#define PATRON_CONTAINER_H_

#include "patron.h"
// starting size of the hashtable
const int kMaxHashTableSize = 10;
class Patron;
class PatronContainer {
  private:
    struct Node {
        Patron *patron = nullptr; // stored data in each node
        Node *next = nullptr;     // pointer to next node in list
    };

  public:
    /* Constructor for Patron, initializes patron pointers in hashtable*/
    PatronContainer();

    /* Removes all patrons from the hashtable using RemoveFront*/
    ~PatronContainer();

    /* given a pointer to a Patron, this function will insert the pointer into
       the hash table. If a patron is added with the same ID then this function
       will return false, otherwise it will return true
    */
    bool Insert(Patron *insert_patron);

    /* given a patron ID and a pointer, this function will search for the
    patron within the hashtable. If the patron is found then true is returned
    and the retrievedPatron pointer (paramter) will be updated to the found
    patron*/
    bool retrievePatron(int patron_ID, Patron *&retrieved_patron) const;

  private:
    /* Helper function for the destructor that deletes the front node of
       given chain.*/
    void RemoveFront(Node *remove_node);

    /*Hashtable of all the patrons who are currently
  registered in the libraries system*/
    Node *patrons_[kMaxHashTableSize];

    // Returns the table index of the patron
    int hash(int patron_ID) const;
};
#endif

#include "patron_container.h"

//--------------------------------------------------------------------------
// PatronContainer (constructor)
/* Constructor for Patron, simply sets all the patron pointers in the
   hashtable to nullptr*/
PatronContainer::PatronContainer() {
    for (int i = 0; i < kMaxHashTableSize; i++) {
        patrons_[i] = nullptr;
    }
}
//--------------------------------------------------------------------------
// PatronContainer (destructor)
/* Removes all patrons from the hashtable by deleting the first patron
   in each chain of the hashtable*/
PatronContainer::~PatronContainer() {
    /*removes all patrons from the front of each index of the hashtable till
    till none remain*/
    for (int i = 0; i < kMaxHashTableSize; i++) {
        while (patrons_[i] != nullptr) {
            RemoveFront(patrons_[i]);
        }
    }
}
//--------------------------------------------------------------------------
// insert
/* given a pointer to a Patron, this function will insert the pointer into
   the hash table by hashing the Patrons ID then following the chain and
   placing the patron at the end of the chain. If a patron is added with the
   same ID then this function will return false, otherwise it will return true
   */
bool PatronContainer::Insert(Patron *insert_patron) {
    int hashed_ID = hash(insert_patron->getID());
    // head of the list for that index in the hashtable
    if (patrons_[hashed_ID] == nullptr) {
        Node *insert_node = new Node;
        insert_node->patron = insert_patron;
        insert_node->next = nullptr;
        patrons_[hashed_ID] = insert_node;
        return true;
    } else { // added into a list at the hashed index
        Node *cur = patrons_[hashed_ID];

        while (cur->next != nullptr) {
            if (cur->patron->getID() == insert_patron->getID()) {
                return false; // make sure no duplicate id
            }
            cur = cur->next;
        }
        if (cur->patron->getID() == insert_patron->getID()) {
            return false; // make sure last node is not a duplicate id
        }
        Node *insert_node = new Node;
        insert_node->patron = insert_patron;
        insert_node->next = nullptr;
        cur->next = insert_node;
        return true;
    }
}

//--------------------------------------------------------------------------
// removeFront
/* removes the first node of the chain. the chain that has it's first node
   removed is found by hashing the current nodes patrons ID*/
void PatronContainer::RemoveFront(Node *remove_node) {
    patrons_[hash(remove_node->patron->getID())] = remove_node->next;
    delete remove_node->patron;
    delete remove_node;
}

//--------------------------------------------------------------------------
// retrievePatron
/* given a patron ID and a pointer, this function will search for the patron
   within the hashtable. If the patron is found then true is returned and
   the retrievedPatron pointer (paramter) will be updated to the found
   patron*/
bool PatronContainer::retrievePatron(int patron_ID,
                                     Patron *&retrieved_patron) const {
    int hashed_ID = hash(patron_ID);
    // starts looking in the hashtable and looks through list
    Node *cur = patrons_[hashed_ID];
    while (cur != nullptr) {
        if (cur->patron->getID() == patron_ID) {
            retrieved_patron = cur->patron;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

//--------------------------------------------------------------------------
// hash
/* simple hash function, simply converts a patrons ID to the index that they
   will be stored in the hashtable*/
int PatronContainer::hash(int patronID) const {
    return patronID % kMaxHashTableSize;
}

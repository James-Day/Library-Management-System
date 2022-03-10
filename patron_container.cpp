#include "patron_container.h"

PatronContainer::PatronContainer()
{
    for (int i = 0; i < kMaxHashTableSize; i++) {
        patrons[i] = nullptr;
    }
}

bool PatronContainer::Insert(Patron* insertPatron)
{
    int hashedID = hash(insertPatron->getID());
    if (patrons[hashedID] == nullptr) {
        Node* insertNode = new Node;
        insertNode->patron = insertPatron;
        insertNode->next = nullptr;
        patrons[hashedID] = insertNode;
        return true;
    }
    else {
        Node* cur = patrons[hashedID];
       
        while (cur->next !=nullptr) {
            if (cur->patron->getID() == insertPatron->getID()) {
                return false;   //make sure no duplicate id
            }
            cur = cur->next;                                
        }
        if (cur->patron->getID() == insertPatron->getID()) {    
            return false;       //make sure no duplicate id
        }
        Node* insertNode = new Node;
        insertNode->patron = insertPatron;
        insertNode->next = nullptr;
        cur->next = insertNode;
        return true;
    }
    return false;
}

void PatronContainer::displayAll() const
{
    for (int i = 0; i < kMaxHashTableSize; i++) {
        if (patrons[i] != nullptr) {
            Node* cur = patrons[i];
            while (cur != nullptr) {
                cur->patron->displayPatron();
                cout << endl;
                cur->patron->displayBooks();
                cur = cur->next;
            }
        }
    }
}

bool PatronContainer::retrievePatron(int patronID, Patron*& retrievedPatron)
{
    int hashedID = hash(patronID);
    Node* cur = patrons[hashedID];
    while (cur!=nullptr) {
        if (cur->patron->getID() == patronID) {
            retrievedPatron = cur->patron;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

int PatronContainer::hash(int patronID)
{
    return patronID % kMaxHashTableSize;
}

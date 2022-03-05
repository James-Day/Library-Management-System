//----------------------------------------------------------------------------
// class Manager
// Implementation and assumptions:
//     -- Assume format of data file are correct
//     -- Handles the initialization of all books/media of the library
//     -- Handles the initialization of all patrons
//     -- Handles the initialziation of all book transactions
//     -- Allows to check out books for a patron
//     -- Allows to return books for a patron
//     -- Allows to display patron's transaction history
//     -- Allows to display entire library collection, sorted in categories
//----------------------------------------------------------------------------

#ifndef MANAGER_H_
#define MANAGER_H_

#include "patron_container.h"
#include "library.h"
#include "factory.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Manager {
public:
    Manager();                               // default constructor

    // checks out media for a patron
    bool checkOutMedia(Patron&, Media&);

    // returns a media for a patron
    bool returnMedia(Patron&, Media&);

    // prints the history of a patron's transaction history
    bool displayPatronHistory(Patron&) const;

    // prints the library books sorted in each category
    void displayLibrary() const;

    void inputMediaFile(const string infile);       // initializes books of library // This will be moved to a transaction class but for now it's fine
    void inputPatreonFile(const string infile);     // initializes patrons
    void inputTransactions(const string infile);    // initializes book transactions

private:
    Library library;
    PatronContainer patrons;
    Factory mediaFactory;
};
#endif

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
#include "media_factory.h"
#include "command_factory.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
class Manager {
public:
    Manager();                               // default constructor

    void inputMediaFile(const string infile);       // initializes books of library // This will be moved to a transaction class but for now it's fine
    void inputPatreonFile(const string infile);     // initializes patrons
    void inputTransactions(const string infile);    // initializes book transactions
    friend class CheckOut;
    friend class ReturnMedia;
    friend class DisplayLibrary;
    friend class PatronHistory;

private:
    Library library;
    PatronContainer patrons;
    MediaFactory mediaFactory;
    CommandFactory commandFactory;
};
#endif

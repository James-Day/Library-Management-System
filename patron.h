//----------------------------------------------------------------------------
// PATRON_H_
//----------------------------------------------------------------------------
// Patron class is a class that hold a patron information and all
// its books in a hashtable
// The class: 
// -- allows to create a patron object and store its information
// -- allows to store books in an hashtable
// -- allows to check out a book
// -- allows to get a book
// -- allows to display one or all books
//----------------------------------------------------------------------------
#ifndef PATRON_H_
#define PATRON_H_
#include <iostream>
#include <fstream>
#include <vector>
#include "media.h"
class Command;

class Patron
{
public:
    Patron();
    ~Patron();
    Patron(std::string patronName, std::string patronLastName, int id);
    bool checkOut(Media* checkingOut);//inserts Media into "allBooks" hashtable
   // HashTable& getBooks(); //return the hashtable with all the books
    Media* returnMedia(Media* returnBook); //return one book
    bool addHistory(const Command* history);

    bool create(ifstream& infile);
    void displayBooks() const;
    void displayPatron() const;
    void displayHistory() const;
    int getID();
private:
    /*Uses a hashtable to store a list of all the
      books a patron has checked out currently*/
      //change to a vector
    std::vector <Media*> all_books;
    //Command* transactionHistory[kMaxTransactionHistory];
    std::vector<const Command*> command_history_;
    std::string first_name_;
    std::string last_name_;
    int ID;
};

#endif
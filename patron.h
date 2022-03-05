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
#include "media.h"
const int kStartingBookLimit = 10;

class Patron
{
public:
    Patron(std::string patronName, std::string patronLastName, int id);
    bool checkOut(Media* checkingOut);//inserts Media into "allBooks" hashtable
   // HashTable& getBooks(); //return the hashtable with all the books
    Media* returnBook(Media* returnBook); //return one book

    void displayBooks() const;
    void displayPatron() const;
    int getID();
private:
    /*Uses a hashtable to store a list of all the
      books a patron has checked out currently*/
      // HashTable allBooks;
    Media* all_books[kStartingBookLimit];
    //Command* commandHistory[x];
    std::string firstName;
    std::string lastName;
    int ID;
};

#endif
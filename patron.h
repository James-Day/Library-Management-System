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

class Patron
{
public:
    Patron();
    Patron(std::string name, int id);
    bool checkOut(Media&);//inserts Media into "allBooks" hashtable
   // HashTable& getBooks(); //return the hashtable with all the books
    Media& getBook(Media&); //return one book

    // return the patron info (depending on programming style:  return bool or 
    // Patron)
    bool getPatron(Patron*&) const;

    void displayBooks() const;
    void displayPatron() const;
private:
    /*Uses a hashtable to store a list of all the
      books a patron has checked out currently*/
      // HashTable allBooks;
    std::string name;
    int ID;
};

#endif
// ---------------------------------------------------------------------------
// FictionBook: The FictionBook class is a subclass of the Book class.
//		Fiction books have a title, year, and number of copies from the
//		parent media class. Fiction book's also contains a author
//		for sorting the date within the library system.
//
// Implementation and assumptions:
//	 -- It is assumed that ever Fiction book will have an author
//	 -- It is assumed that the library will only hold 5 copies
//		of each Fiction book
//   -- Fiction books are sorted based on the author then the title
//   -- It is assumed that input format will be correct for creating
//      new Fiction Books
//   -- It is assumed that the operators will only be used for comparisons
//      between two Fiction books. Different types of books can not
//      be compared
//----------------------------------------------------------------------------

#ifndef FICTION_BOOK_H_
#define FICTION_BOOK_H_
#include "book.h"
#include <iostream>

// As of now all fiction books start with 5 books in the library
const int kNumFictionBooks = 5;

class FictionBook : public Book {
  public:
    // constructor for fiction book initializes all values of the fiction book
    FictionBook();

    // empty destructor to prevent memory leak
    virtual ~FictionBook();

    /*Overiden create function which creates a new FictionBook and
    returns it as a pointer */
    virtual Media *create(istream &infile);

    /*Overiden create function which creates a new Fiction Book from the
    command input file and returns it as a pointer */
    virtual Media *createFromCommand(istream &infile);

    // checkout function for removing one copy from the library
    virtual bool checkOut();

    // check in increases the count of this Fiction Book in the library by one
    virtual void checkIn();

    /*Overiden display function which displays the title, year, Author*/
    virtual void displayInLibrary() const;

    /* Used for displaying information of this fiction book in a patrons
    history*/
    virtual void displayInPatron() const;

    /*only displays the title of the Fiction Book
      This is useful specifically for error messages*/
    virtual void displayTitle() const;

    /*Displays all the components of Fiction Books.This is used as a header
      when displaying books in the library*/
    virtual void displayComponents() const;

    // less than overload for 2 Fiction Book objects
    virtual bool operator<(const Media &copy) const;

    // greater than overload for 2 Fiction Book objects
    virtual bool operator>(const Media &copy) const;

    // equals overload for 2 Fiction Book objects
    virtual bool operator==(const Media &copy) const;

    // not equals overload for 2 Fiction Book objects
    virtual bool operator!=(const Media &copy) const;

  private:
    // author of this FictionBook
    std::string author_;
};

#endif

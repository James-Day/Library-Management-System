// ---------------------------------------------------------------------------
// ChildrensBook: The ChildrensBook class is a subclass of the Book class.
//		Children's books have a title, year, and number of copies
//      from the parent book class. Children book's also contains a author
//		for sorting the date within the library system.
//
// Implementation and assumptions:
//	 -- It is assumed that ever childrens book will have an author
//	 -- It is assumed that the library will only hold 5 copies
//		of each childrens book (can be changed with kNumChildrensBooks)
//   -- It is assumed that input format will be correct for creating
//      new periodicals
//   -- It is assumed that the operators will only be used for comparisons
//      between two childrens books. Different types of books can not
//      be compared
//   -- Childrens books are sorted based on the title then the author
//----------------------------------------------------------------------------

#ifndef CHILDRENS_BOOK_H_
#define CHILDRENS_BOOK_H_
#include "book.h"
#include <fstream>
#include <iostream>

// For now all children books in the library will have five copies
const int kNumChildrenBooks = 5;
class ChildrensBook : public Book {
  public:
    /*constructor for childrens book initializes all values of the
    childrens book*/
    ChildrensBook();

    // empty destructor to prevent memory leak
    virtual ~ChildrensBook();

    /*Overiden create function which creates a new ChildrensBook and
    returns it as a pointer */
    virtual Media *create(istream &infile);

    /*Overiden create function which creates a new childrens book from the
    command input file and returns it as a pointer */
    virtual Media *createFromCommand(istream &infile);

    // checkout function for removing one copy from the library
    virtual bool checkOut();

    // check in increases the count of this childrens book in the library by one
    virtual void checkIn();

    /*Overiden display function which prints author, title, year*/
    virtual void displayInLibrary() const;

    /* Used for displaying information of this childrens book in a patrons
    history*/
    virtual void displayInPatron() const;

    /*only displays the title of the Childrens Book
      This is useful specifically for error messages*/
    virtual void displayTitle() const;

    /*Displays all the components of Childrens Books.This is used as a header
      when displaying books in the library*/
    virtual void displayComponents() const;

    // less than overload for 2 Childrens Book objects
    virtual bool operator<(const Media &copy) const;

    // greater than overload for 2 Childrens Book objects
    virtual bool operator>(const Media &copy) const;

    // equals overload for 2 Childrens Book objects
    virtual bool operator==(const Media &copy) const;

    // not equals overload for 2 Childrens Book objects
    virtual bool operator!=(const Media &copy) const;

  private:
    // author of this ChildrensBook
    std::string author_;
};

#endif

// ---------------------------------------------------------------------------
// class
// Book: The book class is a subclass of the media class and it is a base
//       class for different types of books. Books have a title, year of
//       publishing, and a number of copies in the library. This class
//       outlines the pure virtual functions that will be used for any type of
//       book.
//
// Implementation and assumptions:
//	 -- It is assumed that ever book will have a title, number of copies,
//and
//      a year of publishing.
//   -- The Media class is used for implementing the book subclass.
//----------------------------------------------------------------------------

#ifndef BOOK_H_
#define BOOK_H_
#include "media.h"
#include <iomanip>
#include <iostream>
#include <string>

// Constants used for displaying books
const int kMaxTitleLength = 36;
const int kMaxAuthorLength = 22;
const int kMaxYearLength = 4;
const int kMaxNumBooksLength = 4;
const int kDisplayIndentSize = 2;

class Book : public Media {
  public:
    /* Creates a media from the command input file, this allows for the media
    input file and the command input file to function seperately
    overwritten by all media subclasses and will return a pointer to
    a new media subclass object that is created*/
    virtual Media *createFromCommand(istream &infile) = 0;

    /*overwritten by all book subclasses and will return a pointer to
    a new media subclass object that is created*/
    virtual Media *create(istream &infile) = 0;

    /* When displaying the library this function is called to display this
       type of book*/
    virtual void displayInLibrary() const = 0;

    /* When displaying the patrons histories this function is called*/
    virtual void displayInPatron() const = 0;

    /* Simple function that displays the title or the name of the book to be
       used in error messages*/
    virtual void displayTitle() const = 0;

    // less than overload for 2 book objects
    virtual bool operator<(const Media &rhs) const = 0;

    // greater than overload for 2 book objects
    virtual bool operator>(const Media &rhs) const = 0;

    // equals overload for 2 book objects
    virtual bool operator==(const Media &rhs) const = 0;

    // not equals overload for 2 book objects
    virtual bool operator!=(const Media &rhs) const = 0;

    /*checkOut command to be overloaded by subclasses. This function
      decreases the count of books in the library*/
    virtual bool checkOut() = 0;

    /*checkOut command to be overloaded by subclasses. This function
      increases the count of books in the library*/
    virtual void checkIn() = 0;

  protected:
    /*Number of copies of this media in the library.*/
    int num_copies_ = 0;
    /*Year the media was published*/
    int year_ = 0;
    /*Title of the media*/
    std::string title_;
};

#endif

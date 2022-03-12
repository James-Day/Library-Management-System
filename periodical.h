// ---------------------------------------------------------------------------
// PeriodicalBook: The PeriodicalBook class is a subclass of the Book class.
//		Periodical books have a title, year, and number of copies from
//the 		parent media class. The Periodical class also contains a month 		for sorting
//the date within the library system.
//
// Implementation and assumptions:
//	 -- It is assumed that ever periodical will have a title
//	 -- It is assumed that the library will only hold 1 copies
//		of each periodical
//   -- it is assumed that ever Periodical will have a month and year of
//      publishing
//   -- Periodicals are sorted by year then month of publishing and then by
//      title
//   -- it is assumed that input is formated properly for creating periodicals
//   -- It is assumed that the operators will only be used for comparisons
//      between two Fiction books. Different types of books can not
//      be compared
//----------------------------------------------------------------------------

#ifndef PERIODICAL_BOOK_H_
#define PERIODICAL_BOOK_H_
#include "book.h"
#include <iomanip>
#include <iostream>
#include <string>

// For now all periodical books in the library will only have one copies
const int kNumPeriodicals = 1;
// max length of the month displayed
const int kMaxMonthLength = 4;

class Periodical : public Book {
  public:
    // constructor initializes all values for any periodical created
    Periodical();

    // empty destructor to prevent memory leak
    virtual ~Periodical();

    /*Overiden create function which creates a new Periodical and
    returns it as a pointer */
    virtual Media *create(istream &infile);

    /*Overiden create function which creates a new PeriodicalBook from the
    command input file and returns it as a pointer */
    virtual Media *createFromCommand(istream &infile);

    // checkout function for removing one copy from the library
    virtual bool checkOut();

    // check in increases the count of this periodical in the library by one
    virtual void checkIn();

    /*Overiden display function which displays the number of copies,
    title, year, month*/
    virtual void displayInLibrary() const;

    /*Overiden display function which displays the month, and year of
    publishing as well as the title of the periodical*/
    virtual void displayInPatron() const;

    /*overiden displayTitle which only displays the title of the periodical
      This is useful specifically for error messages*/
    virtual void displayTitle() const;

    /*Displays all the components of periodicals.This is used as a header
      when displaying books in the library*/
    virtual void displayComponents() const;

    // less than overload for 2 Periodical objects
    virtual bool operator<(const Media &copy) const;

    // greater than overload for 2 Periodical objects
    virtual bool operator>(const Media &copy) const;

    // equals overload for 2 Periodical objects
    virtual bool operator==(const Media &copy) const;

    // not equals overload for 2 Periodical objects
    virtual bool operator!=(const Media &copy) const;

  private:
    /*The month the periodical was published. When comparing dates, the year
    and the month will be used*/
    int month_;
};

#endif

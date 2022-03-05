#ifndef PERIODICAL_BOOK_H_
#define PERIODICAL_BOOK_H_
#include <iostream>
#include "book.h"
// ---------------------------------------------------------------------------
// PeriodicalBook: The PeriodicalBook class is a subclass of the Book class.
//		Periodical books have a title, year, and number of copies from the 
//		parent media class. The Periodical class also contains a month
//		for sorting the date within the library system.
// 
// Implementation and assumptions:
//	 -- It is assumed that ever Fiction book will have an author
//	 -- It is assumed that the library will only hold 5 copies 
//		of each Fiction book
// 
//For now all periodical books in the library will only have one copies
const int kNumPeriodicals = 1;
const int kMaxMonthLength = 4;

class Periodical : public Book {
public:
	Periodical();
	/*Overiden create function which creates a new PeriodicalBook and
	returns it as a pointer */
	virtual Media* create(istream& infile);
	virtual ~Periodical();

	virtual bool checkOut();						//I'm not sure if all of these still need to be virtual, I should check the internet and ask the prof in office hours
	virtual bool checkIn();

	/*Overiden display function which displays the title, year, month*/
	virtual void display() const;
	virtual bool operator< (const Media& copy) const;
	virtual bool operator> (const Media& copy) const;
	virtual bool operator== (const Media& copy) const;
	virtual bool operator!= (const Media& copy) const;

	void changevals(int months2, int year2, std::string title2, int copies);

private:
	/*The month the periodical was published.when comparing dates, the year
	and the month will be used*/
	int month;
};

#endif

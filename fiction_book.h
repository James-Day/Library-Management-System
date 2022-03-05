#ifndef FICTION_BOOK_H_
#define FICTION_BOOK_H_
#include <iostream>
#include "Book.h"
// ---------------------------------------------------------------------------
// FictionBook: The FictionBook class is a subclass of the Book class.
//		Fiction books have a title, year, and number of copies from the 
//		parent media class. Fiction book's also contains a author
//		for sorting the date within the library system.
// 
// 
// Implementation and assumptions:
//	 -- It is assumed that ever Fiction book will have an author
//	 -- It is assumed that the library will only hold 5 copies 
//		of each Fiction book
// 
// 
//For now all fiction books in the library will have five copies
const int kNumFictionBooks = 5;

class FictionBook : public Book {
public:
	FictionBook();
	/*Overiden create function which creates a new FictionBook and
	returns it as a pointer */
	virtual Media* create(istream& infile);
	virtual ~FictionBook();

	virtual bool checkOut();						//I'm not sure if all of these still need to be virtual, I should check the internet and ask the prof in office hours
	virtual bool checkIn();

	/*Overiden display function which displays the title, year, Author*/
	virtual void display() const;
	virtual bool operator< (const Media& copy) const;
	virtual bool operator> (const Media& copy) const;
	virtual bool operator== (const Media& copy) const;
	virtual bool operator!= (const Media& copy) const;


	void changevals(std::string author2, int year2, std::string title2, int copies);
private:
	std::string author;
};

#endif

#ifndef CHILDRENS_BOOK_H_
#define CHILDRENS_BOOK_H_
#include <iostream>
#include <fstream>
#include "Book.h"

// ---------------------------------------------------------------------------
// ChildrensBook: The ChildrensBook class is a subclass of the Book class.
//		Children's books have a title, year, and number of copies from the 
//		parent media class. Children book's also contains a author
//		for sorting the date within the library system.
// 
// Implementation and assumptions:
//	 -- It is assumed that ever childrens book will have an author
//	 -- It is assumed that the library will only hold 5 copies 
//		of each childrens book

//For now all children books in the library will have five copies
const int kNumChildrenBooks = 5;
class ChildrensBook: public Book {
public:
	ChildrensBook();
	/*Overiden create function which creates a new ChildrensBook and 
	returns it as a pointer */
	virtual Media* create(istream& infile);
	virtual ~ChildrensBook();

	virtual bool checkOut();						//I'm not sure if all of these still need to be virtual, I should check the internet and ask the prof in office hours
	virtual bool checkIn();

	/*Overiden display function which prints author, title, year*/
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

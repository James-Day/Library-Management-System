#ifndef BOOK_H_
#define BOOK_H_
#include <iostream>
#include "Media.h"
// ---------------------------------------------------------------------------
// Book: 
// 
// Implementation and assumptions:
//	

const int kMaxTitleLength = 36;
const int kMaxAuthorLength = 22;
const int kMaxYearLength = 4;
const int kMaxNumBooksLength = 4;

class Book : public Media {
public:
	virtual Media* create() = 0;
	virtual void display() const = 0;
	virtual bool operator< (const Media& rhs) const = 0;
	virtual bool operator> (const Media& rhs) const = 0;
	virtual bool operator== (const Media& rhs) const = 0;
	virtual bool operator!= (const Media& rhs) const = 0;

	virtual bool checkOut() = 0;
	virtual bool checkIn() = 0;

protected:
	/*Number of copies of this media in the library. When a patron checks out
	 a Media their media object will have 1 copy since that person only has
	 one copy */
	int numCopies = 0;
	/*Year the media was published*/
	int year = 0;
	/*Title of the media*/
	std::string title;
};

#endif

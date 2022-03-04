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

	//lowers the number of copies by 1, checkout is in the book class instead of the media class because if media was something 
	//like music, then maybe we wouldn't need to checkout we'd need to just download the mp3 file
	virtual bool checkOut() = 0;
	/*overwritten by all media subclassesand will return a pointer to
	a new media subclass object that is created*/
	virtual Media* create() = 0;

	 //I probablly will keep display pure virtual but maybe I'll wanna make the base classes call the parent display funciton??




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

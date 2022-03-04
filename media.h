#ifndef MEDIA_H_
#define MEDIA_H_
#include <iostream>
// ---------------------------------------------------------------------------
// Media: The Media class is a base class for media items that would be stored
//		  in a library's system. Media could be types of books, media, etc.
//		  Every media that is stored in the library will have a number of 
//		  copies, a year of publishing, and a title.
// 
// Implementation and assumptions:
//	 -- It is assumed that ever media will have a title and year of publishing
//	 -- This class can be used as a base class for any new media types that 
//		the library would like to hold.
//	 -- When a patron checks out some form of media, they will recieve a copy 
//		of the media object.
class Media {
public:
	/* No constructor for the media class?
	* 
	/*overwritten by all media subclassesand will return a pointer to
	a new media subclass object that is created*/
	virtual Media* create() =0;
	virtual void display() const =0;
	virtual bool operator< (const Media& rhs) const = 0;
	virtual bool operator> (const Media& rhs) const = 0;
	virtual bool operator== (const Media& rhs) const = 0;
	virtual bool operator!= (const Media& rhs) const = 0;


	
protected:
	//might add some data for media objects here
};

#endif

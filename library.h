#ifndef LIBRARY_H_
#define LIBRARY_H_
#include <iostream>
#include "media.h"
#include "bintree.h"

// ---------------------------------------------------------------------------
// Media: The Library class holds Media containers for each type of media.
//		  these containers hold all the different types of media that the
//		  library. Storage of new media types can be created and added to 
//			"containers" array.
// 
// Implementation and assumptions:
//	 -- For now it is assumed that there are only 3 types of media that can
//		be checked out in the library
//	 -- If the Library would like to add new types of Media, they will
//		also have to add a new container to hold those medias.
//	 -- for now 10 is used as the max numebr of medias that can be stored
//	    future work could grow the size of the array if too many media types
//		are added

//The maximum number of media types the library can have is 10 for now
const int MAXMEDIA = 10;

class Library{
public:
	//Calls constructors for each container for types of books / media

	Library() {
	//container for Children Books
	containers[0] = BinTree();
	//container for Fiction Books
	containers[1] = MediaContainer();
	//container for Periodical Books
	containers[2] = MediaContainer ();
		for (int i = 3; i < MAXMEDIA) {
			container[i] = NULL;
		}
	}
	//Calls destructors for each type of Media Container
	~Library();

	/*Inserts a new media object in the library, into the correct container
	for that type of media*/
	bool insert(const Media* aMedia);
	/*Completely remevoes a media from it's respective container given a 
	title of the media to be removed*/
	bool remove(const std::string title);

	/*Would check to see if the book is in the library, if it is in the
	library, then it will check if there are any copies in the library, 
	if there are copies then the number of copies in the library is reduced by
	one, and a copy of the book object with copies set to 1 is returned*/
	Media* checkOutMedia();

	/*would delete the Media object that is being returnedand increase the
	number of copies of the book object in the library by 1 */
	bool checkInMedia(Media* aMedia);

private:
	/*An array that hold all the containers for each type of media that is 
   stored in the library. There should be 1 container for each type of media*/
	BinTree containers[MAXMEDIA];
};

#endif
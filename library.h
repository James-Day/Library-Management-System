// ---------------------------------------------------------------------------
// Library: The Library class holds Binary Search trees for each type of media.
//		  these containers hold all the different types of media that
//the 		  library stores. Storage of new media types can be created and added
//        to "containers" array. Media can be checked in and out of the
//        library.
//
// Implementation and assumptions:
//	 -- For now it is assumed that there are only 3 types of media that can
//		be checked out in the library
//   -- New types of media(new BSTrees) can not be added without editing
//      library constructor and initializing an extra tree from there.
//	 -- If the Library would like to add new types of Media, they will
//		also have to add a new container to hold those medias.
//	 -- for now 26 is used as the max number of medias that can be stored
//	    future work could grow the size of the array if too many media types
//		are added
//----------------------------------------------------------------------------

#ifndef LIBRARY_H_
#define LIBRARY_H_
#include "bintree.h"
#include "media.h"
#include <iostream>

// The maximum number of media types the library can have is 26
const int kMaxMedia = 26;

class Library {
  public:
    // Calls constructors for each container for types of media we store
    Library();

    // Calls destructors for each bstree that stores a type of book.
    ~Library();

    /*Inserts a new media object in the library, into the correct container
    for that type of media*/
    bool insert(Media *insert_media, char book_type);

    /*checks to see if the book is in the library, if it is in the
    library, then it will check if there are any copies in the library*/
    Media *checkOutMedia(const Media *check_out_media, char book_type);

    /*would delete the Media object that is being returnedand increase the
    number of copies of the book object in the library by 1 */
    bool checkInMedia(Media *check_in_media, char book_type);

    /*displays each type of media in the library as well as all the media
    that is stored for each type of media*/
    void display() const;

  private:
    /*An array that hold all the containers for each type of media that is
   stored in the library. There should be 1 container for each type of media*/
    BinTree *containers_[kMaxMedia];

    // returns the index of the array to use for storing the book
    int hash(const char &type_media) const;
};
#endif

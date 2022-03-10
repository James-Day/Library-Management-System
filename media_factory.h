//----------------------------------------------------------------------------
// class Factory
// Factory: Creates proper Media object type accoordingly
// Implementation and assumptions:
//     -- Each character creates a different type of media
//     -- Stores an array of media pointers
//     -- Has a hash function for indexing character letter
//     -- Creates and returns the correct Media object according to the
//        character passed in, character indicates type of media
//----------------------------------------------------------------------------

#ifndef MEDIA_FACTORY_H_
#define MEDIA_FACTORY_H_

#include "media.h"
#include "fiction_book.h"
#include "childrens_book.h"
#include "periodical.h"
using namespace std;

const int kNumTypesOfBooks = 26;

class MediaFactory {
public:
    /*Constructor for factory, creates 1 of each type of media that is
    stored in the mediaFactor array*/
    MediaFactory();
    /*Deletes each of the media objects that are in the mediaFactory
    This will call Media destructor*/
     ~MediaFactory();                                                              

    /*uses a hash and mediaFactory to create the correct type of media from
    the command input file. This is different from reading from the media file
    which helps future proof this system so that command inputs and
    media inputs are not linked together.*/
     Media* createMediaFromCommand(const char& ch, istream& infile);

     /*uses hash and mediaFactory to create the correct type of media and
    returns a pointer to it. Takes a character to decide which type of media to
    create.*/
    Media* createMedia(const char& ch, istream& infile);
    void display();                                                                 // will delete

private:
    /* Holds one of each type of media to create new types of that media
    size is only large enough for one character codes
    characters(in the future if we want to have more than 26
    types of media we could create a method that grows the array)*/
    Media* mediaFactory[kNumTypesOfBooks];

    // returns the index of the array to use for creating the Media
    int hash(const char& ch) const;
};
#endif

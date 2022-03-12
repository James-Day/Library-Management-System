//----------------------------------------------------------------------------
// class MediaFactory
// MediaFactory: Given a type of Media, the media factory calls the respective
//               media's create command and the factory returns the new
//               respective media type that was created
// Implementation and assumptions:
//     -- Each character creates a different type of media
//     -- Stores an array of media pointers
//     -- Has a hash function for indexing character letter
//     -- Creates and returns the correct Media object according to the
//        character passed in, character indicates type of media
//     -- Currently only one character codes are usable, but longer codes
//        could be used in the future (the array storing command codes would
//        need to grow)
//----------------------------------------------------------------------------

#ifndef MEDIA_FACTORY_H_
#define MEDIA_FACTORY_H_

#include "childrens_book.h"
#include "fiction_book.h"
#include "media.h"
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

    /*uses a hash and the mediaFactory to create the correct type of media
    from the command input file. This is different from reading from the media
    file which helps future proof this system so that command inputs and
    media inputs are not linked together.*/
    Media *createMediaFromCommand(const char &media_type,
                                  istream &infile) const;

    /*uses hash and mediaFactory to create the correct type of media and
   returns a pointer to it. Takes a character to decide which type of media to
   create.*/
    Media *createMedia(const char &media_type, istream &infile) const;

  private:
    /* Holds one of each type of media to create new types of that media
    size is only large enough for one character codes
    characters(in the future if we want to have more than 26
    types of media we could create a method that grows the array)*/
    Media *media_factory_[kNumTypesOfBooks];

    // returns the index of the array to use for creating the Media
    int hash(const char &media_type) const;
};
#endif

// ---------------------------------------------------------------------------
// Media: The Media class is a base class for media items that would be stored
//		  in a library's system. Media could be types of books, music,
//etc.
//
// Implementation and assumptions:
//	    -- This class can be used as a base class for any new media types
//that 	       the library would like to hold.
//	    -- When a patron checks out some form of media, they will recieve a
//         pointer to the media object.
//      -- It is assumed that input if formated properly for crete and
//         createFromCommand
//----------------------------------------------------------------------------

#ifndef MEDIA_H_
#define MEDIA_H_
#include <iostream>
using namespace std;
class Media {
  public:
    /*overwritten by all media subclasses and will return a pointer to
    a new media subclass object that is created*/
    virtual Media *create(istream &infile) = 0;

    /* Creates a media from the command input file, this allows for the media
    input file and the command input file to function seperately
    overwritten by all media subclasses and will return a pointer to
    a new media subclass object that is created*/
    virtual Media *createFromCommand(istream &infile) = 0;

    /* the destructor for the media class currently has no code but
       is required to prevent memory leak */
    virtual ~Media() = 0;

    /* When displaying the library this function is called to display this
       type of media*/
    virtual void displayInLibrary() const = 0;

    /* when displaying the patrons histories this function is called*/
    virtual void displayInPatron() const = 0;

    /* simple function that displays the title or the name of the media to be
       used in error messages*/
    virtual void displayTitle() const = 0;

    /* displays the components that are stored for the media. This is used for
       displaying the books in the library*/
    virtual void displayComponents() const = 0;

    // less than overload for 2 media objects
    virtual bool operator<(const Media &rhs) const = 0;

    // greater than overload for 2 media objects
    virtual bool operator>(const Media &rhs) const = 0;

    // equals overload for 2 media objects
    virtual bool operator==(const Media &rhs) const = 0;

    // not equals overload for 2 media objects
    virtual bool operator!=(const Media &rhs) const = 0;

    // checkOut command to be overloaded by subclasses
    virtual bool checkOut() = 0;

    // checkOut command to be overloaded by subclasses
    virtual void checkIn() = 0;
};

#endif

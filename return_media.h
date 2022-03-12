//----------------------------------------------------------------------------
// class
// ReturnMedia: This class is a subclass of the command class and overloads
//                its create, display, and exectue functions. The execute
//                method of this class reads in the patrons ID and attempts
//                to find the book that is attempting to be returned. If the
//                media is found then it is removed from the patrons curently
//                checkout media
// Implementation and assumptions:
//      -- It is assumed that this command will be stored in the patron which
//         means that the patron is responsible for deleting this command
//         when it is no longer needed.
//      -- This class is a subclass of Command
//      -- the format of the input is assumed to be correct.
//----------------------------------------------------------------------------

#ifndef RETURN_MEDIA_H_
#define RETURN_MEDIA_H_

#include "command.h"
#include "media.h"
#include "patron.h"
using namespace std;

class ReturnMedia : public Command {
  public:
    /* the constructor for the returnMedia command subclass. Simply
    initializes the media returned*/
    ReturnMedia();

    /* ReturnMedia destructor needs no code for now*/
    virtual ~ReturnMedia();

    /* the ReturnMedia command is executed using the given manager and input
       file. The book given from the input file is searched for in the library
       and if found is checked out from the library as well as taken out of the
       patrons current checked out books */
    virtual bool execute(Manager *library_manager, istream &infile);

    /* displays this command and the book that was returned*/
    virtual void display() const;

    /* returns a new ReturnMedia command to the command factory*/
    virtual Command *create() const;

  private:
    /*media returned is a pointer to the media that was returned to the lbrary
    using this classes execute function*/
    Media *media_returned_ = nullptr;
};
#endif

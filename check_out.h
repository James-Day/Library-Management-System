//----------------------------------------------------------------------------
// class
// CheckOutMedia: This class is a subclass of the command class and overloads
//                its create, display, and exectue functions. The execute
//                method of this class reads in the patrons ID and attempts
//                to find the book that is attempting to be checked out.If the
//                media is found then it is added to the patrons curently
//                checkout media
// Implementation and assumptions:
//      -- It is assumed that this command will be stored in the patron which
//         means that the patron is responsible for deleting this command
//         when it is no longer needed.
//      -- This class is a subclass of Command
//      -- the format of the input is assumed to be correct.
//----------------------------------------------------------------------------

#ifndef CHECK_OUT_H_
#define CHECK_OUT_H_

#include "command.h"
#include "media.h"
#include "patron.h"
using namespace std;
class CheckOut : public Command {
  public:
    /* the constructor for the returnMedia command subclass. Simply
    initializes the media checked out*/
    CheckOut();

    /* ReturnMedia destructor needs no code for now*/
    virtual ~CheckOut();

    /* the checkOut command is executed using the given manager and input file.
       First. The book given from the input file is searched for in the
       library and if found is checked out from the library as well as stored
       in the patrons current checked out books */
    virtual bool execute(Manager *library_manager, istream &infile);

    /* displays this command and the book that was returned*/
    virtual void display() const;

    /* returns a new CheckOut command to the command factory*/
    virtual Command *create() const;

  private:
    /*pointer to the book that was checked out using this
    command's execute function*/
    Media *media_checked_out_;
};
#endif

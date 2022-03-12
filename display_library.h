//----------------------------------------------------------------------------
// class
// DisplayLibrary: This class is a subclass of the command class and overloads
//                its create, and exectue functions. The execute method
//                of this class calls the librarys display function found in
//                the given manager.
// Implementation and assumptions:
//      -- It is assumed that this command will not be stored anywhere
//         this means that once this command is executed, it will be deleted
//      -- This class is a subclass of Command
//      -- this class does not overload the display function because it is
//         assumed that this command will not be displayed anywhere including
//         the patrons history.
//----------------------------------------------------------------------------

#ifndef DISPLAY_LIBRARY_H_
#define DISPLAY_LIBRARY_H_

#include "command.h"
using namespace std;

class DisplayLibrary : public Command {
  public:
    /* currently this destructor holds no code but is neccesary to prevent
    memory leak*/
    virtual ~DisplayLibrary();

    /* calls the display function of the given managers library*/
    virtual bool execute(Manager *library_manager, istream &infile);

    /* simply creates and returns a new DisplayLibrary command*/
    virtual Command *create() const;
};
#endif

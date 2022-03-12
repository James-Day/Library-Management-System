//----------------------------------------------------------------------------
// class
// PatronHistory: This class is a subclass of the command class and overloads
//                its create, and exectue functions. The execute method
//                of this class reads in a patrons ID and finds their history
//                and displays it.
//
// Implementation and assumptions:
//      -- It is assumed that this command will not be stored anywhere
//         this means that once this command is executed, it will be deleted
//      -- This class is a subclass of Command
//      -- this class does not overload the display function because it is
//         assumed that this command will not be displayed anywhere including
//         the patrons history.
//----------------------------------------------------------------------------

#ifndef PATRON_HISTORY_H_
#define PATRON_HISTORY_H_

#include "command.h"
using namespace std;

class PatronHistory : public Command {
  public:
    /* the destructor needs no code for now*/
    virtual ~PatronHistory();

    /* This function executes the patron histroy command. If the given file
        contains a existing patron's ID, then their history is displayed.*/
    virtual bool execute(Manager *library_manager, istream &infile);

    // simply returns a new PatronHistory command to the command factory
    virtual Command *create() const;
};
#endif

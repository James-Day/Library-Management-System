//----------------------------------------------------------------------------
// class 
// patron: 
// Implementation and assumptions:
//     
//----------------------------------------------------------------------------

#ifndef PATRON_HISTORY_H_
#define PATRON_HISTORY_H_

#include "command.h"
using namespace std;

class PatronHistory : public Command {
public:

    virtual bool execute(Manager* libraryManager, istream& infile) const;
    virtual void display() const;                                                                 // will delete!

};
#endif

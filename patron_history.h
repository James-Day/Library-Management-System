//----------------------------------------------------------------------------
// class 
// patron: 
// Implementation and assumptions:
//     
//----------------------------------------------------------------------------

#ifndef RETURN_MEDIAW_H_
#define RETURN_MEDIA_H_

#include "command.h"
using namespace std;

class PatronHistory : Command {
public:

    virtual bool execute(Manager& libraryManager, istream& infile) const;
    virtual void display() const;                                                                 // will delete!

private:
};
#endif

//----------------------------------------------------------------------------
// class 
// CheckOut: 
// Implementation and assumptions:
//     
//----------------------------------------------------------------------------

#ifndef CHECK_OUT_H_
#define CHECK_OUT_H_

#include "command.h"
#include "media.h"
#include "patron.h"
using namespace std;
class CheckOut: Command {
public:

    virtual bool execute(Manager* libraryManager, istream& infile) const;
    virtual void display() const;                                                                 // will delete!

private:
};
#endif

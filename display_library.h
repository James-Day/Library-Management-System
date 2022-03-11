//----------------------------------------------------------------------------
// class 
// CheckOut: 
// Implementation and assumptions:
//     
//----------------------------------------------------------------------------

#ifndef DISPLAY_LIBRARY_H_
#define DISPLAY_LIBRARY_H_

#include "command.h"
using namespace std;

class DisplayLibrary : public Command {
public:
    virtual ~DisplayLibrary();

    virtual bool execute(Manager* libraryManager, istream& infile);
    virtual void display() const;                                                                 // will delete!
    virtual Command* create();

};
#endif

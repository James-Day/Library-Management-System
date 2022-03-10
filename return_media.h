//----------------------------------------------------------------------------
// class 
// ReturnMedia: 
// Implementation and assumptions:
//     
//----------------------------------------------------------------------------

#ifndef RETURN_MEDIA_H_
#define RETURN_MEDIA_H_

#include "command.h"
#include "media.h"
#include "patron.h"
using namespace std;

class ReturnMedia : public Command {
public:

    virtual bool execute(Manager* libraryManager, istream& infile) const;
    virtual void display() const;                                                                 // will delete!

};
#endif

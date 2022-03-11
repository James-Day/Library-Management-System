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
    ReturnMedia();
    virtual ~ReturnMedia();

    /* the checkOut command is executed using the given manager and input file.
       First the patron ID is read in and validated, then the type of media
       and format of media are read in and validated. The book given from the
       input file is searched for in the library and if found is checked out from
       the library as well as stored in the patrons current checked out books */
    virtual bool execute(Manager* library_manager, istream& infile);
    virtual void display() const;
    virtual Command* create();

private:
    Media* media_returned_ = nullptr;

};
#endif

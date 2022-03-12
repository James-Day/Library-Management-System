// ---------------------------------------------------------------------------
// HardCopy: The HardCopy class is a child class of Format. Hard copy
//           is a type of Format that will take a copy out of the library
//           when a media is checked out, and when returned a hard copy
//           will increase the number of copies in the library by one.
//
// Implementation and assumptions:
//      -- This class is implemented using the Format class as a base class.
//      -- Hard Copies use a media's checkIn and checkOut functions which
//         specify what to do if a physical version is taken in our out of the
//         library.
//----------------------------------------------------------------------------

#ifndef HARD_COPY_H_
#define HARD_COPY_H_
#include "format.h"
using namespace std;
class HardCopy : public Format {
  public:
    /* calls the media's checkOut function which indicate how to handle hard
   copy checkOuts. if the book is able to be checked out true is returned
   otherwise, false.*/
    virtual bool checkOutMedia(Media *check_out_media) const;

    /* calls the media's checkIn function which indicates how to handle
    hard copy returns*/
    virtual void returnMedia(Media *return_media) const;
};
#endif
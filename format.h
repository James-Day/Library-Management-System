// ---------------------------------------------------------------------------
// Format: The Format class is a base class for Format objects. Types of
//         Formats that are created will use this format class as a base class.
//         Each type of format must specify what to do when checking in or out
//         that type of media. For example hard copies may change the number
//         of copies of a book in the library, but a audio book won't.
//
// Implementation and assumptions:
//      -- It is assumed that every format class that is used in the library's
//         system will use this Format class as a base class.
//      -- it is assumed that every type of format will specify what to do
//         when checking out that type of format.
//      -- Each format class must also have a unique character specifier for
//         the format factory to use. ex: 'H' for hard copy
//----------------------------------------------------------------------------

#ifndef FORMAT_H_
#define FORMAT_H_
#include "media.h"
using namespace std;
class Format {
  public:
    /* calls the media's checkOut function which indicate how to handle this
   format of checkout. For example audio books don't need to remove a copy
   from the library, but hard copies might.*/
    virtual bool checkOutMedia(Media *check_out_media) const = 0;

    /* calls the media's checkIn function which indicates how to handle
    this type of format's return*/
    virtual void returnMedia(Media *return_media) const = 0;
};
#endif

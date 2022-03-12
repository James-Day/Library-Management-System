// ---------------------------------------------------------------------------
// FormatFactory: Given a type of Format, the format factory calls the
//                respective Format's checkOut or returnMedia function.
//                each format can specify what to do when checking in our out
//                that format of Media. For example a audio book does not need
//                to change the number of copies of a book in the library, but
//                a hard copy would.
//
// Implementation and assumptions:
//      -- Currently this factory can only contain 26 types of formats.
//      -- It is assumed that the formats in this factory will specify what
//         to do when checking out and returning a given media.
//      -- only one letter can be used for specifying a type of Format
//----------------------------------------------------------------------------

#ifndef FORMAT_FACTOR_H_
#define FORMAT_FACTOR_H_
#include "format.h"
#include "hard_copy.h"

// currently the max number of formats that can be stored in the factory is 26
const int kMaxNumTypes = 26;
class FormatFactory {
  public:
    /* the constructor for the format factory creates any formats that will be
   used.*/
    FormatFactory();

    /* the destructor for the format factory deletes any formats that are
    stored in the factory*/
    ~FormatFactory();

    /* uses the formats within the factory to call checkOutMedia which
   indicates what to do when checking out that format of media*/
    bool checkOut(Media *check_out_media, const char &type_ch) const;

    /*uses the formats within the factory to call returnMedia which
   indicates what to do when returning that format of media*/
    bool returnMedia(Media *return_media, const char &type_ch) const;

  private:
    /* Holds one of each format of media to create new formats of that media
    size is only large enough for one character codes
    characters(in the future if we want to have more than 26
    formats of media we could create a method that grows the array)*/
    Format *format_factory_[kMaxNumTypes];

    // returns the index of the array to use for creating the Media
    int hash(const char &type_format) const;
};
#endif
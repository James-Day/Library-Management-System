#ifndef TYPE_FACTOR_H_
#define TYPE_FACTOR_H_
#include "format.h"
#include "hard_copy.h"
const int kMaxNumTypes = 26;
class FormatFactory {
public:

    FormatFactory();

    ~FormatFactory();

    bool checkOut(Media* check_out_media, const char& type_ch);
    bool returnMedia(Media* return_media, const char& type_ch);

private:
    /* Holds one of each type of media to create new types of that media
    size is only large enough for one character codes
    characters(in the future if we want to have more than 26
    types of media we could create a method that grows the array)*/
    Format* format_factory_[kMaxNumTypes];

    // returns the index of the array to use for creating the Media
    int hash(const char& ch) const;
};
#endif
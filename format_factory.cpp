#include "format_factory.h"

//--------------------------------------------------------------------------
// formatFactory (constructor)
/* the constructor for the format factory creates any formats that will be
   used. There is currently no way to add new format types but this could
   be added in the future*/
FormatFactory::FormatFactory() {
    // Initialize all entries in our factory to nullptr
    for (int i = 0; i < kMaxNumTypes; i++) {
        format_factory_[i] = nullptr;
    }
    // HARD coded types of Formats that are in the factory
    format_factory_[hash('H')] = new HardCopy();
}

//--------------------------------------------------------------------------
// formatFactory (destructor)
/* the destructor for the format factory deletes any formats that are stored
   inthe factory*/
FormatFactory::~FormatFactory() {
    // Deletes all the format objects that we have in our factory
    for (int i = 0; i < kMaxNumTypes; i++) {
        if (format_factory_[i] != nullptr) {
            delete format_factory_[i];
        }
    }
}

//--------------------------------------------------------------------------
// checkOut
/* uses the formats within the factory to call checkOutMedia which
   indicates what to do when checking out that format of media
   for example if a hard copy is checked out then we need to decrease the
   number of copies of a book in the library, but if a digital copy is
   returned then we don't need to do much*/
bool FormatFactory::checkOut(Media *check_out_media,
                             const char &type_ch) const {
    // if the given format exists
    if (format_factory_[hash(type_ch)] != nullptr) {
        // Calls the checkout function of the format type
        return format_factory_[hash(type_ch)]->checkOutMedia(check_out_media);
    }
    cout << "Checkout Error: invalid format type '" << type_ch << "'" << endl;
    return false;
}

//--------------------------------------------------------------------------
// returnMedia
/* uses the formats within the factory to call returnMedia which
   indicates what to do when returning that format of media
   for example if a hard copy is returned then we need to increase the
   number of copies of a book in the library, but if a digital copy is
   returned then we don't need to do much*/
bool FormatFactory::returnMedia(Media *return_media,
                                const char &type_ch) const {
    // if the given format exists
    if (format_factory_[hash(type_ch)] != nullptr) {
        // Calls the return function of the format type
        format_factory_[hash(type_ch)]->returnMedia(return_media);
        return true;
    }
    cout << "Checkout Error: invalid format type '" << type_ch << "'" << endl;
    return false;
}

//--------------------------------------------------------------------------
// hash
/* simple hash function that converts the character for type of format
   to a integer for indexing into the format factory*/
int FormatFactory::hash(const char &ch) const { return ch - 'A'; }

#include "media_factory.h"
//--------------------------------------------------------------------------
// MediaFactory (constructor)
/* the constructor for the Media factory creates any Media types that will be
   used. There is currently no way to add new Media types but this could
   be afuture work*/
MediaFactory::MediaFactory() {
    for (int i = 0; i < kNumTypesOfBooks; i++) {
        media_factory_[i] = nullptr;
    }
    media_factory_[hash('F')] = new FictionBook();
    media_factory_[hash('C')] = new ChildrensBook();
    media_factory_[hash('P')] = new Periodical();
}

//--------------------------------------------------------------------------
// MediaFactory (destructor)
/* the destructor for the media factory deletes any media that are stored in
   the factory*/
MediaFactory::~MediaFactory() {
    for (int i = 0; i < kNumTypesOfBooks; i++) {
        if (media_factory_[i] != nullptr) {
            delete media_factory_[i];
        }
    }
}
//--------------------------------------------------------------------------
// createMediaFromCommand
/* This function is much like createMedia except is tailored to the format
   that books are given for commands. The Character is hashed to find the
   index in which this type of media is stored in the factory. Then the
   specified type of media is created using the already existing media in the
   factory. Inputs will be taken from the infile*/
Media *MediaFactory::createMediaFromCommand(const char &ch,
                                            istream &infile) const {
    int factory_index = hash(ch);

    // invalid characters for creating a media
    if ((factory_index > 25 || factory_index < 0) ||
        (media_factory_[factory_index] == nullptr)) {
        return nullptr;
    }
    return media_factory_[factory_index]->createFromCommand(infile);
}

//--------------------------------------------------------------------------
// createMedia
/* This function takes a character and an input file stream to create a new
   media. The Character is hashed to find the index in which this type of
   media is stored in the factory. Then the specified type of media is created
   using the already existing media in the factory. Inputs will be taken from
   the infile*/
Media *MediaFactory::createMedia(const char &ch, istream &infile) const {
    int factory_index = hash(ch);

    // invalid characters for creating a media
    if ((factory_index > 25 || factory_index < 0) ||
        (media_factory_[factory_index] == nullptr)) {
        return nullptr;
    }
    return media_factory_[factory_index]->create(infile);
}

//--------------------------------------------------------------------------
// hash
/* simple hash function that converts the character for type of media
   to a integer for indexing into the media factory*/
int MediaFactory::hash(const char &media_type) const {
    return media_type - 'A';
}

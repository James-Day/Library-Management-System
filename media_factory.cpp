#include "media_factory.h"
MediaFactory::MediaFactory()
{
    for (int i = 0; i < kNumTypesOfBooks; i++) {
        mediaFactory[i] = nullptr;
    }
    //FictionBook* a1 = new FictionBook();
    mediaFactory[hash('F')] = new FictionBook();
    mediaFactory[hash('C')] = new ChildrensBook();      //Not sure if this is allowed, I should ask prof during office hours
    mediaFactory[hash('P')] = new Periodical();
}

MediaFactory::~MediaFactory()
{
    for (int i = 0; i < kNumTypesOfBooks; i++) {
        if (mediaFactory[i] != nullptr) {
            delete mediaFactory[i];
        }
    }
}

Media* MediaFactory::createMediaFromCommand(const char& ch, istream& infile)
{
    int factoryIndex = hash(ch);
    if ((factoryIndex > 25 || factoryIndex < 0) || (mediaFactory[factoryIndex] == nullptr)) {
        return nullptr;
    }
    return mediaFactory[factoryIndex]->createFromCommand(infile);
}

Media* MediaFactory::createMedia(const char& ch , istream& infile)
{
    int factoryIndex = hash(ch);
    if ( (factoryIndex > 25 || factoryIndex < 0) || (mediaFactory[factoryIndex] == nullptr)) {
        return nullptr;
    }
    return mediaFactory[factoryIndex]->create(infile);
}

void MediaFactory::display()
{
    mediaFactory[hash('C')]->displayInLibrary();
    cout << endl;
    mediaFactory[hash('F')]->displayInLibrary();                                         //will have to remove this later
    cout << endl;   
    mediaFactory[hash('P')]->displayInLibrary();
    cout << endl;
}

int MediaFactory::hash(const char& ch) const
{
    return ch - 'A'; 
}

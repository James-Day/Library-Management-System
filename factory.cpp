#include "factory.h"
Factory::Factory()
{
    for (int i = 0; i < kNumTypesOfBooks; i++) {
        mediaFactory[i] = nullptr;
    }
    //FictionBook* a1 = new FictionBook();
    mediaFactory[hash('F')] = new FictionBook();
    mediaFactory[hash('C')] = new ChildrensBook();      //Not sure if this is allowed, I should ask prof during office hours
    mediaFactory[hash('P')] = new Periodical();
}

Factory::~Factory()
{
    for (int i = 0; i < kNumTypesOfBooks; i++) {
        if (mediaFactory[i] != nullptr) {
            delete mediaFactory[i];
        }
    }
}

Media* Factory::createMedia(const char& ch , istream& infile)
{
    int factoryIndex = hash(ch);
    if ( (factoryIndex > 25 || factoryIndex < 0) || (mediaFactory[factoryIndex] == nullptr)) {
        return nullptr;
    }
    return mediaFactory[factoryIndex]->create(infile);
}

void Factory::display()
{
    mediaFactory[hash('C')]->display();
    cout << endl;
    mediaFactory[hash('F')]->display();                                         //will have to remove this later
    cout << endl;   
    mediaFactory[hash('P')]->display();
    cout << endl;
}

int Factory::hash(const char& ch) const
{
    return ch - 'A'; 
}

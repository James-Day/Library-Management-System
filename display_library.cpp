#include "display_library.h"
#include "manager.h"

DisplayLibrary::~DisplayLibrary()
{
    //nothing for now
}

bool DisplayLibrary::execute(Manager* libraryManager, istream& infile)
{
    libraryManager->library.display();
    /*unlike other commands this command must be deleted since it is not stored anywhere*/
    delete this;
    return true;
}

void DisplayLibrary::display() const
{
    //This type of command will never be displayed so this 
    //function will do nothing 
}

Command* DisplayLibrary::create()
{
    return new DisplayLibrary;
}

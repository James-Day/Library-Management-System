#include "display_library.h"
#include "manager.h"

bool DisplayLibrary::execute(Manager* libraryManager, istream& infile) const
{
    libraryManager->library.display();
    return true;
}

void DisplayLibrary::display() const
{
}

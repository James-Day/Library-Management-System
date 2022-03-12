#include "display_library.h"
#include "manager.h"

//--------------------------------------------------------------------------
// DisplayLibrary (destructor)
/* currently this destructor holds no code but is neccesary to prevent memory
leak*/
DisplayLibrary::~DisplayLibrary() {
    // nothing for now
}

//--------------------------------------------------------------------------
// execute
/* calls the display function of the given managers library*/
bool DisplayLibrary::execute(Manager *library_manager, istream &infile) {
    library_manager->library_.display();
    /*unlike other commands this command must be deleted since it is not
    stored anywhere*/
    delete this;
    return true;
}
//--------------------------------------------------------------------------
// create
/* simply creates and returns a new DisplayLibrary command*/
Command *DisplayLibrary::create() const { return new DisplayLibrary; }

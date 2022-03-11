#include "patron_history.h"
#include "manager.h"

//--------------------------------------------------------------------------
// PatronHistory (destructor)
/* the destructor needs no code for now*/
PatronHistory::~PatronHistory()
{
    //nothing for now
}
//--------------------------------------------------------------------------
// execute 
/* This function executes the patron histroy command. A patron ID will be
   read in from a file and then will be searched for. If the patron is found
   then all of their histories will be displayed.*/
bool PatronHistory::execute(Manager* libraryManager, istream& infile)
{
    int patron_ID = 0;
    //read in patronID
    infile >> patron_ID;
    if (patron_ID == 0) {
        cout << "No Patron ID was given";
        return false;
    }
    //search manager patron container
    Patron* find_patron = nullptr;
    if (!libraryManager->patrons.retrievePatron(patron_ID, find_patron)) {
        cout << "Patron was not found with ID " << patron_ID;
        return false;
    }
    //display the patron then all their history
    find_patron->displayPatron();
    find_patron->displayHistory();

    //once this command is executed it must be deleted unlike other commands
    delete this;
    return true;
}

//--------------------------------------------------------------------------
// display 
/* displays this command, currently this command doesn't need to be displayed*/
void PatronHistory::display() const
{
    //display not used for this this command subclass
}

//--------------------------------------------------------------------------
// create 
/* simply returns a new PatronHistory command to the command factory*/
Command* PatronHistory::create()
{
    return new PatronHistory;
}

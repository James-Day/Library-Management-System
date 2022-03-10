#include "patron_history.h"
#include "manager.h"
bool PatronHistory::execute(Manager* libraryManager, istream& infile) const
{
    int patronID = 0;
    //read in patronID
    //search manager patroncontainer
    Patron* findPatron = nullptr;
    if (!libraryManager->patrons.retrievePatron(patronID, findPatron)) {
        cout << "Patron was not found with ID " << patronID;
        return false;
    }
    findPatron->displayPatron();
    findPatron->displayHistory();

    return true;
}

void PatronHistory::display() const
{
    
}

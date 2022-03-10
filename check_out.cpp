#include "check_out.h"
#include "manager.h"
bool CheckOut::execute(Manager* libraryManager, istream& infile) const
{
    int patronID = -1;
    char bookType = '0';
    char hardOrSoftCopy;
    Media* searchableBook = nullptr;
    Media* foundBook = nullptr;
    Patron* retrievedPatron = nullptr;;
    string s;                  // used to read to end of line holding size

    if (infile.eof()) {
        cout << "No Patron ID was given." << endl;
        return false; // no ID to read
    }
    infile >> patronID;
    if (patronID != -1) {
        if (!(libraryManager->patrons.retrievePatron(patronID, retrievedPatron))) {
            cout << "No Patron was found with ID: " << patronID << endl;
            return false;
        }
    }
    else {
        //no patron ID given
        return false;
    }
    if (infile.eof()) {
        cout << "No book type was given." << endl;
        return false; // no book type to read
    }
    infile >> bookType;

    if (infile.eof()) {
        cout << "No book was given" << endl;
        return false; // no book to read
    }

    infile >> hardOrSoftCopy;

    if (!(searchableBook = libraryManager->mediaFactory.createMediaFromCommand(bookType, infile))) { // will create a book that will only be used for searching.
        cout << "Invalid book type given" << endl;
        return false;
    }
    //LATER ON I HAVE TO CHANGE THIS, THIS BREAKS THE OPEN CLOSE PRINCIPLE, JUST NOT SURE WHAT TO DO
    foundBook = libraryManager-> library.checkOutMedia(searchableBook, bookType);//CHANGE THE LIBRARY TO HAVE A RETURN FUNCTION AND THEN USE CHECK IN MEDIA HERE, AND WHEN ITS A HARD COPY USE CHECK IN / CHECK OUT BUT IF NOT A HARD COPY THEN JUST USE RETRIEVE
    if (foundBook == nullptr) {
        cout << "Book was not found in the library" << endl;
        return false;
    }

    if (hardOrSoftCopy == 'H') { //Definitally need to change this, just not sure what to do with it
        //if there aren't enough copies to check out then don't give the patron a book
        if (foundBook->checkOut()) { //maybe this should be in the library's checkout function, really not sure
            retrievedPatron->checkOut(foundBook);
            if (searchableBook != nullptr) {
                delete searchableBook;
            }
            return true;
        }
    }
    if (searchableBook != nullptr) {
        delete searchableBook;
    }
    //this is a book that is created only to search the tree 
    //this could be better by creating a seperate function in the factory
    //makes a "searchable book that is not a pointer, and doesn't use heap"
    return false;
}

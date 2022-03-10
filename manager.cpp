#include "manager.h"

Manager::Manager()
{
}

bool Manager::checkOutMedia(ifstream& infile)
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
        if (!(patrons.retrievePatron(patronID, retrievedPatron))) {
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

    if (!(searchableBook = mediaFactory.createMediaFromCommand(bookType, infile))) { // will create a book that will only be used for searching.
         cout << "Invalid book type given" << endl;
         return false;
    }
                          //LATER ON I HAVE TO CHANGE THIS, THIS BREAKS THE OPEN CLOSE PRINCIPLE, JUST NOT SURE WHAT TO DO
    foundBook = library.checkOutMedia(searchableBook, bookType);//CHANGE THE LIBRARY TO HAVE A RETURN FUNCTION AND THEN USE CHECK IN MEDIA HERE, AND WHEN ITS A HARD COPY USE CHECK IN / CHECK OUT BUT IF NOT A HARD COPY THEN JUST USE RETRIEVE
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

bool Manager::returnMedia(ifstream& infile)
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
        if (!(patrons.retrievePatron(patronID, retrievedPatron))) {
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

    if (!(searchableBook = mediaFactory.createMediaFromCommand(bookType, infile))) { // will create a book that will only be used for searching.
        cout << "Invalid book type given" << endl;
        return false;
    }
    //LATER ON I HAVE TO CHANGE THIS, THIS BREAKS THE OPEN CLOSE PRINCIPLE, JUST NOT SURE WHAT TO DO
    foundBook = library.checkOutMedia(searchableBook, bookType);        //CHANGE THE LIBRARY TO HAVE A RETURN FUNCTION AND THEN USE CHECK IN MEDIA HERE, AND WHEN ITS A HARD COPY USE CHECK IN / CHECK OUT BUT IF NOT A HARD COPY THEN JUST USE RETRIEVE
    if (foundBook == nullptr) {
        cout << "Book was not found in the library" << endl;
        return false;
    }

    if (hardOrSoftCopy == 'H') { //Definitally need to change this, just not sure what to do with it
        //if there aren't enough copies to check out then don't give the patron a book
        if (foundBook->checkIn()) { //maybe this should be in the library's checkout function, really not sure
            retrievedPatron->returnBook(foundBook);
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

void Manager::displayPatronHistory() const
{
    //patrons.displayAllHistory();
    return;
}

void Manager::displayPatronBooks() const {
    patrons.displayAll();
}

void Manager::displayLibrary() const
{
   library.display();
}

void Manager::inputMediaFile(string infile) // This will be moved to a transaction class but for now it's fine
{
    ifstream media_in_file(infile);                                             //check which type of variable I'm supposed to use _'s or camel
    char bookType = '0';

    for (;;)
    {
        media_in_file >> bookType;                // read the type of book
        if (media_in_file.eof()) return;// stop reading if no more data   ///Maybe this eof check chould be the first thing in the for loop, check if this is correct by testing an empty file

        Media* createdMedia = mediaFactory.createMedia(bookType, media_in_file);
        //if media was created
        if (createdMedia != nullptr) {
            library.insert(createdMedia, bookType);
        }
        else {
            string s;                  // used to read to end of line holding size
            getline(media_in_file, s);
        }
    }
}

void Manager::inputPatreonFile(const string infile)
{
    ifstream patron_in_file(infile);
    while (!patron_in_file.eof()) {

        Patron* newPatron = new Patron;
        if(newPatron->create(patron_in_file)) {
            patrons.Insert(newPatron);
        }
        else {      //Shouldn't ever happen but if we make changes to verifying patron input then this is a good idea
            delete newPatron;   //maybe move this to paytron.create()
        }
    }
    //maybe make a function in patron container that creates, and maybe that create even calls the patron class.
}

void Manager::inputTransactions(const string infile)
{
    ifstream command_in_file(infile);
    string s; // string used for perging file line
    char commandType = '0';

    while (!command_in_file.eof()) {
        command_in_file >> commandType;
        if (commandType == 'C') {   //Obviously have to change this later to have a command factory.
            if (!checkOutMedia(command_in_file)) {
                getline(command_in_file, s);
            }
        }
        else if (commandType == 'D') {
            displayLibrary();
        }
        else if (commandType == 'R') {
            if (!returnMedia(command_in_file)) {
                getline(command_in_file, s);
            } 
        }
        else if (commandType == 'H') {
            getline(command_in_file, s); // change to display a patrons history
        }
        else {
            getline(command_in_file, s);
        }
    }
}

#include "manager.h"

Manager::Manager()
{
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
    if (!commandFactory.executeCommand(this,commandType, command_in_file)) {
        getline(command_in_file, s);
    }
    }


    /*while (!command_in_file.eof()) {
        command_in_file >> commandType;
        if (commandType == 'C') {   //Obviously have to change this later to have a command factory.
            CheckOut newCheckout;
            if (!newCheckout.execute(this,command_in_file)) {
                getline(command_in_file, s);
            }
        }
        else if (commandType == 'D') {
            DisplayLibrary newDisplayCommand;
            newDisplayCommand.execute(this,command_in_file);
        }
        else if (commandType == 'R') {
            ReturnMedia newReturnCommand;

            if (!newReturnCommand.execute(this,command_in_file)) {
                getline(command_in_file, s);
            } 
        }
        else if (commandType == 'H') {
            PatronHistory newPatronHistory;
            if (!newPatronHistory.execute(this, command_in_file)) {
                getline(command_in_file, s);
            }
            getline(command_in_file, s); // change to display a patrons history
        }
        else {
            getline(command_in_file, s);
        }
    }*/
}

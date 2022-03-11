#include "manager.h"
//--------------------------------------------------------------------------
// Manager (constructor)
/* currently this constructor holds no code */
Manager::Manager()
{
    //empty for now
}

//--------------------------------------------------------------------------
// inputMediaFile
/* given a string that is the input file, this function will use the media
   factory to read in the data of each media. Once the media has been read, it
   will be inserted into the library.*/
void Manager::inputMediaFile(string infile)
{
    ifstream media_in_file(infile);
    string s;              // used to read to end of line holding size
    char meida_type = '0';

    for (;;)
    {
        media_in_file >> meida_type;                // read the type of media
        if (media_in_file.eof()) return;// stop reading if no more data   

        //creates a new media given the type of media
        Media* created_media = mediaFactory.createMedia
        (meida_type, media_in_file);
        //if media was created
        if (created_media != nullptr) {
            library.insert(created_media, meida_type);
        }
        else {       // used to read to end of line holding size
            getline(media_in_file, s);
        }
    }
}

//--------------------------------------------------------------------------
// inputPatreonFile
/* given a string that is the input file, this function will read in each
   patrons ID's then create a Patron with that ID if it's valid. Lastly the
   patron will be stored in this managers patronContainer.*/
void Manager::inputPatreonFile(const string infile)
{
    ifstream patron_in_file(infile);
    while (!patron_in_file.eof()) {

        /*new patron that will be inserted to the patron container if a valid
        id is given*/
        Patron* new_patron = new Patron;
        /*Used to search for a patron with the same ID if this patron is found
        then the new patron will not be inserted into the patron container */
        Patron* found_patron = nullptr;

        if (new_patron->create(patron_in_file)) {
            if (!patrons.retrievePatron(new_patron->getID(), found_patron)) {
                patrons.Insert(new_patron);
            }
            else { //if patron with this ID already exists
                delete new_patron;
                return;
            }
        }
        else {      //if bad input like no id
            delete new_patron;
        }
    }
}

//--------------------------------------------------------------------------
// inputTransactions
/* given a string that is the input file, this function will read each
   transaction type and use the command factory to execute the read command.*/
void Manager::inputTransactions(const string infile)
{
    ifstream command_in_file(infile);
    string s; // string used for perging file line
    char command_type = '0';
    while (true) {//runs till end of file
        command_in_file >> command_type;
        if (command_in_file.eof()) {
            return;
        }
        //uses command factory to create and execute the new command
        if (!commandFactory.executeCommand(this, command_type, command_in_file))
        {
            /*if command couldn't be completed then that line
            (rest of that command) is flushed out using getline*/
            getline(command_in_file, s);
        }
    }
}

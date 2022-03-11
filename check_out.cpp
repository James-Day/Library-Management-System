#include "check_out.h"
#include "manager.h"
CheckOut::CheckOut()
{
    media_checked_out = nullptr;
}
CheckOut::~CheckOut()
{
    //empty
}
bool CheckOut::execute(Manager* libraryManager, istream& infile)
{
    int patronID = -1;
    char media_type = '0';
    char format_type = '0';
    /*This media is created from the command fileand is only created to
    search through the library with*/
    Media* searchable_media = nullptr;
    Media* found_media = nullptr;
    Patron* retrieved_patron = nullptr;;

    if (infile.eof()) {
        cout << "No Patron ID was given." << endl;
        return false; // no ID to read
    }
    infile >> patronID;
    if (patronID != -1) {
        if (!(libraryManager->patrons.
            retrievePatron(patronID, retrieved_patron))) {
            cout << "No Patron was found with ID: " << patronID << endl;
            return false;
        }
    }
    else {
        cout << "No Patron ID was given." << endl;
        return false; // no patron ID given
    }
    if (infile.eof()) {
        cout << "No media type was given." << endl;
        return false; // no book type to read
    }
    infile >> media_type;

    if (media_type == '0') {
        cout << "No media type was given." << endl;
        return false; // no book type to read
    }
    if (infile.eof()) {
        cout << "No format type was given." << endl;
        return false; // no book type to read
    }

    infile >> format_type;

    if (format_type == '0') {
        cout << "No format type was given." << endl;
        return false; //no format type given
    }

    if (infile.eof()) {
        cout << "No media was given" << endl;
        return false; // no book to read
    }

    /* will create a media that will only be used for searching.
       this book will be searched for in the library */
    if (!(searchable_media = libraryManager->
        mediaFactory.createMediaFromCommand(media_type, infile))) {
        cout << "Invalid book type given" << endl;
        return false;
    }
    /*searches the library to find the media that will be checked out
      if the media is not found in the library then a book will not be checked
      out*/
    found_media = libraryManager->
        library.checkOutMedia(searchable_media, media_type);
    if (found_media == nullptr) {
        searchable_media->displayTitle();
        cout << " was not found in the library" << endl;
        delete searchable_media;
        return false;
    }

    /*The format factory is used to indicate what should happen when the media
      is checked out. For example if a hard copy is checked out we lower the
      number of copies in the library by 1, but if it's just a digital
      download then we don't need to lower the number of copies*/
    if (libraryManager->formatFactory.checkOut(found_media, format_type)) {
        retrieved_patron->checkOut(found_media);
        if (searchable_media != nullptr) {
            delete searchable_media;
        }
        //media is stored in the command for command history
        media_checked_out = found_media;
        //update the patrons history with this command
        retrieved_patron->addHistory(this);
        return true;
    }
    else { //invalid format type given
        if (searchable_media != nullptr) {
            delete searchable_media;
        }
        cout << "invalid format type" << endl;
        return false;
    }
}

void CheckOut::display() const
{
    cout << left << setw(kIndentSize) << "" << setw(kCommandMaxLength)
        << "CheckOut";
    media_checked_out->displayInPatron();
}

Command* CheckOut::create()
{
    return new CheckOut;
}

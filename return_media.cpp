#include "return_media.h"
#include "manager.h"
//--------------------------------------------------------------------------
// ReturnMedia (constructor)
/* the constructor for the returnMedia command subclass. This constructor
   simply initializes the returned media to nullptr*/
ReturnMedia::ReturnMedia() { media_returned_ = nullptr; }

//--------------------------------------------------------------------------
// ReturnMedia (destructor)
/* the destructor needs no code for now*/
ReturnMedia::~ReturnMedia() {
    // empty
}

//--------------------------------------------------------------------------
// execute
/* the ReturnMedia command is executed using the given manager and input file.
   First the patron ID is read in and validated, then the type of media
   and format of media are read in and validated. The book given from the
   input file is searched for in the library using a book that is created
   only for searching. If the book is found is returned to
   the library as well as taken out of patrons current checked out books */
bool ReturnMedia::execute(Manager *library_manager, istream &infile) {
    int patron_ID = -1;
    char media_type = '0';
    char format_type = '0';
    /*This media is created from the command fileand is only created to
    search through the library with*/
    Media *searchable_media = nullptr;
    Media *found_media = nullptr;
    Patron *retrieved_patron = nullptr;
    ;

    if (infile.eof()) {
        cout << "Return Error: No Patron ID was given." << endl;
        return false; // no ID to read
    }
    // find the patron in our patron container
    infile >> patron_ID;
    if (patron_ID != -1) {
        if (!(library_manager->patrons_.retrievePatron(patron_ID,
                                                       retrieved_patron))) {
            cout << "Return Error: No Patron was found with ID: " << patron_ID
                 << endl;
            return false;
        }
    } else {
        cout << "Return Error: No Patron ID was given." << endl;
        return false;
    }
    if (infile.eof()) {
        cout << "Return Error: No media type was given." << endl;
        return false; // no book type to read
    }
    infile >> media_type;
    if (media_type == '0') {
        cout << "Return Error: No media type was given." << endl;
        return false; // no book type to read
    }
    if (infile.eof()) {
        cout << "Return Error: No format type was given." << endl;
        return false; // no book type to read
    }
    infile >> format_type;
    if (format_type == '0') {
        cout << "Return Error: No format type was given." << endl;
        return false;
    }

    if (infile.eof()) {
        cout << "Return Error: No media was given" << endl;
        return false; // no book to read
    }

    // will create a media that will only be used for searching.
    if (!(searchable_media =
              library_manager->mediaFactory_.createMediaFromCommand(media_type,
                                                                    infile))) {
        cout << "Return Error: Invalid media type given" << endl;
        return false;
    }
    /*searches the library to find the media that will be returned
      if the media is not found in the library then a book will not be
      returned*/
    found_media =
        library_manager->library_.checkOutMedia(searchable_media, media_type);
    if (found_media == nullptr) {
        cout << "Return Error : ";
        searchable_media->displayTitle();
        cout << " was not found in the library" << endl;
        delete searchable_media;
        return false;
    }

    // Checks to make sure patron has this book checked out
    if (retrieved_patron->returnMedia(found_media) == nullptr) {
        cout << "Return Error: ";
        searchable_media->displayTitle();
        cout << " not found in patron" << endl;
        delete searchable_media;
        return false;
    }
    /*The format factory is used to indicate what should happen when the media
      is returned. For example if a hard copy is returned we increase the
      number of copies in the library by 1, but if it's just a digital
      download then we don't need to raise the number of copies*/
    if (library_manager->formatFactory_.returnMedia(found_media, format_type)) {
        if (searchable_media != nullptr) {
            delete searchable_media;
        }
        // media is stored in the command for command history
        media_returned_ = found_media;
        // update the patrons history with this command
        retrieved_patron->addHistory(this);
        return true;
    } else {
        if (searchable_media != nullptr) {
            delete searchable_media;
        }
        cout << "Return Error: invalid format type" << endl;
        return false;
    }
}

//--------------------------------------------------------------------------
// display
/* displays this command and the book that was returned*/
void ReturnMedia::display() const {
    // displays that a media was ruterned and what media
    cout << left << setw(kIndentSize) << "" << setw(kCommandMaxLength)
         << "Return";
    media_returned_->displayInPatron();
}

//--------------------------------------------------------------------------
// create
/* simply returns a new ReturnMedia command to the command factory*/
Command *ReturnMedia::create() const { return new ReturnMedia; }

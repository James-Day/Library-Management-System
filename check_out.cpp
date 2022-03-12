#include "check_out.h"
#include "manager.h"

//--------------------------------------------------------------------------
// CheckOut (constructor)
/* the constructor for the CheckOut command subclass. This constructor
   simply initializes the checked out media to nullptr*/
CheckOut::CheckOut() { media_checked_out_ = nullptr; }
//--------------------------------------------------------------------------
// CheckOut (destructor)
/* the destructor needs no code for now*/
CheckOut::~CheckOut() {
    // empty
}
//--------------------------------------------------------------------------
// execute
/* the checkOut command is executed using the given manager and input file.
   First the patron ID is read in and validated, then the type of media
   and format of media are read in and validated. The book given from the
   input file is searched for in the library using a book that is created
   only for searching. If the book is found is checked out from
   the library as well as stored in the patrons current checked out books */
bool CheckOut::execute(Manager *library_manager, istream &infile) {
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
        cout << "Checkout Error: No Patron ID was given." << endl;
        return false; // no ID to read
    }
    infile >> patron_ID;
    if (patron_ID != -1) {
        if (!(library_manager->patrons_.retrievePatron(patron_ID,
                                                       retrieved_patron))) {
            cout << "Checkout Error: No Patron was found with ID: " << patron_ID
                 << endl;
            return false;
        }
    } else {
        cout << "Checkout Error: No Patron ID was given." << endl;
        return false; // no patron ID given
    }
    if (infile.eof()) {
        cout << "Checkout Error: No media type was given." << endl;
        return false; // no book type to read
    }
    infile >> media_type;

    if (media_type == '0') {
        cout << "Checkout Error: No media type was given." << endl;
        return false; // no book type to read
    }
    if (infile.eof()) {
        cout << "Checkout Error: No format type was given." << endl;
        return false; // no book type to read
    }

    infile >> format_type;

    if (format_type == '0') {
        cout << "Checkout Error: No format type was given." << endl;
        return false; // no format type given
    }

    if (infile.eof()) {
        cout << "Checkout Error: No media was given" << endl;
        return false; // no book to read
    }

    /* will create a media that will only be used for searching.
       this book will be searched for in the library */
    if (!(searchable_media =
              library_manager->mediaFactory_.createMediaFromCommand(media_type,
                                                                    infile))) {
        cout << "Checkout Error: Invalid media type '" << media_type << "'"
             << endl;
        return false;
    }
    /*searches the library to find the media that will be checked out
      if the media is not found in the library then a book will not be checked
      out*/
    found_media =
        library_manager->library_.checkOutMedia(searchable_media, media_type);
    if (found_media == nullptr) {
        cout << "Checkout Error: ";
        searchable_media->displayTitle();
        cout << " was not found in the library" << endl;
        delete searchable_media;
        return false;
    }

    /*The format factory is used to indicate what should happen when the media
      is checked out. For example if a hard copy is checked out we lower the
      number of copies in the library by 1, but if it's just a digital
      download then we don't need to lower the number of copies*/
    if (library_manager->formatFactory_.checkOut(found_media, format_type)) {
        retrieved_patron->checkOut(found_media);
        if (searchable_media != nullptr) {
            delete searchable_media;
        }
        // media is stored in the command for command history
        media_checked_out_ = found_media;
        // update the patrons history with this command
        retrieved_patron->addHistory(this);
        return true;
    } else { // invalid format type given
        if (searchable_media != nullptr) {
            delete searchable_media;
        }
        return false;
    }
}

//--------------------------------------------------------------------------
// display
/* displays this command and the book that was checked out*/
void CheckOut::display() const {
    cout << left << setw(kIndentSize) << "" << setw(kCommandMaxLength)
         << "CheckOut";
    media_checked_out_->displayInPatron();
}

//--------------------------------------------------------------------------
// create
/* simply returns a new CheckOut command to the command factory*/
Command *CheckOut::create() const { return new CheckOut; }

#include "patron.h"
#include "command.h"
//--------------------------------------------------------------------------
// Patron (empty constructor)
/* initializes Patrons first name, last name, ID, and all book pointers */
Patron::Patron() {
    first_name_ = "DEFAULT";
    last_name_ = "DEFAULT";
    ID_ = 0000;
    for (int i = 0; i < all_media_.size(); i++) {
        all_media_[i] = nullptr;
    }
}

//--------------------------------------------------------------------------
// Patron (destructor)
/* deletes all the commands in the patrons history*/
Patron::~Patron() {
    for (int i = 0; i < command_history_.size(); i++) {
        delete command_history_[i];
    }
}
//--------------------------------------------------------------------------
// Patron (constructor)
/* this patron is initialized with a first name, last name, and a ID*/
Patron::Patron(std::string patron_first_name, std::string patron_last_name,
               int patron_ID) {
    first_name_ = patron_first_name;
    last_name_ = patron_last_name;
    ID_ = patron_ID;
    for (int i = 0; i < all_media_.size(); i++) {
        all_media_[i] = nullptr;
    }
}

//--------------------------------------------------------------------------
// checkOut
/* the given book is entered into this patrons list of books*/
bool Patron::checkOut(Media *checking_out) {
    all_media_.push_back(checking_out);
    return false;
}

//--------------------------------------------------------------------------
// returnMedia
/* searches through the patrons books/medias that are currently checked out.
   If the media is found then the media is returned*/
Media *Patron::returnMedia(Media *return_book) {
    for (int i = 0; i < all_media_.size(); i++) { // check each media to find
                                                  // the
        if (all_media_[i] != nullptr) {         // one that needs to be returned
            if (all_media_[i] == return_book) { // book found
                Media *return_copy = all_media_[i];
                all_media_[i] = nullptr;
                return return_copy;
            }
        }
    }
    return nullptr;
}

//--------------------------------------------------------------------------
// addHistory
/* adds a history to the end list of users history of commands*/
bool Patron::addHistory(const Command *history) {
    command_history_.push_back(history);
    return true;
}
//--------------------------------------------------------------------------
// create
/* given an input file, this function will read in the patrons ID number,
   last, and first name. if a patrons given ID is to short or too long, then
   false will be returned, otherwise true will be returned*/
bool Patron::create(ifstream &infile) {
    string first = "";
    string last = "";
    int ID_number = 0;

    infile >> ID_number;

    infile >> last;
    infile >> first;
    ID_ = ID_number;
    last_name_ = last;
    first_name_ = first;

    // incorrect length
    if (ID_number > 999 && ID_number < 10000) {
        return true;
    } else {
        cout << "ID number is incorrect length" << endl;
        return false;
    }
}
//--------------------------------------------------------------------------
// displayBooks
// all books that are currently checked out from this patron will be displayed
void Patron::displayBooks() const {
    for (int i = 0; i < all_media_.size(); i++) {
        if (all_media_[i] != nullptr) {
            all_media_[i]->displayInPatron();
            cout << endl;
        }
    }
}
//--------------------------------------------------------------------------
// displayPatron
/* displays information of the patron including ID and name*/
void Patron::displayPatron() const {
    cout << ID_ << " " << last_name_ << ","
         << " " << first_name_ << ":";
    cout << endl;
}
//--------------------------------------------------------------------------
// displayHistory
/* displays all command histories of this patron*/
void Patron::displayHistory() const {
    for (int i = 0; i < command_history_.size(); i++) {
        command_history_[i]->display();
        cout << endl;
    }
}
//--------------------------------------------------------------------------
// getID
/* returns the PatronsID*/
int Patron::getID() const { return ID_; }

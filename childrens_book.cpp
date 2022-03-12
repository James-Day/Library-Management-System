#include "childrens_book.h"

//--------------------------------------------------------------------------
// ChildrensBook (constructor)
/* This constructor initializes the values of the chldren's book. All
   childrens books start with the tile "FactoryChildrensBook" because any
   children's book that is created must update the title, so the only books
   that should use this factory title are books that are stored in the
   factory.*/
ChildrensBook::ChildrensBook() {
    author_ = "";
    num_copies_ = kNumChildrenBooks;
    title_ = "FactoryChildrensBook";
    year_ = 0;
}

//--------------------------------------------------------------------------
// create
/* Takes inputs from an input file and creates a new children's book with
   the data from the given file.*/
Media *ChildrensBook::create(std::istream &infile) {
    /*Take inputs into seperate strings incase we want to do error checking
    in the future*/
    string author_str = "";
    string title_str = "";
    int date = 0;

    ChildrensBook *created_book = new ChildrensBook();
    infile.get(); // get (and ignore) blank before author
    getline(infile, author_str, ',');
    created_book->author_ = author_str;
    infile.get(); // get (and ignore) blank before author
    getline(infile, title_str, ',');
    created_book->title_ = title_str;
    infile >> date;
    created_book->year_ = date;

    return created_book;
}

//--------------------------------------------------------------------------
// createFromCommand
/* Simmilar to create, takes input from a file to create a new children's book
   with the given data from a file, but this function will only be used when
   creating children's book from a command. This allows commands to have
   differnt formats of input.*/
Media *ChildrensBook::createFromCommand(istream &infile) {
    /*Take inputs into seperate strings incase we want to do error checking
    in the future*/
    string author_str = "";
    string title_str = "";

    ChildrensBook *created_book = new ChildrensBook();

    infile.get(); // get (and ignore) blank before title
    getline(infile, title_str, ',');
    created_book->title_ = title_str;
    infile.get(); // get (and ignore) blank before author
    getline(infile, author_str, ',');
    created_book->author_ = author_str;
    /* Date just stays as zero which is fine because these books will just be
    used to search fro the real book in the library*/

    return created_book;
}

//--------------------------------------------------------------------------
// ChildrensBook (destructor)
/* destructor for childrens books, currently no code needed. this empty
   destructor is needed to prevent memory leaks*/
ChildrensBook::~ChildrensBook() {}

//--------------------------------------------------------------------------
// checkOut
/* simply lowers the number of copies of this children's book in the library.
   If a children's book has no copies left in the library, then
   false will be returned and copies will not be lowered.*/
bool ChildrensBook::checkOut() {
    if (num_copies_ >= 1) {
        num_copies_--;
        return true;
    }
    cout << "Checkout Error: No coppies of '" << title_ << "' left to check out"
         << endl;
    return false;
}

//--------------------------------------------------------------------------
// checkOut
/* Simply raises the number of copies of the childrens book in the library.*/
void ChildrensBook::checkIn() { num_copies_++; }

//--------------------------------------------------------------------------
// displayInLibrary
/* displayInLibrary displays all the aspects of the ChildrensBook including
   number of copies, author, title, and the year it was published with proper
   formating. This function is used when displaying the books in the library*/
void ChildrensBook::displayInLibrary() const {

    string numCopiesStr = to_string(num_copies_);
    string yearStr = to_string(year_);

    cout << left << setw(kMaxNumBooksLength + 2)
         << numCopiesStr.substr(0, kMaxNumBooksLength)
         << setw(kMaxAuthorLength + 2) << author_.substr(0, kMaxAuthorLength)
         << setw(kMaxTitleLength + 2) << title_.substr(0, kMaxTitleLength)
         << right << setw(kMaxYearLength) << yearStr.substr(0, kMaxYearLength);
}

//--------------------------------------------------------------------------
// displayInPatron
/* displayInPatron is used for displaying the childrens books information when
   displaying the patrons history. author and title are displayed
   as well as the year the childrens book was published with proper formating
   */
void ChildrensBook::displayInPatron() const {
    string numCopiesStr = to_string(num_copies_);
    string yearStr = to_string(year_);

    cout << left << setw(kDisplayIndentSize) << "" << setw(kMaxAuthorLength + 2)
         << author_.substr(0, kMaxAuthorLength) << setw(kMaxTitleLength + 2)
         << title_.substr(0, kMaxTitleLength) << right << setw(kMaxYearLength)
         << yearStr.substr(0, kMaxYearLength);
}

//--------------------------------------------------------------------------
// displayTitle
/* Only displays the title of the childrens book which is useful for
error messages*/
void ChildrensBook::displayTitle() const {
    cout << left << title_.substr(0, kMaxTitleLength - 10);
    // a bit shorter for error messages
}

//--------------------------------------------------------------------------
// displayComponents
/* Displays the different components of the childrens book that will be
    displayed when displaying the entire library. It also displays them in the
    order they will appear when using display in library*/
void ChildrensBook::displayComponents() const {
    cout << "AVAIL "
         << "AUTHOR" << setw(18) << ""
         << "TITLE" << setw(33) << ""
         << "YEAR" << endl;
}

//--------------------------------------------------------------------------
// operator <
// operator < overload, ChildrensBook are sorted by title, then by author
bool ChildrensBook::operator<(const Media &rhs) const {
    const ChildrensBook *rhs_ptr = dynamic_cast<const ChildrensBook *>(&rhs);
    if (title_ < rhs_ptr->title_) {
        return true;
    } else if (title_ == rhs_ptr->title_) {
        if (author_ < rhs_ptr->author_) {
            return true;
        }
    }
    // if Title and Author are same or title or author is greater than rhs.
    return false;
}

//--------------------------------------------------------------------------
// operator >
// operator > overload, ChildrensBook are sorted by title, then by author
bool ChildrensBook::operator>(const Media &rhs) const {
    const ChildrensBook *rhs_ptr = dynamic_cast<const ChildrensBook *>(&rhs);
    if (title_ > rhs_ptr->title_) {
        return true;
    } else if (title_ == rhs_ptr->title_) {
        if (author_ > rhs_ptr->author_) {
            return true;
        }
    }
    // if Title and Author are same or title or author is less than rhs.
    return false;
}

//--------------------------------------------------------------------------
// operator ==
/* operator == overload. If two ChildrensBooks have the same author and title,
   then true is returned.*/
bool ChildrensBook::operator==(const Media &rhs) const {
    const ChildrensBook *rhs_ptr = dynamic_cast<const ChildrensBook *>(&rhs);
    if (author_ == rhs_ptr->author_ && title_ == rhs_ptr->title_) {
        return true;
    }

    // Childrens books titles or authors are different
    return false;
}
//--------------------------------------------------------------------------
// operator !=
/* operator != overload. If two ChildrensBooks do not have the same author and
   title, then false is returned.*/
bool ChildrensBook::operator!=(const Media &copy) const {
    return !(*this == copy);
}

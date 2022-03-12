#include "fiction_book.h"

//--------------------------------------------------------------------------
// FictionBook (constructor)
/* This constructor initializes the values of the fiction book. All fiction
   books start with the tile "FactoryFictionBook" because any fiction book
   that is created must update the title, so the only books that use this
   factory title are books that are stored in the factory.*/
FictionBook::FictionBook() {
    author_ = "";
    num_copies_ = kNumFictionBooks;
    title_ = "FactoryFictionBook";
    year_ = 0;
}

//--------------------------------------------------------------------------
// create
/* Takes inputs from an input file and creates a new fiction book with
   the data from the given file.*/
Media *FictionBook::create(istream &infile) {
    /*Take inputs into seperate strings incase we want to do error checking
    in the future*/
    string authorStr = "";
    string titleStr = "";
    int date = 0;

    FictionBook *createdBook = new FictionBook();
    infile.get(); // get (and ignore) blank before author
    getline(infile, authorStr, ',');
    createdBook->author_ = authorStr;
    infile.get(); // get (and ignore) blank before author
    getline(infile, titleStr, ',');
    createdBook->title_ = titleStr;
    infile >> date;
    createdBook->year_ = date;

    return createdBook;
}

//--------------------------------------------------------------------------
// createFromCommand
/* Simmilar to create, takes input from a file to create a new fiction book
   with the given data from a file, but this function will only be used when
   creating fiction book from a command. This allows commands to have differnt
   formats of input.*/
Media *FictionBook::createFromCommand(istream &infile) {
    /*Take inputs into seperate strings incase we want to do error
    checking in the future*/
    string authorStr = "";
    string titleStr = "";
    string endOfLine = "";

    FictionBook *createdBook = new FictionBook();

    infile.get(); // get (and ignore) blank before author
    getline(infile, authorStr, ',');
    createdBook->author_ = authorStr;
    infile.get(); // get (and ignore) blank before title
    getline(infile, titleStr, ',');
    createdBook->title_ = titleStr;

    return createdBook;
}

//--------------------------------------------------------------------------
// FictionBook (destructor)
/* destructor for FictionBook books, currently no code needed. this empty
   destructor is needed to prevent memory leaks*/
FictionBook::~FictionBook() {}

//--------------------------------------------------------------------------
// checkOut
/* simply lowers the number of copies of this fiction book in the library.
   If a fiction book has no copies left in the library, then
   false will be returned and copies will not be lowered.*/
bool FictionBook::checkOut() {
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
/* Simply raises the number of copies of the fiction book in the library.*/
void FictionBook::checkIn() { num_copies_++; }

//--------------------------------------------------------------------------
// displayInLibrary
/* displayInLibrary displays all the aspects of the FictionBook including
   number of copies, author, title, and the year it was published with proper
   formating. This function is used when displaying the books in the library*/
void FictionBook::displayInLibrary() const {
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
/* displayInPatron is used for displaying the books information when
   displaying the patrons history. author and title are displayed
   as well as the year the fiction book was published with proper formating*/
void FictionBook::displayInPatron() const {
    string numCopiesStr = to_string(num_copies_);
    string yearStr = to_string(year_);

    cout << left << setw(kDisplayIndentSize) << "" << setw(kMaxAuthorLength + 2)
         << author_.substr(0, kMaxAuthorLength) << setw(kMaxTitleLength + 2)
         << title_.substr(0, kMaxTitleLength) << right << setw(kMaxYearLength)
         << yearStr.substr(0, kMaxYearLength);
}

//--------------------------------------------------------------------------
// displayTitle
/* Only displays the title of the FictionBook which is useful for
error messages*/
void FictionBook::displayTitle() const {
    cout << left << title_.substr(0, kMaxTitleLength - 10);
    // a bit shorterfor error messages
}

//--------------------------------------------------------------------------
// displayComponents
/* Displays the different components of the FictionBook that will be displayed
   when displaying the entire library. It also displays them in the
    order they will appear when using display in library*/
void FictionBook::displayComponents() const {
    cout << "AVAIL "
         << "AUTHOR" << setw(18) << ""
         << "TITLE" << setw(33) << ""
         << "YEAR" << endl;
}
//--------------------------------------------------------------------------
// operator <
// operator < overload, FictionBook are sorted by Author, then by title
bool FictionBook::operator<(const Media &rhs) const {
    const FictionBook *rhs_ptr = dynamic_cast<const FictionBook *>(&rhs);
    if (author_ < rhs_ptr->author_) {
        return true;
    } else if (author_ == rhs_ptr->author_) {
        if (title_ < rhs_ptr->title_) {
            return true;
        }
    }
    // if Title and Author are same or title or author is greater than rhs.
    return false;
}
//--------------------------------------------------------------------------
// operator >
// operator > overload, FictionBook are sorted by Author, then by title
bool FictionBook::operator>(const Media &rhs) const {
    const FictionBook *rhs_ptr = dynamic_cast<const FictionBook *>(&rhs);
    if (author_ > rhs_ptr->author_) {
        return true;
    } else if (author_ == rhs_ptr->author_) {
        if (title_ > rhs_ptr->title_) {
            return true;
        }
    }
    // if Title and Author are same or title or author is less than rhs.
    return false;
}

//--------------------------------------------------------------------------
// operator ==
/* operator == overload. If two FictionBook have the same author and title,
   then true is returned.*/
bool FictionBook::operator==(const Media &rhs) const {
    const FictionBook *rhs_ptr = dynamic_cast<const FictionBook *>(&rhs);
    if (author_ == rhs_ptr->author_ && title_ == rhs_ptr->title_) {
        return true;
    }

    // Fiction books titles or authors are different
    return false;
}

//--------------------------------------------------------------------------
// operator !=
/* operator != overload. If two FictionBook do not have the same author and
   title, then false is returned.*/
bool FictionBook::operator!=(const Media &copy) const {
    return !(*this == copy);
}

#include "periodical.h"

//--------------------------------------------------------------------------
// Periodical (constructor)
/* This constructor initializes the values of the periodical. All periodicals
   start with the tile "FactoryPeriodical" because any periodical that is
   created must update the title, so the only books that use this factory title
   are books that are stored in the factory.*/
Periodical::Periodical() {
    num_copies_ = kNumPeriodicals;
    title_ = "FactoryPeriodical";
    year_ = 0;
    month_ = 0;
}

//--------------------------------------------------------------------------
// create
/* Takes inputs from an input file and creates a new Periodical with the data
   from the given file.*/
Media *Periodical::create(istream &infile) {
    /*Take input into seperate variables incase we want to do error checking
    in the future*/

    string title_str = "";
    int date_month = 0;
    int date_year = 0;

    Periodical *created_book = new Periodical();

    infile.get(); // get (and ignore) blank before author
    getline(infile, title_str, ',');
    created_book->title_ = title_str;

    infile >> date_month;
    created_book->month_ = date_month;
    infile >> date_year;
    created_book->year_ = date_year;

    return created_book;
}

//--------------------------------------------------------------------------
// createFromCommand
/* Simmilar to create, takes input from a file to create a new periodical with
   the given data from a file, but this function will only be used when
   creating periodicals from a command. This allows commands to have differnt
   formats of input.*/
Media *Periodical::createFromCommand(istream &infile) {
    /*Take input into seperate variables incase we want to do error checking
    in the future*/
    string title_str = "";
    int date_month = 0;
    int date_year = 0;

    Periodical *created_periodical = new Periodical();

    infile >> date_year;
    created_periodical->year_ = date_year;

    infile >> date_month;
    created_periodical->month_ = date_month;
    infile.get(); // get (and ignore) blank before author
    getline(infile, title_str, ',');
    created_periodical->title_ = title_str;

    return created_periodical;
}

//--------------------------------------------------------------------------
// Periodical (destructor)
/* destructor for Periodical books, currently no code needed*/
Periodical::~Periodical() {}

//--------------------------------------------------------------------------
// checkOut
/* simply lowers the number of copies of this periodical in the library.
   If a periodical is checked out and has no copies left in the library, then
   false will be returned.*/
bool Periodical::checkOut() {
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
/* Simply raises the number of copies of the periodical in the library.*/
void Periodical::checkIn() { num_copies_++; }

//--------------------------------------------------------------------------
// displayInLibrary
/* displayInLibrary displays all the aspects of the periodical including
   number of copies, and year and month of publishing all with proper
   formating. This function is used when displaying the books in the library*/
void Periodical::displayInLibrary() const {
    string numCopiesStr = to_string(num_copies_);
    string yearStr = to_string(year_);
    string monthStr = to_string(month_);

    // longer length for title since periodicals don't have authors
    cout << left << setw(kMaxNumBooksLength + 2)
         << numCopiesStr.substr(0, kMaxNumBooksLength)
         << setw(kMaxTitleLength + 20) << title_.substr(0, kMaxTitleLength + 18)
         << setw(kMaxYearLength + 2) << yearStr.substr(0, kMaxYearLength)
         << right << setw(kMaxMonthLength)
         << monthStr.substr(0, kMaxAuthorLength);
}

//--------------------------------------------------------------------------
// displayInPatron
/* displayInPatron is used for displaying the books information when
   displaying the patrons history. Month and year of publishing are displayed
   as well as the title of the periodical with proper formating*/
void Periodical::displayInPatron() const {
    string yearStr = to_string(year_);
    string monthStr = to_string(month_);

    // longer length for title since periodicals don't have authors
    cout << left << setw(kDisplayIndentSize) << "" << setw(kMaxMonthLength)
         << monthStr.substr(0, kMaxAuthorLength) << setw(kMaxYearLength + 2)
         << yearStr.substr(0, kMaxYearLength) << setw(kMaxTitleLength + 20)
         << title_.substr(0, kMaxTitleLength + 18);
}

//--------------------------------------------------------------------------
// displayTitle
/* Only displays the title of the Periodical which is useful for
error messages*/
void Periodical::displayTitle() const {
    cout << left << title_.substr(0, kMaxTitleLength - 10);
    // a little shorter for errors
}
//--------------------------------------------------------------------------
// displayComponents
/* Displays the different components of the Periodical that will be displayed
   when displaying the entire library.*/
void Periodical::displayComponents() const {
    cout << "AVAIL "
         << "Title" << setw(51) << ""
         << "YEAR"
         << " MONTH" << endl;
}

//--------------------------------------------------------------------------
// operator <
/* operator < overload, Periodicals are sorted by year, then month,
then by title */
bool Periodical::operator<(const Media &rhs) const {
    const Periodical *rhs_ptr = dynamic_cast<const Periodical *>(&rhs);

    if (year_ < rhs_ptr->year_) {
        return true;
    } else if (year_ == rhs_ptr->year_) {
        if (month_ < rhs_ptr->month_) {
            return true;
        }
        if (month_ == rhs_ptr->month_) {
            if (title_ < rhs_ptr->title_) {
                return true;
            }
        }
    }
    /*if year is greater, or year is same and month is greater,
    or month and year are the same but the title is greater.*/
    return false;
}

//--------------------------------------------------------------------------
// operator >
/* operator > overload, Periodicals are sorted by year, then month,
then by title */
bool Periodical::operator>(const Media &rhs) const {
    const Periodical *rhs_ptr = dynamic_cast<const Periodical *>(&rhs);

    if (year_ > rhs_ptr->year_) {
        return true;
    } else if (year_ == rhs_ptr->year_) {
        if (month_ > rhs_ptr->month_) {
            return true;
        }
        if (month_ == rhs_ptr->month_) {
            if (title_ > rhs_ptr->title_) {
                return true;
            }
        }
    }
    /*if year is less, or year is same and month is less, or month and year
    are the same but the title is less.*/
    return false;
}

//--------------------------------------------------------------------------
// operator ==
/* operator == overload. If two periodicals have the same year and month of
publishing as well as the same title, then true is returned.*/
bool Periodical::operator==(const Media &rhs) const {
    const Periodical *rhs_ptr = dynamic_cast<const Periodical *>(&rhs);
    if ((year_ == rhs_ptr->year_ && title_ == rhs_ptr->title_) &&
        (month_ == rhs_ptr->month_)) {
        return true;
    }

    // periodical books titles or authors are different
    return false;
}

//--------------------------------------------------------------------------
// operator !=
/* operator != overload. If two periodicals do not have the same year and
month of publishing as well as the same title, then false is returned.*/
bool Periodical::operator!=(const Media &copy) const {
    return !(*this == copy);
}

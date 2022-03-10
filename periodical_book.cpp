#include "periodical.h"

using namespace std;
Periodical::Periodical()
{
    numCopies = kNumPeriodicals;
    title = "FactoryPeriodical";
    year = 0;
    month = 0;
}

Media* Periodical::create(istream& infile)
{
    string titleStr = "";
    int dateMonth = 0;
    int dateYear = 0;

    Periodical* createdBook = new Periodical();

    infile.get();                     // get (and ignore) blank before author
    getline(infile, titleStr, ',');
    createdBook->title = titleStr;
    
    infile >> dateMonth;
    createdBook->month = dateMonth;
    infile >> dateYear;
    createdBook->year = dateYear;

    return createdBook;
}

Media* Periodical::createFromCommand(istream& infile)
{
    string titleStr = "";
    int dateMonth = 0;
    int dateYear = 0;

    Periodical* createdBook = new Periodical();

    infile >> dateYear;
    createdBook->year = dateYear;

    infile >> dateMonth;
    createdBook->month = dateMonth;
    infile.get();                     // get (and ignore) blank before author
    getline(infile, titleStr, ',');
    createdBook->title = titleStr;

    return createdBook;
}

Periodical::~Periodical()
{
}

bool Periodical::checkOut()
{
    if (numCopies >= 1) {
        numCopies--;
        return true;
    }
    return false;
}

bool Periodical::checkIn()
{
    numCopies++;
    return true;
}

void Periodical::displayInLibrary() const
{       
    string numCopiesStr = to_string(numCopies);
    string yearStr = to_string(year);
    string monthStr = to_string(month);

    cout << left << setw(kMaxNumBooksLength + 2)
        << numCopiesStr.substr(0, kMaxNumBooksLength)
        << setw(kMaxTitleLength + 20) << title.substr(0, kMaxTitleLength + 18)  //longer length for title since periodicals don't have authors
        << setw(kMaxYearLength +2)
        << yearStr.substr(0, kMaxYearLength) << right
        << setw(kMaxMonthLength) << monthStr.substr(0, kMaxAuthorLength);
}

void Periodical::displayInPatron() const
{
    string yearStr = to_string(year);
    string monthStr = to_string(month);
                                            //Will have to change to look like hers
    cout << left << "  "
        << setw(kMaxTitleLength + 20) << title.substr(0, kMaxTitleLength + 18)  //longer length for title since periodicals don't have authors
        << setw(kMaxYearLength + 2)
        << yearStr.substr(0, kMaxYearLength) << right
        << setw(kMaxMonthLength) << monthStr.substr(0, kMaxAuthorLength);
}

bool Periodical::operator<(const Media& rhs) const
{
    const Periodical* rhs_ptr = dynamic_cast<const Periodical*>(&rhs);

    if (year < rhs_ptr->year) {
        return true;
    }
    else if (year == rhs_ptr->year) {
        if (month < rhs_ptr->month) {
            return true;
        }
        if (month == rhs_ptr->month) {
            if (title < rhs_ptr->title) {
                return true;
            }
        }
    }
    //if year is greater, or year is same and month is greater, or month and year are the same but the title is greater.
    return false;
}

bool Periodical::operator>(const Media& rhs) const
{
    const Periodical* rhs_ptr = dynamic_cast<const Periodical*>(&rhs);

    if (year > rhs_ptr->year) {
        return true;
    }
    else if (year == rhs_ptr->year) {
        if (month > rhs_ptr->month) {
            return true;
        }
        if (month == rhs_ptr->month) {
            if (title > rhs_ptr->title) {
                return true;
            }
        }
    }
    //if year is less, or year is same and month is less, or month and year are the same but the title is less.
    return false;
}

bool Periodical::operator==(const Media& rhs) const
{
    const Periodical* rhs_ptr = dynamic_cast<const Periodical*>(&rhs);
    if ((year == rhs_ptr->year && title == rhs_ptr->title)      
        && (month == rhs_ptr->month)) {
        return true;
    }

    //periodical books titles or authors are different
    return false;
}
bool Periodical::operator!=(const Media& copy) const
{
    return !(*this == copy);
}
void Periodical::changevals(int months2, int year2, std::string title2, int copies) {       //DELETE THIS ONLY FOR TESTING
    month = months2;
    year = year2;
    title = title2;
    numCopies = copies;
}
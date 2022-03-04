#include "periodical.h"
#include  <string>
#include <iomanip>
using namespace std;
Periodical::Periodical()
{
    numCopies = kNumPeriodicals;
    title = "FactoryPeriodical";
    year = 1996;
    month = 0;
}

Media* Periodical::create()
{
    return this;
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
    return false;
}

void Periodical::display() const
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
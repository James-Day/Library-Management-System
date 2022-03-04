#include "childrens_book.h"
#include  <string>
#include <iomanip>
using namespace std;

ChildrensBook::ChildrensBook()
{
    author = "";
    numCopies = kNumChildrenBooks;
    title = "FactoryChildrensBook";
    year = 1996;
}

Media* ChildrensBook::create()
{
    return this;
}

bool ChildrensBook::checkOut()
{
    if (numCopies >= 1) {
        numCopies--;
        return true;
    }
    return false;
}

bool ChildrensBook::checkIn()
{
    return false;
}

void ChildrensBook::display() const
{
    string numCopiesStr = to_string(numCopies);
    string yearStr = to_string(year);

    cout << left << setw(kMaxNumBooksLength + 2)
        << numCopiesStr.substr(0, kMaxNumBooksLength) <<
        setw(kMaxAuthorLength + 2) << author.substr(0, kMaxAuthorLength)
        << setw(kMaxTitleLength + 2) << title.substr(0, kMaxTitleLength)
        << right << setw(kMaxYearLength) << yearStr.substr(0, kMaxYearLength);
}

bool ChildrensBook::operator<(const Media& rhs) const
{
    const ChildrensBook* rhs_ptr = dynamic_cast<const ChildrensBook*>(&rhs);
    if (title < rhs_ptr->title) {
        return true;
    }
    else if (title == rhs_ptr->title) {
        if (author < rhs_ptr->author) {
            return true;
        }
    }
    //if Title and Author are same or title or author is greater than rhs.
    return false;
}

bool ChildrensBook::operator>(const Media& rhs) const
{
    const ChildrensBook* rhs_ptr = dynamic_cast<const ChildrensBook*>(&rhs);
    if (title > rhs_ptr->title) {
        return true;
    }
    else if (title == rhs_ptr->title) {
        if (author > rhs_ptr->author) {
            return true;
        }
    }
    //if Title and Author are same or title or author is less than rhs.
    return false;
}

bool ChildrensBook::operator==(const Media& rhs) const
{
    const ChildrensBook* rhs_ptr = dynamic_cast<const ChildrensBook*>(&rhs);
    if (author == rhs_ptr->author && title == rhs_ptr->title) {
        return true;
    }

    //Childrens books titles or authors are different
    return false;
}
bool ChildrensBook::operator!=(const Media& copy) const
{
    return !(*this == copy);
}
void ChildrensBook::changevals(std::string author2, int year2, std::string title2, int copies) {       //DELETE THIS ONLY FOR TESTING
    author = author2;
    year = year2;
    title = title2;
    numCopies = copies;
}
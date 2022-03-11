#include "childrens_book.h"
#include  <string>
#include <iomanip>
using namespace std;

ChildrensBook::ChildrensBook()
{
    author = "";
    numCopies = kNumChildrenBooks;
    title = "FactoryChildrensBook";
    year = 0;
}

Media* ChildrensBook::create(std::istream& infile)
{
    //Take inputs into seperate strings incase we want to do error checking in the future
    string authorStr = "";
    string titleStr = "";
    int date = 0;

    ChildrensBook* createdBook = new ChildrensBook();
    infile.get();                     // get (and ignore) blank before author
    getline(infile, authorStr, ',');
    createdBook->author = authorStr;
    infile.get();                     // get (and ignore) blank before author
    getline(infile, titleStr, ',');
    createdBook->title = titleStr;
    infile >> date;
    createdBook->year = date;

    return createdBook;
}

Media* ChildrensBook::createFromCommand(istream& infile)
{
    //Take inputs into seperate strings incase we want to do error checking in the future
    string authorStr = "";
    string titleStr = "";

    ChildrensBook* createdBook = new ChildrensBook();

    infile.get();                     // get (and ignore) blank before title
    getline(infile, titleStr, ',');
    createdBook->title = titleStr;
    infile.get();                     // get (and ignore) blank before author
    getline(infile, authorStr, ',');
    createdBook->author = authorStr;
    //Date just stays as zero which is fine because these books will just be used to search fro the real book in the library

    return createdBook;
}

ChildrensBook::~ChildrensBook()
{
}

bool ChildrensBook::checkOut()
{
    if (numCopies >= 1) {
        numCopies--;
        return true;
    }
    cout << "No coppies left to check out" << endl;
    return false;
}

void ChildrensBook::checkIn()
{
    numCopies++;
}

void ChildrensBook::displayInLibrary() const
{

    string numCopiesStr = to_string(numCopies);
    string yearStr = to_string(year);

    cout << left << setw(kMaxNumBooksLength + 2)
        << numCopiesStr.substr(0, kMaxNumBooksLength) <<
        setw(kMaxAuthorLength + 2) << author.substr(0, kMaxAuthorLength)
        << setw(kMaxTitleLength + 2) << title.substr(0, kMaxTitleLength)
        << right << setw(kMaxYearLength) << yearStr.substr(0, kMaxYearLength);
}

void ChildrensBook::displayInPatron() const
{
    string numCopiesStr = to_string(numCopies);
    string yearStr = to_string(year);

    cout << left << setw(kDisplayIndentSize) << ""
        << setw(kMaxAuthorLength + 2) << author.substr(0, kMaxAuthorLength)
        << setw(kMaxTitleLength + 2) << title.substr(0, kMaxTitleLength)
        << right << setw(kMaxYearLength) << yearStr.substr(0, kMaxYearLength);
}

void ChildrensBook::displayTitle() const
{
    cout << left << setw(kMaxTitleLength + 2) << title.substr(0, kMaxTitleLength);
}

void ChildrensBook::displayComponents() const
{
    cout << "AVAIL " << "AUTHOR" << setw(18) << "" << "TITLE" << setw(33) << "" << "YEAR" << endl;
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

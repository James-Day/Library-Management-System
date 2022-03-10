#include "fiction_book.h"
#include <iomanip>
#include <string>
using namespace std;

FictionBook::FictionBook()
{
    author = "";
    numCopies = kNumFictionBooks;
    title = "FactoryFictionBook";
    year = 0;
}

Media* FictionBook::create(istream& infile)
{
    //Take inputs into seperate strings incase we want to do error checking in the future
    string authorStr = "";
    string titleStr = "";
    int date = 0;

    FictionBook* createdBook = new FictionBook();
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


Media* FictionBook::createFromCommand(istream& infile)
{
    //Take inputs into seperate strings incase we want to do error checking in the future
    string authorStr = "";
    string titleStr = "";
    string endOfLine = "";

    FictionBook* createdBook = new FictionBook();

    infile.get();                     // get (and ignore) blank before author
    getline(infile, authorStr, ',');
    createdBook->author = authorStr;
    infile.get();                     // get (and ignore) blank before author
    getline(infile, titleStr, ',');
    createdBook->title = titleStr;

    return createdBook;
}


FictionBook::~FictionBook()
{
}

bool FictionBook::checkOut()
{
    if (numCopies >= 1) {
        numCopies--;
        return true;
    }
    return false;
}

bool FictionBook::checkIn()
{
    numCopies++;
    return true;
}

void FictionBook::displayInLibrary() const
{
    string numCopiesStr = to_string(numCopies);
    string yearStr = to_string(year);

    cout << left << setw(kMaxNumBooksLength+2)
        << numCopiesStr.substr(0, kMaxNumBooksLength) <<
        setw(kMaxAuthorLength + 2) << author.substr(0, kMaxAuthorLength)
        << setw(kMaxTitleLength + 2) << title.substr(0,kMaxTitleLength)
        << right << setw(kMaxYearLength) << yearStr.substr(0,kMaxYearLength);
}

void FictionBook::displayInPatron() const
{
    string numCopiesStr = to_string(numCopies);
    string yearStr = to_string(year);                           //Will have to change to look like hers

    cout << left << "  "
        << setw(kMaxAuthorLength + 2) << author.substr(0, kMaxAuthorLength)
        << setw(kMaxTitleLength + 2) << title.substr(0, kMaxTitleLength)
        << right << setw(kMaxYearLength) << yearStr.substr(0, kMaxYearLength);
}

bool FictionBook::operator<(const Media& rhs) const
{
   const FictionBook * rhs_ptr = dynamic_cast<const FictionBook*>(&rhs);
   if (author < rhs_ptr->author ) {
       return true;
   }
   else if (author == rhs_ptr->author) {
       if (title < rhs_ptr->title) {
           return true;
       }
   }
   //if Title and Author are same or title or author is greater than rhs.
    return false;
}

bool FictionBook::operator>(const Media& rhs) const
{
    const FictionBook* rhs_ptr = dynamic_cast<const FictionBook*>(&rhs);
    if (author > rhs_ptr->author) {
        return true;
    }
    else if (author == rhs_ptr->author) {
        if (title > rhs_ptr->title) {
            return true;
        }
    }
    //if Title and Author are same or title or author is less than rhs.
    return false;
}

bool FictionBook::operator==(const Media& rhs) const
{
    const FictionBook* rhs_ptr = dynamic_cast<const FictionBook*>(&rhs);
    if (author == rhs_ptr->author && title == rhs_ptr->title) {
        return true;
    }

    //Fiction books titles or authors are different
    return false;
}
bool FictionBook::operator!=(const Media& copy) const
{
    return !(*this == copy);
}
void FictionBook::changevals(std::string author2, int year2, std::string title2, int copies){       //DELETE THIS ONLY FOR TESTING
    author = author2;
    year = year2;
    title = title2;
    numCopies = copies;
}
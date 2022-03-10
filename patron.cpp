#include "patron.h"
#include "command.h"

Patron::Patron()
{
    firstName = "DEFAULT";
    lastName = "DEFAULT";
    ID = 0000;
    for (int i = 0; i < kStartingBookLimit; i++) {
        all_books[i] = nullptr;
    }
}

Patron::Patron(std::string patronName,std::string patronLastName, int patronID)
{
    firstName = patronName;
    lastName = patronLastName;
    ID = patronID;
    for (int i = 0; i < kStartingBookLimit; i++) {
        all_books[i] = nullptr;
    }
}

bool Patron::checkOut(Media* checkingOut)
{
    for (int i = 0; i < kStartingBookLimit; i++) {
        if (all_books[i] == nullptr) {
            all_books[i] = checkingOut;
            return true;
        }
    }
    return false;
}

Media* Patron::returnBook(Media* returnBook)
{
    for (int i = 0; i < kStartingBookLimit; i++) {
        if (all_books[i] != nullptr) {
            if (all_books[i] == returnBook) {
                Media* returnCopy = all_books[i];
                all_books[i] = nullptr;
                return returnCopy;
            }
        }
    }
    return nullptr;
}

bool Patron::addHistory(const Command* history)
{
    commandHistory.push_back(history);
    return true;
}

bool Patron::create(ifstream& infile)// bool just incase we want to update it later to check for valid input or something
{
    string first = "";
    string last = "";
    int idNumber = 0;

    infile >> idNumber;
    infile >> last;
    infile >> first;
    ID = idNumber;
    lastName = last;
    firstName = first;

    return true;
}

void Patron::displayBooks() const
{
    for (int i = 0; i < kStartingBookLimit; i++) {
        if (all_books[i] != nullptr) {
            all_books[i]->displayInPatron();
            cout << endl;
        }
    }
}

void Patron::displayPatron() const
{
    cout << ID << " " << lastName << "," << " " << firstName << ":";
}

void Patron::displayHistory() const
{
    for (int i = 0; i < commandHistory.size(); i++) {
        commandHistory[i]->display();
    }
}

int Patron::getID()
{
    return ID;
}

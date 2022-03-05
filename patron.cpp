#include "patron.h"

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
        if (*all_books[i] == *returnBook) {
            Media* returnCopy = all_books[i];
            all_books[i] = nullptr;
            return returnCopy;
        }
    }
    return nullptr;
}

void Patron::displayBooks() const
{
    for (int i = 0; i < kStartingBookLimit; i++) {
        all_books[i]->display();
    }
}

void Patron::displayPatron() const
{
    cout << ID << lastName << "," << firstName;
}

int Patron::getID()
{
    return ID;
}

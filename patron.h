//----------------------------------------------------------------------------
// class
// Patron: This class is a class that holds a patrons information and all
//         its currently checked out media. This class also stores all the
//         history of commands that this patron conducted including check out,
//         and return. This class can also be used to display the history
//         of commands that a patron has used. Patrons can check out media
//         and a pointer to that media will be stored in their currently
//         checked out media. They can also return media.
//
// Implementation and assumptions:
//      -- It is assumed that input will be formated correctly for
//         creating a patron from a file.
//      -- This class is created from a given file using the create method
//      -- It is assumed that every patron has a first and last name as well
//         as a ID
//----------------------------------------------------------------------------

#ifndef PATRON_H_
#define PATRON_H_
#include "media.h"
#include <fstream>
#include <iostream>
#include <vector>
class Command;

class Patron {
  public:
    /* initializes Patrons first name, last name, ID, and all book pointers */
    Patron();

    /* this patron is initialized with a first name, last name, and a ID*/
    Patron(std::string patron_name, std::string patron_last_name, int id);

    /* deletes all the commands in the patrons history*/
    ~Patron();

    /* the given book is entered into this patrons list of books*/
    bool checkOut(Media *checking_out);

    /* searches through the patrons medias that are currently checked out.
   If the media is found then the media is returned*/
    Media *returnMedia(Media *return_book);

    /* adds a history to the end list of users history of commands*/
    bool addHistory(const Command *history);

    /* given an input file, this function will read in the patrons ID number,
   last, and first name. if patron is successfully created, true is returned*/
    bool create(ifstream &infile);

    /* all books that are currently checked out from this patron will be
    displayed*/
    void displayBooks() const;

    /* displays information of the patron including ID and name*/
    void displayPatron() const;

    /* displays all command histories of this patron*/
    void displayHistory() const;

    /* returns the PatronsID*/
    int getID() const;

  private:
    /*Uses a hashtable to store a list of all the
      books a patron has checked out currently*/
    std::vector<Media *> all_media_;

    /*storage of the commands that a user has used for example checking out
      or returning different type sof media*/
    std::vector<const Command *> command_history_;

    // patron's first name
    std::string first_name_;

    // patron's last name
    std::string last_name_;

    // patrons ID
    int ID_;
};

#endif
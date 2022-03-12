//----------------------------------------------------------------------------
// class Manager: The manager is the highest level of the Library System.
//                The manager has a library that stores all the media. The
//                Manager also stores all of the patron's data as well as
//                three factories that are used for creating and executing
//                commands.
// Implementation and assumptions:
//     -- Assume format of data files are correct
//     -- Handles the initialization of all books/media of the library
//     -- Handles the initialization of all patrons
//     -- Handles the initialziation of all book transactions
//     -- Uses Command Factory, Media Factory, and Format factory
//        To make and execute commands
//----------------------------------------------------------------------------

#ifndef MANAGER_H_
#define MANAGER_H_

#include "command_factory.h"
#include "format_factory.h"
#include "library.h"
#include "media_factory.h"
#include "patron_container.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class Manager {
  public:
    /* currently this constructor holds no code */
    Manager();

    // reads in all media from a file and inputs them into the library
    void inputMediaFile(const string infile);

    /* reads in all patrons from a fileand inputs them into
    the patron container */
    void inputPatreonFile(const string infile);

    /* input transactions and processes them one at a time. Each valid
       command is exectuded*/
    void inputTransactions(const string infile);

    // Classes that have access to this classes private data
    //(all command classes)
    friend class CheckOut;
    friend class ReturnMedia;
    friend class DisplayLibrary;
    friend class PatronHistory;

  private:
    /*Library class is used for storing all the media objects that are read in
      using the inuptMediaFile command*/
    Library library_;

    /*A container that holds patrons which are inserted using the
    inputPatronFile command*/
    PatronContainer patrons_;

    /* Factory used for creating new instances of a given type of media*/
    MediaFactory mediaFactory_;

    /* Factory used for creating new instances of a given type of command*/
    CommandFactory commandFactory_;

    /* Factory used for creating new instances of a given type of format*/
    FormatFactory formatFactory_;
};
#endif

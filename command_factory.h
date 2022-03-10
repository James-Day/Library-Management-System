//----------------------------------------------------------------------------
// class Command Factory
// Command Factory: Creates proper Media object type accoordingly
// Implementation and assumptions:
//     -- Each character creates a different type of media
//     -- Stores an array of media pointers
//     -- Has a hash function for indexing character letter
//     -- Creates and returns the correct Media object according to the
//        character passed in, character indicates type of media
//----------------------------------------------------------------------------

#ifndef COMMAND_FACTORY_H_
#define COMMAND_FACTORY_H_

#include "command.h"
#include "check_out.h"
#include "return_media.h"
#include "display_library.h"
#include "patron_history.h"

using namespace std;
class Manager;
const int kMaxNumCommands = 26;
class CommandFactory {
public:
   
    CommandFactory();
   
    ~CommandFactory();                                                             

    bool executeCommand(Manager* libraryManager, const char& commandCh,
        istream& infile);

private:
    /* Holds one of each type of media to create new types of that media
    size is only large enough for one character codes
    characters(in the future if we want to have more than 26
    types of media we could create a method that grows the array)*/
    Command* commandFactory[kMaxNumCommands];
    
    // returns the index of the array to use for creating the Media
    int hash(const char& ch) const;
};
#endif

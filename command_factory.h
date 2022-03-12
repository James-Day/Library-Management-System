//----------------------------------------------------------------------------
// class Command Factory
// Command Factory: Creates proper command object type accoordingly
// Implementation and assumptions:
//     -- Each character creates a different type of command
//     -- Stores an array of command pointers
//     -- Has a hash function for indexing character letter
//     -- Creates and returns the correct command object according to the
//        character passed in, character indicates type of command
//----------------------------------------------------------------------------

#ifndef COMMAND_FACTORY_H_
#define COMMAND_FACTORY_H_

#include "check_out.h"
#include "command.h"
#include "display_library.h"
#include "patron_history.h"
#include "return_media.h"

using namespace std;
class Manager; // forward decleration of the manager class

// max number of commands that can be stored
const int kMaxNumCommands = 26;
class CommandFactory {
  public:
    /* the constructor for the command factory creates any command types that
   are given in the command input file*/
    CommandFactory();

    /* the destructor for the command factory deletes any command types
   that exist within the factory.*/
    ~CommandFactory();

    /*  The function creates a new command and executes it. If the command
    successfully executes, then true is returned if the command does not
    execute properly, it is deleted and false is returned*/
    bool executeCommand(Manager *library_manager, const char &type_command,
                        istream &infile) const;

  private:
    /* Holds one of each type of command to create new types of that command.
    size is only large enough for one character codes (in the future if we
    want to have more than 26 types of commands we could create a method that
    grows the array)*/
    Command *command_factory_[kMaxNumCommands];

    // returns the index of the array to use for creating the command
    int hash(const char &type_command) const;
};
#endif

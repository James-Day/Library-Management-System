// ---------------------------------------------------------------------------
// Command: The Command class is a base class for command objects. Commands
//          are used for any type of operation that is to be accomplished
//          within the library. Commands are given a manager of a library to
//          execute any type of Command.
//
// Implementation and assumptions:
//      -- It is assumed that any types of commands will use this Command
//         class as a base class.
//      -- Every type of command will have an execute function for executing
//         that command.
//      -- Every type of command will also have a create function to create
//         a new instance of that command.
//      -- Commands are executed using an instance of a manager.
//
//----------------------------------------------------------------------------

#ifndef COMMAND_H_
#define COMMAND_H_
#include <iostream>

// max length for displaying the name of the command
const int kCommandMaxLength = 10;
// the indent size that is used when displaying commands in a patron's history
const int kIndentSize = 3;

using namespace std;
class Manager; // forward devleration of the manager class
class Command {
  public:
    /* currently this destructor holds no code but is neccesary to prevent
       memory leak*/
    virtual ~Command() = 0;

    /* executes the command that is read in from the file and uses the
       manager class to complete the command*/
    virtual bool execute(Manager *library_manager, istream &infile) = 0;

    /* currently this display does nothing, but children classes
can overload this if desired*/
    virtual void display() const;

    // creates and returns a new instance of this type of command
    virtual Command *create() const = 0;
};
#endif

#include "command_factory.h"
#include "manager.h"
//--------------------------------------------------------------------------
// CommandFactory (constructor)
/* the constructor for the command factory creates any command types that
   are given in the command input file There is currently no way to add new
   Media types but this could be afuture work*/
CommandFactory::CommandFactory() {
    for (int i = 0; i < kMaxNumCommands; i++) {
        command_factory_[i] = nullptr;
    }
    command_factory_[hash('C')] = new CheckOut();
    command_factory_[hash('D')] = new DisplayLibrary();
    command_factory_[hash('R')] = new ReturnMedia();
    command_factory_[hash('H')] = new PatronHistory();
}

//--------------------------------------------------------------------------
// CommandFactory (destructor)
/* the destructor for the command factory deletes any command types
   that exist within the factory.*/
CommandFactory::~CommandFactory() {
    for (int i = 0; i < kMaxNumCommands; i++) {
        if (command_factory_[i] != nullptr) {
            delete command_factory_[i];
        }
    }
}

//--------------------------------------------------------------------------
// executeCommand
/* This function uses the library manager, the input stream, and a character
   specifying the type of command. The function creates a new command and
   executes it. If the command successfully executes, then true is returned
   if the command does not execute properly, it is deleted and false is
   returned*/
bool CommandFactory::executeCommand(Manager *library_manager,
                                    const char &command_type,
                                    istream &infile) const {
    int factory_index = hash(command_type);
    if ((factory_index > 25 || factory_index < 0) ||
        (command_factory_[factory_index] == nullptr)) { // valid command
        cout << "Command Error: '" << command_type
             << "' is not a valid command type" << endl;
        return false;
    }
    Command *new_command = nullptr;

    // create new command
    new_command = command_factory_[factory_index]->create();
    if (!new_command->execute(library_manager, infile)) { // execute new command
        delete new_command;
        return false;
    }
    return true;
}

//--------------------------------------------------------------------------
// hash
/* simple hash function that converts the character for type of command
   to a integer for indexing into the command factory*/
int CommandFactory::hash(const char &ch) const { return ch - 'A'; }
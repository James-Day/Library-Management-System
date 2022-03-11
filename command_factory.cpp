#include "command_factory.h"
#include "manager.h"
CommandFactory::CommandFactory()
{
    for (int i = 0; i < kMaxNumCommands; i++) {
        commandFactory[i] = nullptr;
    }
    commandFactory[hash('C')] = new CheckOut();
    commandFactory[hash('D')] = new DisplayLibrary();
    commandFactory[hash('R')] = new ReturnMedia();
    commandFactory[hash('H')] = new PatronHistory();

}
CommandFactory::~CommandFactory()
{
    for (int i = 0; i < kMaxNumCommands; i++) {
        if (commandFactory[i] != nullptr) {
            delete commandFactory[i];
        }
    }
}
bool CommandFactory::executeCommand(Manager* libraryManager, const char& ch, istream& infile)
{
    int factoryIndex = hash(ch);
    if ((factoryIndex > 25 || factoryIndex < 0) || (commandFactory[factoryIndex] == nullptr)) {
        return false;
    }
    Command* newCommand = nullptr;
    newCommand = commandFactory[factoryIndex]->create();
    if (!newCommand->execute(libraryManager, infile)) {
        delete newCommand;
        return false;
    }

    return true;
}

int CommandFactory::hash(const char& ch) const
{
    return ch - 'A';
}


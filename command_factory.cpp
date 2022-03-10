#include "command_factory.h"
/*#include "command_factory.h"
CommandFactory::CommandFactory()
{
    for (int i = 0; i < kMaxNumCommands; i++) {
        commandFactory[i] = nullptr;
    }
    //commandFactory[hash('C')] = new CheckOut();
    //commandFactory[hash('D')] = new DisplayLibrary();      //Not sure if this is allowed, I should ask prof during office hours
   // commandFactory[hash('R')] = new ReturnMedia();
    //commandFactory[hash('H')] = new PatronHistory();

}
CommandFactory::~CommandFactory()
{
    for (int i = 0; i < kMaxNumCommands; i++) {
        if (commandFactory[i] != nullptr) {
            delete commandFactory[i];
        }
    }
}
Command* CommandFactory::executeCommand(const char& ch, istream& infile)
{
    int factoryIndex = hash(ch);
    if ((factoryIndex > 25 || factoryIndex < 0) || (commandFactory[factoryIndex] == nullptr)) {
        return nullptr;
    }
    return nullptr;
   // return commandFactory[factoryIndex]->execute(infile);
}

void CommandFactory::display()
{
    for (int i = 0; i < kMaxNumCommands; i++) {
        if (commandFactory[i] != nullptr) {
            commandFactory[i]->display();;
        }
    }
}

int CommandFactory::hash(const char& ch) const
{
    return ch - 'A';
}*/

CommandFactory::CommandFactory()
{
}

CommandFactory::~CommandFactory()
{
}

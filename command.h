#ifndef COMMAND_H_
#define COMMAND_H_
#include <iostream>
// ---------------------------------------------------------------------------
// Command: The Command class is a base class for command objects
// 
// Implementation and assumptions:
//	
const int kCommandMaxLength = 10;
const int kIndentSize = 3;
using namespace std;
class Manager;
class Command {
public:
    Command();
    virtual ~Command() = 0;
    /* No constructor for the media class?
    *
    /*overwritten by all media subclasses and will return a pointer to
    a new Command subclass object that is created*/
    virtual bool execute(Manager* libraryManager, istream& infile) = 0;
    virtual void display() const = 0;
    virtual Command* create() = 0;
protected:

};

#endif

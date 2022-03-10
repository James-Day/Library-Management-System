#ifndef COMMAND_H_
#define COMMAND_H_
#include <iostream>
// ---------------------------------------------------------------------------
// Command: The Command class is a base class for command objects
// 
// Implementation and assumptions:
//	
using namespace std;
class Manager;
class Command {
public:
	/* No constructor for the media class?
	*
	/*overwritten by all media subclasses and will return a pointer to
	a new Command subclass object that is created*/
	virtual bool execute(Manager* libraryManager, istream& infile) const = 0;
	virtual void display() const = 0;
protected:

};

#endif

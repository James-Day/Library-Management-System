#include "command.h"

//--------------------------------------------------------------------------
// Command (destructor)
/* currently this destructor holds no code but is neccesary to prevent memory
leak*/
Command::~Command() {}

//--------------------------------------------------------------------------
// display
/* currently this display does nothing, but children classes
can overload this if desired*/
void Command::display() const {}

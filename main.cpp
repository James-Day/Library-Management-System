#include "manager.h"

using namespace std;
//--------------------------------------------------------------------------
// Main
/* A Manager of the library is created, then all data is read in from a
   specified file, followed by patrons from a specified file, and lastly
   transactions from a specified file*/
int main() {

    Manager manager;
    manager.inputMediaFile("data4books.txt");
    manager.inputPatreonFile("data4patrons.txt");
    manager.inputTransactions("data4commands.txt");
}

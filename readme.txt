1. Everything works as intended. There are no memory leaks as well.
2. The Patron Container class is the hashtable that I created. IT is used to store all the patrons by ID.(patron_container.h)
   Media Factory, Command Factory, and Format Factory are all essentially hash tables.
3. Manager(manager.h) reads the type of book from the inputMediaFile function, this is sent to the factory which creates the correct type of book
   Once the book is made, it reads the rest of the data that is needed for it.
4. Manager(manager.h) reads the type of command which is passed to the command factory. The command factory makes the respective type of command.
   Then the command reads in the required data. In the case of check out and return, the command factory reads the patron ID, type of book and the format
   Then a book is created to read the rest of data for the book that is being checked out or returned.
5. I am not aware of any instances in which I break the open close principle.
6. I'm just pretty proud of accomplishing an assignment of this size. I didn't have any particular class that I was impressed with I guess.
   
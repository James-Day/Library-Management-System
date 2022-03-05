#include "manager.h"

Manager::Manager()
{
}

void Manager::displayLibrary() const
{
   library.display();
}

void Manager::inputMediaFile(string infile) // This will be moved to a transaction class but for now it's fine
{
    ifstream media_in_file(infile);                                             //check which type of variable I'm supposed to use _'s or camel
    char bookType = '0';       

    
    // you must purge the rest of the int line or the end-of-line char will
    // be the string read
   

    // read graph node information
     for(;;)
    {
        media_in_file >> bookType;                // read the type of book
        if (media_in_file.eof()) return;// stop reading if no more data   ///Maybe this eof check chould be the first thing in the for loop, check if this is correct by testing an empty file

        Media* createdMedia = mediaFactory.createMedia(bookType, media_in_file);
        //if media was created
        if (createdMedia != nullptr) {
            library.insert(createdMedia, bookType);
        }
        else {
             string s;                  // used to read to end of line holding size
             getline(media_in_file, s);        
        }
    }
    // read the edge data and add to the adjacency list
    /*for (;;)
    {
        media_in_file >> fromNode >> toNode;
        if (fromNode == 0 && toNode == 0) return;   // end of edge data
        insertEdge(fromNode, toNode);
        // insert a valid edge into the adjacency edge STL list for fromNode
    }*/
}

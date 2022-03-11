#include "library.h"
//--------------------------------------------------------------------------
// Library (constructor)
/* constructor for the library creates binary search trees to store each type 
   of media. For now there are 3 types of books that are created and stored
   in the library.*/
Library::Library() {
    for (int i = 0; i < MAXMEDIA; i++) {
        containers[i] = nullptr;
    }
    //container for Children Books
    containers[hash('C')] = new BinTree("Childrens Books");
    //container for Fiction Books
    containers[hash('F')] = new BinTree("Fiction Books");
    //container for Periodical Books
    containers[hash('P')] = new BinTree("Periodicals");

}

//--------------------------------------------------------------------------
// Library (destructor)
/* destructor for the library calls destructor of each binary tree that
   is being stored in this library for sorting media*/
Library::~Library()
{
    for (int i = 0; i < MAXMEDIA; i++) {
        if (containers[i] != nullptr) {
            delete containers[i];
        }
    }
}

//--------------------------------------------------------------------------
// insert
/* given a media pointer and the type of book this function hashes the media
   type and inserts the media into the respective container.*/
bool Library::insert(Media* insert_media, char media_type)
{
    return containers[hash(media_type)]->insert(insert_media);
}

//--------------------------------------------------------------------------
// checkOutMedia
/* given a media pointer and the type of book this function hashes the media
   type and retrieves the book from the respective binary search tree
   if the book is not found, then nullptr is returned.*/
Media* Library::checkOutMedia(const Media* check_out_media, char media_type)
{
    Media* found = nullptr;
    if (containers[hash(media_type)]->retrieve(*check_out_media, found)) {
        return found;
    }
    //book was not found
    return nullptr;
}

//--------------------------------------------------------------------------
// checkInMedia
/* given a media pointer and the type of book this function hashes the media
   type and retrieves the book from the respective binary search tree
   if the book is not found false is returned. If the book is found checkIn
   is called on the found media and true is returned*/
bool Library::checkInMedia(Media* check_in_media, char media_type)
{
    Media* found = nullptr;
    if (containers[hash(media_type)]->retrieve(*check_in_media, found)) {
        found->checkIn();
        return true;
    }
    //book was not found in system and book was not returned.
    return false;
}

//--------------------------------------------------------------------------
// display
/* displays all the books in the library. Each tree in the container is
   printed as well as the type of media they are storing*/
void Library::display() const
{
    for (int i = 0; i < MAXMEDIA; i++) {
        if (containers[i] != nullptr) {
            //display a header for each container of books
            cout << endl << "------ " << containers[i]->getName()
                << " -------" << endl;
            cout << *containers[i];
        }
    }
}

//--------------------------------------------------------------------------
// hash
/* simple hash function that converts the character for type of media
   to a integer for indexing into it's respective tree in the library*/
int Library::hash(const char& type_media) const
{
    return type_media - 'A';
}

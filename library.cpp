#include "library.h"
Library::Library() {
	for (int i = 0; i < 2; i++) {
		//container for Children Books
		//container for Fiction Books
		//container for Periodical Books
		containers[i] = new BinTree();
	}
	for (int i = 3; i < MAXMEDIA; i++) {
		containers[i] = NULL;
	}
}

Library::~Library()
{
	for (int i = 0; i < MAXMEDIA; i++) {
		containers[i]->makeEmpty();
	}
}

bool Library::insert(Media* aMedia, int containerNumber)
{
	if (containers[containerNumber]->insert(aMedia)) {
		return true;
	}
	return false;
}

Media* Library::checkOutMedia(const Media* aMedia, int containerNumber) // might have to rework this as I'm not sure how you would have a book before checking it out. //I also might bass by value a book to be updated to the one that is checkedout
{
	Media* found = nullptr;
	if (containers[containerNumber]->retrieve(*aMedia, found)) {
		found->checkOut();
		return found;
	}
	//book was not found
	return nullptr;
}

bool Library::checkInMedia(Media* aMedia, int containerNumber)
{
	Media* found = nullptr;
	if (containers[containerNumber]->retrieve(*aMedia, found)) {
		found->checkIn();
		return true;
	}
	//book was not found in system and book was not returned.
	return false;
}

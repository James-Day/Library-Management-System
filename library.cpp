#include "library.h"
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

Library::~Library()
{
	for (int i = 0; i < MAXMEDIA; i++) {
		if (containers[i] !=nullptr) {
			delete containers[i];
		}
	}
}

bool Library::insert(Media* aMedia, char bookType)
{
	return containers[hash(bookType)]->insert(aMedia);
		
}

Media* Library::checkOutMedia(const Media* aMedia, char bookType) // might have to rework this as I'm not sure how you would have a book before checking it out. //I also might bass by value a book to be updated to the one that is checkedout
{
	Media* found = nullptr;
	if (containers[hash(bookType)]->retrieve(*aMedia, found)) {
		//if (found->checkOut()) { //doing this in manager class instead
			return found;
		//}
	}
	//book was not found
	return nullptr;
}

bool Library::checkInMedia(Media* aMedia, char bookType)
{
	Media* found = nullptr;
	if (containers[hash(bookType)]->retrieve(*aMedia, found)) {
		found->checkIn();
		return true;
	}
	//book was not found in system and book was not returned.
	return false;
}

void Library::display() const
{
	for (int i = 0; i < MAXMEDIA; i++) {
		if (containers[i] != nullptr) {
			cout << endl << "------ " << containers[i]->getName() << " -------" << endl;
			cout << *containers[i];
		}
	}
}

int Library::hash(const char& ch) const
{
	return ch - 'A';
}

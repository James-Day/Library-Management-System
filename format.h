#ifndef TYPE_OF_MEDIA_H_
#define TYPE_OF_MEDIA_H_
// ---------------------------------------------------------------------------
// TypeOfBook: The TypeOfBook class is a base class for TypeOfBook objects
// 
// Implementation and assumptions:
//	
#include "media.h"
using namespace std;
class Format {
public:

    virtual bool checkOutMedia(Media* checkOutMedia) = 0;
    virtual void returnMedia(Media* returnMedia) = 0;

};

#endif


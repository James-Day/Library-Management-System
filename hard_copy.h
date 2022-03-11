#ifndef HARD_COPY_H_
#define HARD_COPY_H_
// ---------------------------------------------------------------------------
// HardCopy: The HardCopy class is a child class for TypeOfBook 
// 
// Implementation and assumptions:
//	
#include "format.h"
using namespace std;
class HardCopy : public Format {
public:

    virtual bool checkOutMedia(Media* checkOutMedia);
    virtual void returnMedia(Media* returnMedia);

protected:

};
#endif
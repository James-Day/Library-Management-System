#include "hard_copy.h"
//--------------------------------------------------------------------------
// checkOutMedia
/* calls the media's checkOut function which indicate how to handle hard copy
   checkOuts. if the book is able to be checked out true is returned
   otherwise, false.*/
bool HardCopy::checkOutMedia(Media* checkOutMedia)
{
    //Calls the checkout function of the media type
    return checkOutMedia->checkOut();
}

//--------------------------------------------------------------------------
// returnMedia
/* calls the media's checkIn function which indicate how to handle hard copy
   returns*/
void HardCopy::returnMedia(Media* returnMedia)
{
    //Calls the checkIn function of the media type
    return returnMedia->checkIn();
}

#include "hard_copy.h"
//--------------------------------------------------------------------------
// checkOutMedia
/* calls the media's checkOut function which indicate how to handle hard copy
   checkOuts. if the book is able to be checked out true is returned
   otherwise, false.*/
bool HardCopy::checkOutMedia(Media *check_out_media) const {
    // Calls the checkout function of the media type
    return check_out_media->checkOut();
}

//--------------------------------------------------------------------------
// returnMedia
/* calls the media's checkIn function which indicates how to handle hard copy
   returns*/
void HardCopy::returnMedia(Media *return_media) const {
    // Calls the checkIn function of the media type
    return return_media->checkIn();
}

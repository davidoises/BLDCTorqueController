#ifndef _PRINT_H_
#define _PRINT_H_

// Includes
//#include "hal_obj.h"
//#include <string.h>

//!
//!
//! \defgroup Print
//!
//@{


#ifdef __cplusplus
extern "C" {
#endif

// This variable is initialized in hal init
SCI_Handle uart_sciHandle;

void printChar(char data)
{
    SCI_putDataNonBlocking(uart_sciHandle, data);
}

void printString(const char * data)
{
    int i;
    for (i = 0; data[i] != '\0'; ++i)
    {
        // Need to be blocking in order for it to wait/block until the current character finishes and attempt the next one
        SCI_putDataBlocking(uart_sciHandle, data[i]);
        //SCI_putDataNonBlocking(uart_sciHandle, data[i]);
    }
}


#ifdef __cplusplus
}
#endif // extern "C"

//@} // ingroup
#endif // end of _PRINT_H_ definition

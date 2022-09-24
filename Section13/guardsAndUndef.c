#include <stdio.h>

#define SOMETHING 7

// include guards looks like
#ifndef MYFILENAME  // if not define 'MYFILENAME' than..
#define MYFILENAME 1
#endif

// undef mean undefine the thing (the thing is without meaning)
#undef SOMETHING

void main(){
    #ifdef SOMETHING == 7 && MYFILENAME == 1
        printf("Something is on.\n");
    #elif MYFILENAME == 1
        printf("Something is off.\n");
    #endif


}
#include <stdio.h>
// also can be written here
// extern int i;

// the 1 dimension array dont must be initialize
// the 2D must initialize
// extern char text[][50];

extern int count;

void foo(void)
{
    // here its more organized
    extern int i;
    i = 100;
}


void write_extern(void){
    printf("Count is %d\n", count);
}
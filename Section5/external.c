#include <stdio.h>
#include "foo.c"

int i = 5;

// char text[255][25];

void foo(void);

int count;

extern void write_extern();


int main(void){
    printf("%i  ", i);
    foo();
    printf("%i  \n", i);

    count = 5;
    write_extern();
    return 0;
}
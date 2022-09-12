#include <stdio.h>

int main(){

    volatile int loc1; // loc1 is a volatile location
    volatile int *ploc; // ploc points to a volatile location

    /*
    volatile is option to lock the variable from changing by the compiler automatic,
    the compiler sometimes do optimizations like:
    if you declare 'int c = 10;'
    and after few lines (that not changed c value) you declare:
    'c = 23;' so the compiler understand that the program waste memory
    and could be faster if she delete the first declaration that c = 10.. 


    volatile vs const,
    const - things that not suppose to be change by the program
    volatile - if its will change by an agency other than the program
    */


    return 0;
}
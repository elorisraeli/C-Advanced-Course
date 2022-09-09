#include <stdio.h>

typedef int* i_pointer;

#define peach int;
unsigned peach x;
typedef int banana;

i_pointer chalk, cheese; // same as int *chalk, cheese;

typedef char * char_ptr;
char_ptr Bently, Rolls_Royce; // Both pointer to a char


int main(){

    i_pointer p; // same as int *p
    i_pointer a, *b; // same as int *a, **b;
    i_pointer myArray[10];// same as int *myArray[10];

    x = 0;
    banana i;
    i = 10;
    printf("%d and %d", x, i);

    return 0;
}
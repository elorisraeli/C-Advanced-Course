#include <stdio.h>

extern int count;

extern void display(void){
    printf("\n%d", count+1);
}
#include <stdio.h>

union mixed
{
    char c;
    float f;
    int i;
};

union number
{
    int x;
    double y;
};

void foo(union number n){
    union number x = n;
}


void main()
{
    // in union we can access to one variable each time
    union mixed data;
    data.c = 'j';
    // data.f = 784.3323;
    // data.i = 6;

    printf("Character = %c\n", data.c);
    // printf("Float = %f\n", data.f);
    // printf("Int = %d\n", data.i);


    union number value;

    value.x = 100;
    printf("Value of integer x: %d\n", value.x);
    printf("Value of double y: %f\n", value.y);

    value.y = 100;
    printf("Value of integer x: %d\n", value.x);
    printf("Value of double y: %f\n", value.y);

    union number value2 = {15}; // must be as the first variable (this time in number union is int)
    // also can be write as
    union number value3 = {.x = 16};

    union number x;
    union number *y = &x;
    y->y = 100.0; // put a double in the same union
    printf("X:\n");
    printf("Value of integer x: %d\n", x.x);
    printf("Value of double y: %f\n", x.y);
    printf("Y:\n");
    printf("Value of integer x: %d\n", y->x);
    printf("Value of double y: %f\n", y->y);
}
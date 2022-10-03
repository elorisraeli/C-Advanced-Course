#include <stdio.h>


/*
A macro is faster than a function (function takes longer than inline code)
*/

#define PI 3.14

#define PRNT(a, b)\
    printf("value of the first number is: %d\n", a); \
    printf("value of the second number is: %d\n", b); 

#define SQUARE(x) x*x

#define CIRCLE_AREA(radius) (PI * radius * radius)

#define Warning(...) fprintf(stderr, __VA_ARGS__)
// #define WarningAnotherOption(format, ...) fprintf(format, stderr, __VA_ARGS__) // need to define the format

// #define MISC(x) (puts("incrementing", (x)++)) // unfinished example

#define Max(a,b) ((a) > (b) ? (a) : (b)) // if a>b print a else print b


void main(){

    int x = 2;
    int y = 3;
    PRNT(x, y);
    printf("The square of y is: %d\n", SQUARE(y));

    int c = 5;
    int area = CIRCLE_AREA(c + 2);
    printf("The area of radius %d is: %d\n",c ,area);
    double r1 = 6.78;
    double r2 = 5.92;
    double max_r = Max(r1,r2);
    double circle_area = CIRCLE_AREA(max_r);
    printf("The area of radius %.2lf is: %.2lf\n",max_r ,circle_area);

    Warning("%s: this program is here\n", "ELOR");

}
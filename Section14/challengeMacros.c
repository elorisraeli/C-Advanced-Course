#include <stdio.h>

#define SUM(x, y) x + y
#define SQUARE(x) x *x
#define CUBE(x) x *x *x

#define IS_UPPER(char) (('A' <= char &&char <= 'Z') ? 1 : 0)
#define IS_LOWER(char) (('a' <= char &&char <= 'z') ? 1 : 0)

void main()
{

    printf("The sum is: %d\n", SUM(5, 6));
    printf("The square is: %d\n", SQUARE(5));
    printf("The cube is: %d\n", CUBE(5));
    for (char c = 'z'; c > '!'; c -= 32)
    {
        if (IS_LOWER(c))
            printf("%c is lowercase.\n", c);
        else if (IS_UPPER(c))
            printf("%c is uppercase.\n", c);
        else
            printf("%c is not an alphabetic character.\n", c);
    }

    char c;
    printf("Please enter a char: ");
    scanf("%c", &c);
    // c = getchar(); // another option
    (IS_UPPER(c) ? printf("%c is uppercase.\n", c) : printf("%c is lowercase.\n", c));
}
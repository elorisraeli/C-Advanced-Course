#include <stdio.h>

void main()
{
    char a[50] = "the empire strikes back";
    int i;
    for (i = 0; a[i] != 'm'; i++)
        ; // null statement

    printf("The 'm' char in the string is in position %d\n", i);

    int x = 3, y = 1, z = 2;
    if (y < z)
        if (x < y)
            printf("%d is the number in the middle\n", y);
        else
            ; // null statement because we want use the other 'else'
    else
        printf("The middle is unkown.\n");
}
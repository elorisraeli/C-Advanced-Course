#include <stdio.h>
#include "fun.c"

// if I write the function as a static function:
// static int fun(){..}
// I can only use the fun() function inside my file (only the same file that static have been written)
// and I wouldn't be able to call him in the fun.c file in fun2() function
int fun()
{
    static int count = 0;
    int localVar = 0;

    printf("automatic = %d, static = %d\n", localVar, count);

    count++;
    localVar++;
    return count;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        fun();
        fun2();
    }
    return 0;
}
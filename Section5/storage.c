#include <stdio.h>
#include <stdlib.h>

// a global double variable' only accessible inside this file
static double b = 5;
// a global float variable that is accessible with the entire program
float c = 10;
// a function that is only accessible with this file
void static func(void) {}

static int sumAll = 0;
int sum(int num)
{
    sumAll += num;
}

int sum_another_option(int num)
{
    static int sumAll = 0;
    sumAll += num;
    return sumAll;
}

#include "display.c" // without that line the extern seems not working..
int count;
void display(void);

int main()
{
    // an int variable with block scope and temporary storage
    auto int a = 0;
    // a float local variable with permanent storage
    register float d = 15;
    // a register int variable
    register int e = 20;

    printf("\n-First option-");
    printf("\n %d", sum(25));
    printf("\n %d", sum(15));
    printf("\n %d", sum(30));

    printf("\n-Second option-");
    printf("\n %d", sum_another_option(25));
    printf("\n %d", sum_another_option(15));
    printf("\n %d", sum_another_option(30));

    for (count = 0; count < 5; count++)
    {
        display();
    }

    return 0;
}

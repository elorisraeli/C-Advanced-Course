#include <stdio.h>

/*
Try not to use the goto statement unless its very useful in your code.
its mess the control flow of the program and its harder to follow.
instead we can use: 'continue;' and 'break;'.
*/

int main()
{
    /*

    // example of using goto statement:
    // example 1:
    const int calls = 5;
    int i, num, total = 0, average;
    for (i = 0; i < calls; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num < 0)
        {
            goto anotherLine;
        }
        total += num;
    }
// if the num is less than 1 gets here
// if the loop ends get here anyway
anotherLine:
    average = total / i;
    printf("The average is: %d\n\n", average);

    // example 2:
    const int max = 10;
    int sum = 0;
    for (int i = 0; i < 5; i++) // run 5 times
    {
        for (int j = 0; j < 6; j++) // run 5x6 times
        {
            for (int k = 0; k < 10; k++) // run 5x6x10 times
            {
                sum = i + j + k;
                printf("The sum of vars is: %d\n", sum);
                // with the max we can control how many times the loop execute
                if (sum == max)
                {
                    goto someLine;
                }
            }
        }
    }

someLine:
    printf("WE GET TO MAX SUM. (%d)", sum);

    */

    // Challenge:       ("Spaghetti loop", not good programming..)
    int value = 18;
    int i = 1, j, k= 0;

    outerLoop:
        if (i < value) {
           j = i;

           innerLoop:
              if (j < value) {
                printf(" ");
                j++;
                goto innerLoop;
              }
              else {
                 innerLoop2:
                    if (k != ((2 * i)))  {
                        if (k == 0 || k == (2 * i) - 3) {
                             printf("*");
                        }
                        printf(" ");
                        k++;
                        goto innerLoop2;
                    }

                    k = 0;
                    printf("\n");
                    i++;
                    goto outerLoop;
              }
        }
        else {
           i = 0;
           loop:
             if (i < (2 * value) - 1) {
               printf("*");
               i++;
               goto loop;
             }
        }

    return 0;
}
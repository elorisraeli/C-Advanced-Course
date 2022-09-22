#include <stdio.h>

int factorial(int n)
{
    int result = 0;
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void up_and_down(int n);

void main()
{

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial = %d\n", factorial(num));

    up_and_down(1);
}

void up_and_down(int n)
{
    printf("Level %d: n location %p\n", n, &n);
    if (n < 4)
        up_and_down(n + 1);

    printf("Level %d: n location %p\n", n, &n);
}
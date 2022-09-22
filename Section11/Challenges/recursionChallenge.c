#include <stdio.h>

int sum(int n);

int gcd(int a, int b);

char *reverse(char *str);

void main()
{

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Sum from number to zero = %d\n", sum(num));

    int a, b;
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    printf("gcd(%d, %d) = %d\n", a, b, findGCD(a, b));


    char str[100];
    char *rev = NULL;

    printf("Enter a string: ");
    scanf("%s", str);
    
    printf("The original string is: %s\n", str);
    rev = reverse(str);
    printf("The reverse string is: %s\n", rev);

}

int sum(int n)
{
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int findGCD(int a, int b){
    while (a != b)
    {
        if(a > b)
            return findGCD(a-b, b);
        else 
            return findGCD(a, b-a);
    }
    return a;
}

char *reverse(char *str){
    static int i = 0;
    static char rev[100];

    if (*str) // if (*str == NULL)
    {
        reverse(str + 1);
        rev[i++] = *str;
        printf("Current string is: %s\n", rev);
    }
    return rev;
    
}
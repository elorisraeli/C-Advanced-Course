#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPrime(int num);
int isEven(int num);

void main()
{

    FILE *fp = NULL;
    char numbers[255];
    int num = 0, success = 0;
    fp = fopen("numbersFile.txt", "r");
    if (fp == NULL)
    {
        puts("Cant open file.\n");
        exit(EXIT_FAILURE);
    }

    success = fscanf(fp, "%d", &num);

    do
    {
        if (isPrime(num))
            printf("Prime number: %d\n", num);
        else if (isEven(num))
            printf("Even number: %d\n", num);
        else
            printf("Odd number: %d\n", num);
        success = fscanf(fp, "%d", &num);
    } while (success != -1);

    fclose(fp);
}

int isEven(int num)
{
    return !(num & 1);
}

int isPrime(int num)
{
    int i = 0;
    if (num < 0)
        return 0;
    for (int i = 2; i < num / 2; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
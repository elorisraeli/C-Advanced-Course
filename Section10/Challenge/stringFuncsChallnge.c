#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/*
the program will get a letter and a file name,
if there is line who starts with that letter, print her,
if there is more than one line like that, only print the first.
*/

void main()
{
    // get the character
    char ch;
    printf("Please enter a character from a-z:");
    ch = getc(stdin);

    // // get the string of the file name (works ok if the 'ch = getc(stdin);' not called)
    // char filenameBuffer[255];
    // char *b = filenameBuffer;
    // size_t myBufsize = 32;
    // size_t myCharacters;
    // printf("Please enter the file name:");
    // myCharacters = getline(&b, &myBufsize, stdin);
    // printf("\nYou type:\n %s \n", &filenameBuffer);

    // find the character and prints his line
    FILE *fp = NULL;
    char c;
    fp = fopen("challengeFile.txt", "r");
    // fp = fopen(&filenameBuffer, "r");
    if (fp == NULL)
        exit(1);
    int counter = 1;
    while (c != EOF)
    {
        c = getc(fp);
        if (c == ch)
        {
            while ((c != '\n') && (c != EOF))
            {
                fputc(c, stdout);
                c = getc(fp);
            }
            break;
        }
        while ((c != '\n') && (c != EOF))
            c = getc(fp);
        if (c == EOF)
        {
            printf("end of file.\n", counter++);
            break;
        }
        printf("Run number %d finished.\n", counter++);
    }
    fclose(fp);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

// int fputs(const char *buffer, FILE *filePtr);

void main()
{

    /*
    printf("Enter some words: \n");

    char buf[255];
    int ch = '\0';
    char *p = NULL;
    if (fgets(buf, sizeof(buf), stdin))
    {
        p = strchr(buf, '\n');
        if (p)
        {
            *p = '\0';
        }
        else {
            while (((ch = getchar()) != '\n') && (!feof(stdin)) && (!ferror(stdin)));
        }
    }
    else
    printf("fgets Failed.\n");

    printf("The buffer contains:\n %s\n", buf);
    */

    /*
    // option 1:
    char *buffer = NULL;
    size_t bufsize = 32;
    size_t characters;
    buffer = (char*)malloc(bufsize * sizeof(char));
    if (buffer == NULL)
     exit(1);
    printf("Type something: ");
    characters = getline(&buffer, &bufsize, stdin);

    printf("\nThe amount of character that have been read: %zu\n", characters);
    printf("You type:\n %s \n", buffer);



    // option 2:
    char myBuffer[32];
    char *b = myBuffer;
    size_t myBufsize = 32;
    size_t myCharacters;
    printf("Type something: ");
    myCharacters = getline(&b, &myBufsize, stdin);
    printf("\nThe amount of character that have been read: %zu\n", myCharacters);
    printf("You type:\n %s \n", &myBuffer);



    // output a sting
    char string[40];
    strcpy(string, "Hello, how are you?");
    puts(string);
    */


   FILE *fp = NULL;
   fp = fopen("someFile.txt", "w");
   if (fp == NULL)
    exit(1);
    fputs("Hello there, I hope its will be written in the file 'someFile.txt'\n", fp);
    fputs("If it does its really awesome!!\n", fp);
    fclose(fp);
   


}
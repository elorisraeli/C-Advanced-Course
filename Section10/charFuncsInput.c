#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getc(FILE *stream);

int ungetc(int ch, FILE *stream);

void main()
{
    /*
    char ch = '\0';
    FILE *fp;
    if (fp = fopen("About_Section10.txt", "rw"))
    {
        ch = getc(fp);
        printf("%c", ch);
        while (ch != EOF)
        {
            ch = getc(fp);
            printf("%c", ch);
        }
        fclose(fp);
    }
    */

    printf("Please enter a character: ");
    char ch_read = '\0';
    ch_read = getc(stdin);
    printf("The character is: %c\n", ch_read);

    //    // more option (need to run without the first option)
    //    printf("Another character is: %c\n", getchar());

    // // another way to read characters in a row
    // int ch_instant_read = 0;
    // while ((ch_instant_read = getchar()) != EOF)
    // {
    //     printf("%c\n", ch_instant_read);
    // }

    /*
    // another read from file option
    FILE *fptr = NULL;
    char c = '\0';
    fptr = fopen("About_Section10.txt", "r");
    if (fptr == NULL)
    {
        printf("Couldnt open file.\n");
        exit(0);
    }

    printf("Reading the file.\n");
    while (1)
    {
        c = fgetc(fptr);
        if (c == EOF)
        {
            break;
        }
        printf("%c", c);
    }
    printf("\nClosing the file.\n");
    fclose(fptr);
    */

   char chr = 0;
   while (isspace(chr = (char)getchar())); // Read as long as there are space
   ungetc(chr, stdin); // put back the nonspace character

   printf("char is: %c", chr);
}
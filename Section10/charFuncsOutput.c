#include <stdio.h>

int putchar(int c);

int fputc(int character, FILE *stream);

void main()
{

    /*
    // option 1:
    char ch = '\0';
    FILE *fp = NULL;

    if (fp = fopen("testFile.txt", "rw"))
    {
        ch = getc(fp);
        printf("%c", ch);
        while (ch != EOF)
        {
            putc(ch, fp);
            ch = getc(fp);
            printf("%c", ch);
        }
        fclose(fp);
    }

    // option 2:
    char chr = 'd';
    putc(chr, stdout);
    */

    /*
     char string[] = "Hello Elor, \nHey dude.";
     int i = 0;
     while (string[i] != '\0')
     {
         if (string[i] != '\0')
             putchar(string[i]);
         i++;
     }

     int c = 0;
     while ((c = getchar()) != EOF)
         putchar(c);
     // ungetc() returns EOF previously read back to stdin
     ungetc(c, stdin);
     printf("Thanks.\n");
     */

    FILE *pFile = NULL;
    char character = '\0';
    pFile = fopen("newFile.txt", "w");
    fputc('\n', pFile);

    if (pFile != NULL)
    {
        for (character = 'A'; character <= 'Z'; character++)
            fputc(character, pFile);
            // fputc(character, stdout); // option to print
        fclose(pFile);
    }
}

// if writing in command line we can get the text into a file directly by:
// ./a.out < infile
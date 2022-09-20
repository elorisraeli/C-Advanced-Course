#include <stdio.h>
#include <ctype.h> // need this to use toupper() function.

void main()
{

    /*
    // Challenge 1:
    FILE *fp = NULL;
    char ch = '\0';
    int countLines = 0, countChars = 0, countWords = 0;

    fp = fopen("challengeFile.txt", "r");
    if (fp != NULL)
    {
        ch = fgetc(fp);
        while (ch != EOF)
        {
            ch = fgetc(fp);
            if (ch == '\n')
            {
                countLines++;
                countWords++;
                countChars--;
            }
            if (ch == ' ')
                countWords++;
            countChars++;
        }
        // after EOF still remaining an extra word and line to count
        countLines++;
        countWords++;
        fclose(fp);
    }
    printf("The number of lines in the file are: %d\n", countLines);
    printf("The number of words in the file are: %d\n", countWords);
    printf("The number of characters in the file are: %d\n", countChars);
    */

    // Challenge 2:
    FILE *fptr = NULL;
    char c = '\0';
    if (fptr = fopen("lowToUpCaseFile.txt", "rw"))
    {
        c = fgetc(fptr);
        while (c != EOF)
        {
            if(isupper(c))
                c = tolower(c);
            else if(islower(c))
                c = toupper(c);
            fputc(c, stdout);
            c = fgetc(fptr);
        }
        fclose(fptr);
    }
}
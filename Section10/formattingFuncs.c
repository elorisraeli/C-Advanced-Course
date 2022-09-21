#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

void main()
{
    /*
    char string[100];
    int a = 10, b = 20, c = a + b;
    sprintf(string, "The sum of %d and %d is %d",a ,b ,c);
    puts(string);
    */

    /*
     FILE *f = NULL;
     char ch[100];

     // open the file to read and write operation
     if ((f = fopen("dataFile.txt", "r+")) == NULL)
     {
         printf("Cannot open the file.\n");
         exit(1);
     }
     for (int i = 0; i < 10; i++)
     {
         // enter the strings with values in the file
         fprintf(f, "The count number is %d\n", i + 1);
     }
     fclose(f);

     // reopen the file to read the data
     if ((f = fopen("dataFile.txt", "r+")) == NULL)
     {
         printf("Cannot open the file.\n");
         exit(1);
     }
     printf("\nFile content is: \n");
     while (!feof(f))
     {
         fgets(ch, 100, f);
         printf("%s", ch);
     }

     fclose(f);
     */

    /*
    // read from file using fscanf
    FILE *fp = NULL;
    char buff[255];
    fp = fopen("someFile.txt", "rw");
    while(fscanf(fp, "%s", buff) != EOF){
     // not get line down, its just to see a way of using fscanf function
     printf("%s ", buff);
    }
    fclose(fp);


    // write into a file using fscanf
    FILE *fptr = NULL;
    char words[MAX];
    fptr = fopen("dataFile.txt", "a+"); // mode 'a+' enable you to read and write
    if (fptr == NULL)
    {
        fprintf(stdout, "Can't open the file.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter words to add to the file.");
    puts("Press # key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && words[0] != '#')
        fprintf(fptr, "%s\n", words);
    // read the content from the file
    puts("File content:\n");
    rewind(fptr); // go back at the beginning of the file
    while (fscanf(fptr, "%s", words) == 1)
        puts(words);
    puts("Done!\n");
    if(fclose(fptr) != 0)
        fprintf(stderr, "Error closing file.\n");
     */

    // using sscanf, enter values from a string
    char *str = "Elor Israeli 13";
    char name[10], title[10];
    int age = 0, answer = 0;
    answer = sscanf(str, "%s %s %d", name, title, &age);
    printf("Name: %s\n", name);
    printf("Title: %s\n", title);
    printf("Age: %d\n", age);
    printf("Answer: %d\n", answer);
    
    // fflush() function flush/clean a file or buffer.
}
#include <stdio.h>
#include <stdlib.h>

// #define DEBUG

// // another option is to define with args
// #define DEBUG(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__);

// option with options (change the process function to print if level is 1 or 2 and so..)
int Debug = 0;
#ifdef DEBON
#define DEBUG(level, fmt, ...) \
    if (Debug >= level) \
        fprintf(stderr, fmt, __VA_ARGS__);
#else
#define DEBUG(level, fmt, ...)
#endif

/*
int process(int i, int j, int k)
{
    return i + j + k;
}

int process2(int i, int j)
{
    int val = 0;
#ifdef DEBUG
    fprintf(stderr, "process2(%d, %d)\n", i, j);
#endif

    val = i * j;

#ifdef DEBUG
    fprintf(stderr, "return %d\n", val);
#endif
    return val;
}
int process3(int i, int j)
{
    int val = 0;
    DEBUG("process3(%d, %d)\n", i, j);

    val = i * j;

    DEBUG("return %d\n", val);
    return val;
}
*/
int process4(int i, int j)
{
    int val = 0;
    DEBUG(1, "process4(%d, %d)\n", i, j);

    val = i * j;

    DEBUG(3, "return %d\n", val);
    return val;
}

void main(int argc, char *argv[])
{

    
  /*
    int i, j, k, nread;
    printf("Enter 3 numbers: ");
    nread = scanf("%d %d %d", &i, &j, &k);

#ifdef DEBUG
    fprintf(stderr, "Number of integers read: %i\n", nread);
    fprintf(stderr, "The numbers are: %i, %i, %i\n", i, j, k);
#endif
    printf("%d\n", process(i, j, k));
    */

    /*
    run from the cmd, must to pass two args, here is the way to run:
    (with capital letters its the thing you should change to your own program)
    call in the cmd to the folder of this file by the command: cd FOLDERNAME
    than type: gcc FILENAME.c
    than type: gcc -D DEBUG FILENAME.c (this is to define the DEBUG to print our data by the ifdef)
    than call the running file with the 2 arguments: gcc FILENAME.exe ARGUMENT1 ARGUMENT2
    Example:
    cd C Advanced Course
    cd Section15
    gcc debugWithPreprocessor.c
    gcc -D DEBUG debugWithPreprocessor.c
    gcc debugWithPreprocessor.exe 5 10
    */

   /*
    int arg1 = 0, arg2 = 0;
    if (argc > 1)
        arg1 = atoi(argv[1]);
    if (argc == 3)
        arg2 = atoi(argv[2]);

// if there is another DEBUG, he is override the none args one, so its wont print this
#ifdef DEBUG
    fprintf(stderr, "Processed %d arguments\n", argc - 1);
    fprintf(stderr, "arg1 = %i, arg2 = %i\n", arg1, arg2);
#endif
    printf("%i\n", process2(arg1, arg2));

    // the another option to print(if the DEBUG with args)
    printf("Gets here.\n");
    DEBUG("Processed %d arguments\n", argc - 1);
    DEBUG("arg1 = %i, arg2 = %i\n", arg1, arg2);

    printf("%i\n", process3(arg1, arg2));
*/
  

    // the option with the options:
    /* in the cmd:
    gcc FILENAME.c (and than will be opened a file calls "a.exe")
    a.exe ARGUMENT_LEVEL ARGUMENT1 ARGUMENT2
    Example:
    gcc debugWithPreprocessor.c
    a.exe 1 5 10
    (so im using level 1, with the arguments 5, 10)
    */
    int arg1 = 0, arg2 = 0;
    if (argc > 2)
    {
        Debug = atoi(argv[1]);
        arg1 = atoi(argv[2]);
    }
    if (argc == 4)
        arg2 = atoi(argv[3]);
    printf("Gets here. (2) \n");
    DEBUG(2, "Processed %d arguments\n", argc - 1);
    DEBUG(3, "arg1 = %i, arg2 = %i\n", arg1, arg2);
    printf("%i\n", process4(arg1, arg2));

}
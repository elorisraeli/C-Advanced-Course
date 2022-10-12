#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#define SIZE 10

/*
FILE *openFile(const char *file){
    FILE *inFile;
    if ((inFile = fopen(file, "r") == NULL))
    {
        fprintf(stderr, "Can't open %s for reading.\n", file);
        exit(EXIT_FAILURE);
    }
    return inFile;
}
*/

void sign_off(void);
void too_bad(void);
int comp_ints(const void *p1, const void *p2);

void show_array(const int ar[], int n);
// static_assert(sizeof(double) == 2 * sizeof(int), "double not twice int size"); // 

void main(void){

/*
    int n = 0;
    atexit(sign_off);
    puts("Enter an integer: ");
    if (scanf("%d", &n) != 1)
    {
        puts("That's no integer!");
        atexit(too_bad);
        exit(EXIT_FAILURE);
    }
 */    

/* 
    FILE *fp;
    fp = fopen("fileThatNotOpenWell.txt", "r");
    if(fp == NULL){
        printf("Going to abort the program\n");
        abort();
    }

    printf("Going to close the file\n");
    fclose(fp);
 */

/* 
    int data[5] = {54, 3, 12, 9, 24};
    qsort(data, 5, sizeof(int), comp_ints);
    // first argument - pointer to the start of the array,
    // second argument - size of the array
    // third argument - size of each element in the array
    // forth argument - function pointer: return an int, take 2 parameters (void pointers)
    // looks like: int (*compar)(const void *, const void *)

    for (int i = 0; i < 5; i++)
        printf("%d  ", data[i]);
    */

    /* 
    // ato_() functions
    char a[10] = "100";
    int value = atoi(a);
    printf("Value = %d\n", value);

    char b[10] = "3.14";
    float value2 = atof(b);
    printf("Value2 = %f\n", value2);

    char c[10] = "1000000000";
    long value3 = atol(c);
    printf("Value3 = %ld\n", value3);
    // also an option:
    sprintf(c, "%d", 45);
    printf("Value3 = %s\n", c);

    char d[] = "123.456xyz", *end;
    double value4 = 0;
    value4 = strtod(d, &end);
    printf("Value4 = %f\n", value4);

    char e[] = "365.25 7.0", *end2;
    double value5 = 0;
    value5 = strtod(e, &end2);
    double value6 = 0;
    value6 = strtod(end2, NULL);
    printf("Value5 = %f, Value6 = %f\n", value5, value6);

    char str[30] = "2030300 This is test";
    char *ptr = NULL;
    long ret = 0;
    ret = strtol(str, &ptr, 10);
    printf("The number (unsigned long integer) is: %d\n", ret);
    printf("String part is: |%s|\n", ptr);
    */

    /* 
    srand(time(0));
    for (int i = 0; i < 5; i++)
        printf(" %d ", rand() % 5 + 1); // generates random numbers between 0 to 5
    printf("Another random number without range: %d\n", rand());
    */

    /* 
   char command[50];
   strcpy(command, "ls -l");
   system(command);
   printf("\n");
   strcpy(command, "pwd");
   system(command);
   */

    /* 
    char *str = NULL;
    // attempt to access environment variables using getenv()
    assert((str = getenv("PATH")) != NULL);
    printf("Value of PATH Environment Variable : %s\n", str);
    assert((str = getenv("HOME")) != NULL);
    printf("Value of HOME Environment Variable : %s\n", str);
    assert((str = getenv("LONGNAME")) != NULL);
    printf("Value of LONGNAME Environment Variable : %s\n", str);
    assert((str = getenv("ELOR")) != NULL);
    printf("Value of ELOR Environment Variable : %s\n", str);
    */

    /* 
   int values[SIZE] = {1,2,3,4,5,6,7,8,9,10};
   int target[SIZE];
   double curious[SIZE/2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30};
   puts("Values (original data): ");
   show_array(values, SIZE);
    memcpy(target, values, SIZE * sizeof(int));
   puts("Values (copy of Values): ");
   show_array(target, SIZE);

    puts("\nUsing memmove() with overlapping ranges: ");
    memmove(values + 2, values, 5 * sizeof(int));
    puts("values -- elements 0-5 copied to 2-7: ");
    show_array(values, SIZE);

    puts("\nUsing memcpy() to copy double to int: ");
    memcpy(target, curious, (SIZE/2) * sizeof(double));
    puts("target -- 5 doubles into 10 int positions: ");
    show_array(target, SIZE/2);
    show_array(target+5, SIZE/2);
    */

    /* 
   char *p1 = "Elor";
   char *p2 = NULL;
   p2 = strdup(p1);
   printf("Duplicated string is: %s\n", p2);

   char source[] = "Elor";
   char *target = strndup(source, 4);
   printf("Duplicated string is: %s\n", target);
    */
}

void show_array(const int ar[], int n){
    printf("[");
    for (int i = 0; i < n-1; i++)
        printf("%d, ", ar[i]);
    printf("%d]\n", ar[n-1]);
}

int comp_ints(const void *p1, const void *p2){
    const int i1 = * (const int *)p1;
    const int i2 = * (const int *)p2;
    // return i1 - i2; // positive answer = i1 follow i2
    // return i1 > i2; // positive answer(1 or 0) = i1 follow i2 (because i1 bigger)
    return i1 < i2; // positive answer(1 or 0) = i2 follow i1 (because i2 bigger)
}


void sign_off(void){
    puts("in sign_in...\n");
}

void too_bad(void){
    puts("in too_bad...\n");
}


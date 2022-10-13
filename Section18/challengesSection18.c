#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatesRand();

#define N 40
void fillArray(double ar[], int n);
void showArray(const double ar[], int n);
int mycomp(const void *p1, const void *p2);

void main(){
    // challenge 1 - generates 50 random numbers between -0.5 to 0.5
    generatesRand();

    // challenge 2 - generate 40 numbers for array and than sort the array
    double vals[N];
    fillArray(vals, N);
    puts("Random List: ");
    showArray(vals, N);
    qsort(vals, N, sizeof(double), mycomp);
    puts("Sorted List: ");
    showArray(vals, N);

    // challenge 3 - print the current time
    time_t cur_time = 0;
    char *cur_t_string;
    cur_time = time(NULL);
    if (cur_time == ((time_t)-1))
    {
        fprintf(stderr, " Failed to get the current time.\n");
        exit(EXIT_FAILURE);
    }
    cur_t_string = ctime(&cur_time);
    if (cur_t_string == NULL)
    {
        fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }
    printf("\n The Current time is: %s \n", cur_t_string);
    // exit(EXIT_FAILURE); // for the running of the 4th challenge


    // challenge 4 - compute the number of seconds passed since the beginning of the current month
    time_t now = 0;
    time(&now);
    struct tm beg_month;
    beg_month = *localtime(&now);

    beg_month.tm_hour = 0;    
    beg_month.tm_min = 0;
    beg_month.tm_sec = 0;
    beg_month.tm_mday = 1;

    double seconds = difftime(now, mktime(&beg_month));
    printf("\n %.f seconds passed since the beginning of the month.\n\n", seconds);
    exit(EXIT_FAILURE);
    
    

}

void generatesRand()
{
    srand(time(NULL));
    // number = (rand() % (upper - lower + 1)) + lower
    for (int i = 0; i < 50; i++)
        printf("Number number %d: %0.4lf\n", i, (rand() % 2001 - 1000) / 2.e3);
}

void fillArray(double ar[], int n)
{
    for (int i = 0; i < n; i++)
        ar[i] = (double)rand() / ((double)rand() + 0.1);
}

void showArray(const double ar[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%9.4f ", ar[i]);
        if (i % 6 == 5)
            putchar('\n');
    }
    if(i % 6 != 0)
        putchar('\n');
}

int mycomp(const void *p1, const void *p2){
    const double *i1 = (const double*) p1;
    const double *i2 = (const double*) p2;
    if(*i1 < * i2)
        return -1;
    else if (*i1 == * i2)
        return 0;
    else
        return 1;
}

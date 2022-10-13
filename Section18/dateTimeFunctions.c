#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

void main()
{
    /*
    clock_t start = 0, end = 0;
    double cpu_time = 0.0;
    start = clock();
    // Execute the process for which you want the processor time..
    end = clock();
    cpu_time = (double)(end - start) / CLOCKS_PER_SEC; // processor time in second
    printf("The time in seconds: %f\n", cpu_time);
   
    time_t calender_start = time(NULL);
    clock_t cpu_start_calender = clock();
    int count = 0;
    const long long iterations = 100000000LL;
    char answer = 'y';
    double x = 0.0;
    printf("Initial clock time = %lld, ", (long long)cpu_start_calender);
    printf("Initial calender time = %lld\n", (long long)calender_start);
    while (tolower(answer) == 'y')
    {
        for (long long i = 0LL; i < iterations; i++)
            x = sqrt(3.14159265);

        printf("%lld square roots completed.\n", iterations * (++count));
        printf("Do you want to run some more(y or n)? \n");
        scanf("\n%c", &answer);
    }
    clock_t cpu_end = clock();
    time_t calender_end = time(NULL);
    printf("Final clock time = %lld, ", (long long)cpu_end);
    printf("Final calender time = %lld\n", (long long)calender_end);
    printf("CPU time for %lld iterations is %.2lf seconds\n", count * iterations,
           ((double)(cpu_end - cpu_start_calender)) / CLOCKS_PER_SEC);
    printf("Elapsed calender time to execute the program is %8.2lf seconds.\n",
           difftime(calender_end, calender_start));
    */

   time_t calender = time(NULL);
   struct tm *time_data;
   const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
   const char *months[] = {"January", "February", "March", "April", "May", "June", 
                        "July", "August", "September", "October", "November", "December"};
    time_data = localtime(&calender);
    printf("Today is %s, %s %d %d\n", days[time_data->tm_wday], 
    months[time_data->tm_mon], time_data->tm_mday, time_data->tm_year+1900);
    printf("The %d day in the year.\n", time_data->tm_yday);
    printf("The time is: %d:%d, %d seconds\n", time_data->tm_hour, time_data->tm_min, time_data->tm_sec);

    printf("\n");
    const char *suffix[] = {"st", "nd", "rd", "th"};
    enum sufindex{st, nd, rd, th} sufsel = th;    // suffix selector
    struct tm birthday = {0};
    char name[30] = {'\0'};
    printf("Enter a name: ");
    scanf("%s", name);
    printf("Enter the birthday for %s as day month year integers separated by spaces."
            "\ne.g. Enter 1st February 1995 as 1 2 1995 : ", name);
    scanf("%d %d %d", &birthday.tm_mday, &birthday.tm_mon, &birthday.tm_year);
    birthday.tm_mon -= 1;
    birthday.tm_year -= 1900;

    if (mktime(&birthday) == -1)
        fprintf(stderr, "Operation failed.\n");

    switch (birthday.tm_mday)
    {
    case 1: case 21: case 31:
        sufsel = st;
        break;
    case 2: case 22:
        sufsel = nd;
        break;
    case 3: case 23:
        sufsel = rd;
        break;
    default:
        sufsel = th;
        break;
    }

    
    printf("%s was born on the %d%s %s %d, which was a %s.\n", name, birthday.tm_mday,
         suffix[sufsel], months[birthday.tm_mon], birthday.tm_year, days[birthday.tm_wday]);

}
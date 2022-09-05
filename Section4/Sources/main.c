#include <stdio.h>
// #include "../Headers/date.h"
#include "../Sources/other.c"
// #include <Section4/Headers/date.h>

// // Function that calculate tomorrow's date
// Date dateUpdate(Date today)
// {
//     Date tomorrow;

//     if (today.day != numberOfDays(today))
//     {
//         setDate(tomorrow, today.day + 1, today.month, today.year);
//     }
//     else if (today.month == December)
//     {
//         setDate(tomorrow, January, 1, today.year + 1);
//     }
//     else
//         setDate(tomorrow, 1, today.month + 1, today.year);

//     return tomorrow;
// }

int main()
{
    // Date date1;
    // date1.day = 1;
    // date1.month = 12;
    // date1.year = 2022;
    // printf("The date is: %d, %d, %d", date1.day,date1.month,date1.year);
    // dateUpdate(date1);
    // printf("The date is: %d, %d, %d", date1.day,date1.month,date1.year);

    int a = 10;
    int b = 16;
    int sum = add(a, b);
    int subtraction = sub(a, b);
    printf("a+b=%d\na-b=%d\n", sum, subtraction);
    

    return 0;
}

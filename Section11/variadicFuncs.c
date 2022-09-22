#include <stdio.h>
#include <stdarg.h>

double average(double v1, double v2, ...);

void main()
{
    double v1 = 10.5, v2 = 2.5;
    int num1 = 6, num2 = 5;
    long num3 = 12L, num4 = 20L;

    printf("Average = %.2lf\n", average(v1, 3.5, v2, 4.5, 0.0));
    printf("Average = %.2lf\n", average(1.0, 2.0, 0.0));
    printf("Average = %.2lf\n", average((double)num2, v2, (double)num1, (double)num4, (double)num3, 0.0));
}

double average(double v1, double v2, ...)
{
    va_list parg; // name of the arguments list
    double sum = v1 + v2;
    double value = 0.0;

    int count = 2;
    va_start(parg, v2); // starts the list from the last argument

    /*
    va_list parg_copy;
    va_copy(parg_copy, parg); // copy the arguments to the copy list
    */

    while ((value = va_arg(parg, double)) != 0.0) // double is the arguments data type we use here
    {
        sum += value;
        count++;
    }
    va_end(parg);

    return sum / count;
}

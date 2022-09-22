#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double sample_stddev(int count, ...); // Standard deviation function
/*
Standard deviation = √((1/n)*(∑i=1..n (xi−x)^2))
n: number of arguments
xi: each argument
x: arguments average
∑: sum all cases of '(xi-x)^2'
√: square root
*/

void main()
{
    printf("%f\n", sample_stddev(4, 25.0, 27.3, 26.9, 25.7));
}

double sample_stddev(int count, ...)
{
    double sum = 0;

    va_list arg1;
    va_start(arg1, count);

    va_list arg2;
    va_copy(arg2, arg1);

    for (int i = 0; i < count; i++)
    {
        double num = va_arg(arg1, double);
        sum += num;
    }
    va_end(arg1);

    double mean = sum / count;
    double sum_spr_diff = 0;

    for (int i = 0; i < count; i++)
    {
        double num = va_arg(arg2, double);
        sum_spr_diff += (num - mean) * (num - mean);
    }
    va_end(arg2);
    return sqrt(sum_spr_diff / count);
}
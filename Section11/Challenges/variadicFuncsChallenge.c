#include <stdio.h>
#include <stdarg.h>

int addingNumbers(int count, ...);

void main(){

    printf("Sum = %d\n", addingNumbers(2, 10, 20));
    printf("Sum = %d\n", addingNumbers(3, 10, 20, 30));
    printf("Sum = %d\n", addingNumbers(4, 10, 20, 30, 40));

}

int addingNumbers(int count, ...){
    va_list parg;
    int sum = 0;
    va_start(parg, count);

    for (int i = 0; i < count; i++)
        sum += va_arg(parg, int);
    
    va_end(parg);

    return sum;
}
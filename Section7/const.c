#include <stdio.h>
#include "header.h"

const double PI = 3.14159;
const char *MONTH[12] = {
    "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"
};

int main(){

    const double pi = 3.141592654;
    printf("%.10f\n", pi);
    
    const int days[12] = {31, 28, 31, 30};
    for (int i = 0; i < 4; i++)
    {
        printf("days[%d]=%d\n", i, days[i]);
    }
    
    typedef const int zip;
    zip q = 8;
    printf("%d\n", q);


    const float *pf; // pf points to a constant float value (value cannot changed)
    float *const pt; // pt is a const pointer (address cannot changed)
    const float *const ptr; // both are constant

    float const *ptc; // same as 'const float *ptc;'




    return 0;
}


// void display(const int array[], int limit);

// char *strcat(char *restrict sl, const char *restrict s2);
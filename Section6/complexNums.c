#include <stdio.h>
#include <complex.h>

#define _STDC_WANT_LIB_EXT1__ 1

/*
Some types of complex variables:
- float_Complex --> real and imaginary number as float
- double_Complex --> real and imaginary number as double
- long double_Complex --> real and imaginary number as long double
- float_Imaginary --> imaginary number as float
- double_Imaginary --> imaginary number as double
- long double_Imaginary --> imaginary number as long double
*/


int main(){
    /*
    // check if my compiler support Complex numbers:

    #ifdef __STDC_NO_COMPLEX__
    printf("Not support Complex.\n");
    exit(1);
    #else
    printf("Support Complex.\n");
    #endif
    */

   
    // double_Complex z1 = 1.3 + 2.1 * I; // not working this way
    double complex z1 = 4.5 + 6.7 * I;
    printf("\nComplex is: %.2f%+.2fi\n", z1);
    printf("Same as call each part apart, complex is: %.2f + %.2fi\n", creal(z1), cimag(z1));
    printf("The conjugate complex is: %.2f%+.2fi\n", conj(z1));

    double complex z2 = 1.0 + 2.0 * I;
    double complex sum = z1 + z2;
    double complex sub = z1 - z2;
    double complex mult = z1 * z2;
    double complex div = z1 / z2;
    double complex pow = cpow(z1, z2);
    printf("\nThe sum of the complexes is: %f%+fi\n", sum);
    printf("The subtraction of the complexes is: %f%+fi\n", sub);
    printf("The multiplication of the complexes is: %f%+fi\n", mult);
    printf("The division of the complexes is: %f%+fi\n", div);
    printf("The exponentiation is: %f%+fi\n\n", pow);


    // double imaginary i2 = 2.4*I;
    // printf("complex is: %.2f + %.2fi\n", i2);

    // const float complex _Complex_I; // a constant number value of 0+1*i
    // const float complex I; // a constant number value of 0+1*i
    printf("I = %f%+fi\n", _Complex_I);
    printf("I = %f%+fi\n", I);

    // double real_part = creal(z1);
    // double imaginary_part = cimag(z1);
    // double conjugate_number = conj(z1);
    // // if we use float complex number the functions are:
    // // crealf(), cimagf(), conjf()
    // // if we use long double complex number the functions are:
    // // creall(), cimagl(), conjl()
    // // conjugate example: z1 = (1.2 + 3.4 * I) , z1_conjugate = (1.2 - 3.4 * I)

    

    return 0;
}

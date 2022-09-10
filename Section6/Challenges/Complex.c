#include <stdio.h>
#include <complex.h>
#include <math.h>

typedef double complex dc;

int main(){

    double complex x = I * I;
    printf("\n I*I --> Real part: %f, Imaginary part: %+fi\n", creal(x), cimag(x));

    double complex expo = pow(I, 2);
    printf(" I^2 --> Real part: %f, Imaginary part: %+fi\n", creal(expo), cimag(expo));

    double complex PI = acos(-1);
    double complex exponent_PI = I * PI;
    printf("acos(-1) <=> Cos^(-1) (-1) --> Real part: %f, Imaginary part: %+fi\n", creal(PI), cimag(PI));
    printf("I*acos(-1) --> Real part: %f, Imaginary part: %+fi\n", creal(exponent_PI), cimag(exponent_PI));
    
    // get lazy so create typedef that is I write 'dc' is like 'double complex'
    dc z1 = 1.0 + 2.0 * I;
    dc z1_conj = conj(z1);
    printf("z1 --> Real part: %f, Imaginary part: %+fi\n", creal(z1), cimag(z1));
    printf("z1 conjugate --> Real part: %f, Imaginary part: %+fi\n", creal(z1_conj), cimag(z1_conj));


    return 0;
}
#include <stdio.h>
#include "../Section8/binaryNumsBits.c"

int main(){
    short int w1 = 25; // 0000000011001
    short int w2 = 77; // 0000001001101
    short int w3 = 0; //  0000000000000
    short int w4 = 0; //  0000000000000
    short int w5 = 0; //  0000000000000


    w3 = w1 & w2; // 0000000001001  (AND gate - both bits are 1) 
    w4 = w1 | w2; // 0000001011101  (OR gate - one of bits are 1)
    w5 = w1 ^ w2; // 0000001010100  (XOR gate - number of bits odd)

    printf("decimal = %d, binary = %d\n", w3, decimal2Binary(w3));
    printf("decimal = %d, binary = %d\n", w4, decimal2Binary(w4));
    printf("decimal = %d, binary = %d\n", w5, decimal2Binary(w5));

    short int w6 = 147;
    short int w7 = 61;
    short int temp = 0;

    // one way of swapping w6 and w7:
    printf("w6: decimal = %d, binary = %d _____ ", w6, decimal2Binary(w6));
    printf("w7: decimal = %d, binary = %d\n", w7, decimal2Binary(w7));
    temp = w6;
    w6 = w7;
    w7 = temp;
    printf("w6: decimal = %d, binary = %d _____ ", w6, decimal2Binary(w6));
    printf("w7: decimal = %d, binary = %d\n", w7, decimal2Binary(w7));
    // other way to do this:
    w6 ^= w7;
    w7 ^= w6;
    w6 ^= w7;
    printf("w6: decimal = %d, binary = %d _____ ", w6, decimal2Binary(w6));
    printf("w7: decimal = %d, binary = %d\n", w7, decimal2Binary(w7));

    signed int s1 = 2; // 0000010
    signed int s2 = 0; // 0000000
    s2 = ~(s1);        // 1111101 (Tilde operator, NOT gate - the opposite bit)
    printf("s1: decimal = %d, s2: decimal = %d\n", s1, s2);


    return 0;
}
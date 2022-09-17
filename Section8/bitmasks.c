#include <stdio.h>
#include "../Section8/binaryNumsBits.c"

// masks can use to turn on and off bits and to verify bits in numbers

int main(){
    int results[4];

    int flags = 15; // 0000 1111
    int mask = 182; // 1011 0110
    flags = flags | mask; // 1011 1111  (OR operator)
    results[0] = flags;

    flags = 15; // 0000 1111
    mask = 182; // 1011 0110
    // ~mask <=> 0100 1001 (NOT operator)
    flags = flags & (~mask); // 0000 1001 (AND operator)
    results[1] = flags;

    flags = 15; // 0000 1111
    mask = 182; // 1011 0110
    flags = flags ^ mask; // 1011 1001 (XOR operator)
    results[2] = flags;

    flags = 99; // 0110 0011
    mask = 64; // 0010 0010
    // checking if the bits in flags is on in the places I want, this time 2s and 6s bits
    if (flags&mask == mask)
    {
        results[3] = flags;
    }else printf("Not as mask");

    for (int i = 0; i < 4; i++)
    {
        printf("i:%d, %d in binary: %d\n", i, results[i], decimal2Binary(results[i]));
    }





    return 0;
}
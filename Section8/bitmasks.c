#include <stdio.h>
#include "../Section8/binaryNumsBits.c"

// masks can use to turn on and off bits and to verify bits in numbers

#define BYTE_MASK 0xff

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


    /*
    if we want to store data in bits like a pack,
    we can calculate how many bits we need to use:
    example:
    we need to store 3 flags (1 bit each), a number between 1-255 (8 bits),
    and a number between 1-100,000 (18 bits).
    To sum up, we need 29 bits and this is the reason we need storage with 32 bits in this case.

    unused   f1  f2  f3      type (1-255)           index (1-100,000)
    | 0 0 0 | 0 | 0 | 0 | 0 0 0 0 0 0 0 0 | 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 |
        3     1   1   1          8                          18                   

   unsigned int packed_data; // 32 bits on the most systems
   packed_data = (packed_data | 7) << 18; // change the value of the type bits, OR with 18 bits left
   packed_data &= 0xfc03ffff; // packed_data & (1111 1100 0000 0011 1111 1111 1111 1111)

   to extract the type field of packed_data and assign it to n:
   n = (packed_data >> 18) & 0xff; // its drop the 18 bits that right and leaves the next bits
   // with the operator AND and the number 1111 1111 then you get what you want

    */

   unsigned int data = 99; // 0110 0011
   unsigned int result1 = (data >> 4);
   unsigned int result2 = (data >> 4) & 0xf;
    printf("0xf = %u, %d\n", 0xf, 0xf);
    printf("data = %u, result1 = %u, result2 = %u\n", data, result1, result2);
    printf("AWESOME!!\n");

    unsigned long color = 0x002a162f; // 0000 0000 0010 1010 0001 0110 0010 1111
    unsigned char blue, green, red;
    red = color & BYTE_MASK; // 0010 1111
    green = (color >> 8) & BYTE_MASK; // 0001 0110
    blue = (color >> 16) & BYTE_MASK; // 0010 1010


    return 0;
}
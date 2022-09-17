#include <stdio.h>

struct packed_struct
{
    // (we continue the packed data from bitSetRead.c)
    unsigned int : 3;        // unused bits (even in the initialize we dont mention them)
    unsigned int f1 : 1; // f1 bit..
    unsigned int f2 : 1;
    unsigned int f3 : 1;
    unsigned int type : 8;
    unsigned int index : 18;
};

int main()
{
    printf("Start\n");

    struct packed_struct packed_data = {1, 1, 0, 123, 1234};
    unsigned int type_bits = packed_data.type;
    unsigned int index_bits = packed_data.index;
    printf("%u\n", type_bits);
    printf("%u\n", index_bits);

    if (packed_data.f2)
    {
        printf("Bit on\n");
    }

    return 0;
}
#include <stdio.h>
#include <stddef.h>

#define MASK_ONE 0x1

int main()
{
    int num, n, bit_status, nth_bit, n_mask;

    printf("Enter any number: ");
    scanf("%d", &num);
    printf("Enter the nth bit to check and set(0-31): ");
    scanf("%d", &n);
    
    bit_status = (num >> n) & 1;

    // check if the nth bit is 1 or 0
    nth_bit = (num >> n) & MASK_ONE;
    if (nth_bit == MASK_ONE)
    {
        printf("The %d bit is %d\n", n, bit_status);
    }
    else
        printf("The %d bit is %d\n", n, bit_status);

    printf("Number before set the %d bit: %d (in decimal)\n", n, num);
    // set the nth bit to 1
    n_mask = (MASK_ONE << n);
    num |= n_mask;
    printf("Number after set the %d bit: %d (in decimal)\n", n, num);

    return 0;
}
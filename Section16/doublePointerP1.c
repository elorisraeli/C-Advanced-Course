#include <stdio.h>

void main(){

    // Basic pointer
    int num = 3;
    int *pointer = NULL;
    pointer = &num;
    printf("The number is with the address: %u\n", &num);
    printf("The pointer points to: %d\n With the address: %u\n", *pointer, &pointer);

    int **pointer2 = NULL;
    pointer2 = &pointer;
    printf("The pointer2 points to: %d\n With the address: %u\n", **pointer2, &pointer2);

    // Double pointers:
    int a = 10, b = 20, c = 30;

    /* pointer p1 points to address of a with the value 30, p1 -> 10 */
    int *p1 = &a; 
    int *p2 = &b; // same, p2 -> 20 && p1 -> 10

    /* pointer pp1 points to the address of p1 with the value of address with the value of 10,
        pp1 -> p1 -> 10 && p2 -> 20 */
    int **pp1 = &p1;
    printf("\nValues: *p1=%d, *p2=%d, **pp1=%d\n", *p1, *p2, **pp1);
    printf("Addresses: *p1=%u, *p2=%u, **pp1=%u\n", &p1, &p2, &pp1);

    /* pointer pp1 (which still points to pointer p1) tells p1 to point to where pointer p2 
    with the value of address of the value 20, pp1 -> p1 -> 20 && p2 -> 20 */
    *pp1 = p2;
    printf("\nValues: *p1=%d, *p2=%d, **pp1=%d\n", *p1, *p2, **pp1);
    printf("Addresses: *p1=%u, *p2=%u, **pp1=%u\n", &p1, &p2, &pp1);

    /* pointer pp1, which points to p1, tells p1 to point to the address of c with the value of 30,
        pp1 -> p1 -> 30 && p2 -> 20 */
    *pp1 = &c;
    printf("\nValues: *p1=%d, *p2=%d, **pp1=%d\n", *p1, *p2, **pp1);
    printf("Addresses: *p1=%u, *p2=%u, **pp1=%u\n", &p1, &p2, &pp1);





}
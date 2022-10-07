#include <stdio.h>
#include <malloc.h>

// function that modify pointer value
void foo(int **ptr){
    int num = 555;
    *ptr = &num;
}

// function to allocate memory
void allocateMemory(int **ptr){
    *ptr = (int *) malloc(sizeof(int));
}

void main(){
    int num = 5;
    int *p = NULL;
    int **pp = NULL;
    p = &num;
    pp = &p;
    printf("\nPRINT ALL THE POSSIBLE WAYS TO FIND:\n\n");
    printf("VALUE OF num: num=%d, *p=%d, **pp=%d\n", num, *p, **pp);
    printf("ADDRESS OF num: &num=%u, p=%u, *pp=%u\n", &num, p, *pp);
    printf("VALUE OF *p: *p=%d, **pp=%d\n", *p, **pp);
    printf("ADDRESS OF *p: &p=%u, pp=%u\n", &p, pp);
    printf("VALUE OF *pp: **pp=%d\n", **pp);
    printf("ADDRESS OF *pp: &pp=%u\n", &pp);

    foo(pp);
    printf("pp: value=%d, address=%u\n", **pp, &pp);
    
    // allocation challenge:
    int *ptr = NULL;
    allocateMemory(&ptr);
    *ptr = 20;
    printf("ptr=%d\n", *ptr);
    free(ptr);

}
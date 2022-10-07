#include <stdio.h>
#include <malloc.h>
#include <string.h>

// the full functions are below main function
void foo(int *ptr);
void foo2(int *ptr);
void fooDP(int **ptr);
void fooStr(char *ptr);
void fooStrFix(char **ptr);

void main(){
    int *ptr = NULL;
    ptr = (int *) malloc(sizeof(int));
    *ptr = 10;
    printf("Pointer: address=%u, value=%d\n", &ptr, *ptr);

    /* value of ptr still will be 10 because the ptr in the foo 
        function is just a local copy */
    foo(ptr);
    printf("Pointer: address=%u, value=%d\n", &ptr, *ptr);

    /* THE CORRECT WAY IS USING foo2(), you can still change the value
        where the pointer points to, but you cant change the value of the pointer.*/
    foo2(ptr);
    printf("Pointer: address=%u, value=%d\n", &ptr, *ptr);

    /* ANOTHER CORRECT WAY IS USING DOUBLE POINTER */
    int *ptr2 = NULL;
    ptr2 = (int *) malloc(sizeof(int));
    *ptr2 = 10;
    printf("Pointer2: address=%u, value=%d\n", &ptr2, *ptr2);
    fooDP(&ptr2); // we could create a double pointer but is the same, its the address of the pointer
                 // because that address pointing to a pointer with another address
    printf("Pointer2: address=%u, value=%d\n", &ptr2, *ptr2);

    /*
    // CRASHING PROGRAM (in purpose):
    char *ptrS = NULL;
    fooStr(ptrS);   // in the fooStr() function we allocating memory for the copy (not for ptrS)
    printf("PointerS: address=%u, value=%s\n", &ptrS, ptrS);
    free(ptrS);
    */
   // FIXED PROGRAM:
    char *ptrS = NULL;
    fooStrFix(&ptrS);   // in the fooStr() function we allocating memory for the copy (not for ptrS)
    printf("PointerS: address=%u, value=%s\n", &ptrS, ptrS);
    free(ptrS);
}

void foo(int *ptr){
    int a = 5;
    ptr = &a;
    printf("In foo(), ptr: address=%u, value=%d\n", &ptr, *ptr);
}

void foo2(int *ptr){
    int a = 5;
    *ptr = a;
    printf("In foo2(), ptr: address=%u, value=%d\n", &ptr, *ptr);
}

void fooDP(int **ptr){
    int a = 5;
    *ptr = &a; // change the value of where the pointer points to value
    printf("In fooDP(), ptr: address=%u, value=%d\n", &ptr, *ptr);
}

void fooStr(char *ptr){
    ptr = malloc(255);
    strcpy(ptr, "Hello World");
    printf("In fooStr(), ptr: address=%u, value=%s\n", &ptr, *ptr);
}

void fooStrFix(char **ptr){
    *ptr = malloc(255);
    strcpy(*ptr, "Hello World");
    printf("In fooStrFix(), ptr: address=%u, value=%s\n", &ptr, *ptr);
}

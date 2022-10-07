#include <stdio.h>
#include <malloc.h>

int someDisplay();
void func1(int);
void func2(int);

typedef void FuncType(int);

void main(){
    int (*func_ptr) (); // a pointer to a function
    func_ptr = someDisplay;
    printf("\nAddress of function someDisplay is %p\n", func_ptr);
    (*func_ptr)();

    FuncType *func_pointer = NULL;
    func_pointer = func1;
    (*func_pointer)(100);
 
    func_pointer = func2;
    (*func_pointer)(200);

}


int someDisplay(){
    printf("--Display some text--\n");
    return 0;
}

void func1(int testArg){
    printf("func1 got an argument of %d\n", testArg);
}

void func2(int testArg){
    printf("func2 got an argument of %d\n", testArg);
}

#include <stdio.h>

// register cannot be called outside the scope of function

int main(){

    register int x; // register variable (counter)

    for (x = 1; x <= 15; x++)
    {
        printf("\n %d", x);
    }
    

    int y = 20;
    register int *a = &y;
    printf("\n %d", *a);
    return 0;
}
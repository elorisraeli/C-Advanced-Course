#include <stdio.h>


int main(){

    int x;  // local variable

    int m; // m in scope
    printf("\n Enter a number under 5:");
    scanf("%d", &m);
    {
        int i; // both m and i in scope
        int n = 5;
        for (i = m; i < n; i++)
        {
            printf("The number is: %d\n", i);
        }
        
    }

    return 0;
}

char *myFunction(){
    char x[] = "apple";
}

int func_name(){

    auto int y;  // local variable

    return y;
}
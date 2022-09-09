#include <stdio.h>

// FAM - Flexible Array Members

struct s
{
    int arraySize;
    int array[];
}; // end of struct s


int main(){

    int desiredSize = 5;
    struct s *ptr;
    ptr = malloc( sizeof(struct s) + desiredSize * sizeof(int) );

    return 0;
}
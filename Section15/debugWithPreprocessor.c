#include <stdio.h>

#define DEBUG

int process(int i, int j, int k){
    return i + j + k;
}

void main(){
    int i, j, k, nread;
    nread = scanf("%d %d %d", &i, &j, &k);

    #ifdef DEBUG
    fprintf(stderr, "Number of integers read: %i\n", nread);
    fprintf(stderr, "The numbers are: %i, %i, %i\n", i, j, k);
    #endif

    printf("%d\n", process(i,j,k));

}
#include <stdio.h>

void create_and_sum_arr(){
    int sum = 0;
    size_t rows = 0;
    size_t columns = 0;
    printf("Enter number of rows:");
    scanf("%zd", &rows);
    printf("Enter number of columns:");
    scanf("%zd", &columns);
    int array[rows][columns];


    for(int r = 0; r<rows; r++)
        for(int c = 0; c<columns; c++){
            printf("Enter value to array[%d][%d]: ", r, c);
            scanf("%zd", &array[r][c]);
            sum += array[r][c]; // same as -> sum += value;
            printf("array[r][c]=%d\n", array[r][c]);
            // sum += value;
        }

    printf("Sum of elements: %d", sum);
}

int main(){
    
    create_and_sum_arr();

    return 0;
}
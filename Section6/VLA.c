#include <stdio.h>

// VLA - Variable Length Arrays

#define Length(arr) ((int)(sizeof(arr) / sizeof(arr)[0]));

void array(int size)
{
    char alpha[size];
    int x = 0;

    while (x < size)
    {
        alpha[x] = 'A' + x;
        printf("alpha is %c\n", alpha[x]);
        x++;
    }
}

int sum2d(int rows, int columns, int array[rows][columns]) // this is a VLA (Variable Length Array)
{
    int r;
    int c;
    int total = 0;
    for (r = 0; r < rows; r++)
        for (c = 0; c < columns; c++)
            total += array[r][c];
    return total;
}

int main()
{

    size_t size = 0;

    printf("\nEnter the number of elements you want to store:");
    scanf("%zd", &size);

    float values[size];
    int values_length = sizeof(values) / sizeof(int);

    printf("\nThe size of the array is: %d\n", values_length);

    // can be also suppurated like:
    size_t rows = 0;
    size_t columns = 0;
    printf("\nEnter the number of rows you want to store:");
    scanf("%zd", &rows);
    printf("\nEnter the number of columns in a row:");
    scanf("%zd", &columns);
    float myArray[rows][columns];

    // because of using the define option we could write:
    int myArray_length = Length(myArray);
    int myArray_width = Length(myArray[0]);
    printf("\nmyArray\n number of rows %d\n number of columns %d\n", myArray_length, myArray_width);

    // Same as:  (without the define)
    // int myArray_length = sizeof(myArray) / sizeof(myArray[0]);
    // int myArray_width = sizeof(myArray[0]) / sizeof(myArray[0][0]);
    // printf("\nmyArray\n number of rows %d\n number of columns %d\n", myArray_length, myArray_width);

    printf("\nNew Flow:\n");
    array(5);
    printf("\nNew Flow:\n");
    array(20);
    printf("\nNew Flow:\n");
    array(9);

    return 0;
}
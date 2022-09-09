#include <stdio.h>
#include <malloc.h>

struct myArray
{
    int length;
    int array[];
};

int main()
{
    int length = 0;
    printf("Enter the length of the array:");
    scanf("%d", &length);

    struct myArray *arrayPointer = NULL;
    arrayPointer = malloc(sizeof(struct myArray) + length * sizeof(int));
    arrayPointer->length = length;

    for (int i = 0; i < length; i++)
    {
        arrayPointer->array[i] = i;
    }

    printf("The Array is:\n[");
    for (int i = 0; i < length; i++)
    {
        if (i == length - 1)
        {
            printf("%d]", arrayPointer->array[i]);
        }
        else
            printf("%d, ", arrayPointer->array[i]);
    }

    return 0;
}

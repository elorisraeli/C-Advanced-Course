#include <stdio.h>

union student
{
    char letterGrade;
    int roundedGrade;
    float exactGrade;
};


void main(){

    union student record1;
    union student record2;

    record1.letterGrade = 'B';
    record1.roundedGrade = 87;
    record1.exactGrade = 86.50;

    printf("Union record1 values example:\n");
    printf("Letter Grade: %c\n", record1.letterGrade);
    printf("Rounded Grade: %d\n", record1.roundedGrade);
    printf("Exact Grade: %f\n", record1.exactGrade);

    printf("--- This is how to access which data type each time in union ---\n");

    printf("Union record2 values example:\n");
    record2.letterGrade = 'A';
    printf("Letter Grade: %c\n", record2.letterGrade);

    record2.roundedGrade = 100;
    printf("Rounded Grade: %d\n", record2.roundedGrade);

    record2.exactGrade = 99.53;
    printf("Exact Grade: %f\n", record2.exactGrade);


}
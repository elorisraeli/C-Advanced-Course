#include <stdio.h>
#include <stdlib.h>

// The 2 options are doing the same:


// // Function for Stack option

// double multipleByTwo(double input){
//     double twice = input * 2.0;
//     return twice;
// }

// Function for Heap option

double *multipleByTwo(double *input){
    double *twice = malloc(sizeof(int));
    *twice = *input * 2.0;
    return twice;
}



int main(){
// // Main for Stack option

//     int age = 30;
//     double salary = 12345.67;
//     double myList[3] = {1.2, 2.3, 3.4};
//     printf("double your salary is %.3f\n", multipleByTwo(salary));


// Main for Heap option

    int *age = malloc(sizeof(int));
    *age = 30;
    double *salary = malloc(sizeof(double));
    *salary = 12345.67;
    double *myList = malloc(3 * sizeof(double));
    myList[0] = 1.2;
    myList[1] = 2.3;
    myList[2] = 3.4;
    double *twiceSalary = multipleByTwo(salary);
    printf("double your salary is %.3f\n", *twiceSalary);

    free(age);
    free(salary);
    free(myList);


    return 0;
}
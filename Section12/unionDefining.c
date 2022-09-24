#include <stdio.h>


union car
{
    int i_value;
    float f_value;
    char c_value[40]; // without that value the size of the car union was 4
    //  because the largest value data needed 4 bytes.
};

// an example of using 'anonymous union' which is in a struct, 
// we can't create any unions type data of that anonymous union
struct owner
{
    char socSecurity[12];
};

struct leaseCompany
{
    char name[40];
    char headquarters[40];
};

struct car_data
{
    char make[15];
    int status; /* 0 = owned, 1 = leased */
    union
    {
        struct owner ownCar;
        struct leaseCompany leaseCar;
    };
    
};

/*
// another example
struct{
    char *name;
    enum symbolType type;
    union
    {
        int i;
        float f;
        char c;
    }data;
}table[entries];
*/



void main(){

    union car car1, car2, *car3; 
    printf("Memory size occupied by data: %zu\n", sizeof(car1));

}
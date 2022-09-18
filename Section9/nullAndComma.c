#include <stdio.h>

int f1();
int f2();

void main()
{
    // null statement
    char a[50] = "the empire strikes back";
    int i;
    for (i = 0; a[i] != 'm'; i++)
        ; // null statement

    printf("The 'm' char in the string is in position %d\n", i);

    int x = 3, y = 1, z = 2;
    if (y < z)
        if (x < y)
            printf("%d is the number in the middle\n", y);
        else
            ; // null statement because we want use the other 'else'
    else
        printf("The middle is unkown.\n");

    // The comma operator
    int j = 0, sum = 0;
    int data[] = {[0 ... 99] = 5};
    int array_length = sizeof(data) / sizeof(int);
    while (j < array_length)
    {
        // printf("sum=%d, j=%d\n", sum, j);
        sum += data[j], j++; // first sum += data and than i++;
        // printf("sum=%d, j=%d\n", sum, j);
        // printf("\n");
    }
    printf("sum = %d\n", sum);


    int k = (5, 10);
    printf("%d\n", k);

    int h = (f1(), f2()); // execute f1() function first and than f2()
    printf("%d\n", h);

    int m = (y = 3, (z = ++y + 2) + 5); // y=3, y=4, z=4+2=6, z=6+5=11
    printf("%d\n", m);

    int c,b;
    for (c = 0, b = 100; c != 10; ++c, b-=10)
    {
        printf("Elor "),
        printf("Israeli"),
        printf("\n");
    }

    int house_price = (249, 500);
    printf("%d\n", house_price);
    
    char ch, date;
    int d = 1, e = 2;
    printf("%d, %d", d, e);

} 

int f1(){
    return 6;
}

int f2(){
    return 60;
}
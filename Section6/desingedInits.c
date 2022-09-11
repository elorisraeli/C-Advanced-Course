#include <stdio.h>

struct point{ int x, y;};


int main(){

    int a[6] = { [5] = 123, [2] = 54};
    int a_length = (int) sizeof(a)/sizeof(int);

    for (int i = 0; i < a_length; i++)
    {
        printf("index_%d->%d\n", i, a[i]);
    }

    int b[] = {[0 ...9] = 1, [10 ...99] = 2, [100] = 3};
    int b_length = (int) sizeof(b)/sizeof(int);

    for (int i = 0; i < b_length; i++)
    {
        printf("index_%d->%d\n", i, b[i]);
    }
    

    struct point p1 = {.y = 2, .x = 3};
    struct point p2 = {y: 2, x: 3};
    struct point p3 = { 2, 3}; // the order is x=2, y=3 (as the point struct built)

    struct point ps[3] = {p1, p2, p3};
    // struct point ps[3] = {[0]=p1, [1]=p2, [2]=p3}; // another option
    int p_length = (int) sizeof(ps)/sizeof(ps[0]);
    printf("%d\n", p_length);
    for (int i = 0; i < p_length; i++)
    {
        printf("X=%d, Y=%d\n", ps[i].x, ps[i].y);
    }
    // another option
    struct point ps2[] = {[0].x=4, [1].x=7, [6].y=9};
    int p2_length = (int) sizeof(ps)/sizeof(ps[0]);
    printf("%d\n", p2_length);
    for (int i = 0; i < p2_length; i++)
    {
        printf("X=%d, Y=%d\n", ps2[i].x, ps2[i].y);
    }
    
    return 0;
}
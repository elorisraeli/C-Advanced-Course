#include <stdio.h>

#define JUST_CHECKING // without that line the ifdef wont print
#define LIMIT 4

#define MYDEF 5
#define MYOTHERDEF 2


#define US 0
#define UK 1
#define France 2
#define Germany 3
#define Country France // changing this we get another options

void main(void)
{

    int i = 0;
    int total = 0;

    for (i = 1; i <= LIMIT; i++)
    {
        total += 2 * i * i + 1;
        #ifdef JUST_CHECKING
          printf("i=%d, running total = %d\n", i, total);
        #endif
    }
    printf("Total = %d\n", total);



    #if MYDEF == 5 && MYOTHERDEF == 2 // without both of them, its wont print
        printf("hello.\n");
    #endif        


    /*
    // un potion of use (not initialize anything)
    #ifdef UNIX
    # define DATADIR "/uxn1/data"
    #else
    # define DATADIR "\usr\data"
    #endif
    */



   // another use:
    #if Country == US || Country == UK
        #define Greeting "Hello."
    #elif Country == France
        #define Greeting "Bonjour."    
    #elif Country == Germany
        #define Greeting "Guten Tag."
    #endif

    printf("Greeting is: %s\n", Greeting);
}
#include <stdio.h>

/*
4 operators for the processor: 
1) \ 
    allows for the continuation of a macro to the next line when the macro
    is too long for a single line.
2) defined()
    used in constant expressions to determine if an identifier is defined using #define. 
3) #
    '#' is used within a macro definition, causes a replacement text token to be
    converted to a string surrounding by quotes.
4) ##
    '##' performs token pasting, concatenates two tokens, the two tokens on either side of
    each '##' operator are combined into a single token.
*/

#define min(x,y)\
((x) < (y) ? x : y)

#if defined(DEBUG)
// ... rest of code
#endif

#if defined(WINDOWS) || defined(WINDOWSNT)
# define BOOT_DRIVE "C:/"
#else 
# define BOOT_DRIVE "D:/"
#endif

#define str(x) #x

#define HELLO(x) printf("Hello, " #x "\n");

#define printint(var) printf(#var " = %i\n", var);

#define TOKENCONCAT(x,y) x ## y

#define make_function(name) int my_ ## name (int foo){printf("The number is: %d\n", foo);}
make_function(elor);

#define eat(what) puts("I'm eating " #what " today.\n");

/*
if you want to write this:

struct command{
    char *name;
    void (*function)(void);
};
struct command commands[] = {
    ("quit", quit_command)
    ("help", help_command)
    ...
};

you can write:
*/
#define COMMAND(NAME) {#NAME, NAME ## _command}
struct command commands[]
{
    COMMAND(quit);
    COMMAND(help);
    // ...
};


void main(){

    printf("Here is the boot drive path: %s\n", BOOT_DRIVE);
    
    printf(str(Programming is fun!!\n));

    HELLO(Elor);
    
    printint(5);
    
    int xy = 10;
    printf("%d\n", TOKENCONCAT(x,y)); // printf("%d\n", xy); 

    my_elor(7);

    eat(fruit);
}
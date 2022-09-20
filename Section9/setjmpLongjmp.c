#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

/*
mainly use to implement exception handling
setjmp can be used as 'try catch'
longjmp can be used as 'throw'
(difference from goto command: its can jump between functions while goto can't)
(longjmp can also jump between files)

handling call chain without error

HOW THEY WORKS?
setjmp - saves a copy of the program counter and the current pointer to the top of the stack
int setjmp(jmp_buf j)
longjmp - invoked after setjmp
longjmp(jmp_buf j, int i)
says go back to the place that the k is remembering
restore the process in the state that it existed when it called setjmp
return the value if i so the code can tell when you actually got back here via longjmp()
the contents of the k are destroyed when it is used in a longjmp()

must include header <setjmp.h>
*/

jmp_buf buf;

jmp_buf myBuf;
void myFunction()
{
    printf("in myFunction()\n");
    longjmp(myBuf, 1);

    // NOT REACHED
    printf("we won't see this line printed because I longjmp'd.\n");
}

void main()
{
    // example 1
    int i = setjmp(buf);
    printf("i=%d\n", i);
    if (i != 0) 
        goto example2; // this line and exit() command are to avoid infinite loop
        // exit(0);
    longjmp(buf, 42);
    printf("End\n");

    // example 2
    example2:
    if (setjmp(myBuf))
    {
        printf("back in main\n");
    }
    else
    {
        printf("First time through\n");
        myFunction();
    }
}
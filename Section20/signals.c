#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
// #include <sys/signal.h>

void nothing(int signum);

void handler_DivideByZero(int signum);

void signalHandler(int signalValue);

void main()
{
    //  signal(SIGINT, SIG_IGN);
    //  while(1);
    
    /*
    printf("Testing SIGSTOP\n");
    raise(SIGSTOP);
    printf("I an back\n\n");
    */

    /*
     alarm(5);
     // NEED TO CATCH SIGALRM or process terminates
     // signal(SIGALRM, alarmHandler)
     for (int i = 1; i <= 10; i++)
     {
         printf("%d\n", i);
         sleep(1);
     }
     */

    /*
    // handling a signal using signal function
    int result = 0, v1 = 121, v2 = 0;
    void (*sigHandlerReturn)(int);
    sigHandlerReturn = signal(SIGFPE, handler_DivideByZero);
    if (sigHandlerReturn == SIG_ERR)
    {
        perror("Signal Error: ");
        return;
    }
    result = v1/v2;
    printf("Result of Divide by Zero is %d\n", result);
 */

    int i; // counter used to loop 100 times
    int x; // variable to hold random values between 1-50
    signal(SIGINT, signalHandler);
    srand(clock());
    // output numbers 1-100
    for (i = 1; i <= 100; i++)
    {
        x = 1 + rand() % 50;

        if (x == 25){
            raise(SIGINT);
            printf("\n SIGINT = %4d \n", SIGINT);
        }

        printf("%4d", i);

        if (i % 10 == 0)
            printf("\n");
    }
}

void signalHandler(int signalValue){
    int response; // user response to signal 1 or 2
    // printf("%s%d%s\n%s", "\n Interrupt signal (", signalValue,") received.",
    // " Do you wish to continue (1=yes, 2=no): ");
    printf("\n Interrupt signal (%d) received. \nDo you wish to continue (1=yes, 2=no): ", signalValue);
    scanf("%d", &response);
    // check for invalid responses
    while ((response != 1) && (response != 2))
    {
        printf("Enter choice (1 = yes, 2 = no): ");
        scanf("%d", &response);
    }
    if (response == 1) // reregister signal handler for next SIGINT
        signal(SIGINT, signalHandler);
    else
        exit(EXIT_SUCCESS);
}   

void handler_DivideByZero(int signum)
{
    if (signum == SIGFPE)
    {
        printf("Received SIGFPE, Divide by Zero Exception\n");
        exit(0);
    }
    else
    {
        printf("Received %d Signal", signum);
    }
}
#include <stdlib.h>
#include <stdio.h>

pthread_attr_t attr;

void *doWork(void *threadid){
    long tid;
    size_t myStackSize;
    tid = (long)threadid;
    pthread_attr_getstacksize(&attr, &myStackSize);
    printf("Thread %ld: stack size = %li bytes \n", tid, myStackSize);
    pthread_exit(NULL);    
}

int main(){
    pthread_t myThread;
    size_t stackSize;
    pthread_t myID;
    long t;

    pthread_attr_init(&attr);
    pthread_attr_getstacksize(&attr, &stackSize);
    printf("Default stack size = %li\n", stackSize);
    stackSize = 9000000;
    printf("Amount of stack needed per thread = %li\n", stackSize);
    pthread_attr_getstacksize(&attr, %stackSize);

    printf("Creating thread with stack size = %li bytes", stackSize);

    myID = pthread_create(&myThread, &attr, doWork, (void *)t);
    if (myID)
    {
        printf("ERROR: return code from pthread_create() is %lud\n", myID);
        exit(-1);
    }
    pthread_exit(NULL);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
// #include <process.h>
// #include <io.h>
// #include <Windows.h>

void main(){
    int myProcessID, myParentProcessID;
    printf("Program to know PID and PPID's information.\n");
    myProcessID = getpid();
    // myParentProcessID = getppid();
    printf("My process ID is %d\n", myProcessID);
    // printf("My parent process ID is %d\n", myParentProcessID);
    printf("Cross verification of pid's by executing commands on shell\n");
    system("ps -ef");
}

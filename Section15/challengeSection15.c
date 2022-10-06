#include <stdlib.h>
#include <stdio.h>

int sum(int x, int y, int z)
{
    char c = 2;
    int *a = malloc(sizeof(int));

#ifdef DEBUG
    fprintf(stderr, "x=%d\n", x);
    fprintf(stderr, "y=%d\n", y);
    fprintf(stderr, "z=%d\n", z);
    fprintf(stderr, "a=%ld\n", (long)a);
#endif

    *a = 5;

#ifdef DEBUG
    fprintf(stderr, "*a=%d\n", *a);
#endif

    return (c + x + y + z + *a) / 3;
}

int main(int argc, char *argv[])
{
    int i, j, k;
    int result;

#ifdef DEBUG
    fprintf(stderr, "Number of parameters = %d\n", argc);
#endif

    if (argc == 1)
    {
        printf("Please specify three numbers as parameters.\n");
        exit(1);
    }

    i = atoi(argv[1]);

#ifdef DEBUG
    fprintf(stderr, "i=%d\n", i);
#endif

    j = atoi(argv[2]);

#ifdef DEBUG
    fprintf(stderr, "j=%d\n", j);
#endif

    k = atoi(argv[3]);

#ifdef DEBUG
    fprintf(stderr, "k=%d\n", k);
#endif

    result = sum(i, j, 12) + sum(j, k, 19) + sum(i, k, 13);

    printf("%d\n", result);

    return 0;
}




/*
RUNNING IN THE CMD CHALLENGE NUMBER 2:

C:\Users\Elor Israeli\C Advanced Course\Section15>gcc -g coreFiles.c

C:\Users\Elor Israeli\C Advanced Course\Section15>a.exe

C:\Users\Elor Israeli\C Advanced Course\Section15>ls
About_Section15.txt  coreFiles.c    debugWithGDB.c    debugWithPreprocessor.c
a.exe                coreFiles.exe  debugWithGDB.exe  debugWithPreprocessor.exe

C:\Users\Elor Israeli\C Advanced Course\Section15>gcc challengeSection15.c

C:\Users\Elor Israeli\C Advanced Course\Section15>ls -lrt
total 189
-rw-r--r-- 1 Elor Israeli 197121   151 Oct  4 14:54 About_Section15.txt
-rwxr-xr-x 1 Elor Israeli 197121 41516 Oct  6 18:46 debugWithPreprocessor.exe
-rw-r--r-- 1 Elor Israeli 197121  3394 Oct  6 18:52 debugWithPreprocessor.c
-rwxr-xr-x 1 Elor Israeli 197121 41210 Oct  6 19:53 debugWithGDB.exe
-rw-r--r-- 1 Elor Israeli 197121  3203 Oct  6 20:21 debugWithGDB.c
-rwxr-xr-x 1 Elor Israeli 197121 40680 Oct  6 20:31 coreFiles.exe
-rw-r--r-- 1 Elor Israeli 197121   624 Oct  6 20:38 coreFiles.c
-rw-r--r-- 1 Elor Israeli 197121  1028 Oct  6 21:10 challengeSection15.c
-rwxr-xr-x 1 Elor Israeli 197121 41569 Oct  6 21:11 a.exe

C:\Users\Elor Israeli\C Advanced Course\Section15>chmod a+x a.exe

C:\Users\Elor Israeli\C Advanced Course\Section15>a.exe
Please specify three numbers as parameters.

C:\Users\Elor Israeli\C Advanced Course\Section15>gcc challengeSection15.c -o main

C:\Users\Elor Israeli\C Advanced Course\Section15>main.exe
Please specify three numbers as parameters.

C:\Users\Elor Israeli\C Advanced Course\Section15>gcc -o main.exe main.o
gcc: error: main.o: No such file or directory
gcc: fatal error: no input files
compilation terminated.

C:\Users\Elor Israeli\C Advanced Course\Section15>ls -lrt
total 233
-rw-r--r-- 1 Elor Israeli 197121   151 Oct  4 14:54 About_Section15.txt
-rwxr-xr-x 1 Elor Israeli 197121 41516 Oct  6 18:46 debugWithPreprocessor.exe
-rw-r--r-- 1 Elor Israeli 197121  3394 Oct  6 18:52 debugWithPreprocessor.c
-rwxr-xr-x 1 Elor Israeli 197121 41210 Oct  6 19:53 debugWithGDB.exe
-rw-r--r-- 1 Elor Israeli 197121  3203 Oct  6 20:21 debugWithGDB.c
-rwxr-xr-x 1 Elor Israeli 197121 40680 Oct  6 20:31 coreFiles.exe
-rw-r--r-- 1 Elor Israeli 197121   624 Oct  6 20:38 coreFiles.c
-rw-r--r-- 1 Elor Israeli 197121  1028 Oct  6 21:10 challengeSection15.c
-rwxr-xr-x 1 Elor Israeli 197121 41569 Oct  6 21:11 a.exe
-rwxr-xr-x 1 Elor Israeli 197121 41569 Oct  6 21:12 main.exe

C:\Users\Elor Israeli\C Advanced Course\Section15>gcc -c challengeSection15.c

C:\Users\Elor Israeli\C Advanced Course\Section15>gcc -o main.exe main.o
gcc: error: main.o: No such file or directory
gcc: fatal error: no input files
compilation terminated.

C:\Users\Elor Israeli\C Advanced Course\Section15>gcc -o main.exe challengeSection15.o

C:\Users\Elor Israeli\C Advanced Course\Section15>ls -lrt
total 237
-rw-r--r-- 1 Elor Israeli 197121   151 Oct  4 14:54 About_Section15.txt
-rwxr-xr-x 1 Elor Israeli 197121 41516 Oct  6 18:46 debugWithPreprocessor.exe
-rw-r--r-- 1 Elor Israeli 197121  3394 Oct  6 18:52 debugWithPreprocessor.c
-rwxr-xr-x 1 Elor Israeli 197121 41210 Oct  6 19:53 debugWithGDB.exe
-rw-r--r-- 1 Elor Israeli 197121  3203 Oct  6 20:21 debugWithGDB.c
-rwxr-xr-x 1 Elor Israeli 197121 40680 Oct  6 20:31 coreFiles.exe
-rw-r--r-- 1 Elor Israeli 197121   624 Oct  6 20:38 coreFiles.c
-rw-r--r-- 1 Elor Israeli 197121  1028 Oct  6 21:10 challengeSection15.c
-rwxr-xr-x 1 Elor Israeli 197121 41569 Oct  6 21:11 a.exe
-rw-r--r-- 1 Elor Israeli 197121  1313 Oct  6 21:14 challengeSection15.o
-rwxr-xr-x 1 Elor Israeli 197121 41569 Oct  6 21:15 main.exe

C:\Users\Elor Israeli\C Advanced Course\Section15>gcc -g challengeSection15.c -o main.exe

C:\Users\Elor Israeli\C Advanced Course\Section15>gcc -Wall challengeSection15.c -o main.exe

C:\Users\Elor Israeli\C Advanced Course\Section15>gcc -Werorr challengeSection15.c -o main.exe
gcc: error: unrecognized command line option '-Werorr'; did you mean '-Werror'?

C:\Users\Elor Israeli\C Advanced Course\Section15>gcc -Werror challengeSection15.c -o main.exe

C:\Users\Elor Israeli\C Advanced Course\Section15>ls -lrt
total 237
-rw-r--r-- 1 Elor Israeli 197121   151 Oct  4 14:54 About_Section15.txt
-rwxr-xr-x 1 Elor Israeli 197121 41516 Oct  6 18:46 debugWithPreprocessor.exe
-rw-r--r-- 1 Elor Israeli 197121  3394 Oct  6 18:52 debugWithPreprocessor.c
-rwxr-xr-x 1 Elor Israeli 197121 41210 Oct  6 19:53 debugWithGDB.exe
-rw-r--r-- 1 Elor Israeli 197121  3203 Oct  6 20:21 debugWithGDB.c
-rwxr-xr-x 1 Elor Israeli 197121 40680 Oct  6 20:31 coreFiles.exe
-rw-r--r-- 1 Elor Israeli 197121   624 Oct  6 20:38 coreFiles.c
-rw-r--r-- 1 Elor Israeli 197121  1028 Oct  6 21:10 challengeSection15.c
-rwxr-xr-x 1 Elor Israeli 197121 41569 Oct  6 21:11 a.exe
-rw-r--r-- 1 Elor Israeli 197121  1313 Oct  6 21:14 challengeSection15.o
-rwxr-xr-x 1 Elor Israeli 197121 41569 Oct  6 21:16 main.exe

C:\Users\Elor Israeli\C Advanced Course\Section15>main.exe
Please specify three numbers as parameters.

C:\Users\Elor Israeli\C Advanced Course\Section15>main.exe 1 2 3

C:\Users\Elor Israeli\C Advanced Course\Section15>gcc -D DEBUG -g challengeSection15.c -o main.exe

C:\Users\Elor Israeli\C Advanced Course\Section15>main.exe 1 2 3
Number of parameters = 4
i=1
j=2
k=3
x=1
y=2
z=12
a=0

C:\Users\Elor Israeli\C Advanced Course\Section15>
*/

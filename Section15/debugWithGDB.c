#include <stdio.h>
#include <stdlib.h>

struct date{
    int month;
    int day;
    int year;
};

struct date foo(struct date x){
    ++x.day;
    return x;
}


// int foo(void){
//     int x = 0;
//     return x * x;
// }

void main(){
    /*
    const int data[5] = {1, 2, 3, 4, 5};
    int i = 0, sum = 0;

    for (i = 0; i >= 0; i++)
        sum += data[i];

    printf("sum = %i\n", sum);
    */

   struct date today = {10, 6, 2022};
   int array[5] = {1, 2, 3, 4, 5};
   struct date *newDate, foo();
   char *string = "text string";
   int i = 3;

   newDate = (struct date *) malloc(sizeof(struct date));
   newDate->month = 10;
   newDate->day = 3;
   newDate->year = 2022;

   today = foo(today);

   free(newDate);

}


/*
cmd:
gcc -g FILENAME.c
gcc a.exe
run     --> will run the program
list 9      --> will give you the list of the 10 line before and after 9
print sum       --> will print the sum variable (can be use to print any variable)
quit        --> to quit the gdb


also after running the program:
(gdb) set var i=5
(gdb) print i
$1 = 5      --> the gdb prints this line
(gdb) set var i = i * 2
(gdb) print i
$2 = 10
(gdb) set var i = $1 + 20
(gdb) print i
$3 = 25
(gdb) print main::i
$4 = 25
(gdb) set var main::i=0
(gdb) print main::i
$5 = 0

(if we have the appropriate variable wwe can write:
print dataPtr->year
and its will print it..)

also JUST THE LETTER P IS PRINT and do the same
(gdb) p data
$7 = {1, 2, 3, 4, 5}
(gdb) p /x i         --> the option to print with HEX numbers
$8 = 0x0
(gdb) p /x data
$9 = {0x1, 0x2, 0x3, 0x4, 0x5}          --> the HEX print


also JUST THE LETTER L IS LIST and do the same
if we type:
list 5      --> will give you the list of the 10 line before and after 5
ENTER       --> continue the list of the next 10 lines
l 5         --> same as list 5

l 10, 15        --> give you the range of lines between 10 to 15
l +             --> next 10 lines
l -             --> previous 10 lines


to be able see specific function, must enter the line:
gcc -d FILENAME.c
gdb a.exe
and than to search:
list FUNCTION_NAME
(gdb) list foo
1       #include <stdio.h>
2
3       int foo(void){
4           int x = 0;
5           return x * x;
6
7       }


we can create breakpoints with the gdb, just type:
break 9     --> in line 9 we will have a breakpoint
break foo   --> in the first line of the function we will have a breakpoint
break foo.c:foo     --> in specific file in specific function
run     --> to run the program
(the program will stop at the breakpoint)
c       --> to continue the program to run (maybe to the next breakpoint)
s       --> to continue to the next line (step)
next    --> same as s


while the program runs, we can search:
info locals     --> list of all the local variables
info break      --> all the breakpoints in the program

clear 20        --> clear the breakpoint from line 20
clear foo       --> clear the breakpoint from the line of foo function


more commands of gdb:
help                --> all the commands
help breakpoints        --> specific breakpoints commands

*/
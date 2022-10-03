#include <stdio.h>

void my_function_name(void){
    printf("%s was called.\n", __func__);
}


void main(){
    my_function_name();

    /*
    // a case of using the __FILE__ and __LINE__ macros
    if (fopen(&pfile, filemane, "rb")) // open for binary read
    {
        fprintf(stderr, "Failed to open file in %s line %d\n", __FILE__, __LINE__);
    }
    */

   printf("File is %s line is %d\n", __FILE__, __LINE__);

   printf("Program last compiled at %s on %s\n", __TIME__, __DATE__);

    #if (__STDC__ == 1)
        printf("Implementation is ISO-conforming.\n");
    #else
        printf("Implementation is not ISO-conforming.\n");
    #endif

}
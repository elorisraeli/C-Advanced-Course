#include <stdio.h>

/*
BIT _Bool (1 bit)--> 0 to 1
Byte char (8 bit)--> -128 to 127
Word short int (16 bits)--> -32,768 to 32,767
Long long int (32 bits)--> -2,147,483,648 to 2,147,483,647
*/

int binary2Decimal(long long binary_number){
    long long int answer = 0;
    int i = 1;
    while (binary_number > 0)
    {
        answer += ((binary_number%10)*i);
        // printf("i=%d, bin=%lld, answer=%d (+%d)\n",i ,binary_number, answer, (binary_number%10)*i);
        i*=2;
        binary_number /= 10;
    }
    return answer;
}

long long decimal2Binary(int decimal){
    long long answer = 0;
    int i = 1;
    int reminder;
    while (decimal != 0)
    {
        // printf("i=%d, dec=%d, answer=%lld (+%d)\n",i ,decimal, answer, (reminder*i));
        reminder = decimal%2;
        decimal /= 2;
        answer += (reminder*i);
        i *= 10;
    }
    // printf("i=%d, dec=%d, answer=%lld (+%d)\n",i ,decimal, answer, (reminder*i));
    return answer;
}

// in comment for the 'bitwiseOps.c' file that run main and use this file functions
/*
int main(){
    printf("\nStart\n");
    long long binary = 0;
    printf("Enter binary number: ");
    scanf("%d", &binary);
    int decimal = binary2Decimal(binary);
    printf("Binary=%lld, Decimal=%d\n", binary, decimal);

    int dec = 0;
    printf("Enter decimal number: ");
    scanf("%d", &dec);
    long long bin = decimal2Binary(dec);
    printf("Dec=%d, Bin=%lld\n",dec, bin);

}
*/
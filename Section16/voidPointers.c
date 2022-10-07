#include <stdio.h>
#include <string.h>
#include <malloc.h>

// send(void *pData, int nLength);

// char *data = "blah";
// send(data, strlen(data));

void main(){
    int a = 100, *ip;
    float f = 12.2, *fp;
    char c = 'a';
    void *vp = NULL;

    vp = &a;
    printf("void pointer now points to int pointer, vp: value=%d, address=%u\n", *(int *)vp, &vp);

    ip = &a;
    vp = ip;
    printf("void pointer now points to int pointer, vp: value=%d, address=%u\n", *(int *)vp, &vp);

    fp = &f;
    vp = fp;
    printf("void pointer now points to float pointer, vp: value=%.2f, address=%u\n", *(float *)vp, &vp);

    vp = &c;
    printf("void pointer now points to char, vp: value=%c, address=%u\n", *(char *)vp, &vp);


    // pointer sizes (4 bytes (in the teacher program its 8 bytes))
    void *pvData = NULL;
    int *iData = NULL;
    char *cData = NULL;
    float *fData = NULL;
    printf("size of void pointer = %d\n", sizeof(pvData));
    printf("size of int pointer = %d\n", sizeof(iData));
    printf("size of char pointer = %d\n", sizeof(cData));
    printf("size of float pointer = %d\n", sizeof(fData));


    // example void pointer
    int aiData[3] = {100, 200, 300};
    pvData = &aiData[1]; // address of 200
    pvData += sizeof(int);
    printf("pvData value = %d\n", *(int *)pvData);

}
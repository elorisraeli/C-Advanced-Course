#include <stdio.h>
#include <pthread.h>

void* calls(void* ptr){
    printf("In function \nthread id = %d\n", pthread_self());
    pthread_exit(NULL);
    return NULL;
}

void *threadFn(void *arg){
    pthread_detach(thread_self());
    sleep(1);
    printf("Thread Fn\n");
    pthread_exit(NULL);
}

int main(){
    /* 
    pthread thread;
    pthread_create(&thread, NULL, calls, NULL);
    printf("In main \nthread id = %d\n", thread);
    pthread_join(thread, NULL);
    */

   pthread_t tid;
   int ret = pthread_create(&tid, NULL, threadFn, NULL);

   if (ret != 0)
   {
    perror("Thread Creation Error\n");
    exit(1);
   }
   printf("After thread crated in main\n");
   pthread_exit(NULL);
   


    return 0;
}
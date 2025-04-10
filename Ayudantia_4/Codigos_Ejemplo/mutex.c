#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;

void *thread_func(void *arg){
    pthread_mutex_lock(&lock);
    //  SC
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(){
    pthread_t threads[4];
    pthread_mutex_init(&lock, NULL);
    for(int i = 0 ; i < 4 ; i++){
        pthread_create(threads[i], NULL, thread_func, NULL);
    }
    for(int i = 0 ; i < 4 ; i++){
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&lock);
}
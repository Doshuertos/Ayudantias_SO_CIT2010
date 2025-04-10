#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t semaforo;

void* thread_func(void* arg){
    sem_wait(&semaforo);
    //  SC
    sem_post(&semaforo);
    return NULL;
}

int main(){
    sem_init(&semaforo, 0, 2);
    pthread_t threads[4];
    for(int i = 0 ; i < 4 ; i++){
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }
    for(int i = 0 ; i < 4 ; i++){
        pthread_join(threads[i], NULL);
    }
    return 0;
}
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t pl;
int arr[10];
int flag = 0;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

void* rp() {
    int i = 0;
    printf("\nIngrese valores\n");
    for (i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
    }
    pthread_mutex_lock(&pl);
    pthread_cond_wait(&cv, &pl);
    pthread_mutex_unlock(&pl);
    pthread_exit(NULL);
}

void* ev() {
    int i = 0;
    pthread_mutex_lock(&pl);
    pthread_cond_signal(&cv);
    pthread_mutex_unlock(&pl);
    printf("Los valores ingresados en el arreglo son:");
    for (i = 0; i < 4; i++) {
        printf("\n%d\n", arr[i]);
    }
    pthread_exit(NULL);
}








/*El error del codigo viene al usar pthread_cond_wait en la funcion rp,
ya que, el fauncion ev podría ya haber enviado pthread_cond_signal antes
 de que rp empiece a esperar. Eso causaría que el hilo rp se quede bloqueado para siempre */

 //Posible solucion con flags:

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t pl = PTHREAD_MUTEX_INITIALIZER;
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
    // Esperar a que flag sea 1
    while (flag == 0) {
        pthread_cond_wait(&cv, &pl);
    }
    pthread_mutex_unlock(&pl);
    pthread_exit(NULL);
}

void* ev() {
    int i = 0;
    pthread_mutex_lock(&pl);
    flag = 1;
    pthread_cond_signal(&cv);
    pthread_mutex_unlock(&pl);

    printf("Los valores ingresados en el arreglo son:");
    for (i = 0; i < 4; i++) {
        printf("\n%d\n", arr[i]);
    }
    pthread_exit(NULL);
}

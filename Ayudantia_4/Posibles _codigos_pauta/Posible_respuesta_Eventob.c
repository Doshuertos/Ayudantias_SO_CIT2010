/* A: Los threads serian las personas que quieren comprar entradas de cancha
o galeria. La seccion crıtica serian los asientos de la galerıa y la cancha. Utilizar un
asiento o un lugar de cancha seria entrar a la seccion critica.*/



#include <stdio.h>
#include <pthread.h>

int asientos_galeria[M_GALERIA] = {0};
int asientos_cancha = 0;

pthread_mutex_t mutex_galeria = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_cancha = PTHREAD_MUTEX_INITIALIZER;

void* comprar_galeria(void* arg) {
    pthread_mutex_lock(&mutex_galeria);
    for (int i = 0; i < M_GALERIA; i++) {
        if (asientos_galeria[i] == 0) {
            asientos_galeria[i] = 1;
            printf("Asiento asignado a cliente en galería, en el asiento %d\n", i);
            break;
        }
    }
    pthread_mutex_unlock(&mutex_galeria);
    return NULL;
}

void* comprar_cancha(void* arg) {
    pthread_mutex_lock(&mutex_cancha);
    if (asientos_cancha < N_CANCHA) {
        asientos_cancha++;
        int asiento = asientos_cancha;
        printf("Lugar asignado a cliente en Cancha, asiento %d\n", asiento);
    }
    pthread_mutex_unlock(&mutex_cancha);
    return NULL;
}
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

int asientos_galeria[M_GALERIA] = {0};
int asientos_cancha = 0;

pthread_mutex_t mutex_galeria = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_cancha = PTHREAD_MUTEX_INITIALIZER;

int concierto_actual = 0;
int galeria_llena = 0;
int cancha_llena = 0;

void reiniciar_ventas() {
    pthread_mutex_lock(&mutex_cancha);
    pthread_mutex_lock(&mutex_galeria);
    guardar_en_BD();
    for (int i = 0; i < M_GALERIA; i++) {
        asientos_galeria[i] = 0;
    }
    asientos_cancha = 0;
    galeria_llena = 0;
    cancha_llena = 0;
    pthread_mutex_unlock(&mutex_galeria);
    pthread_mutex_unlock(&mutex_cancha);
}

void* comprar_galeria(void* arg) {
    pthread_mutex_lock(&mutex_galeria);
    bool encontrado = false;
    for (int i = 0; i < M_GALERIA; i++) {
        if (asientos_galeria[i] == 0) {
            asientos_galeria[i] = 1;
            printf("Asiento asignado a cliente en galería, en el asiento %d\n", i);
            encontrado = true;
            break;
        }
    }
    if (!galeria_llena && !encontrado) {
        galeria_llena = 1;
    }
    pthread_mutex_unlock(&mutex_galeria);
    if (cancha_llena && galeria_llena)
        reiniciar_ventas();
}

void* comprar_cancha(void* arg) {
    pthread_mutex_lock(&mutex_cancha);
    if (asientos_cancha < N_CANCHA) {
        asientos_cancha++;
        int asiento = asientos_cancha;
        printf("Lugar asignado a cliente en Cancha\n");
    } else {
        cancha_llena = 1;
    }
    pthread_mutex_unlock(&mutex_cancha);
    if (cancha_llena && galeria_llena)
        reiniciar_ventas();

}
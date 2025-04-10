/* El problema que tiene el codigo es que puede generar un busy waiting,
ya que, 2 o mas treads pueden pasar el while(lock) lock siendo 0, asi accediendo
a la seccion critica pudiendo asi generar errores de output, para solucionarlo se 
podria usar mutex o semaforo*/

//Solucion mutex: 
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

void* mythread(void* arg) {
    pthread_mutex_lock(&lock);
    // sección crítica
    pthread_mutex_unlock(&Lock)
    return NULL;
}
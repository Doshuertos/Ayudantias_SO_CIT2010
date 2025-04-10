/*A:Profesores: Mauricio Hidalgo, Victor Reyes, y Martin Gutierrez. Representan a los productores.
Platos: Representan los recursos compartidos que los profesores van a preparar en las
parrillas y colocar en las mesas.
Mesa: Representa la seccion citica donde los platos son dispuestos para que los comensales los retiren.
Comensales: Representan los procesos o hilos que participan en el evento y retiran
los platos de la mesa.
Capacidad de la mesa (N): Representa el numero maximo de platos que pueden ser colocados en la mesa.
Cantidad de carne disponible (K): Representa la cantidad total de platos que pueden
ser preparados durante todo el evento. Capacidad de produccion.
Cantidad de comensales (M): Representa el numero total de procesos que participan
en el evento.
Parrillas: Representan los recursos compartidos por los profesores para cocinar los
platos. Recursos para producir.
Limite de platos por parrilla (K/2): Representa la cantidad maxima de platos que cada
parrilla puede cocinar durante todo el evento. Limite de produccion.*/


#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5       // Capacidad de la mesa
#define K 1000    // Cantidad de carne disponible
#define M 10      // Cantidad de comensales

sem_t mutex;                 // Para exclusión mutua
sem_t platos_disponibles;    // Semáforo para indicar platos disponibles en la mesa

int platos_en_mesa = 0;
int carne_disponible = K;

void* profesor(void* id) {
    int* prof_id = (int*) id;
    while (1) {
        sem_wait(&mutex);  // Bloquear la sección crítica
        if (platos_en_mesa < N && carne_disponible > 0) {
            printf("Profesor %d colocando un plato en la mesa.\n", *prof_id);
            platos_en_mesa++;
            carne_disponible--;
            sem_post(&platos_disponibles);  // Indicar que hay un plato disponible en la mesa
        }
        sem_post(&mutex);  // Desbloquear la sección crítica
        sleep(3);          // Tiempo que tarda el profesor en preparar un plato
    }
}

void* comensal(void* id) {
    int* com_id = (int*) id;
    while (1) {
        sem_wait(&platos_disponibles);  // Esperar a que haya un plato disponible
        sem_wait(&mutex);               // Bloquear la sección crítica
        printf("Comensal %d retirando un plato de la mesa.\n", *com_id);
        platos_en_mesa--;
        sem_post(&mutex);               // Desbloquear la sección crítica
        sleep(5);                       // Tiempo que tarda el comensal en comer
    }
}
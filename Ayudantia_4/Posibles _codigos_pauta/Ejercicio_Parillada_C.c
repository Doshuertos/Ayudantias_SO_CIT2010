#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define PARRILLAS 2  // Cantidad de parrillas
#define N 5          // Capacidad de la mesa
#define K_INICIAL 1000  // Cantidad inicial de carne disponible

sem_t mutex[PARRILLAS];                    // Exclusión mutua para cada parrilla
sem_t platos_disponibles[PARRILLAS];      // Indicar platos disponibles en las mesas
int platos_en_mesa[PARRILLAS] = {0};      // Contadores de platos en cada mesa
int K = K_INICIAL;                         // Carne restante

void* profesor(void* id) {
    int* profid = (int*) id;
    while (true) {
        for (int i = 0; i < PARRILLAS; i++) {
            sem_wait(&mutex[i]);  // Bloquear la sección crítica de la parrilla i

            if (platos_en_mesa[i] < N && K > 0) {
                printf("Profesor %d colocando un plato en la mesa %d.\n", *profid, i + 1);
                platos_en_mesa[i]++;
                K--;
                sem_post(&platos_disponibles[i]);  // Indicar que hay un plato disponible
            }

            sem_post(&mutex[i]);  // Desbloquear la sección crítica de la parrilla i
        }
        sleep(3);  // Tiempo que tarda el profesor en preparar un plato
    }

}

void* comensal(void* id) {
    int* com_id = (int*) id;
    while (1) {
        for (int i = 0; i < PARRILLAS; i++) {
            sem_wait(&platos_disponibles[i]);  // Esperar a que haya un plato disponible en la mesa i
            sem_wait(&mutex[i]);               // Bloquear la sección crítica de la parrilla i

            printf("Comensal %d retirando un plato de la mesa %d.\n", *com_id, i + 1);
            platos_en_mesa[i]--;

            sem_post(&mutex[i]);               // Desbloquear la sección crítica de la parrilla i
        }
        sleep(5);  // Tiempo que tarda el comensal en comer el plato
    }

}

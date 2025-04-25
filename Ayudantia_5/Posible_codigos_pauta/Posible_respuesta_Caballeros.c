//a
// Los caballeros son los threads, las espadas y los escudos son los recursos y equiparse es la seccion critica

//b
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


pthread_mutex_t espadas[N];
pthread_mutex_t escudos[N];

void* caballero(void* arg) {
    int id = *(int*)arg;
    int escudo = id;
    int espada = (id + 1) % N;

    int primero, segundo;
    pthread_mutex_t* lock1;
    pthread_mutex_t* lock2;

    // Determinar qué recurso se toma primero para evitar interbloqueo
    if (escudo < espada) {
        primero = escudo;
        segundo = espada;
        lock1 = &escudos[escudo];
        lock2 = &espadas[espada];
    } else {
        primero = espada;
        segundo = escudo;
        lock1 = &espadas[espada];
        lock2 = &escudos[escudo];
    }

    while (1) {
        // Simula pensar (fuera de la sección crítica)
        printf("Caballero %d está pensando...\n", id);
        sleep(1);

        // Entra a la sección crítica en orden
        pthread_mutex_lock(lock1);
        pthread_mutex_lock(lock2);

        // Sección crítica: el caballero descansa con sus recursos
        printf("Caballero %d descansa con espada %d y escudo %d \n", id, espada, escudo);
        sleep(2);

        // Sale de la sección crítica: libera los recursos
        pthread_mutex_unlock(lock2);
        pthread_mutex_unlock(lock1);
    }

    return NULL;
}
//c

if (id == 2) {
    // Seath hace cosas impredecibles
    int r = rand() % 3;
    if (r == 0) {
        // Acapara ambos recursos
        pthread_mutex_lock(&espadas[espada]);
        pthread_mutex_lock(&escudos[escudo]);
        printf("Seath ha tomado espada %d y escudo %d, ¡caos en la hoguera!\n", espada, escudo);
        sleep(4);
        pthread_mutex_unlock(&espadas[espada]);
        pthread_mutex_unlock(&escudos[escudo]);
    } else if (r == 1) {
        // Solo toma uno
        pthread_mutex_lock(&espadas[espada]);
        printf("Seath manipula solo la espada %d...\n", espada);
        sleep(2);
        pthread_mutex_unlock(&espadas[espada]);
    } else {
        // Finge tomar recursos (¡no hace lock!)
        printf("Seath finge tener escudo %d y espada %d...\n", escudo, espada);
        sleep(3);
    }
    continue;
}
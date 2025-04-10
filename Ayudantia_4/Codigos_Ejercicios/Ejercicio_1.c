#include <stdio.h>

int lock = 0;

void* mythread(void* arg) {
    while (lock);
    lock = 1;
    // sección crítica
    lock = 0;
    return NULL;
}

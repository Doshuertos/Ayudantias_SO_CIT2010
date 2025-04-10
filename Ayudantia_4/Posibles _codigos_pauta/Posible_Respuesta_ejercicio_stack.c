/*Se crean 4 semaforos para gestionar el stack */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutexA;//Se utiliza para que solo un thread pueda acceder a la seccion critica "StackA"
sem_t mutexB;//Se utiliza para que solo un thread pueda acceder a la seccion critica "StackB"
sem_t itemsA;//Se utiliza para esperar que haya elementos en StackA 
sem_t itemsB;//Se utiliza para esperar que haya elementos en StackB

void AtoB() {
    sem_wait(&itemsA);        
    sem_wait(&mutexA);       
    int x = pop(StackA);      
    sem_post(&mutexA);        
    sem_wait(&mutexB);         
    push(x, StackB);          
    sem_post(&mutexB);        
    sem_post(&itemsB);       
}

void BtoA() {
    sem_wait(&itemsB);         
    sem_wait(&mutexB);         
    int x = pop(StackB);     
    sem_post(&mutexB);         
    sem_wait(&mutexA);        
    push(x, StackA);           
    sem_post(&mutexA);    
    sem_post(&itemsA);         
}

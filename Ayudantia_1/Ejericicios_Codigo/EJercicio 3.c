#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
    
    pid_t id = fork();
    for(int i = 0; i < 2 ; i++)
    {
        pid_t pid = fork();
        if(pid == id){
            printf("Hola como estas\n");
        }else{
            printf("Adios\n");
        }
    }
}
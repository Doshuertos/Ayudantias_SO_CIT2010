
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
int main(){
    pid_t pid = fork();
    if(pid == 0){
        printf("Hola soy el hijo y mi id es %d y mi pid es %d\n", getpid(), pid);
    }else{

        printf("Hola soy el padre y mi id es %d y mi pid es %d\n",getpid(),pid);
        
    }
}
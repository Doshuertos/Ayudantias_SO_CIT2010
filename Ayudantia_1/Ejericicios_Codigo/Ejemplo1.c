#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>


int counter = 0; //variable global
int main(){ //codigo1 
    pid_t r;
    while(counter < 2){
        r= fork();
        if(r > 0 ){
            execlp("./Ejemplo2", "", NULL);
        }
        counter = counter + 1;

        printf("%d\n", counter);
    }

    return 0;
}
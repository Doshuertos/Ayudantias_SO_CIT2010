#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int iter = 0;

int main() {
    while (iter < 2) {
        iter++;
        if (fork()) {
            printf("Hollow Knight\n");
            if (iter > 1) {
                pid_t tt = fork();
                if (tt > 0)
                    printf("Ender Lilies\n");
                
                printf("Ender Magnolia\n");
                exit(1);
            }
        }
    }
    printf("Silksong\n");
}
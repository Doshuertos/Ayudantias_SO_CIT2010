#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main() {
    if (fork() != fork()) {
        pid_t t = fork();
        printf("Artorias\n");
        if (t > 0) {
            printf("Ornstein\n");
        } else if (t == 0) {
            printf("Smough\n");
            exit(0);
        } else {
            printf("Hydra\n");
            exit(0);
        }
    }
    printf("Gwyn\n");
}

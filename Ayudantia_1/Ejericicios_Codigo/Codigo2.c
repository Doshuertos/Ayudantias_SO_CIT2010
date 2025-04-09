#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() { // Codigo 2
    sleep(666);
    fork();
    printf("Brisket\n");
    exit(0);
}
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
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


int main() {
    // Codigo 1
    pid_t r[3];

    for (int i = 0; i < 3; i++) {
        r[i] = fork();
        if (r[i] == 0) {
            printf("Ramen\n");
            execlp("./Codigo2", "", NULL);
        }
    }

    sleep(10);
    printf("Sushi\n");

    for (int i = 0; i < 3; i++) {
        kill(r[i], SIGKILL);
    }

    return 0;
}










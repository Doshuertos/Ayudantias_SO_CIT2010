#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int num = 1; // variable global

int main() {
    pid_t t = fork();
    if (t != 0) {
        num = num * 2;
        pid_t tt = fork();
        if (tt > 0) {
            num = num - 2;
        } else if (tt < 0) {
            fork();
            num = num + 2;
        }
    }
    num = num + 1;
    sleep(1);
    printf("%d\n", num);
}
#include <stdio.h>
#include <zconf.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>


int main() {
    int p = fork();
    if(p == 0) {
        while(1) {
            printf("I'm alive\n");
            sleep(1);
        }
    }
    else {
        sleep(10);
        printf("I don't want to die\n");
        printf("(╥﹏╥)\n");
        kill(0, SIGTERM);
    }
    return 0;
}
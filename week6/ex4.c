#include <stdio.h>
#include <zconf.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

/*void sg(int n) {
    if (n == SIGINT)
        printf("    Intercepts Ctrl+C\n");
}*/
void sgkill(int n) {
    printf("    Kill signal\n");
}
void sgstop(int n) {
    printf("    Stop signal\n");
}
void sgusr1(int n) {
    printf("    USR1 signal\n");
}

int main() {
    //signal(SIGINT, sg);
    signal(SIGKILL, sgkill);
    signal(SIGSTOP, sgstop);
    signal(SIGUSR1, sgusr1);
    while(1){};
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
    int n = 101;
    pid_t  pid;
    pid = fork();
    if(pid == 0) {
        printf("Hello from child ");
        printf("%d\n", pid - n);
    }
    else {
        printf("Hello from parent ");
        printf("%d\n", pid - n);
    }
    return 0;
}
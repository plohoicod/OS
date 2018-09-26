#include <stdio.h>
#include <zconf.h>
#include <string.h>


int main() {
    int pipe1[2], p;
    const char a[] = "OSlab";
    char b[6];
    pipe(pipe1);
    p = fork();
    if(p == 0) {
        write(pipe1[1], a, strlen(a));
    }
    else {
        read(pipe1[0], b, 5);
        printf("%s\n", b);
    }
    return 0;
}
#include <stdio.h>
#include <zconf.h>
#include <string.h>


int main() {
    int pipe1[2];
    const char a[] = "OSlab";
    char b[5];
    pipe(pipe1);
    write(pipe1[1], a, strlen(a));
    read(pipe1[0], b, 5);
    printf("%s\n", b);
    return 0;
}
#include <stdio.h>
#include <zconf.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

void sg(int n) {
    if (n == SIGINT)
        printf("    Intercepts Ctrl+C\n");
}
int main() {
    signal(SIGINT, sg);
    while(1){};
    return 0;
}
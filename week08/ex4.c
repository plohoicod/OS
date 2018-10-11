#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <zconf.h>

int main(){
    struct rusage usage;
    int b = 1024 * 1024 * 10;
    char *data;
    for(int i = 0; i < 10; i++){
        data =  calloc(b, 1);
        getrusage(RUSAGE_SELF, &usage);
        printf("Usage:%d\n", usage.ru_ixrss);
        sleep(1);
    }
    return 0;
}
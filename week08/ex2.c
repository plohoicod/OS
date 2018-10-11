#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <zconf.h>

int main(){
    int b = 1024 * 1024 * 10;
    char *data;
    for(int i = 0; i < 10; i++){
        data =  calloc(b, 1);
        sleep(1);
    }
    return 0;
}
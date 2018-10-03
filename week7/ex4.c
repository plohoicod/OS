#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
void *reallc(void *old, int sz){
    int sz1;
    void *new;
    if(old == NULL) {
        new = malloc(sz);
        return new;
    }
    if(sz == 0) {
        free(old);
        return old;
    }
    sz1 = sizeof(old);
    if (sz > sz1) {
        new = malloc(sz);
        memcpy(new, old, sz1);
        free(old);
        return new;
    }
    return old;
}
int main(){
    int *a = malloc(10*sizeof(int));
    for(int i = 0; i < 10; i++)
        a[i] = i;
    for(int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
    a = realloc(a, 15);
    for(int i = 0; i < 15; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
void begin() {
    printf("Write command: ");
}
void readin(char *s) {
    fgets (s , 100, stdin);
}
//void print(char *s) {
//}
int main() {
    char s[100];
    while(1) {
        begin();
        readin(s);
        system(s);
    }
}
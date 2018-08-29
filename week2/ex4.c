#include <stdio.h>
#include <string.h>
void swap(int *a, int *b) {
    int p = *b;
    *b = *a;
    *a = p;
}
int main() {
    int a, b;
    printf("Print two integers:\n");
    scanf("%d", &a);
    scanf("%d", &b);
    swap(&a, &b);
    printf("%d\n", a);
    printf("%d\n", b);
    return 0;
}
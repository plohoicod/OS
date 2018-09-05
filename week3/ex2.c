#include <stdio.h>
#include <string.h>
int * bubble_sort(int n, int a[]) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                int z = a[i];
                a[i] = a[j];
                a[j] = z;
            }
        }
    }
    return a;
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int *z = bubble_sort(n, a);
    for(int i = 0; i < n; i++) {
        printf("%d ", *(z + i));
    }
    printf("\n");
    return 0;
}
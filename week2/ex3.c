#include <stdio.h>
#include <string.h>
int main() {
    int n;
    scanf("%d", &n);
    int l = n - 1;
    int r = n + 1;
    for(int z = 0; z < n; z++) {
        for(int i = 0; i < l; i++) {
            printf(" ");
        }
        for(int i = l + 1; i < r; i++) {
            printf("%c", '*');
        }
        for(int i = r; i < n * 2 - 2; i++) {
            printf(" ");
        }
        l--;
        r++;
        printf("\n");
    }
    return 0;
}
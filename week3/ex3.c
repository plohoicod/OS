#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    int n;
    struct Node * node;
};
/*void CreateList() {
    struct Node *z = NULL;
    return z;
}*/
void insert_node(struct Node **k, int n) {
    struct Node *z;
    z = malloc(sizeof(struct Node));
    z -> n = n;
    z -> node = *k;
    *k = z;
}
int print_top(struct Node **k) {
    return (*k) -> n;
}
void delete_node(struct Node **k) {//pop last added element
    struct Node *z;
    z = malloc(sizeof(struct Node));
    z = (*k) -> node;
    *k = z;
}
void print_list(struct Node **k) {
    struct Node * z = *k;

    while (z != NULL) {
        printf("%d ", z -> n);
        z = z -> node;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    struct Node *a = malloc(sizeof(struct Node));
    //a -> node = malloc(sizeof(struct Node));
    insert_node(a, n);
    insert_node(a, 3);
    print_list(a);
    printf("\n");
    printf("%d", print_top(a));
    printf("\n");
    delete_node(a);
    printf("%d", print_top(a));
    return 0;
}
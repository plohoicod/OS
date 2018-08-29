#include <stdio.h>
#include <limits.h>
#include <float.h>
int main() {
    int a1 = 20;
    float a2 = 2.1;
    double a3 = 2232.113213;
    printf("The value of integer %d\n", a1);
    printf("The size of integer %d\n", sizeof(a1));
    printf("The max int %d\n", INT_MAX);
    printf("\n");
    printf("The value of float %f\n", a2);
    printf("The size of float %d\n", sizeof(a2));
    printf("The max float %f\n", FLT_MAX);
    printf("\n");
    printf("The value of double %lf\n", a3);
    printf("The size of double %d\n", sizeof(a3));
    printf("The max doutble %lf\n", DBL_MAX);
    return 0;
}
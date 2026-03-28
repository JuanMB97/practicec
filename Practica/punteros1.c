#include <stdio.h>

void swap(int *a, int *b) {
    int tem = *a;
    *a = *b;
    *b = tem;
}

int main() {
    int a = 5;
    int b = 10;

    printf("A: %d - B: %d\n", a, b);

    printf("Intercambiando! \n");
    swap(&a, &b);

    printf("A: %d - B: %d\n", a, b);
}
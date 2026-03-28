#include <stdio.h>

int main() {
    char *heores[] = { "Lion", "Lich", "Cristal M"};

    // Bucle for
    for (int i=0; i < 3 ;i++) {
        printf("%s\n", heores[i]);
    }

    // Bucle while

    int min = 10;
    int max =15;

    while (min < max) {
        printf("%d\n", min);
        min++;
    }

    // Bucle Do while

    int count = 0;

    do {
        printf("%d ", count);
        count ++;
    } while (count < 10);


    return 0;
}
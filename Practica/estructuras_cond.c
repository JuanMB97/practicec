#include <stdio.h>

int main() {
    int dato = 23;

    if (dato > 20) {
        printf("Es mayor a 20\n");
    }else {
        printf("Es menor a 20\n");
    }

    switch(dato) {
        case 1: 
            printf("Vale 1\n");
            break;
        case 232: 
            printf("Vale 23\n");
            break;
        default:
            printf("No aplica\n");

    }

    return 0;
}
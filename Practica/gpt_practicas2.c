#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    if(argc != 3) {
        return 1;
    }

    printf("Cantidad de parametros: %d.\n", argc);
    int num1 = atoi(argv[1]);
    printf("Num1: %d.\n", num1);

    int num2 = atoi(argv[2]);  
    printf("Num2: %d.\n", num2);

    int suma = num1 + num2;
    printf("La suma entre %i y %i es %i. \n", num1, num2, suma );
    return 0;

}
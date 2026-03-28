#include <stdio.h>
#include <stdlib.h>

int main() {
    int cant_letras;
    char *palabra;
    printf("Cuantas letras tendra la palabra?");
    scanf("%i", &cant_letras);
    
    // Reservamos espacio para la cantidad de letras mas el salto de linea.
    palabra = malloc((cant_letras+1) * sizeof(char));
    printf("Ingrese la palabra:");
    scanf("%s", palabra);
    free(palabra);

    return 0;
}

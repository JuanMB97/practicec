#include <stdio.h>


int sumar(int a, int b) {
    return a + b;
}


int main(void) {

    char frase [] = "Soy una frase";
    int tel = 2312;
    char letra = 'y';

    char *heores[] = { "Lion", "Lich", "Cristal M"};

    // Solo puede tener un maximo de dos elementos. 
    char *limitado[2] = { "Juan", "Manuel" }; 

    // Constantes
    const float PI = 3.14;

    #define AGE 28
   
    printf("%i\n",AGE);

    
    // Llamamos a una funcion

    int c = sumar(55, 8);
    printf("%d\n", c);

    printf("Hola mundo\n");
    printf("%s\n", frase);   
    printf("%d\n", tel);
    printf("%c\n", letra);

    printf("%s\n", heores);
    printf("%f\n", PI);

    printf("%d\n", 4 == 5);

    printf("%d\n", 1 && 0);
    printf("%d\n", 1 || 0);
    return 0;
}



#include <stdio.h>

int main() {
    int entero = 11;
    float flotante = 9.5;
    char caracter = 'p';

    int *m_entero = &entero;
    float *m_flotante = &flotante;
    char *m_caracter = &caracter;

    printf("Entero: %d %p \n", entero, m_entero);
    printf("Flotante: %f %p \n", flotante, m_flotante);
    printf("Caracter: %c %p \n", caracter, m_caracter);

    return 0;
}
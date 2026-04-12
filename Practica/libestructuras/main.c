#include "include/cola.h"
#include "include/pila.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Cola* cola = cola_crear();
    Pila* pila = pila_crear();

    printf("POINTER QUEUE: %p", cola);
    printf("POINTER STACK: %p", pila);

    free(pila);
    free(cola);



    return 0;
}

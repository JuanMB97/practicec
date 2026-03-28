#include<stdio.h>
#include <stdlib.h>

struct NodoCola {
    int dato;
    struct NodoCola *next;
};

struct Cola {
    struct NodoCola *first;
    struct NodoCola *last;
};

void agregar_cola(struct Cola *cola, int dato){
    struct NodoCola *nuevo = malloc(sizeof(struct NodoCola));
    
    nuevo->dato = dato;
    nuevo->next = NULL;

    if(cola->first == NULL){
        cola->first = nuevo;
        cola->last = nuevo;
    } else {
        cola ->last->next = nuevo;     
        cola ->last = nuevo;
    }
}


void imprimir_cola(struct Cola *cola){

    struct NodoCola *temp = malloc(sizeof(struct NodoCola));
    temp = cola->first;

    while (temp != NULL) { 
        printf("%d \n", temp->dato);
        temp = temp->next;
    }
}

int main() {
    
    // Esto es una lista por lo que no se pide memoria en el heap
    // como si ocurre al crear un nodo 'struct'.
    struct Cola n_cola = {NULL};

    agregar_cola(&n_cola, 5);
    agregar_cola(&n_cola, 10);
    agregar_cola(&n_cola, 6);

    imprimir_cola(&n_cola);


    return 0;
}

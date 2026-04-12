#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

typedef struct Pila {
    Nodo* tope;   
} Pila;

Pila* pila_crear(){
    Pila* p = malloc(sizeof(struct Pila));
    p->tope = NULL;
    return p;
}

void pila_push(Pila* p, int dato){
    Nodo* temp_nodo = malloc(sizeof(Nodo));

    temp_nodo->dato = dato;
    temp_nodo->siguiente = p->tope;
    p->tope = temp_nodo;
}

int pila_pop(Pila* p){
    int dato = 0;
    if(p->tope != NULL) {
        Nodo* temp_nodo = p->tope;
        dato = temp_nodo->dato;

        p->tope = p->tope->siguiente;
        free(temp_nodo);
    } 
    return dato;
}

void pila_destruir(Pila* p){
    Nodo* temp_nodo;

    while(p->tope != NULL){
        temp_nodo = p->tope;
        p->tope = p->tope->siguiente;
        free(temp_nodo);
    }
}

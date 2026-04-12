#include <stdlib.h>
#include <stdio.h>
#include "./../include/pila.h"

typedef struct Cola {
    Nodo *primero;
    Nodo *ultimo;
} Cola;

Cola* cola_crear(){
    Cola* cola = malloc(sizeof(Cola));
    cola->primero = NULL;
    cola->ultimo = NULL;
    return cola;
}

void cola_push(Cola* cola, int dato){
    Nodo* n_nodo = malloc(sizeof(Nodo));
    n_nodo->dato = dato;
    n_nodo->siguiente = NULL;

    if(cola->primero == NULL){
        cola->primero = n_nodo;
        cola->ultimo = n_nodo;
    } else{
        cola->ultimo->siguiente = n_nodo;
        cola->ultimo = n_nodo; 
    } 
}

int cola_pop(Cola* cola){
    int dato = 0;
    if(cola->primero != NULL){
        Nodo* t_nodo = cola->primero;
        dato = t_nodo->dato;

        cola->primero = cola->primero->siguiente;
        free(t_nodo);
    }
    return dato; 
}

void cola_destruir(Cola* cola){
    Nodo* t_nodo;
    while(cola->primero != NULL){
        t_nodo = cola->primero;
        cola->primero = cola->primero->siguiente;

        free(t_nodo);
    }
    cola->ultimo = NULL;
}

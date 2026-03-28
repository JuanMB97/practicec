#include <stdlib.h>
#include <stdio.h>
struct NodoCola {
    int dato;
    struct NodoCola *siguiente;
};

struct Cola {
    struct NodoCola *primero;
    struct NodoCola *ultimo;
};


void agregar_elem_cola(struct Cola *apilador, int dato){
    struct NodoCola *nuevo_elem = malloc(sizeof(struct NodoCola));
    
    nuevo_elem->dato = dato;

    if(apilador->primero == NULL){
        apilador->primero = nuevo_elem;
        apilador->ultimo = nuevo_elem;
        apilador->primero->siguiente = NULL;
    }else{
        // Si agregamos un segundo elemento, entonces el primer elemento 
        // debe tener una referencia al segundo elemento que sera nuevo_elem
        apilador->ultimo->siguiente = nuevo_elem;

        // Al primer elemento 
        apilador->ultimo = nuevo_elem;
    }
}

void imprimir_cola(struct Cola *cola){

    struct NodoCola *nodo_actual = malloc(sizeof(struct NodoCola));

    nodo_actual = cola->primero;

    while(nodo_actual != NULL){
        printf("%d \n", nodo_actual->dato);
        nodo_actual = nodo_actual->siguiente;
    }
}

int main(){

    struct Cola elementos = {NULL, NULL};
    
    agregar_elem_cola(&elementos, 23);

    agregar_elem_cola(&elementos, 57);

    agregar_elem_cola(&elementos, 100);

    imprimir_cola(&elementos);

   return 0;
}



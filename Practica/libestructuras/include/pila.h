#ifndef PILA_H
#define PILA_H

typedef struct Nodo{
    int dato;
    struct Nodo* siguiente;
} Nodo;


typedef struct Pila {
    Nodo* tope;
} Pila;

// creación
Pila* pila_crear();

// operaciones
void pila_push(Pila* p, int dato);
int pila_pop(Pila* p);

// liberar memoria
void pila_destruir(Pila* p);

#endif

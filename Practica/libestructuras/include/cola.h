#ifndef COLA_H
#define COLA_H
#include "pila.h"

typedef struct Cola{
    Nodo* primero;
    Nodo* ultimo;
} Cola;

Cola* cola_crear();
void cola_push(Cola* c, int dato);
int cola_pop(Cola* c);
void cola_destruir(Cola* c);

#endif

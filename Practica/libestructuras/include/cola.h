#ifndef COLA_H
#define COLA_H

typedef struct Cola Cola;

Cola cola_crear();
void push_cola(Cola c, int dato);
int pop_cola(Cola c);
void cola_destruir(Cola c);

#endif

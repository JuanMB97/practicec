#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int data;
    struct Nodo *next;
};

void push(struct Nodo **cima, int valor){
    struct Nodo *nuevo = malloc(sizeof(struct Nodo));
    nuevo->data = valor;
    nuevo->next = *cima;
    *cima = nuevo;
}

int main(){
    struct Nodo *tope = NULL;
    
    push(&tope, 5);
    push(&tope, 8);

    printf("%i\n", tope->data);

}

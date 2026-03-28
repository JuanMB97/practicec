#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int data;
    struct Nodo *next;
};

struct Nodo* push(struct Nodo *top, int value){

    struct Nodo *nuevo = malloc(sizeof(struct Nodo));

    nuevo->data = value;
    nuevo->next = top;

    return nuevo;
}

int pop(struct Nodo **top){

    struct Nodo *temp = *top;
    int valor = temp->data;
    *top = temp->next;

    free(temp);

    return valor;
}

int main(){

    struct Nodo *top = NULL;

    top = push(top, 3);
    top = push(top, 8);

    printf("%d\n", pop(&top));

    printf("%d\n", top->data);
}

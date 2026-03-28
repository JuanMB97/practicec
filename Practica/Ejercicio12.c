#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int data;
    struct Nodo *next;
};

void push(struct Nodo **top, int value){
    struct Nodo *nuevo = malloc(sizeof(struct Nodo));
    nuevo->data = value;
    nuevo->next = *top;
    *top = nuevo;
}

void clear(struct Nodo *top){
    struct Nodo *actual = top;

    while(actual != NULL){
        free(actual);
        actual = actual->next;
    }
}

int main(){

    struct Nodo *top = NULL;

    push(&top, 1);
    push(&top, 2);
    push(&top, 3);

    clear(top);

    if(top != NULL){
        printf("Top: %d\n", top->data);
    }

    return 0;
}


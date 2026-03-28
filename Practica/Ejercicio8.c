#include <stdio.h>
#include <stdlib.h>

// Lista enlazada por nodos (PILA)

struct Nodo {
    int data;
    struct Nodo *next;
};

struct Nodo  *tope = NULL;

void add_node(int data){
    
    struct Nodo *n_nuevo;
    n_nuevo = malloc(sizeof(struct Nodo));
    n_nuevo->data = data;

    if(tope == NULL){
        tope = n_nuevo;
        n_nuevo->next = NULL;
    } else{
        n_nuevo->next = tope;
        tope = n_nuevo;
    }
}

void clear_memory(){
    struct Nodo *prev;
    while(tope != NULL) {
        prev = tope;
        tope = tope->next;
        free(prev);
    }
}

void read_stack() {
    struct Nodo *current = tope;
    int unsigned pos = 0;
    while(current != NULL){
        printf("Data %i: %i \n", pos, current->data);
        current = current->next;
        pos++;
    }
}

int main(){
    
    add_node(6);
    add_node(10);

    read_stack(); 

    clear_memory();

    return 0;
}

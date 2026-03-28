#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nodo para una lista que almacena enteros.
struct Elemento{
    int dato;
    struct Elemento *siguiente;
};

// Cola de nodos que almacena enteros.
struct Cola {
    struct Elemento *primero;
    struct Elemento *ultimo;
};

void agregar_cola(struct Cola *cola, int dato){
    struct Elemento *nuevo = malloc(sizeof(struct Elemento));

    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    if(cola->primero == NULL){
        cola->primero = nuevo;
        cola->ultimo = nuevo;
    }else{
        cola->ultimo->siguiente = nuevo;
        cola->ultimo = nuevo;
    }
}

// Lo siguiente modifica la variable 'elem_pila' del main
// por lo que al salir de la funcion agregar_pila
// la variable elem_pila del main queda apuntando
// a lo que apunta el 'elem_pila' de la funcion agregar,
// por eso le puse el mismo nombre, porque se trata de exactamente
// lo mismo, aunque se puede ponerle otro nombre.
void agregar_pila(struct Elemento **elem_pila, int dato){
    struct Elemento *n_elemento = malloc(sizeof(struct Elemento)); 
    n_elemento->dato = dato;
   
    n_elemento->siguiente = *elem_pila;
    *elem_pila = n_elemento;
}

// Esto recibe una copia de la referencia al que apunta 'elem_pila' del main
// Por lo que al modificar tope, la variable 'elem_pila' del main no modifica 
// la referencia al que estaba apuntando antes de llamar a 'mostrar_pila'.
void mostrar_pila(struct Elemento *tope){
    printf("[");
    while(tope != NULL){
        printf("%d, ", tope->dato);
        tope = tope->siguiente;
    }
    printf("] \n");
}

void mostrar_cola(struct Cola *cola){
    struct Elemento *temp = cola->primero;

    printf("[");
    while(temp != NULL){
         printf("%d, ", temp->dato);
         temp = temp->siguiente;
    }
    printf("] \n");
    
}

void liberar_pila(struct Elemento **elem){
    while(*elem != NULL){
        struct Elemento *temp  = *elem;
        
        *elem = temp->siguiente;
        free(temp);        
    }
    // Setteamos a null la referencia a la que apunta elem, que al
    // pasarlo con doble ** esta modificacion lo afecta directamente.
    *elem = NULL;
}


// No hace falta pasar con doble asterisco porque la variable
// cola declarado en el main no es una direccion sino una structura.
// Simplemente le pasamos la direccion para que trabaje sobre esos 
// datos (Dos nodos a liberar). Y no el ownership
void liberar_cola(struct Cola *cola){
    struct Elemento *temp;

    while(cola->primero != NULL){
        temp = cola->primero;
        
        cola->primero = cola->primero->siguiente;
         
        free(temp);
    }
    cola->ultimo = NULL;    
}

int pop_pila(struct Elemento **elem_pila){
     
    int dato = -1;

    if(*elem_pila != NULL){
        struct Elemento *nodo = *elem_pila;
        dato = (*elem_pila)->dato;
        *elem_pila = (*elem_pila)->siguiente;
        free(nodo);
    }

    return dato;
}

int dequeue(struct Cola *cola){
    int dato = -1;

    if(cola->primero != NULL){
        struct Elemento *tope = cola->primero;
        dato = tope->dato;
        cola->primero = tope->siguiente;
        free(tope);
    }
    
    // Al extraer el ultimo elemento, queda *primero apuntando a null, *tope
    // libera ese ultimo nodo y *ultimo queda apuntando a una
    // memoria que fue liberada.
    // Por lo tanto:
    if(cola->primero == NULL){
        cola->ultimo = NULL;
    }

    return dato;
}

int size_pila(struct Elemento *pila){
    int count = 0;

    while(pila != NULL){
        count++;
        pila = pila->siguiente;
    }

    return count;
}

int size_cola(struct Cola *cola){
    int count = 0;
    struct Elemento *nodo = cola->primero; 
    
    while(nodo != NULL){
        count++;
        nodo = nodo->siguiente;
    }

    free(nodo);

    return count;
}

void invertir_pila(struct Elemento **elem_pila){
    struct Elemento *aux =  NULL;

    while(*elem_pila != NULL){
        struct Elemento *temp = (*elem_pila);
        
        *elem_pila = (*elem_pila)->siguiente;
        temp->siguiente = aux;
        aux = temp;
    }

    *elem_pila = aux;
}

int main(){
    // Es una direccion de memoria que almacena un struct
    struct Elemento *elem_pila = NULL;
    
    // Es una estructura, no una direccion de memoria
    struct Cola cola = {NULL, NULL};

    char opc;
    int dato;
    do {
        printf("Ingrese un valor para guardar en una lista LIFO y una FIFO: \n");
        scanf("%d", &dato);
        
        agregar_pila(&elem_pila, dato);
        agregar_cola(&cola, dato);
        
        printf("Desea agregar otro elemento? y/n\n");
        scanf(" %c", &opc);
 
    }while(opc != 'n');
    
    printf("PILA: ");
    mostrar_pila(elem_pila);
    printf("COLA: ");
    mostrar_cola(&cola);

    pop_pila(&elem_pila);
    dequeue(&cola);

    printf("DESAPILAR: ");
    mostrar_pila(elem_pila);

    printf("Size stack: %d \n", size_pila(elem_pila));
    printf("Size Queue: %d \n", size_cola(&cola));

    invertir_pila(&elem_pila);
    printf("PILA INVERTIDA: ");
    mostrar_pila(elem_pila);

    liberar_pila(&elem_pila);
    liberar_cola(&cola);

    

    return 0;
}


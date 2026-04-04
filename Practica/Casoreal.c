#include <stdio.h>
#include <stdlib.h>

struct Pedido {
    int id;
};


struct Elemento {
    struct Pedido pedido;
    struct Elemento *siguiente;
};

struct Pedidos {
    struct Elemento *primero;
    struct Elemento *ultimo;
};

int mostrar_menu(){
    int opc = -1;
    printf("----MENU-----");
    printf("1. Nuevo pedido\n");
    printf("2. Cancelar ultimo\n");
    printf("3. Atender pedido\n");
    printf("4. Rehacer cancelacion\n");
    printf("5. Mostrar estado\n");
    printf("6. Salir");
    printf("Seleccione una opcion: ");
    scanf("%d", &opc);
    return opc;
}

void agregar_pedido(struct Pedidos *pedidos, struct Pedido nuevo_pedido){

    struct Elemento *nuevo = malloc(sizeof(struct Elemento));

    nuevo->pedido = nuevo_pedido;
    nuevo->siguiente = NULL;
    
    if(pedidos->primero == NULL){
        pedidos->primero = nuevo;
        pedidos->ultimo = nuevo;
    }else{
        pedidos->ultimo->siguiente = nuevo;
        pedidos->ultimo = nuevo;

    }

}
// 
void eliminar_ultimo(struct Elemento **cancelados, struct Pedidos *pedidos){

    if(pedidos->primero != NULL){

        if(pedidos->primero != pedidos->ultimo){
            struct Elemento *penultimo = pedidos->primero;
    
            while(penultimo->siguiente->siguiente != NULL){
                penultimo = penultimo->siguiente;
            }
            pedidos->ultimo->siguiente = *cancelados;
            *cancelados = pedidos->ultimo;
            penultimo->siguiente = NULL;
            pedidos->ultimo = penultimo;
        }else{
            pedidos->primero->siguiente = *cancelados;
            *cancelados = pedidos->primero;
            pedidos->primero = NULL;
            pedidos->ultimo = NULL;
        }
    }
}

void limpiar_cola(struct Pedidos *cola){
    struct Elemento *nodo;

    while(cola->primero != NULL){
        nodo = cola->primero;
        cola->primero = cola->primero->siguiente;
        free(nodo);
    }
    cola->ultimo = NULL;
}

void limpiar_pila(struct Elemento **pila){
    struct Elemento *temp_nodo;

    while(*pila != NULL){
        temp_nodo = *pila;
        *pila = (*pila)->siguiente;
        free(temp_nodo); 
    }
}

void mostrar_eliminados(struct Elemento *pila){
    printf("ELiminados: [ ");
    while(pila != NULL){
        printf("%d ", pila->pedido.id);
        pila = pila->siguiente;
    }
    printf("]\n");
}

void mostrar_cola(struct Pedidos *cola){
    struct Elemento *temp_nodo = cola->primero;
    printf("Elementos de la cola: [ ");
    while(temp_nodo != NULL){
        printf("%d ", temp_nodo->pedido.id);
        temp_nodo = temp_nodo->siguiente;
    }
    printf("]\n");
}

void rehacer_pedido(struct Pedidos *pedido, struct Elemento **cancelados){
    if(*cancelados != NULL){
        if(pedido->primero != NULL){
            pedido->ultimo->siguiente = *cancelados;
            pedido->ultimo = *cancelados;
            *cancelados = (*cancelados)->siguiente;
            pedido->ultimo->siguiente = NULL;
        }else {
            pedido->primero = *cancelados;
            pedido->ultimo = *cancelados;
            *cancelados = (*cancelados)->siguiente;
            pedido->primero->siguiente = NULL;
        }
    }

}

int main(){

    struct Pedidos pedidos = {NULL,NULL};
    struct Elemento *nodo_cancelados = NULL;


    struct Pedido ped1 = {5};
    struct Pedido ped2 = {10};
    struct Pedido ped3 = {22};

    agregar_pedido(&pedidos, ped1);
    //agregar_pedido(&pedidos, ped2);
    //agregar_pedido(&pedidos, ped3);

    mostrar_cola(&pedidos);
    eliminar_ultimo(&nodo_cancelados, &pedidos);
    mostrar_eliminados(nodo_cancelados);
    mostrar_cola(&pedidos);
    rehacer_pedido(&pedidos, &nodo_cancelados);
    mostrar_cola(&pedidos);
    mostrar_eliminados(nodo_cancelados);
    limpiar_cola(&pedidos);
    limpiar_pila(&nodo_cancelados);

    return 0;
}

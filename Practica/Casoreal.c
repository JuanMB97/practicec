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
    struct Elemento primero;
    struct Elemento ultimo;
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
        pedidos->primero = *nuevo;
        pedidos->ultimo = *nuevo;
    }else{
        pedidos->primero->siguiente = nuevo;

    }

}

void agregar_cancelado(struct Elemento **cancelados, struct Pedido dato){
   struct Elemento *nodo = malloc(sizeof(struct Elemento));

   nodo->pedido = dato;
   nodo->siguiente = *cancelados;

   *cancelados = nodo;
}




int main(){

    struct Pedidos *pedidos = {NULL,NULL};
    struct Elemento *nodo_cancelados = NULL;

    int opc;

    struct Pedido ped1 = {5};
    agregar_pedido(pedidos, ped1);

    //agregar_cancelado(&, ped1 );
    return 0;
}

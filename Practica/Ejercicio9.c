#include<stdio.h>
#include<stdlib.h>

struct Empleado {
    int id;
    char nombre[40];
    char rol[40];
};


struct NodeEmpleado {
    struct Empleado empleado;
    struct NodeEmpleado *sig_empleado;
};

// Creamos el tope en este archivo, ya que la funcion main podria no estar
// en este archivo, y seria mas normal que este lo controlase.
struct NodeEmpleado *tope;

void agregar_empleado(struct Empleado nuevo_empleado){
   
    // Reservamos memoria para un nuevo nodo tipo empleado
    struct NodeEmpleado *nodo_empleado;
    nodo_empleado = malloc(sizeof(struct NodeEmpleado));

    // Le damos los datos del nuevo empleado al nodo
    nodo_empleado->empleado = nuevo_empleado;
    
    // La primera carga de empleado, tope apunta a NULL
    // La segunda carga de empleado, tope apunta a los
    // que apuntaba nodo_empleado.
    nodo_empleado->sig_empleado = tope;
    
    // Como nodo_empleado se pierde al terminar la funcion hacemos
    // que tope apunte a lo que apunta actualmente nodo_empleado.
    tope = nodo_empleado;

}

void mostrar_empleados(){
    struct NodeEmpleado *temp_empleado = tope;

    while (temp_empleado != NULL){
        printf("Empleado: %s \n", temp_empleado->empleado.nombre);
        temp_empleado = temp_empleado->sig_empleado;
    }
}

void limpiar_empleados(){
     int x = 4; 
}


int main() {

    
    struct Empleado n_empleado = {1, "Juanjo", "Proplayer"};
    struct Empleado n1_empleado = {2, "Jaime", "Anasi"}; 

    agregar_empleado(n_empleado);
    agregar_empleado(n1_empleado);

    mostrar_empleados();

    limpiar_empleados();


    return 0;
}




#include <stdio.h>
#include <string.h>

#define TAM_CLIENTE 10

struct Cliente{ 
	int unsigned id;
	char nombre[40];
	char apellido[40];
	char email[50];
};

// Retorna el id si existe, sino devuelve -1
int buscar_cliente(struct Cliente temp_cliente, struct Cliente clientes[TAM_CLIENTE], int cant){
	int res = -1;
	for (int i = 0; i < cant; i++){
		if(strcmp(temp_cliente.email, clientes[i].email) == 0){
			res = 1;
			break;
		}
	}
	return res;
}

// Carga un cliente
void cargar_clientes(struct Cliente clientes[TAM_CLIENTE]){
	struct Cliente temp_cliente;
	int flag = 0;
	int cant_regs = 0;
	for (int i = 0; i < TAM_CLIENTE; i++){
		clientes[i].id = i;
        do {
			printf("Nombre del cliente %i: \n", i+1);
			scanf("%s", temp_cliente.nombre);
			printf("Ingrese el apellido %i: \n", i+1);
			scanf("%s", temp_cliente.apellido);
			printf("Ingrese el mail %i: \n", i+1);
			scanf("%s", temp_cliente.email);
			printf("\n");

            int incg = buscar_cliente(temp_cliente, clientes, cant_regs);
			if (incg == 1 && cant_regs != 0){
				flag = 1;
				printf("El cliente con el mail %s ya existe \n",
					temp_cliente.email
				);
                printf("Ingrese un cliente no registrado por favor \n");
			}else {
				flag = 0;
			}
		} while(flag == 1);


        // Agregamos el cliente al vector
        clientes[i] = temp_cliente;
        cant_regs++;
	}
}
    
int main(){
	struct Cliente clientes[TAM_CLIENTE];
	cargar_clientes(clientes);
	
	return 0;
}

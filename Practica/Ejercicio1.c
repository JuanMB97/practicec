#include <stdio.h>
#include <string.h>
#define TAM 2 

struct Materias {
    int cod;
    char name[4];
    int nota;
};

void imprimir(struct Materias mat[TAM]){
	
	for (int i=0; i<TAM; i++) {
        	printf("COD: %i - NAME: %s - NOTA: %i \n",
			mat[i].cod, mat[i].name, mat[i].nota
		);
    	}
}

void cargar(struct Materias mat[TAM]){

	for(int i=0; i<TAM; i++){
		printf("Ingrese el codigo: \n");
		scanf("%i", &mat[i].cod);
		// Limpiamos el buffer hasta el salto de linea
		while(getchar() != '\n');

		printf("Ingrese el nombre de la materia: \n");
		fgets(mat[i].name, sizeof(mat[i].name), stdin);
		mat[i].name[strcspn(mat[i].name, "\n")] = 0;
		printf("Ingrese la nota: \n");
		scanf("%i", &mat[i].nota);

		while(getchar() != '\n');
	}
}

int main() {

	struct Materias mat[TAM];
	cargar(mat);
	imprimir(mat);
	return 0;
}

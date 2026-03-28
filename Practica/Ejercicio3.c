#include <stdio.h>

#define TAMANIO_MUESTRA 4 

struct Tornillo {
	float longitud;
	float diametro;
};

void cargar_datos (struct Tornillo tornillos[TAMANIO_MUESTRA]) {
	for (int i=0; i<TAMANIO_MUESTRA; i++){
		printf("Ingrese la longitud del tornillo %i: \n", i + 1);
		scanf("%f", &tornillos[i].longitud);
		printf("Ingrese el diametro del tornillo %i: \n", i +1);
		scanf("%f", &tornillos[i].diametro);
	}
}

float promedio_longitud(struct Tornillo tornillos[TAMANIO_MUESTRA]) {
	float acum = 0;
	for (int i = 0; i < TAMANIO_MUESTRA; i++) {
		acum += tornillos[i].longitud;
	}
	return acum / TAMANIO_MUESTRA;
}

void promedio_diametro(struct Tornillo tornillos[TAMANIO_MUESTRA], float* prom_diam) {
	float acum = 0;
	for (int i = 0; i < TAMANIO_MUESTRA; i++) {
		acum += tornillos[i].diametro;
	}
	*prom_diam = acum / TAMANIO_MUESTRA;
}

int main(){
	struct Tornillo tornillos[TAMANIO_MUESTRA];	
	cargar_datos(tornillos);

	float prom_long = promedio_longitud(tornillos);

	printf("La longitud promedio es %f", prom_long);

	float prom_diam;

	promedio_diametro(tornillos, &prom_diam);

	printf("El diametro promedio es %f", prom_diam);

	return 0;
}

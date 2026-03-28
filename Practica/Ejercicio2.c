// Para la gestión de los libros de una pequeña biblioteca es preciso conocer su título, su
//autor, el ISBN (cadena de 17 caracteres: 978-3-16-148410-0) y si está prestado o no.
//Escribir un programa en C que:
//a) Defina una estructura denominada fichaLibro que permita almacenar los datos
//de cualquier libro
//b) Declarare e inicialice dos variables del tipo fichaLibro
//c) Compruebe si las variables declaradas representan ejemplares de un mismo libro
//o de libros distintos.
//
#include <stdio.h>
#include <string.h>


struct FichaLibro {
	char titulo[40];
	char autor[40];
	char isbn[17];
	int prestado;
};



int main() {
	
	struct FichaLibro miLibro = { "las eprer", "lsdah hon", "123123123123", 1};
	struct FichaLibro mi2libro = { "las eprer", "lsdah hon", "034534503450", 0 };

	
	printf("Libro 1 - Titulo: %s \n", miLibro.titulo);
	printf("Libro 2 - Titulo: %s \n", mi2libro.titulo);

	if (strcmp(miLibro.titulo, mi2libro.titulo) == 0 && strcmp(miLibro.autor, mi2libro.autor) == 0){
		printf("Los libros son ejemplares del mismo autor");
	}else {
		printf("Los ejemplares no son del mismo autor");
	}

	return 0;
}

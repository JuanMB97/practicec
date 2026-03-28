SEMANA 1 — Sintaxis + Modelo mental
Día 1 — Setup serio

    Instalar gcc (ya lo tenés en Linux seguramente)

    Compilar desde terminal

    Entender flags: -Wall -Wextra -std=c11

    Escribí:

    Hola mundo

    Programa con argumentos (argc, argv)

    Leer input con fgets

Día 2 — Tipos y memoria básica

    int, char, float, double

    sizeof

    Stack

    Ejercicio:
    Imprimir direcciones de memoria de variables.

    Eso empieza a abrir la cabeza.

Día 3 — Punteros (clave)

    & operador

    operador

    Puntero a int

    Puntero a puntero

    Ejercicio:
    Intercambiar dos números usando punteros.

Día 4 — Arrays y strings

    Arrays como memoria contigua

    Strings como char[]

    '\0'

    strlen manual

    Ejercicio:
    Implementar tu propia strlen.

Día 5 — Struct + memoria

    Definir struct

    Pasar struct por valor vs por puntero

    sizeof(struct)

    Ejercicio:
    Crear struct Persona y modificarlo con funciones.

Día 6 — Heap real

    malloc

    calloc

    free

    memory leak

    Ejercicio:
    Crear array dinámico en heap.

    Compilar con:

    -fsanitize=address
Día 7 — Repaso profundo

    Implementar:

    Vector dinámico simple

    Con push

    Con resize (realloc)

    Si entendés esto, entendés memoria dinámica.

⚡ SEMANA 2 — Nivel ingeniero
Día 8 — Funciones y modularización

    Archivos .h

    Separar en módulos

    static

    extern

    Ejercicio:
    Separar tu vector dinámico en módulo propio.

Día 9 — Punteros avanzados

    Puntero a función

    Array de punteros

    Double pointer

    Ejercicio:
    Tabla de funciones (mini menú dinámico).

Día 10 — Layout de memoria

    Padding

    Alineación

    offsetof

    Packing

    Esto es clave para embedded.

Día 11 — Strings más profundo

    strtok

    memcpy

    memmove

    Ejercicio:
    Pequeño parser de comandos.

Día 12 — Estructuras dinámicas

    Implementar:

    Lista enlazada

    Nodo dinámico

Día 13 — Mini proyecto

    Crear:

    Programa que lea archivo

    Parse datos

    Los almacene dinámicamente

    Los procese

Día 14 — Debugging serio

    Aprender:

    gdb básico

    breakpoints

    inspeccionar memoria

    Eso te sube de nivel mucho.
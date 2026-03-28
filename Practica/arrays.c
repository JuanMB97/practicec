#include <stdio.h>

int main() {

    int valores [5] = { 44, 20, 12, 76, 100};
    printf("%d\n", valores[2]);

    char datos[5] = {'a','g','p','b'};
    printf("%c\n", datos[2]);

    // Transformarlo a String
    char datos_string[5] = {'a','g','p','b', '\0'};
    printf("%s\n", datos_string);
    
    return 0;
}
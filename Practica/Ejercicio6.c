#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int *p;

    p = malloc(5*sizeof(int));


    for (int i = 0; i < 5; i++){
        p[i] = i;
    }
    
    for (int j = 0; j < 5; j++){
        printf("%i", p[j]);
    }
    return 0;

    free(p);
}

#include "../getnum.h"
#include <stdlib.h>
#define BLOCK 10

int pertenece(int elem, int v[], int dim) {
    for(int i = 0; i < dim; i++) {
        if(elem == v[i]) {
            return 1;
        }
    }

    return 0;
}

int * cargarNumeros(int * dim) {

    int repetido = 0;

    int * arr = NULL;
    int i;
    for(i = 0; !repetido; i++) {
        arr[i] = getint("ingrese un numero: ");
        if ( pertenece(arr[i], arr, i) ) {
            repetido = 1;
        }
        else if(i % BLOCK == 0) {
            arr = realloc(arr, (i + BLOCK) * sizeof(int));
        }

    }

    arr = realloc(arr, i * sizeof(int));

    *dim = i;

    return arr;
}
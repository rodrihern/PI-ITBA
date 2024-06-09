#include <stdio.h>
#include <assert.h>

void secuenciaAsc(const int v[], int dim, int *comienzo, int *longitud);

int main() {
    int comienzo, longitud;

    int v1[] = {1, 1, 3, 4, 4, 7, 10, 9, 11};
    int v2[] = {3};
    int v3[] = {2, 2, 2};
    int v4[] = {3, 2, 1, 0, -1};
    int v5[] = {1, 2, 3, 4, 5, 7, 10, 90, 111};

    secuenciaAsc(v1, 9, &comienzo, &longitud);
    assert(comienzo == 1);
    assert(longitud == 3);

    secuenciaAsc(v1, 0, &comienzo, &longitud);
    assert(comienzo == 0);
    assert(longitud == 0);

    secuenciaAsc(v2, 1, &comienzo, &longitud);
    assert(comienzo == 0);
    assert(longitud == 1);

    secuenciaAsc(v3, 3, &comienzo, &longitud);
    assert(comienzo == 0);
    assert(longitud == 1);

    secuenciaAsc(v4, 5, &comienzo, &longitud);
    assert(comienzo == 0);
    assert(longitud == 1);

    secuenciaAsc(v5, 9, &comienzo, &longitud);
    assert(comienzo == 0);
    assert(longitud == 9);


    printf("OK !\n");



    return 0;
}

void secuenciaAsc(const int v[], int dim, int *comienzo, int *longitud) {
    *comienzo = 0;
    if(dim == 0) {
        *longitud = 0;
        return;
    }
    *longitud = 1;
    int newLen = 1, newIndex = 0;

    
    for(int i = 0; i < dim-1; i++) {
        if(v[i] < v[i+1]) {
            newLen++;
        }
        if (v[i] >= v[i+1] || i == dim-2) {
            if(*longitud < newLen) {
                *longitud = newLen;
                *comienzo = newIndex;
            }
            newLen = 1;
            newIndex = i+1;
        }
    }
}
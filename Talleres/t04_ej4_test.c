#include <stdio.h>
#include <assert.h>
 
int interseccion(const int[], int, const int[], int, int[]);
 
int
main(void) {
    // Prueba para interseccion de desordenados
    // int a[] = {7,9,3,5,15};
    // int b[] = {5,6,7,9,8};
    // int ayb[5];
    // int aybDim = interseccion(a, 5, b, 5, ayb);
    // assert(aybDim == 3);
    // for(int i = 0; i < aybDim; i++) { // Debería obtenerse 5, 7 y 9 en cualquier orden
    //     printf("%d ", ayb[i]);
    // }
 
    // Prueba para interseccion de ordenados (y también desordenados)
    int c[] = {3,5,7,9,15};
    int d[] = {5,6,7,8,9};
    int cyd[5];
    int cybDim = interseccion(c, 5, d, 5, cyd);
    assert(cybDim == 3);
    assert(cyd[0] == 5);
    assert(cyd[1] == 7);
    assert(cyd[2] == 9);
 
    printf("\nOK!");
    return 0;
}
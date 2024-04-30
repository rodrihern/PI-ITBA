#include "../rand.h"

/*
Dado un arreglo ordenado ascendentemente se pide escribir una función que reciba como parámetro de entrada/salida
el arreglo y como parámetro de entrada su dimensión y que lo devuelva desordenado, simulando la mezcla de un mazo
de cartas o de un bolillero (en no más de 10 líneas).
*/

void shuffle(int arr[], unsigned int dim) {
    int randIndex, aux;
    for(int i = 0; i < dim; i++) {
        randIndex = randInt(0, dim-1);
        aux = arr[i];
        arr[i] = arr[randIndex];
        arr[randIndex] = aux;
    }
}


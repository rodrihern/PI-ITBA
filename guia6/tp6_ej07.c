#include <stdio.h>

/*
Hacer una función que reciba dos parámetros de entrada representando arreglos de números enteros positivos, 
ordenados en forma ascendente y sin elementos repetidos. El último elemento de cada arreglo es -1. 
La función debe devolver en un tercer parámetro de salida un arreglo ordenado con la unión de los dos primeros,
también terminado en -1.
*/  

void unirArreglos (const int ar1[], const int ar2[], int out[]) {
    int j = 0, outIndex = 0;
    for (int i = 0; ar1[i] != -1; i++) {
        for(; ar2[j] <= ar1[i] && ar2[j] != -1; j++) {
            if(ar2[j] != ar1[i]) {
                out[outIndex++] = ar2[j];
            }
        }
        out[outIndex++] = ar1[i];
    }
    for(int i = j; ar2[i] != -1; i++) {
        out[outIndex++] = ar2[i];
    }
    out[outIndex] = -1;
}
#include <stdio.h>
/*
    ver la respuesta de la catedra en el campus
*/
int interseccion(int arr1[], int dim1, int arr2[], int dim2, int out[]) {
    int index = 0, prev = 0;

    for (int i = 0; i < dim1; i++) {
        for(int j = prev; j < dim2 &&  arr2[j] <= arr1[i]; j++) {
            if(arr1[i] == arr2[j]) {
                out[index++] = arr1[i];
                prev = j;
            }
        }
    }

    return index;
}

// PARA ARREGLOS NO ORDENADOS
/*
int interseccion(int arr1[], int dim1, int arr2[], int dim2, int out[]) {
    int index = 0;
    for (int i = 0; i < dim1; i++) {
        for(int j = 0; j < dim2; j++) {
            if(arr1[i] == arr2[j]) {
                out[index++] = arr1[i];
            }
        }
    }

    return index;
}
*/
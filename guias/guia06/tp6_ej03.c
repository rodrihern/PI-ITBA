#include <math.h>
#include <stdio.h>
/*
Dado un arreglo lineal de números reales, cuyo indicador de fin de elementos es cero, 
escribir una función para obtener la mayor diferencia entre dos elementos consecutivos. 
(En no más de 5 líneas). Tener en cuenta que los números pueden ser negativos. 
En caso de que el vector tenga un solo elemento deberá retornar como diferencia el valor cero.
*/

double maxDiferencia(const double arr[]) {
    double dif = 0;
    for(int i = 0; arr[i] != 0; i++) {
        if(arr[i+1] != 0 && fabs(arr[i]-arr[i+1]) > dif) {
            dif = fabs(arr[i] - arr[i+1]);
        }
    }
    return dif;
}



#include <stdio.h>
#define FIN -1

/*
Repetir el ejercicio anterior, teniendo en cuenta que los arreglos de entrada pueden tener elementos repetidos, 
pero el de salida NO debe tener repeticiones. 
*/

void unirArreglos ( const int ar1[], const int ar2[], int out[]) {
    int j = 0, outIndex = 0, last = FIN; //  Para que sea distinto al primer elemento de los arrays no vacios
    
    for (int i = 0; ar1[i] != FIN; i++) {
        while(ar2[j] < ar1[i] && ar2[j] != FIN) {
            if(ar2[j] != last) {
                out[outIndex++] = ar2[j];
                last = out[outIndex-1];
            }
            j++;
        }
        if(ar1[i] != last) {
            out[outIndex++] = ar1[i];
            last = out[outIndex-1];
        }
    }

    for(int i = j; ar2[i] != -1; i++) {
        if(ar2[i] != last) {
            last = out[outIndex];
            out[outIndex++] = ar2[i];
        }
    }

    out[outIndex] = -1;
}

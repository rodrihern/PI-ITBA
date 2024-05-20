

/*
Escribir una función que reciba un vector desordenado de números enteros y su dimensión,
y construya otro vector eliminando los valores repetidos. 
La función deberá retornar en su nombre la dimensión del nuevo vector (La función solicitada  no debe superar las 10 líneas).
*/

int isRepeted(const int arr[], int elem, int dim) {
    for(int i = 0; i < dim; i++) {
        if(arr[i] == elem) {
            return 1;
        }
    }
    return 0;
}

int eliminaRepetidos( const int arr[], int dim, int out[]) {
    int dimOut = 0;
    
    for(int i = 0; i < dim; i++) {
        if(!isRepeted(out, arr[i], dimOut)) {
            out[dimOut++] = arr[i];
        }
    }

    return dimOut;
}


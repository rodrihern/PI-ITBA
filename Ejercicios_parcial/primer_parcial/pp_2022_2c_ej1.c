#include <assert.h>
#include <stdio.h>
#define N 4

/*
Cada fila tiene que tener estos elementos no repetidos
1 --> N
N+1 --> 2N
2N+1 --> 3N
...
(N-1)N + 1 --> N*N

Generico
i*N + 1 --> (i+1) * N
*/

int pretenece(int elem, const int arr[], int dim);
int filaOk(const int v[], int min, int max);
int esMatrizLinda(const int m[][N]);

int main() {
    const int mat1[N][N] = {
        {3, 4, 1, 2},
        {8, 7, 6, 5},
        {9, 10, 11, 12},
        {15, 16, 13, 14},
    };

    const int mat2[N][N] = {
        {3, 1, 1, 2},
        {8, 7, 6, 5},
        {9, 10, 11, 12},
        {15, 16, 13, 14},
    };

    assert(esMatrizLinda(mat1) == 1);
    assert(esMatrizLinda(mat2) == 0);

    puts("OK !");

    
}

// devuelve true si el elemento elem esta en el array arr
int pretenece(int elem, const int arr[], int dim) {
    for(int i = 0; i < dim; i++) {
        if(arr[i] == elem) {
            return 1;
        }
    }

    return 0;
}

// recibe una fila, el minimo, el maximo, y devuelve true si los numeros estan en [min, max] sin repeticiones
int filaOk(const int v[], int min, int max) {
    int anteriores[N];
    int esValida = 1;
    for(int i = 0; i < N && esValida; i++) {
        if(v[i] < min || max < v[i] || pretenece(v[i], anteriores, i)) {
            esValida = 0;
        }
        anteriores[i] = v[i];
    }

    return esValida;
}



// la matriz es linda cuando tiene todos los numeros de 1 a N*N
// y en cada fila contiene numeros consecutivos (no necesariamente ordenados)
int esMatrizLinda(const int m[][N]) {
    int esLinda = 1;
    for(int i = 0; i < N && esLinda; i++) {
        int min = i*N + 1;
        int max = (i+1) * N;
        if( !filaOk(m[i], min, max) ) {
            esLinda = 0;
        }
    }

    return esLinda;
}
#include <stdio.h>
#include <assert.h>
#define M 6

int sumaFila(const int fila[], int dim, int borde);
int sumaColumna(const int m[][M], int col, int rows, int borde);
void bordes(const int mat[][M], int sumas[]);



int main() {

    int matriz[][M] = {
        {1, 1, 1, 1, 1, 1},
        {1, 2, 2, 2, 2, 1},
        {1, 2, 3, 3, 2, 1},
        {1, 2, 3, 3, 2, 1},
        {1, 2, 2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1},
    };

    int vec[3];

    bordes(matriz, vec);

    assert(vec[0] == 20);
    assert(vec[1] == 24);
    assert(vec[2] == 12);


    printf("OK !\n");
    return 0;
}

// suma todos los elementos de la fila
int sumaFila(const int fila[], int dim, int borde) {
    int sum = 0;
    for(int i = borde; i < dim-borde; i++) {
        sum += fila[i];
    }

    return sum;
}

// suma la columna sin tener en cuenta ni el primer ni el ultimo elemento de la columna
int sumaColumna(const int m[][M], int col, int rows, int borde) {
    int sum = 0;
    for(int i = 1+borde; i < rows-1-borde; i++) {
        sum += m[i][col];
    }

    return sum;
}

void bordes(const int mat[][M], int sumas[]) {
    
    for(int i = 0; i < M/2; i++) {
        int sum = 0;

        sum += sumaFila(mat[i], M, i); // primera fila del borde i
        sum += sumaFila(mat[M-1 - i], M, i); // ultima fila del borde i
        sum += sumaColumna(mat, i, M, i); // primera columna del borde i
        sum += sumaColumna(mat, M-1 - i, M, i); // ultima columna del borde i

        sumas[i] = sum;
    }
}


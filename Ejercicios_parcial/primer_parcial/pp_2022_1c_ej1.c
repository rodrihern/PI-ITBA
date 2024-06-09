#include <stdio.h>
#define FILS 6
#define COLS 5
#define FIN -1

void difSim(const int m1[][COLS], const int m2[][COLS], int m3[][COLS], int filas);
void difSimFila(const int v1[], const int v2[], int v3[]);

int main() {
    int mat1[FILS][COLS] = {
        {1, 2, 3, 4, -1},
        {3, 4, 5, -1, 0},
        {10, 15, 20, -1, 0},
        {-1, 0, 0, 0, 0},
        {-1, 0, 0, 0, 0},
        {5, 6, 7, -1, 0}
    };

    int mat2[FILS][COLS] = {
        {3, 4, 5, 6, -1},
        {3, 4, 5, -1, 0},
        {10, 20, -1, 0, 0},
        {1, 2, 3, 4, -1},
        {-1, 0, 0, 0, 0},
        {1, 2, 7, -1, 0}
    };

    int mat3[FILS][COLS];

    difSim(mat1, mat2, mat3, FILS);

    for(int i = 0; i < FILS; i++) {
        putchar('\n');
        for(int j = 0; mat3[i][j] != FIN; j++) {
            printf("%d\t", mat3[i][j]);
        }
    }



    return 0;
}

void difSimFila(const int v1[], const int v2[], int v3[]) {
    int i = 0, j = 0, k = 0;

    while(v1[i] != FIN && v2[j] != FIN) {
        // se que un elemento no esta en el otro cuando el otro es mayor
        if (v1[i] == v2[j]) {
            i++;
            j++;
        }
        else if (v1[i] < v2[j]) {
            v3[k++] = v1[i++];
        }
        else { // v2[j] < v1[i]
            v3[k++] = v2[j++];
        }
    }

    while (v1[i] != FIN) {
        v3[k++] = v1[i++];
    }
    while (v2[j] != FIN) {
        v3[k++] = v2[j++];
    }
    
    v3[k] = FIN;

}

void difSim(const int m1[][COLS], const int m2[][COLS], int m3[][COLS], int filas) {
    for(int i = 0; i < filas; i++) {
        difSimFila(m1[i], m2[i], m3[i]);
    }
}
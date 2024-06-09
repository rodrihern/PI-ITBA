#include <stdio.h>
#define COLS 6
#define ROWS 4

int eliminaCapicua(char m[][COLS], int rows);
int esCapicua(const char v[], int dim);

int main() {

    char matriz[ROWS][COLS] = {
        {'L', '#', 'B', 'B', '#', 'L'},
        {'3', '1', 'r', 'R', '1', '3'},
        {'3', '2', 'S', 'S', '2', '3'},
        {'H', 'O', 'L', 'A', '2', '3'},
    };

    int newDim = eliminaCapicua(matriz, ROWS);

    for(int i = 0; i < newDim; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", matriz[i][j]);
        }
        putchar('\n');
    }


    return 0;
}



int esCapicua(const char v[], int dim) {
    int sonIguales = 1;
    for(int i = 0; i < dim/2 && sonIguales; i++) {
        if(v[i] != v[dim-1 - i]) {
            sonIguales = 0;
        }
    }

    return sonIguales;
}

int eliminaCapicua(char m[][COLS], int rows) {
    int dimResp = 0;
   
    for(int i = 0; i < rows; i++) {
        if( ! esCapicua(m[i], COLS) ) {
            for(int j = 0; j < COLS; j++) {
                m[dimResp][j] = m[i][j];
            }
            dimResp++;
        }
    }

    return dimResp;
}
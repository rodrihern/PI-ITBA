#include <stdio.h>
#define COLUMNAS 30


/*
(i-1)(j-1)      (i-1)j     (i-1)(j+1)  
    i(j-1)          ij         i(j+1)
(i+1)(j-1)      (i+1)j     (i-1)(j+1)
*/

int hayEstrella(const int sky[][COLUMNAS], int i, int j) {
    int sum = 0;

    for(int row = i - 1; row <= i + 1; row++) {
        for(int col = j - 1; col <= j + 1; col++) {
            sum += sky[row][col];
        }
    }
    return (sum / 9 > 10);
}

void graficar (const int sky[][COLUMNAS], int rows, int cols) {
    
    for(int i = 1; i < rows-1; i++) {

        for(int j = 1; j < cols-1; j++) {

            if (hayEstrella(sky, i, j)) {
                putchar('*');
            } 
            else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

}
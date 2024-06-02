#ifndef _SUDOKU_H
#define _SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

typedef int tSudoku[9][9];

/*   * BACKEND *   */

// copia en dest el sudoku source
void cpySudoku(tSudoku dest, tSudoku source);

// devuelve 1 si la solucion es valida, 0 si no
int checkSolution(tSudoku sud);

// devuelve 1 si el source es correcto, 0 si no
// y deja en missing[0] cuantos espacios en blanco hay
// deja en missing[i] cuantos faltan del digito i
int checkSource(tSudoku sud, int missing[]);

// se fija si hay repetidos en la direccion dir desde la posicion [i][j]
// permite que hayan espacios sin completar
// devuelve 1 si es valida, 0 si no.
int checkDir(tSudoku sud, int i, int j, int dir[], int emptySpacesAllowed);

// se fija que esten todos los numeros del 1 al 9 en un cuadrado de 3x3 con esquina superior izquierda [i][j]
// si es valido devuelve 1, sino 0
int check3x3(tSudoku sud, int i, int j, int emptySpacesAllowed);

// llena los espacios vacios del sukoku con los elementos del vector
void fillSudoku(tSudoku sud ,int v[], int dim);


// devuelve 1 y deja en ans una solucion al sudoku, devuelve 0 si no hay soulucion
int solveSudoku(tSudoku source, tSudoku ans);



/*   * FRONTEND *   */

// imprime en salida estandar el sudoku
void printSudoku(tSudoku sud);

// recibe por entrada estandar el sudoku y lo deja en sud
// lee exactamente 81 digitos ignorando cualquier caracter que no sea un digito
void getSudoku(tSudoku * sud);

#endif
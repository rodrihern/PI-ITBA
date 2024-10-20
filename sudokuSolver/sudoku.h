#ifndef _SUDOKU_H
#define _SUDOKU_H
#define SIZE 9
#include <stdio.h>
#include <stdlib.h>


typedef int tSudoku[9][9];

/*   * BACKEND *   */


// devuelve 1 si la solucion es valida, 0 si no
int checkSolution(tSudoku sud);

// devuelve 1 si el source es correcto, 0 si no
// y deja en missing[0] cuantos espacios en blanco hay
// deja en missing[i] cuantos faltan del digito i
int isValidNumInSquare(tSudoku sud, int num, int row, int col);

// devuelve 1 si el numero esta en la direccion dir desde [row][col]
int numInDir(tSudoku sud, int num, int row, int col, int dir[]);

// devuelve 1 si el numero esta en el box
int numInBox(tSudoku sud, int num, int row, int col);


// devuelve 1 si lo resuelve, devuelve 0 si no
int solveSudoku(tSudoku sud);



/*   * FRONTEND *   */

// imprime en salida estandar el sudoku
void printSudoku(tSudoku sud);

// recibe por entrada estandar el sudoku y lo deja en sud
// lee exactamente 81 digitos ignorando cualquier caracter que no sea un digito
void getSudoku(tSudoku * sud);

#endif
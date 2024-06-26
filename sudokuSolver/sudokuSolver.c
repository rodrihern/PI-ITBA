#include <stdio.h>
#include "sudoku.h"
#include <assert.h>

/*
        * DISCLAIMER *

    NO ES EFICIENTE PARA NADA
    LO HICE PARA PRACTICAR RECURSIVIDAD Y PORQUE TENIA GANAS
    CUANDO APRENDA BACKTRACKING LO MEJORARE

*/

/*

    SUDOKUS YA HECHOS PARA PROBAR:

    {3,8,1,9,7,6,5,4,2}, 
    {2,4,7,5,3,8,1,9,6},
    {5,6,9,2,1,4,8,7,3},
    {6,7,4,8,5,2,3,1,9},
    {1,3,5,7,4,9,6,2,8},
    {9,2,8,1,6,3,7,5,4},
    {4,1,2,6,8,5,9,3,7},
    {7,9,6,3,2,1,4,8,5},
    {8,5,3,4,9,7,2,6,1}


    {5,3,4,6,7,8,9,1,2}, 
    {6,7,2,1,9,5,3,4,8}, 
    {1,9,8,3,4,2,5,6,7}, 
    {8,5,9,7,6,1,4,2,3}, 
    {4,2,6,8,5,3,7,9,1}, 
    {7,1,3,9,2,4,8,5,6}, 
    {9,6,1,5,3,7,2,8,4}, 
    {2,8,7,4,1,9,6,3,5}, 
    {3,4,5,2,8,6,1,7,9} 

*/

int main(void) {
    // sudoku de respuesta
    tSudoku solution;

    tSudoku sudoku = {
        {3,8,1,9,7,6,5,4,2}, 
        {2,4,7,0,3,8,1,0,6},
        {5,0,9,2,1,0,8,7,3},
        {6,7,4,8,5,2,3,0,9},
        {1,3,5,7,0,9,6,2,8},
        {9,0,8,1,6,3,7,5,4},
        {0,1,0,6,8,5,9,0,7},
        {7,0,6,3,0,1,4,8,5},
        {8,5,3,4,9,0,2,6,1}

    };

    puts("sudoku a resolver:");
    printSudoku(sudoku);
    if(solveSudoku(sudoku, solution)) {
        puts("resuelto: ");
        printSudoku(solution);
        puts("\nLEGENDARY !");
    }
    else {
        puts("\nNo hay solucion :(");
    }

  return 0;
}







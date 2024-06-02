#include <stdio.h>
#include "sudoku.h"
#include <assert.h>

/*
    TODO:
        
        * HACER LAS FUNCIONES AUXILIARES DE BACK
        * HACER LA WRAPPER
        * VER QUE FUCNIONE CON UN MAIN ASI NOMAS
        * AGREGAR FUNCIONES DE FRONT
        * HACER UN MAIN DEFINITIVO

*/

int main(void) {
    // Una matriz vacía no es solución
    tSudoku sudoku1;

    //faltan 11
    tSudoku sudoku2 = {
        {3,0,1,9,7,6,5,4,2}, 
        {2,4,0,5,0,8,0,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,0,5,7,4,9,0,2,8},
        {9,2,0,1,6,3,7,5,4},
        {4,1,2,6,8,5,0,3,7},
        {7,9,6,3,0,1,0,8,5},
        {0,5,3,4,9,7,2,6,1}
    };
    /*
        SOLUCION:

        {3,8,1,9,7,6,5,4,2}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}

    */


    /*

    tSudoku sudoku3 = {
        {5,3,4,6,7,8,9,1,2}, 
        {6,7,2,1,9,5,3,4,8}, 
        {1,9,8,3,4,2,5,6,7}, 
        {8,5,9,7,6,1,4,2,3}, 
        {4,2,6,8,5,3,7,9,1}, 
        {7,1,3,9,2,4,8,5,6}, 
        {9,6,1,5,3,7,2,8,4}, 
        {2,8,7,4,1,9,6,3,5}, 
        {3,4,5,2,8,6,1,7,9} 
    };

        SOLUCION:

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

    
    puts("sudoku a resolver:");
    printSudoku(sudoku2);
    solveSudoku(sudoku2, sudoku1);
    puts("resuelto: ");
    printSudoku(sudoku1);
    

    
   
    puts("\nOK !");

  return 0;
}







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

int main() {

    tSudoku sud = {
    //   0  1  2  3  4  5  6  7  8 
        {1, 2, 3, 1, 1, 1, 1, 1, 1}, // 0
        {4, 5, 6, 1, 1, 1, 1, 1, 1}, // 1
        {7, 8, 9, 1, 1, 1, 1, 1, 1}, // 2
        {1, 1, 1, 1, 1, 1, 1, 1, 1}, // 3
        {1, 1, 1, 1, 1, 1, 1, 1, 1}, // 4
        {1, 1, 1, 1, 1, 1, 1, 1, 1}, // 5
        {1, 2, 3, 1, 1, 1, 0, 0, 0}, // 6
        {0, 0, 0, 1, 1, 1, 0, 0, 0}, // 7
        {4, 5, 6, 1, 1, 1, 0, 0, 0}  // 8
        
    };
    
    puts("\n");
    assert( check3x3(sud, 0, 0, 0) );
    assert( check3x3(sud, 0, 0, 1) );

    assert( !check3x3(sud, 1, 1, 0) );
    assert( !check3x3(sud, 1, 1, 1) );

    assert( check3x3(sud, 6, 0, 1) );
    assert( !check3x3(sud, 6, 0, 0) );

    assert( !check3x3(sud, 6, 6, 0) );
    assert( check3x3(sud, 6, 6, 1) );

    assert( !check3x3(sud, 7, 6, 1) ); // fuera de los limites
    assert( !check3x3(sud, 6, 7, 1) ); // fuera de los limites

    
    
    puts("\nOK !");
    return 0;
}







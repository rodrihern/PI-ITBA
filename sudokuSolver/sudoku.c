#include "sudoku.h"
#define LIMIT 9

#define SWAP(x, y) aux = x; x = y; y = aux;
#define VALID(x) (1 <= (x) && (x) <= 9)

int checkSolution(tSudoku sud) {
    return 0;
}

int checkSource(tSudoku sud, int missing[]);

int checkDir(tSudoku sud, int i, int j, int dir[], int emptySpacesAllowed) {
    int inc_i = dir[0], inc_j = dir[1], ok = 1;
    char repeated[9] = {0};
    
    while(0 <= i && i < LIMIT && 0 <= j && j < LIMIT && ok) {
        if( ( VALID(sud[i][j]) && !repeated[sud[i][j]-1] )) {
            repeated[sud[i][j]-1] = 1;   
        }
        else if ( !(sud[i][j] == 0 && emptySpacesAllowed) ) {
            // si es 0 y se permiten espacios vacios esta ok entonces no entro aca
            ok = 0;
        }
        i += inc_i;
        j += inc_j;
        
    }

    return ok;
}

int check3x3(tSudoku sud, int i_inicial, int j_inicial, int emptySpacesAllowed) {
    int ok = 1;
    char repeated[9] = {0};
    if(i_inicial+3 > LIMIT || j_inicial+3 > LIMIT) { 
        // no es una esquina superior izquierda valida
        //puts("los limites estaban mal");
        return 0;
    }
    if(emptySpacesAllowed) {
        //puts("se permiten 0");
    }

    for(int i = i_inicial; i < i_inicial+3 && ok; i++) {

        for(int j = j_inicial; j < j_inicial+3 && ok; j++) {
            //printf("sud[%d][%d]: %d\n",i, j, sud[i][j]);

            if( ( VALID(sud[i][j]) && !repeated[sud[i][j]-1] )) {
                repeated[sud[i][j]-1] = 1;   
            }
            else if ( !(sud[i][j] == 0 && emptySpacesAllowed) ) {
                // si es 0 y se permiten espacios vacios esta ok entonces no entro aca
                //printf("entre aca porque sud[i][j] era: %d\n", sud[i][j]);
                ok = 0;
            }
        }
    }

    return ok;
}

void fillSudoku(tSudoku sud ,int v[], int dim) {
    int k = 0;
    for(int i = 0; i < LIMIT && k < dim; i++) {
        for(int j = 0; j < LIMIT && k < dim; j++) {
            if(sud[i][j] == 0) {
                sud[i][j] = v[k++];
            }
        } 
    }
}


static void solveSudokuRec(tSudoku source, tSudoku ans, int v[], int cidx, int dim, int * solved) {
    int aux;
    if(cidx == dim-1) {
        fillSudoku(ans, v, dim);
        if(checkSolution(ans)) {
            *solved = 1;
        }
        return;
    }

    for(int i = cidx; i < dim && !(*solved); i++) {
        SWAP(v[i], v[cidx]);
        solveSudokuRec(source, ans, v, cidx+1, dim, solved);
        SWAP(v[i], v[cidx]);
    }
}

int solveSudoku(tSudoku source, tSudoku ans) {
    return 1;
}




// imprime en salida estandar el sudoku
void printSudoku(tSudoku sud) {
    for(int i = 0; i < LIMIT; i++) {
        for(int j = 0; j < LIMIT; j++) {
            if(sud[i][j]) {
                printf("%d ", sud[i][j]);
            }
            else {
                printf(". ");
            }
        }
        putchar('\n');
    }
}

// recibe por entrada estandar el sudoku y lo deja en sud
void getSudoku(tSudoku * sud);
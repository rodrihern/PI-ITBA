#include "sudoku.h"
#define LIMIT 9

#define SWAP(x, y) aux = x; x = y; y = aux;
#define VALID(x) (1 <= (x) && (x) <= 9)

void cpySudoku(tSudoku dest, tSudoku source) {
    for(int i = 0; i < LIMIT; i++) {
        for(int j = 0; j < LIMIT; j++) {
            dest[i][j] = source[i][j];
        }
    }
}

int checkSolution(tSudoku sud) {
    int dir[2][2] = {
        {1, 0}, // hacia abajo
        {0, 1}, // hacia la derecha
    };
    int ok = 1;
    for(int i = 0; i < LIMIT && ok; i++) {
        ok = checkDir(sud, i, 0, dir[1], 0);
    }
    for(int j = 0; j < LIMIT && ok; j++) {
        ok = checkDir(sud, 0, j, dir[0], 0);
    }
    for(int i = 0; i < LIMIT; i += 3) {
        for(int j = 0; j < LIMIT && ok; j += 3) {
            ok = check3x3(sud, i, j, 0);
        }
    }

    return ok;
}

int checkSource(tSudoku sud, int missing[]) {
    
    int ok = 1;
    missing[0] = 0;
    for(int i = 1; i <= LIMIT; i++) {
        missing[i] = LIMIT;
    }
    
    // la primera vez que ciclo lleno el missing y valido a mano para evitar ciclar una vez de mas
    for(int i = 0; i < LIMIT && ok; i++) {
        char repeated[LIMIT] = {0};
        for(int j = 0; j < LIMIT && ok; j++) {
            if(VALID(sud[i][j]) && !repeated[sud[i][j]-1]) {
                missing[sud[i][j]]--;
                repeated[sud[i][j]-1] = 1;
            }
            else if(sud[i][j] == 0) {
                missing[0]++;
            }
            else {
                ok = 0;
            }
        }
    }

    //valido las columnas y el 3x3
    int dir[] = {1, 0};
    for(int j = 0; j < LIMIT && ok; j++) {
        ok = checkDir(sud, 0, j, dir, 1);
    }
    for(int i = 0; i < LIMIT; i += 3) {
        for(int j = 0; j < LIMIT && ok; j += 3) {
            ok = check3x3(sud, i, j, 1);
        }
    }
    
    return ok;
}

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
        else {
            cpySudoku(ans, source);
        }
        return;
    }
    char alreadyFixed[LIMIT] = {0};
    for(int i = cidx; i < dim && !(*solved); i++) {
        if(!alreadyFixed[v[i]-1]) {
            SWAP(v[i], v[cidx]);
            solveSudokuRec(source, ans, v, cidx+1, dim, solved);
            SWAP(v[i], v[cidx]);
            alreadyFixed[v[i]-1] = 1;

        }
        
    }
}

int solveSudoku(tSudoku source, tSudoku ans) {
    int missing[10];
    if(!checkSource(source, missing)) {
        return 0;
    }
    int solved = 0;
    int * vec = malloc(missing[0] * sizeof(vec[0]));
    // ahora tengo que llenar el vec
    int k = 0;
    for(int i = 1; i <= LIMIT; i++) {
        for(int j = 0; j < missing[i]; j++) {
            vec[k++] = i;
        }
    }
    cpySudoku(ans, source);
    puts("\nwait for it...\n");
    solveSudokuRec(source, ans, vec, 0, k, &solved);
    free(vec);
    
    return solved;
}




// imprime en salida estandar el sudoku
void printSudoku(tSudoku sud) {
    for(int i = 0; i < LIMIT; i++) {
        if(i % 3 == 0) {
            puts(" -----------------------");
        }
        for(int j = 0; j < LIMIT; j++) {
            if(j % 3 == 0) {
                printf("| ");
            }
            if(sud[i][j]) {
                printf("%d ", sud[i][j]);
            }
            else {
                printf("  ");
            }
        }
        puts("|");

    }
    puts(" -----------------------");



}

// recibe por entrada estandar el sudoku y lo deja en sud
void getSudoku(tSudoku * sud) {
    char c;
    for(int i = 0; i < LIMIT; i++) {
        for(int j = 0; j < LIMIT; j++) {
            while((c=getchar()) < '0' || '9' < c)
                ;
            *sud[i][j] = c - '0';
        }
    }
}
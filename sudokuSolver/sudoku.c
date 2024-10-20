#include "sudoku.h"

// imprime en salida estandar el sudoku
void printSudoku(tSudoku sud) {
    for(int i = 0; i < SIZE; i++) {
        if(i % 3 == 0) {
            puts(" -----------------------");
        }
        for(int j = 0; j < SIZE; j++) {
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
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            while((c=getchar()) < '0' || '9' < c)
                ;
            *sud[i][j] = c - '0';
        }
    }
}

int numInDir(tSudoku sud, int num, int row, int col, int dir[]) {
    int i = row;
    int j = col;
    while(0 <= i && i < SIZE && 0 <= j && j < SIZE) {
        if(sud[i][j] == num) {
            return 1;
        }
        i += dir[0];
        j += dir[1];
    }
    return 0;
}

int numInBox(tSudoku sud, int num, int row, int col) {
    int firstRow = (row/3) * 3;
    int firstCol = (col/3) * 3;
    for(int i = firstRow; i < firstRow+3; i++) {
        for(int j = firstCol; j < firstCol+3; j++) {
            if(sud[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

int isValidNumInSquare(tSudoku sud, int num, int row, int col) {
    int directions[][2] = {
        {0, 1},
        {1, 0}
    };

    return !numInBox(sud, num, row, col) 
        && !numInDir(sud, num, row, 0, directions[0]) // checking the row
        && !numInDir(sud, num, 0, col, directions[1]); // checking the col
}


static int solveRec(tSudoku sud, int fromRow, int fromCol) {
    for(int i = fromRow; i < SIZE; i++) {
        for(int j = (i == fromRow) ? fromCol : 0; j < SIZE; j++) {
            if(sud[i][j] == 0) {
                for(int toTry = 1; toTry <= SIZE; toTry++) {
                    if(isValidNumInSquare(sud, toTry, i, j)) {
                        sud[i][j] = toTry;
                        if(solveRec(sud, i, j)) {
                            return 1;
                        } else {
                            sud[i][j] = 0;
                        }
                        
                    }
                }
                return 0;
            }
            
        }
    }
    return 1;
}

static int isRepeated(int num, int app[]) {
    if(num < 0 || num > SIZE || (num > 0 && app[num-1])) {
        return 1;
    }
    if(num != 0) {
        app[num-1] = 1;
    }
    return 0;
}

static int isValidDir(tSudoku board, int fromRow, int fromCol, int dir[]) {
    int i = fromRow;
    int j = fromCol;
    int apps[SIZE] = {0};
    while(0 <= i && i < SIZE && 0 <= j && j < SIZE) {
        if(isRepeated(board[i][j], apps)) {
            return 0;
        }
        i += dir[0];
        j += dir[1];
    }
    return 1;
}

static int isValidRow(tSudoku board, int row) {
    int dir[] = {0, 1};
    return isValidDir(board, row, 0, dir);
}

static int isValidCol(tSudoku board, int col) {
    int dir[] = {1, 0};
    return isValidDir(board, 0, col, dir);
}

static int isValidBox(tSudoku board, int row, int col) {
    int apps[9] = {0};
    for(int i = row; i < row+3; i++) {
        for(int j = col; j < col+3; j++) {
            if(isRepeated(board[i][j], apps)) {
                return 0;
            }
        }
    }
    return 1;
}

static int isValidBoard(tSudoku board) {
    // checking rows and cols
    for(int i = 0; i < SIZE; i++) {
        if(!isValidRow(board, i) || !isValidCol(board, i)) {
            printf("failed i = %d\n", i);
            return 0;
        }
    }
    // checking box
    for(int i = 0; i < SIZE; i += 3) {
        for(int j = 0; j < SIZE; j += 3) {
            if(!isValidBox(board, i, j)) {
                return 0;
            }
        }
    }
    return 1;
    
}

int solveSudoku(tSudoku sud) {
    
    if(!isValidBoard(sud)) {
        printf("invalid board");
        return 0;
    }
    
    return solveRec(sud, 0, 0);
}


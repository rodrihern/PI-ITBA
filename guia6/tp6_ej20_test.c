#include <stdio.h>
#include <assert.h>

#define DIM 9

int sudokuSolver(const char m[][DIM]);
int pertenece(int elem, const char v[], int dim);
int checkRow(const char v[]);
int checkCol(const char m[][DIM], int col);
int check3x3(const char m[][DIM], int row, int col);

int main(void) {
  // Una matriz vacía no es solución
  char sudoku[DIM][DIM] = {{0}};

  assert(sudokuSolver(sudoku)==0);

  char sudoku2[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,2}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku2)==1);
  
  char sudoku3[DIM][DIM] = {
        {2,8,1,9,7,6,5,4,2}, 
        {3,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku3)==0);
  
  // Cuando se tomó este ejercicio en un parcial, en una de las respuestas
  // sólo chequeaban que la suma de cada fila, columna y cuadrado fuera 45
  char sudoku4[DIM][DIM] = {
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}
  };

  assert(sudokuSolver(sudoku4)==0);

  char sudoku5[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,12}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku5)==0);

  printf("OK !\n");

  return 0;
}

// funcion que se fija si un elem esta en el vector v
int pertenece(int elem, const char v[], int dim) {
      int foundIt = 0;

      for (int i = 0; i < dim && !foundIt; i++) {
            if(elem == v[i]) {
                  foundIt = 1;
            }
      }

      return foundIt;
}

// devuelve true si la fila es valida
int checkRow(const char v[]) {
      char prev[DIM];

      for(int i = 0; i < DIM; i++) {
            if(v[i] < 1 || v[i] > 9 || pertenece(v[i], prev, i)) {
            // si se cumple alguna de estas condiciones, la fila no es valida
                  return 0;
            }
      
            prev[i] = v[i];
            
      } 

      // si llego aca es porque la fila es valida
      return 1;

}

// devuele true si la columna col es valida
int checkCol(const char m[][DIM], int col ) {
      char prev[DIM];

      for(int i = 0; i < DIM; i++) {
            if(m[i][col] < 1 || m[i][col] > 9 || pertenece(m[i][col], prev, i)) {
                  return 0;
            }
            prev[i] = m[i][col];
      }

      return 1;

}

// devuelve true si el cuadrante de 3x3 con esquina superior izq m[row][col] es valido
int check3x3(const char m[][DIM], int row, int col) {
      char prev[DIM];
      int dimPrev = 0;

      for(int i = row; i < row+3; i++) {
            for(int j = col; j < col+3; j++) {
                  if(m[i][j] < 1 || m[i][j] > 9 || pertenece(m[i][j], prev, dimPrev)) {
                        return 0;
                  }

                  prev[dimPrev++] = m[i][j];
            }
      }

      return 1;


}


int sudokuSolver(const char m[][DIM]) {
      //las funciones ya validan que los numeros esten entre 0 y 9.
      // un ciclo para cada funcion que adentro ciclaran ellos.

      // me fijo que para toda fila chequee que todos los numeros esten entre 1 y 9 y sean distintos
      for(int i = 0; i < DIM; i++) {
            if(!checkRow(m[i])) {
                  return 0;
            }
      }

      // me fijo lo mismo pero para las columnas
      for(int j = 0; j < DIM; j++) {
            if(!checkCol(m, j)) {
                  return 0;
            }
      }

      // me fijo lo mismo para los subcuadrados de 3x3
      for(int i = 0; i < DIM; i += 3) {
            for(int j = 0; j < DIM; j += 3) {
                  if(!check3x3(m, i, j)) {
                        return 0;
                  }
            }
      }

      // si llega aca es que paso todos los controles
      return 1;


      
}

/*
00 01 02 03 04 05 06 07 08 
01
02
03




*/
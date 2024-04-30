#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#define COLS 4

int checkLadder(const char v1[], const char v2[], int dim, int lastChange);
int isWordLadder(int rows, int cols, const char m[][cols]);

int main(void) {
    char wordMatrix[][COLS] = {
        {'T', 'e', 'S', 't'},
        {'b', 'e', 'S', 'T'},
        {'B', 'E', 's', 'o'},
        {'B', 'E', 'S', 'A'}
    };
    // Considerando todas las filas no es escalera
    // pues los últimos dos cambios son en la última letra
    assert(!isWordLadder(4, 4, wordMatrix));// Considerando una sola fila es escalera
    assert(isWordLadder(1, 4, wordMatrix) == 1);// Considerando las tres primeras filas es escalera
    assert(isWordLadder(3, 4, wordMatrix) == 1);
    
    char wordMatrix2[][3] = {
        {'T', 'e', 'S'},
        {'t', 'b', 'e'},
        {'S', 'b', 'E'},
        {'B', 'b', 'e'}
    };
    // TeS -> Tbe cambian dos letras
    assert(!isWordLadder(4, 3, wordMatrix2));

    char wordMatrix3[][3] = {
        {'a', 'm', 'o'},
        {'a', 'r', 'o'},
        {'o', 's', 'a'}
    };// aro -> osa cambian tres letras
    
    assert(!isWordLadder(3, 3, wordMatrix3));
    puts("OK!");
    return 0;
    
}





// se fija que v1 y v2 difieran exactamente en un elemento que no sea el de indice: lastChange
// si es valida devuelve el indice de la letra que cambio, si no lo es devuelve -1
int checkLadder(const char v1[], const char v2[], int dim, int lastChange) {
  int changed = 0, newChange = -1;
  for(int i = 0; i < dim; i++) {
    if( toupper(v1[i]) != toupper(v2[i]) ) {
      if(changed || i == lastChange) {
        return -1;
      }
      changed = 1;
      newChange = i;
    }
  }
 
  // si no hubo cambios es -1, si lo hubo es el indice del elemento que cambio
  return newChange;
}
 
int isWordLadder(int rows, int cols, const char m[][cols]) {
  int isValid = 1;
  int change = -1; //para que en el primer llamado a checkLadder pueda cambiar cualquier indice
  for(int i = 1; i < rows && isValid; i++) {
    change = checkLadder(m[i-1], m[i], cols, change);
    if(change < 0) {
      isValid = 0;
    }
  }
 
  return isValid;
}
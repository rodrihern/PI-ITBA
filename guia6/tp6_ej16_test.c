#include <stdio.h>
#include <assert.h>

#define FILS 3
#define COLS 4

int ascendenteODescendente(const int (m[])[COLS]);

int main(void){
    int m1[][COLS] = {
		{-6,-5,2,6},
		{7,9,9,14},
		{21,32,45,46}
	}; // m1 es ascendente

	
  assert(ascendenteODescendente(m1)==1);
	int m2[][COLS] = {
		{19,13,12,8},
		{7,7,5,-1},
		{-6,-10,-14, -16}
	}; // m2 es descendente
assert(ascendenteODescendente(m2)==-1);


	int m3[][COLS] = {
		{-6,-5,-6,6},
		{7,9,10,14},
		{21,32,45,46}
	}; // m3 no es ascendente ni descendente
  assert(ascendenteODescendente(m3)==0);
	
	int m4[][COLS] = {
		{19,13,18,8},
		{7,5,2,-1},
		{-6,-10,-14}
	}; // m4 no es ascendente ni descendente
assert(ascendenteODescendente(m4)==0);

int m5[][COLS] = {
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1}
	}; // m5 es ascendente y descendente. La funciÃ³n podrÃ­a devolver 1 Ã³ -1
  int respM5 =  ascendenteODescendente(m5);
  assert(respM5==1 || respM5 == -1);
  
  int m6[][COLS] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,10}
	}; 
  int respM6 =  ascendenteODescendente(m6);
  assert(respM6 == 0);
  
  int m7[][COLS] = {
		{1,2,3,4},
		{1,2,3,4},
		{1,2,3,4}
	}; 
  int respM7 =  ascendenteODescendente(m7);
  assert(respM7 == 0);

  
	int m8[][COLS] = {
		{19,19,12,8},
		{7,7,5,-1},
		{-6,-10,-14, -16}
	}; // m2 es descendente
    assert(ascendenteODescendente(m8)==-1);

   int m9[][COLS] = {
		{-6,-6,-6,6},
		{7,9,9,14},
		{21,32,45,46}
	}; 
	   assert(ascendenteODescendente(m9)==1);
	   
    puts("OK");
    return 0;
}

int ascendenteODescendente(const int (m[])[COLS]) {
	int ascendente = 1, descendente = 1;
	
	for(int i = 0; i < FILS; i++) {
		//comparo contra el ultimo de la fila anterior
		if(i != 0) {
			if(m[i-1][COLS-1] < m[i][0]) { // si el anterior es mas chico --> no es descendente
				descendente = 0;
			}
			else if (m[i-1][COLS-1] > m[i][0]) { // si el anterior es mas grande --> no es ascendente
				ascendente = 0;
			}
		}

		// si no es ninguno de los dos dejo de ciclar
		if(ascendente == 0 && descendente == 0) {
			return 0;
		}

		//me fijo dentro de la fila
		for(int j = 1; j < COLS; j++) {
			if(m[i][j-1] < m[i][j]) { // si el anterior es mas chico --> no es descendente
				descendente = 0;
			}
			else if(m[i][j-1] > m[i][j]) { // si el anterior es mas grande --> no es ascendente
				ascendente = 0;
			}
		}

	}

	if (ascendente) return 1;
	if (descendente) return -1;
	return 0;
}
#include <stdio.h>
#include <assert.h>

#define COLS 4
// devuelve 1 si la fila 1 esta contenida en la fila 2
int esFilaAmiga(const int fila1[], unsigned int dim1,const int fila2[], unsigned int dim2);
// devuelve 1 si m1 es amiga de m2, 0 si no.
int esMatrizAmiga(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2);
int sonAmigas(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2 );

int 
main(void)
{
	int m1[][COLS] = {{0,1,2,3}, {4,4,5,6}, {7,8,8,9}};
	int m2[][COLS] = {{0,1,2,3}, {-3,7,8,9}, {-1,3,4,7}, {4,5,6,8}};
	int m3[][COLS] = {{2,3,3,7}};
	assert(sonAmigas(m1,3,m2,4)==1);
	assert(sonAmigas(m1,1,m2,4)==1);
	assert(sonAmigas(m1,2,m2,4)==1);
	assert(sonAmigas(m1,2,m2,2)==0);
	assert(sonAmigas(m2,4,m1,3)==2);
	assert(sonAmigas(m1,3,m3,1)==0);
	assert(sonAmigas(m3,1,m1,3)==0);
	int res = sonAmigas(m1,3,m1,3);
	assert(res==1 || res==2);
	
	printf("OK !\n");

	return 0;
}


int esFilaAmiga(const int v1[], unsigned int dim1, const int v2[], unsigned int dim2) {
	// quiero ver que todos los elementos de v1 enten en v2 (ambos estan ordenados)
	int i = 0, j = 0;

	while(i < dim1 && j < dim2) {
		if(v1[i] == v2[j]) {
			i++;
		}
		else if(v2[j] < v1[i]) {
			j++;
		}
		else {
			return 0;
		}
	}

	return j < dim2;  //si termine porque j llego a dim2 --> 0, sino quiere decir que son amigas --> 1
	

	
}



int esMatrizAmiga(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2) {
	//por cada fila de m1 quiero ver que sea amiga de una fila de m2

	for(int i = 0; i < fils1; i++) {
		int foundIt = 0;
		for(int j = 0; j < fils2 && !foundIt; j++) {
			if(esFilaAmiga(m1[i], COLS, m2[j], COLS)) {
				foundIt = 1;
			}
		}
		if(!foundIt) { //si sale porque termino de ciclar y no la encontro devuelve 0
			return 0;
		}
	}
	// si llega aca es porque todas las filas de m1 estaban en m2
	return 1;

}



int sonAmigas(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2) {
	if(esMatrizAmiga(m1, fils1, m2, fils2)) {
		return 1;
	}
	if(esMatrizAmiga(m2, fils2, m1, fils1)) {
		return 2;
	}
	return 0;

}

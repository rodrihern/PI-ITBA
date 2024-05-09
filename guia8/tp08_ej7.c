#include <stdlib.h>
#include <ctype.h>

#define FILS 7
#define COLS 6
#define BLOCK 40

typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB } Tdireccion;

typedef struct posicion {
	char * palabra;
	size_t fila;
	size_t columna;
	Tdireccion direccion;
} posicion;


int contienePalabra(char m[][COLS], int pos_i, int pos_j, Tdireccion dir, char * palabra) {
    int directions[][2] = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}
    };

    int inc_i = directions[dir][0];
    int inc_j = directions[dir][1];
    int i = pos_i + inc_i;
    int j = pos_j + inc_j;

    int contiene = 1;
    
    for(int k = 1; palabra[k] && contiene; k++) {
        if( i < 0 || FILS <= i || j < 0 || COLS <= j || toupper(m[i][j] ) != toupper(palabra[k]) ) {
            contiene = 0;
        }
        else {
            i += inc_i;
            j += inc_j;
        }
    }
    return contiene;
}

posicion * resolverSopa(char sopa[FILS][COLS], char * diccionario[]) {
    posicion * encontradas = NULL;
    size_t dim = 0;

    for(int i = 0; i < FILS; i++) {
        for(int j = 0; j < COLS; j++) {
            
            for(int k = 0; diccionario[k][0] && toupper(sopa[i][j]) >= toupper(diccionario[k][0]); k++) { 
                if(toupper(sopa[i][j]) == toupper(diccionario[k][0])) {

                    for(Tdireccion dir = DER; dir <= D_AB; dir++) {

                        if(contienePalabra(sopa, i, j, dir, diccionario[k])) {
                            if(dim % BLOCK == 0) {
                                encontradas = realloc(encontradas, (dim + BLOCK) * sizeof(posicion));
                            }       

                            encontradas[dim].palabra = diccionario[k];
                            encontradas[dim].fila = i;
                            encontradas[dim].columna = j;
                            encontradas[dim++].direccion = dir;
                        }
                    }
                }

            }
        }
    }


    encontradas = realloc(encontradas, dim * sizeof(posicion));
    encontradas[dim].palabra = NULL;

    return encontradas;
}
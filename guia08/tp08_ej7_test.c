#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define COLS 7
#define FILS 6
#define BLOCK 40


typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB} Tdireccion;

typedef struct posicion {
    char * palabra;
    size_t fila;
    size_t columna;
    Tdireccion direccion;
} posicion;

// NOTA: depende del orden en que realizan la busqueda, el testeo puede dar diferente
//       en esta prueba asumimos que recorren la matriz y por cada letra buscan si hay una palabra en el diccionario
//       que empiece con esa letra
       
//      Si en vez de hacerlo así, se recorre el diccionario, y cada palabra se busca en la sopa de letras.
//      Tienen que cambiar el testeo para que coincida con el orden en que se encuentran.


int contienePalabra(char m[][COLS], int pos_i, int pos_j, Tdireccion dir, char * palabra);
posicion * resolverSopa(char sopa[FILS][COLS], char * diccionario[]);

int main(void) {
    char * diccionario[] = {"ARRE", "CANCION", "CAPA", "ERROR", "ORCO", "PERRO", "PERTINAZ", "REA", "RIO", ""};
    
    char sopa[FILS][COLS] =
        {{'X','X','X','O','X','X','X'},
        {'A','P','A','C','Y','Y','O'},
        {'Z','E','Z','R','Z','C','X'},
        {'E','R','R','O','R','X','X'},
        {'X','R','I','O','I','E','X'},
        {'X','O','X','X','O','X','X'}};
    
    struct posicion * res = resolverSopa(sopa, diccionario);
    // La cantidad de palabras encontradas debe ser 9
    int expected = 9;
    int count = 0;
    while ( res[count].palabra != NULL)
        printf("%s\n", res[count++].palabra);
    assert(count == expected);

    assert(strcmp(res[1].palabra,"ARRE")==0);
    assert(res[1].fila==1);
    assert(res[1].columna==2);
    assert(res[1].direccion==D_AB);

    assert(strcmp(res[5].palabra,"ORCO")==0);
    assert(res[5].fila==3);
    assert(res[5].columna==3);
    assert(res[5].direccion==ARR);
    
    assert(strcmp(res[8].palabra,"ORCO")==0);
    assert(res[8].fila==4);
    assert(res[8].columna==3);
    assert(res[8].direccion==D_AR);

    assert(strcmp(res[4].palabra,"REA")==0);
    assert(res[4].fila==3);
    assert(res[4].columna==2);
    assert(res[4].direccion==I_AR);


    puts("\nOK primera parte");

    char * diccionario2[] = {""};
    res = resolverSopa(sopa, diccionario2);
    // La cantidad de palabras encontradas debe ser 0
    expected = 0;
    count = 0;
    while ( res[count].palabra != NULL)
        printf("%s\n", res[count++].palabra);
        
    assert(count == expected);
    free(res); 
    puts("OK sin palabras encontradas");


    return 0;
}

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
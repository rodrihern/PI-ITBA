#include "palabraADT.h"
#include <stdlib.h>
#define BLOCK 10

typedef struct palabraCDT {
    char * letras;
    int len;
} palabraCDT;

palabraADT crearVacia() {
    return calloc(1, sizeof(palabraCDT));
}

/**
•⁠  ⁠agregaLetra: Agrega una letra al final de una palabra existente.
*/
palabraADT agregarLetra(palabraADT pal, char letra) {
    pal->letras = realloc(pal->letras, pal->len + 1);
    pal->letras[pal->len++] = letra;
    return pal;
}

palabraADT crearDesde(char *s) {
    palabraADT word = crearVacia();
    while(*s) {
        word = agregarLetra(word, *s);
        s++;
    }
    return word;
}
/**
•⁠  ⁠mostrarPalabra: Muestra la palabra en salida estándar (sólo para test)
*/
void mostrarPalabra(palabraADT pal) {
    for(int i = 0; i < pal->len; i++) {
        putchar(pal->letras[i]);
    }
}
/**
•⁠  ⁠destruirPalabra: Libera recursos.
*/
void destruirPalabra(palabraADT pal) {
    free(pal->letras);
    free(pal);
}
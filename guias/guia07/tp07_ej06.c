#include <stdio.h>
#include <stdlib.h>
#include "../getnum.h"
#include "../rand.h"
#define X 5
#define DIGITOS 9
#define MIN_INTENTOS 5
#define SWAP(x, y) int a = x; x = y; y = a;

// deja en incognita un arreglo de X digitos no repetidos
void generaAleatorio(int incognita[]);
// le pide al usuario que elija un numero del 1 al 10 para seleccionar el nivel y lo devuelve
int elegirNivel();
// solicita al usuario que ingrese un numero de X digitos no repetidos
void leerNumero(int numero[]);
// indica si ambos arreglos son exactamente iguales o no
int coincideNumero(int incognita[], int numero[]);
// devuelve cuantos numeros estan bien
int cantidadBien(int incognita[], int numero[]);
// devuelve cuantos numeros estan regular
int cantidadRegular(int incognita[], int numero[]);


int main() {

    int nivel, intentos, incognita[X], numero[X];
    int gano = 0;
    generaAleatorio(incognita);

    printf("\n  BIENVENIDO A MASTERMIND\n\n");

    nivel = elegirNivel();
    intentos = MIN_INTENTOS + 10 - nivel;

    for(int i = 0; i < intentos && !gano; i++) {
        printf("\n\nTienes %d intento%s\n", intentos-i, (intentos-i == 1) ? "" : "s");
        leerNumero(numero);

        if(coincideNumero(incognita, numero)) {
            printf("\nFelicidades el numero era: ");
            gano = 1;
        }
    }

    if(!gano) {
        printf("\n\nLo siento, el numero era: ");
    }

    for(int i = 0; i < X; i++) {
        printf("%d ", incognita[i]);
    }

    putchar('\n');

    return 0;
}

void generaAleatorio(int incognita[]) {
    char digito[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    randomize();

    for(int i = 0; i < X; i++) {
        int j = randInt(0, DIGITOS-1-i);
        incognita[i] = digito[j];
        SWAP( digito[j], digito[DIGITOS-1-i] )
    }
}

int elegirNivel() {
    int nivel;
    do {
        nivel = getint("ingrese el nivel en el que desea jugar [1 -> 10]: ");
    } while(nivel < 1 || 10 < nivel);

    return nivel;
}

void leerNumero(int numero[]) {
    
    int esValido = 1;
    char anteriores[DIGITOS+1] = {0};
    
    do {
        if(!esValido) {
            puts("incorrecto, vuelva a intentarlo.");
            for(int j = 0; j <= DIGITOS; j++) {
                anteriores[j] = 0;
            }
        }
        esValido = 1;
        int num = getint("ingrese un numero de %d digitos no repetidos distintos de 0: ", X);
        int aux = num;
        int i;

        for(i = X-1; aux && i >= 0; i--) {
            int digito = aux % 10;
            if(digito == anteriores[digito]) {
                aux = 0; //para que corte
                esValido = 0;
            }
            else {
                anteriores[digito] = digito;
                numero[i] = digito;
            }
            aux /= 10;
        }
        // va a ser valido <-> i < 0 && aux == 0
        if( !(i < 0 && aux == 0) ) {
            esValido = 0;
        }

    } while(!esValido);

}

int coincideNumero(int incognita[], int numero[]) {
    int bien = cantidadBien(incognita, numero);
    if(bien == X) {
        return 1;
    }

    int regular = cantidadRegular(incognita, numero);
    printf("Hay %d bien y %d regular", bien , regular); 

    return 0;
}

int cantidadBien(int incognita[], int numero[]) {
    int i, cantBien = 0;
    for(i = 0; i < X; i++) {
        if(incognita[i] == numero[i]) {
            cantBien++;
        }
    }

    return cantBien;
}

int cantidadRegular(int incognita[], int numero[]) {
    char digEnInc[DIGITOS+1] = {0};
    int cantRegular = 0;

    for(int i = 0; i < X; i++) {
        digEnInc[incognita[i]] = incognita[i];
    }

    // qvq este el digito en incognta y que este en la posicion incorrecta
    for(int i = 0; i < X; i++) {
        if( numero[i] == digEnInc[numero[i]] && numero[i] != incognita[i] ) {
            cantRegular++;
        }
    }

    return cantRegular;
}

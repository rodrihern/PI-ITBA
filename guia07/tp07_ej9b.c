#include <stdio.h>
#include <stdlib.h>
#include "../rand.h"
#include "../getnum.h"
#define BOLILLAS 90
#define ROWS 3
#define COLS 5
#define SWAP(x, y) int a = x; x = y; y = a;

typedef int tipoLinea[COLS];
typedef tipoLinea tipoCarton[ROWS];

// genera 15 numeros aleatorios no ordenados y los deja en la matriz carton
void generarCarton(tipoCarton carton);
// la funcion en la que se juega al bingo
void jugar(int bolillero[], tipoCarton jugador[], int jugadores);
// Devuelve un numero de bolilla que todavia no salio y actualiza el bolillero
int sacarBolilla(int bolillero[], int * cantBolillas);
// Dado un carton y una bolilla verifica si pertenece al mismo y la marca (devuelve la cantidad de lineas completas o -1 si el carton no se actualizo)
int controlarCarton(tipoCarton carton, int bolilla);
// imprime el estado de un carton
void imprimirCarton(tipoCarton carton);
// devuelve 1 se esta la bolilla y la marca, devuelve 0 en caso contrario
int buscarBolilla(tipoCarton carton, int bolilla);
// Devuelve 1 si la linea esta completa (todos los numeros ya marcados)
int controlarLineas(tipoLinea linea);
//solicita la cantidad de jugadores
int leerJugadores();


int main() {
    // para una constante simnolica voy a hacer un array de cartones
    printf("\t\tBIENVENIDO AL SIMULADOR DEL BINGO\n");
    int jugadores = leerJugadores();
    int bolillero[BOLILLAS];

   tipoCarton * jugador = malloc(jugadores * ROWS * COLS * sizeof(int));

    for(int i = 0; i < BOLILLAS; i++) {
        bolillero[i] = i + 1;
    }
    randomize();
    //for para generar cartones
    for(int i = 0; i < jugadores; i++) {
        generarCarton(jugador[i]);
    }
    

    puts("Cartones iniciales:");

    for(int i = 0; i < jugadores; i++) {
        printf("Jugador%d:\n", i+1);
        imprimirCarton(jugador[i]);
    }

    jugar(bolillero, jugador, jugadores);

    free(jugador);
    
    return 0;
}

void generarCarton(tipoCarton carton) {
    int bolilla[BOLILLAS];
    static unsigned int seed;
    seed += randInt(1, 1000); //no es relevante que numero es, si es importante que no sea 0
    srand(seed);
    
    for(int i = 0; i < BOLILLAS; i++) {
        bolilla[i] = i+1;
    }

    for(int i = 0; i < ROWS*COLS; i++) {
        int j = randInt(0, BOLILLAS-1-i);
        *(*carton + i) = bolilla[j];
        SWAP(bolilla[j], bolilla[BOLILLAS-1-i]);
    }

}

void jugar(int bolillero[], tipoCarton jugador[], int jugadores) {
    int bolillasRestantes = BOLILLAS, fil;
    int filaCompleta = 0, bingo = 0;
    int * filasCompletas = calloc(jugadores, sizeof(int));
    
    
    do {

        int bolilla = sacarBolilla(bolillero, &bolillasRestantes);
        printf("\n\n**** Salio: %d ****\n", bolilla);
        printf("Bolillas restantes: %d\n", bolillasRestantes);

        for(int i = 0; i < jugadores; i++) {
            fil = controlarCarton(jugador[i], bolilla);
            if(fil > 0) {
                filasCompletas[i] = fil;
            }
        }

        for(int i = 0; i < jugadores; i++) {
            printf("Jugador%d:\n", i+1);
            imprimirCarton(jugador[i]);
        }

        // para una constante simbolica aca estaria bueno una funcion para ver quien gano
        if(!filaCompleta) {
            for(int i = 0; i < jugadores; i++) {
                if( filasCompletas[i] ) {
                    printf("\n\t\tJUGADOR %d COMPLETO UNA FILA", i+1);
                    filaCompleta = 1;
                }
            }
        }

        // para una constante simbolica aca estaria bueno una funcion para ver quien gano
        if(filaCompleta) {
            for(int i = 0; i < jugadores; i++) {
                if(filasCompletas[i] == ROWS) {
                    bingo = 1;
                    printf("\n\n\t\tGANO EL JUGADOR %d\n", i+1);
                }
            }
        }
        

    } while(!bingo);

    free(filasCompletas);

}

int sacarBolilla(int bolillero[], int * cantBolillas) {
    randomize();
    (*cantBolillas)--;
    int i = randInt(0, *cantBolillas);
    int bolilla = bolillero[i];
    SWAP(bolillero[i], bolillero[*cantBolillas]);

    return bolilla;
}

int controlarCarton(tipoCarton carton, int bolilla) {
    int lineasFormadas = 0;

    if(buscarBolilla(carton, bolilla)) {
        for(int i = 0; i < ROWS; i++) {
            if( controlarLineas(carton[i]) ) {
                lineasFormadas++;
            }
        }
    }
    else {
        lineasFormadas = -1; // osea que no se actualizo el carton y las lineas formadas son las mismas que antes
    }

    return lineasFormadas;
}

void imprimirCarton(tipoCarton carton) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(carton[i][j]) {
                printf("%d ", carton[i][j]);
            }
        }
        putchar('\n');
    }
}

int buscarBolilla(tipoCarton carton, int bolilla) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(carton[i][j] == bolilla) {
                carton[i][j] = 0; // la marco como que ya salio
                return 1;
            }
        }
    }

    return 0;
}

int controlarLineas(tipoLinea linea) {
    // si ya salieron todas las de una linea la suma tiene que dar 0
    int sum = 0;
    for(int i = 0; i < COLS; i++) {
        sum += linea[i];
    }

    return (sum == 0);
}

int leerJugadores() {
    int jugadores;
    do {
        jugadores = getint("ingrese cantidad de jugadores [2 -> 10]: ");
    } while(jugadores < 2 || 10 < jugadores);

    return jugadores;
}

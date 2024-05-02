#include <stdio.h>
#include <stdlib.h>
#include "../rand.h"
#define BOLILLAS 90
#define ROWS 3
#define COLS 5
#define SWAP(x, y) int a = x; x = y; y = a;

typedef int tipoLinea[5];
typedef tipoLinea tipoCarton[3];
// genera 15 numeros aleatorios no ordenados y los deja en la matriz carton
void generarCarton(tipoCarton carton);
// la funcion en la que se juega
int jugar(int bolillero[], tipoCarton jugador1, tipoCarton jugador2);
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



int main() {
    // para una constante simnolica voy a hacer un array de cartones
    tipoCarton jugador1, jugador2;
    int ganador, bolillero[BOLILLAS];

    for(int i = 0; i < BOLILLAS; i++) {
        bolillero[i] = i + 1;
    }
    
    randomize();
    generarCarton(jugador1);
    generarCarton(jugador2);

    puts("Cartones iniciales:");
    puts("Jugador1:");
    imprimirCarton(jugador1);

    puts("\nJugador2:");
    imprimirCarton(jugador2);

    ganador = jugar(bolillero, jugador1, jugador2);

    
    if(ganador) {
        printf("\n\nEL GANADOR FUE EL JUGADOR %d\n", ganador);
    }
    else {
        printf("\n\nWTF HUBO EMPATE\n");
    }

    
    return 0;
}

void generarCarton(tipoCarton carton) {
    int bolilla[BOLILLAS];
    static unsigned int seed;
    seed += rand();
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

int jugar(int bolillero[], tipoCarton jugador1, tipoCarton jugador2) {
    // TODO: saber que tengo que controlar que controlarCarton me devuelve algo > 0 si se actualizo
    int bolillasRestantes = BOLILLAS, filas1 = 0, filas2 = 0, fil;
    int filaCompleta = 0, bingo = 0, gano = 0;
    
    
    do {

        int bolilla = sacarBolilla(bolillero, &bolillasRestantes);
        printf("\nSalio: %d\n", bolilla);
        printf("Bolillas restantes: %d\n", bolillasRestantes);

        fil = controlarCarton(jugador1, bolilla);
        if(fil > 0) {
            filas1 = fil;
        }

        fil = controlarCarton(jugador2, bolilla);
        if(fil > 0) {
            filas2 = fil;
        }
        puts("Jugador1:");
        imprimirCarton(jugador1);
        puts("Jugador 2:");
        imprimirCarton(jugador2);

        // para una constante simbolica aca estaria bueno una funcion para ver quien gano
        if(!filaCompleta) {
            if(filas1 > 0 || filas2 > 0) {
                filaCompleta = 1;

                if(filas1 > 0 && filas2 > 0) {
                    puts("\n\n\tAMBOS COMPLETARON 1 FILA\n\n");
                }
                else if (filas1 > 0) {
                    puts("\n\n\tJUGADOR 1 COMPLETO UNA FILA\n\n");
                }
                else {
                    puts("\n\n\tJUGADOR 2 COMPLETO UNA FILA\n\n");
                }
            }
        }

        // para una constante simbolica aca estaria bueno una funcion para ver quien gano
        if(filas1 == ROWS || filas2 == ROWS) {
            bingo = 1;

            if(filas1 == ROWS && filas2 == ROWS) {
                gano = 0;
            }
            else if (filas1 == ROWS) {
                gano = 1;
            }
            else {
                gano = 2;
            }

        }
        

    } while(!bingo && bolillasRestantes > 0);

    return gano;
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

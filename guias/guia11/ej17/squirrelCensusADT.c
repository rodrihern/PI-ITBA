#include "squirrelCensusADT.h"

typedef struct squirrelRow {
    size_t * squirrels;
    size_t cols;
} squirrelRow;

typedef struct squirrelCensusCDT {
    size_t blockSize;
    squirrelRow * rows;
    size_t rowCount;
} squirrelCensusCDT;


squirrelCensusADT newSquirrelCensus(size_t blockSizeMetres) {
    if(!blockSizeMetres) {
        exit(1);
    }
    squirrelCensusADT new = calloc(1, sizeof(squirrelCensusCDT));
    new->blockSize = blockSizeMetres;
    return new;
}

static void map(size_t blockSize, size_t x, size_t y, size_t * row, size_t * col) {
    *row = y / blockSize;
    *col = x / blockSize;
}
/**
 * Registra una ardilla en el bloque (manzana) correspondiente al punto (yDistance, xDistance) donde
 * - yDistance es la distancia vertical en metros del extremo superior izquierdo del parque
 * - xDistance es la distancia horizontal en metros del extremo superior izquierdo del parque
 * Retorna cuántas ardillas fueron registradas en ese mismo bloque
 */
size_t countSquirrel(squirrelCensusADT sq, size_t yDistance, size_t xDistance) {
    size_t i, j;
    map(sq->blockSize, xDistance, yDistance, &i, &j);
    if(i >= sq->rowCount) {
        sq->rows = realloc(sq->rows, (i + 1) * sizeof(sq->rows[0]));
        for(int k = sq->rowCount; k < i; k++) {
            sq->rows[k].squirrels = NULL;
            sq->rows[k].cols = 0;
        }
        sq->rows[i].squirrels = calloc(j + 1, sizeof(size_t));
        sq->rows[i].squirrels[j] = 1;
        sq->rows[i].cols = j + 1; 
        sq->rowCount = i + 1; 
        return 1;
    }
    if(j >= sq->rows[i].cols) {
        sq->rows[i].squirrels = realloc(sq->rows[i].squirrels, (j + 1) * sizeof(size_t));
        for(int k = sq->rows[i].cols; k < j; k++) {
            sq->rows[i].squirrels[k] = 0;
        }
        sq->rows[i].squirrels[j] = 1;
        sq->rows[i].cols = j + 1;
        return 1;
    }

    sq->rows[i].squirrels[j]++;
    return sq->rows[i].squirrels[j];
}

/**
 * Retorna cuántas ardillas fueron registradas en el bloque correspondiente al punto (yDistance, xDistance)
 */
size_t squirrelsInBlock(const squirrelCensusADT sq, size_t yDistance, size_t xDistance) {
    size_t i, j;
    map(sq->blockSize, xDistance, yDistance, &i, &j);
    if(i >= sq->rowCount || j >= sq->rows[i].cols) {
        return 0;
    }
    
    return sq->rows[i].squirrels[j];
}

/**
 * Libera los recursos utilizados para el conteo de ardillas en un parque
 */
void freeSquirrelCensus(squirrelCensusADT sq) {
    for(int i = 0; i < sq->rowCount; i++) {
        free(sq->rows[i].squirrels);
    }
    free(sq->rows);
    free(sq);

    //libero el ADT
}
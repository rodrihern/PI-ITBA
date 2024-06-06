//
// Created on 27/05/2024.
//
#include "vectorADT.h"

typedef struct element {
    elemType elem;
    char occupied;      // 1 si hay un elemento, 0 sinó
} element;

typedef struct vectorCDT {
    element * vec;
    // Con la opcion 3 ( 2 vectores)
    // elemType * vec;
    // char * occupied;
    // Con la opcion 1 (vector de punteros)
    // elemType ** vec;
    size_t dim; // espacio reservado, empieza en cero
    compare cmp;
    size_t count;   // elementos guardados, empieza en cero
} vectorCDT;

vectorADT newVector(compare cmp) {
    vectorADT aux = calloc(1, sizeof(*aux));
    aux->cmp = cmp;
    return aux;
}

void freeVector(vectorADT v) {
    free(v->vec);
    free(v);
}

int putElement(vectorADT v, elemType elem, size_t idx) {
    if ( idx >= v->dim) {
        v->vec = realloc(v->vec, (idx+1) * sizeof(struct element) );
        for(int i=v->dim; i <= idx ; i++) {
            v->vec[i].occupied = 0;
        }
        v->dim = idx + 1;
    }
    v->vec[idx].elem = elem;
    int flag = v->vec[idx].occupied == 0; // 1 si estaba libre, 0 si estaba ocupada
    v->vec[idx].occupied = 1;
    v->count += flag;
    return flag;
}

int get(vectorADT v, size_t idx, elemType * elem) {
    if (!isOccupied(v, idx)) {
        return 0;
    }
    *elem = v->vec[idx].elem;
    return 1;
}

int deleteElement(vectorADT v, size_t idx) {
    if (!isOccupied(v, idx)) {
        return 0;
    }
    v->vec[idx].occupied = 0;
    v->count--;
    return 1;
}

int isOccupied(vectorADT v, size_t idx) {
    return idx < v->dim && v->vec[idx].occupied;
}

size_t count(vectorADT v) {
    return v->count;
}

int indexOf(vectorADT v, elemType elem) {
    for(int i=0; i<v->dim; i++) {
        if (v->vec[i].occupied && v->cmp(elem, v->vec[i].elem)==0) {
            return i;
        }
    }
    return -1;
}
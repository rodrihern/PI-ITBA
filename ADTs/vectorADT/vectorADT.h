//
// Created on 27/05/2024.
//

#ifndef UNTITLED7_VECTORADT_H
#define UNTITLED7_VECTORADT_H
#include <stdlib.h>

typedef int elemType;
typedef struct vectorCDT * vectorADT;

// Retorna <0, 0 o >0
typedef int (*compare) (elemType, elemType);

vectorADT newVector(compare cmp);

void freeVector(vectorADT);

// Reteorna 1 si pisa un elemento, 0 si la posición estaba libre
int putElement(vectorADT v, elemType elem, size_t idx);

// Retorna 1 si había un elemento en idx, cero si estaba libre
int deleteElement(vectorADT v,  size_t idx);

// Si en idx hay un elemento retorna 1 y en *elem deja el elemento
// sinó retorna cero y no cambia *elem
int get(vectorADT v, size_t idx, elemType * elem);

int isOccupied(vectorADT v, size_t idx);

// Retorna la primer posición de elem en v, o -1 si elem no está
int indexOf(vectorADT v, elemType elem);

/* Retorna la cantidad de elementos insertados */
size_t count(vectorADT v);

#endif //UNTITLED7_VECTORADT_H

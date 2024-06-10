#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BLOCK 20

typedef struct CDT * ADT;

typedef struct CDT {

} CDT;

typedef int elemType;

typedef int (*compare) (elemType, elemType);

typedef struct node {
    elemType elem;
    struct node * tail;
} node;

typedef node * tList;


// crea una copia del string en el heap y devuelve la direccion
char * cpyStr(char * s) {
    if(s == NULL) {
        return NULL;
    }
    return strcpy(malloc(strlen(s) + 1), s);
}

// lo mismo que cpyStr pero sin strlen y haciendo realloc de a bloques
static char * cpyStrBlock(const char * s, size_t * len) {
    if(s == NULL) {
        return NULL;
    }
    int i = 0;
    char * dest = NULL;
    while(*s) {
        if(i % BLOCK == 0) {
            dest = realloc(dest, (i + BLOCK) * sizeof(char));
        }
        dest[i++] = *s++;
    }
    dest = realloc(dest, (i+1) * sizeof(char));
    dest[i] = 0;
    *len = i;
    return dest;
}

// retorna el puntero al nodo o NULL si no esta
tList findInList(tList list, elemType elem, compare cmp) {
    tList ans = NULL;
    while(!ans && list) {
        if(cmp(list->elem, elem) == 0) {
            ans = list;
        }
        list = list->tail;
    }

    return ans;
}

// inserta ordenado
tList insertRec(tList list, elemType elem, compare cmp, int *added) {
    int c;
    if ( list==NULL || (c = cmp(list->elem, elem)) > 0 ) {
        // inserto
        tList aux = malloc(sizeof(node));
        aux->elem = elem;
        aux->tail = list;
        *added=1;
        return aux;
    }
    if (c < 0) {
        // inserto en la cola xd
        list->tail = insertRec(list->tail, elem, cmp, added);
    }
    // son iguales asi que no inserto y retorno
    return list;
}

// borra de la lista el elemento
static tList deleteListRec(tList list, elemType elem, compare cmp, int *deleted) {
    int c;
    if (list == NULL ||(c=cmp(list->elem, elem)) > 0) {
        // ya el elemento no esta
        return list;
    }
    if (c == 0) {
        // borro
        tList aux = list->tail;
        free(list);
        *deleted = 1;
        return aux;
    }
    // lo sigo buscando en la cola
    list->tail = deleteListRec(list->tail, elem, cmp, deleted);
    return list;
}


/*
    * RECURSIVIDAD DE PILA: 

        PRIMERO HAGO EL LLAMADO RECURSIVO Y USO LO QUE ME RETORNA
        LIFO

    * RECURSIVIDAD DE COLA:

        HAGO LO QUE TENGO QUE HACER Y VUELVO A LLAMAR (N! = N * (N-1)!)
        FIFO
*/
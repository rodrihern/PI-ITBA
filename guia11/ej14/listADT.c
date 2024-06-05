#include "listADT.h"

typedef struct node {
    elemType elem;
    struct node * tailAsc;
    struct node * tailAdded;
} node;

typedef node * tList;

typedef struct listCDT {
    tList listAsc;
    tList nextAsc;
    tList firstAdded;
    tList lastAdded;
    tList nextAdded;
    size_t dim;
    compare cmp;
} listCDT;



listADT newList(compare cmp) {
    listADT new = calloc(1, sizeof(listCDT));
    new->cmp = cmp;
    return new;
}



static tList insert(tList list, elemType elem, compare fn, int * added, tList * newNode) {
    int c;
    if( list == NULL || (c = fn(list->elem, elem)) > 0 ) {
        // agrego
        *added = 1;
        tList new = malloc(sizeof(node));
        new->elem = elem;
        new->tailAsc = list;
        *newNode = new;
        return new;
    }
    if(c < 0) {
        list->tailAsc = insert(list->tailAsc, elem, fn, added, newNode);
    }
    return list;
}

void add(listADT list, elemType elem) {
    // lo inserto en la lista asc
    int added = 0;
    tList newNode = NULL;
    list->listAsc = insert(list->listAsc, elem, list->cmp, &added, &newNode);
    if(!added) {
        return;
    }

    // si no hay firstAdded lo agrego en ambos
    if(list->firstAdded == NULL) {
        list->firstAdded = newNode;
        list->lastAdded = newNode;
        return;
    }

    // lo agrego al tail lastAdded y actualizo lastAdded
    list->lastAdded->tailAdded = newNode;
    list->lastAdded = newNode;
}

/* Elimina un elemento. */
// void remove(listADT list, elemType elem);


void toBegin(listADT list) {
    list->nextAdded = list->firstAdded;
}


int hasNext(listADT list) {
    return list->nextAdded != NULL;
}


elemType next(listADT list) {
    if(!hasNext(list)) {
        exit(1);
    }
    elemType ans =  list->nextAdded->elem;
    list->nextAdded = list->nextAdded->tailAdded;
    return ans;
}

/* Resetea el iterador que recorre la lista en forma ascendente */
void toBeginAsc(listADT list) {
    list->nextAsc = list->listAsc;
}

/* Retorna 1 si hay un elemento siguiente en el iterador que
** recorre la lista en forma ascendente. Sino retorna 0 */
int hasNextAsc(listADT list) {
    return list->nextAsc != NULL;
}

/* Retorna el elemento siguiente del iterador que recorre la lista en forma ascendente. 
** Si no hay un elemento siguiente o no se invocó a toBeginAsc aborta la ejecución.
*/
elemType nextAsc(listADT list) {
    if(!hasNextAsc(list)) {
        exit(1);
    }
    elemType ans = list->nextAsc->elem;
    list->nextAsc = list->nextAsc->tailAsc;
    return ans;
}

/* Libera la memoria reservada por la lista */
static void freeRec(tList list) {
    if(list == NULL) {
        return;
    }
    freeRec(list->tailAsc);
    free(list);
}

void freeList(listADT list) {
    freeRec(list->listAsc);
    free(list);
}



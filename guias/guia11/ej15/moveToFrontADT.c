#include "moveToFrontADT.h"


typedef struct node {
    elemType elem;
    struct node * tail;
} node;

typedef node * tList; 

typedef struct moveToFrontCDT {
    tList first;
    tList last;
    tList next;
    size_t dim;
    compare cmp;
} moveToFrontCDT;


 

moveToFrontADT newMoveToFront(compare cmp) {
    moveToFrontADT new = calloc(1, sizeof(moveToFrontCDT));
    new->cmp = cmp;
    return new;
}

static void freeList(tList list) {
    if(list == NULL) {
        return;
    }
    freeList(list->tail);
    free(list);
}
/* Libera toda la memoria reservada por el TAD */
void freeMoveToFront(moveToFrontADT mtf) {
    freeList(mtf->first);
    free(mtf);
}
 
static int belongs(tList list, elemType elem, compare fn) {
    int found = 0;
    while(!found && list) {
        if(fn(list->elem, elem) == 0) {
            found = 1;
        }
        list = list->tail;
    }
    return found;
}

unsigned int add(moveToFrontADT mtf, elemType elem) {
    if(belongs(mtf->first, elem, mtf->cmp)) {
        return 0;
    }
    mtf->dim++;
    tList newNode = malloc(sizeof(node));
    newNode->elem = elem;
    newNode->tail = NULL;
    if(mtf->first == NULL) {
        mtf->first = newNode;
    }
    else {
        mtf->last->tail = newNode;
    }
    mtf->last = newNode;

    return 1;
}
  


unsigned int size(moveToFrontADT mtf) {
    return mtf->dim;
}
 

void toBegin(moveToFrontADT mtf) {
    mtf->next = mtf->first;
}


int hasNext(moveToFrontADT mtf) {
    return mtf->next != NULL;
}


elemType next(moveToFrontADT mtf) {
    if(!hasNext(mtf)) {
        exit(1);
    }
    elemType ans = mtf->next->elem;
    mtf->next = mtf->next->tail;
    return ans;
}



elemType * get(moveToFrontADT mtf, elemType elem) {
    if(mtf->first == NULL) {
        return NULL;
    }
    compare fn = mtf->cmp;
    tList current = mtf->first->tail;
    tList prev = mtf->first;
     
    int found = 0;
    if(fn(prev->elem, elem) == 0) {
        found = 1;
    }
    while(!found && current) {
        if( fn(current->elem, elem) == 0 ) {
            // lo mando al principio
            found = 1;
            prev->tail = current->tail;
            current->tail = mtf->first;
            mtf->first = current;
        }

        prev = current;
        current = current->tail;
    }

    if(!found) {
        return NULL;
    }

    
    // esta al principio
    elemType * ans = malloc(sizeof(elemType));
    *ans = mtf->first->elem;
    return ans;
}
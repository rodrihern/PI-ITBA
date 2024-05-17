#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../utilist.h"

 
TList concatenarLista(TList, const TList);
 
int
main(void) {
    int v1[] = {4,3,7};
    TList l1 = fromArray(v1, 3);
    int v2[] = {3,2,6};
    TList l2 = fromArray(v2, 3);
    int v1yv2[] = {4,3,7,3,2,6};
    TList l1yl2 = concatenarLista(l1, l2);
    assert(checkElems(l1yl2, v1yv2, 6));
    freeList(l1yl2);
    freeList(l2);
 
    TList l3 = NULL;
    TList l4 = fromArray(v1yv2, 6);
    TList l3yl4 = concatenarLista(l3, l4);
    assert(checkElems(l3yl4, v1yv2, 6));
    freeList(l3yl4);
    freeList(l4);
 
    printf("OK!\n");
    return 0;
}

TList concatenarLista(TList l1, TList l2) {
    if(l2 == NULL) {
        return l1;
    }

    if(l1 == NULL) {
        TList new = malloc(sizeof(TNode));
        new->elem = l2->elem;
        new->tail = concatenarLista(l1, l2->tail);
        return new;
    }

    l1->tail = concatenarLista(l1->tail, l2);
    return l1;
}
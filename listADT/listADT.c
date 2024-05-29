//
// Created on 22/05/2024.
//

#include <stdlib.h>
#include "listADT.h"

typedef struct node {
    elemType head;
    struct node * tail;
} node;

typedef struct node * List;

struct listCDT {
    List first;
    List current;
    size_t size;
    compare cmp;
};

listADT newList(compare cmp) {
    listADT aux = malloc(sizeof (struct listCDT));
    aux->first = NULL;
    aux->size = 0;
    aux->cmp = cmp;
    return aux;
}

void freeRec(List l) {
    if ( l==NULL) {
        return;
    }
    freeRec(l->tail);
    free(l);
}

void freeList(listADT list) {
    freeRec(list->first);
    free(list);
}

int isEmptyList(const listADT list) {
    return list->first == NULL;
}

int belongsList(const listADT list, elemType elem) {
    List aux = list->first;
    int c;
    while(aux != NULL && (c=list->cmp(aux->head, elem)) <= 0) {
        if (c==0) {
            return 1;
        }
        aux = aux->tail;
    }
    return 0;
}

static int belongsRec(List list, elemType elem, compare cmp) {
    if (list==NULL) {
        return 0;
    }
    int c = cmp(list->head, elem);
    // c puede ser cero, negativo o positivo
    if (c==0) {
        return 1;
    }
    if ( c > 0) {
        return 0;
    }
    // Sabemos que list->head es "menor" que elem
    return belongsRec(list->tail, elem, cmp);
}

// Version recursiva de belongs
int belongsListRec(const listADT list, elemType elem) {
    return belongsRec(list->first, elem, list->cmp);
}

static List insertRec(List list, elemType elem, compare cmp, int *flag) {
    int c;
    if (list==NULL || (c=cmp(list->head, elem)) > 0) {
        List aux = malloc(sizeof(node));
        aux->head = elem;
        aux->tail = list;
        *flag=1;
        return aux;
    }
    if ( c < 0) {
        // elem es "mayor" que el primero
        list->tail = insertRec(list->tail, elem, cmp, flag);
    }
    return list;
}

int insertList(listADT list, elemType elem) {
    int flag=0;
    list->first = insertRec(list->first, elem, list->cmp, &flag);
    list->size += flag;
    return flag;
}

static List deleteListRec(List list, elemType elem, compare cmp, int * flag) {
    int c;
    if(list == NULL || (c = cmp(list->head, elem) > 0)) {
        return list;
    }
    if(c < 0) {
        list->tail = deleteListRec(list->tail, elem, cmp, flag);
        return list;
    }
    // aca tengo que borrar
    List aux = list->tail;
    free(list);
    *flag = 1;
    return aux;
}

int deleteList(listADT list, elemType elem) {
    int flag = 0;
    list->first = deleteListRec(list->first, elem, list->cmp, &flag);
    list->size -= flag;
    return flag;
}

static elemType elemAtIndexRec(List list, int idx) {
    if(idx == 0) {
        return list->head;
    }
    return elemAtIndexRec(list->tail, idx-1);
}

elemType elementAtIndex(listADT list, int idx) {
    if(idx >= list->size) {
        exit(1);
    }
    return elemAtIndexRec(list->first, idx);
    
}

void toBegin(listADT list) {
    list->current = list->first;
    return;
}

int validateNext(listADT list) {
    return list->current != NULL;
}

elemType next(listADT list) {
    if (!validateNext(list)) {
        exit(1);
    }
    elemType aux = list->current->head;
    list->current = list->current->tail;
    return aux;
}

int sizeList(const listADT list) {
    return list->size;
}
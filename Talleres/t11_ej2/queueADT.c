#include "queueADT.h"

typedef struct node * tList;

typedef struct node {
    elementType elem;
    tList tail;
} node;

typedef struct queueCDT {
    tList first;
    tList last;
    tList idx;
} queueCDT;

 
queueADT newQueue(void) {
    return calloc(1, sizeof(queueCDT));
}
 
int isEmpty(queueADT q) {
    return q->first == NULL;
}

void queue(queueADT q, elementType n) {
    tList new = calloc(1, sizeof(node));
    new->elem = n;
    if(isEmpty(q)) {
        q->first = new;
        q->last = new;
    }
    else {
        q->last->tail = new;
        q->last = new;
    }
}
 

void dequeue(queueADT q, elementType * out) {
    if(isEmpty(q)) {
        exit(1);
    }
    *out = q->first->elem;
    tList aux = q->first;
    if(q->first->tail == NULL) {
        q->last = NULL;
    }
    q->first = q->first->tail;
    free(aux);
}
 
 
static void freeRec(tList l) {
    if ( l==NULL) {
        return;
    }
    freeRec(l->tail);
    free(l);
}

void freeQueue(queueADT q) {
    freeRec(q->first);
    free(q);
}

void toBegin(queueADT q) {
    q->idx = q->first;
}

int hasNext(queueADT q) {
    return q->idx != NULL;
}

elementType next(queueADT q) {
    if(!hasNext(q)) {
        exit(1);
    }
    elementType element = q->idx->elem;
    q->idx = q->idx->tail; //avanzo uno, para feli
    return element;
    
}

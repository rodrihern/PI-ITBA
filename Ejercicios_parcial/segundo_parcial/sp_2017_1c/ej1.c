#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct node {
    int elem;
    struct node * tail;
} Tnode;

typedef struct node * Tlist;

// recibe un vector de enteros no repetidos y los pasa a lista
Tlist vecToList(int v[]);

// crea una nueva lista eliminando repetidos
Tlist deleteReps(Tlist list);

int main() {
    int v[] = {1, 2, 3, 4, -1};
    Tlist list = vecToList(v);
    Tlist aux = list;
    for(int i = 1; aux; i++) {
        assert(aux->elem == i);
        aux = aux->tail;
    }
    free(list);

    int v2[] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 4, 4, -1};
    Tlist list2 = vecToList(v2);
    list = deleteReps(list2);
    free(list2);
    aux = list;
    for(int i = 1; aux; i++) {
        assert(aux->elem == i);
        aux = aux->tail;
    }

    puts("OK !");

    return 0;
}

Tlist vecToList(int v[]) {
    if(v == NULL || *v == -1) {
        return NULL;
    }

    Tlist newNode = malloc(sizeof(Tnode));
    newNode->elem = *v;
    newNode->tail = vecToList(v+1);
    return newNode;
}

Tlist deleteReps(Tlist list) {
    if(list == NULL) {
        return NULL;
    }

    Tlist subList = deleteReps(list->tail);

    if(list->tail == NULL || list->elem != list->tail->elem) {
        Tlist newNode = malloc(sizeof(Tnode));
        newNode->elem = list->elem;
        newNode->tail = subList;
        return newNode;
    }

    return subList;

}

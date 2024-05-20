#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../utilist.h"

typedef struct nodeBrief * TListBrief; 

typedef struct nodeBrief {
		int elem;
		size_t count;
		struct nodeBrief * tail;
} TNodeBrief;


TListBrief comprimeList(const TList list);

// Auxiliar para que pase el test con sanitizer
void freeListBrief(TListBrief lb) {
	if ( lb == NULL)
		return;
	freeListBrief(lb->tail);
	free(lb);
	}

	int main(void) {

	int v[] = {1,1,2,3,3,3,3,3,10,100,100,998};
	TList list = fromArray(v, sizeof(v)/sizeof(v[0]));
	TListBrief bf = comprimeList(list);

	TListBrief aux = bf;
	assert(aux->elem ==1 && aux->count == 2);

	aux = aux->tail;
	assert(aux->elem ==2 && aux->count == 1);

	aux = aux->tail;
	assert(aux->elem ==3 && aux->count == 5);

	aux = aux->tail;
	assert(aux->elem ==10 && aux->count == 1);

	aux = aux->tail;
	assert(aux->elem ==100 && aux->count == 2);

	aux = aux->tail;
	assert(aux->elem ==998 && aux->count == 1);

	aux = aux->tail;
	assert(aux == NULL);

	freeList(list);
	freeListBrief(bf);
	
	printf ("OK!\n");
	return 0;
}

TListBrief comprimeList(const TList list) {
	if(list == NULL) {
		return NULL;
	}

	TListBrief newNode = malloc(sizeof(TNodeBrief));
	TList aux = list;
	int i;
	for(i = 1; aux->tail != NULL && aux->elem == aux->tail->elem; i++) {
		aux = aux->tail;
	}

	newNode->elem = list->elem;
	newNode->count = i;
	newNode->tail = comprimeList(aux->tail);
	
	return newNode;
}
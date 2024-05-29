#include "setADT.h"
#include <stdlib.h>

typedef struct setCDT {
    listADT list;
    compare cmp;
} setCDT;

setADT newSet(compare fun) {
    setADT new = malloc(sizeof(setCDT));
    new->list = newList(fun);
    new->cmp = fun;
    return new;
}

void freeSet(setADT set) {
    freeList(set->list);
    free(set);
}

int isEmptySet(setADT set) {
    return isEmptyList(set->list);
}

int setContains(const setADT set, elemType element) {
    return belongsList(set->list, element);
}

int addElement(setADT set, elemType element) {
    return insertList(set->list, element);
}

int deleteElement(setADT set, elemType element) {
    return deleteList(set->list, element);
}

int sizeSet(const setADT set) {
    return sizeList(set->list);
}

setADT unionSet(setADT set1, setADT set2) {
    // asumo que la funcion de comparacion de set1 y set2 es la misma, uso la de set1
    setADT ans = newSet(set1->cmp);
    toBegin(set1->list);
    toBegin(set2->list);

    while(hasNext(set1->list)) {
        insertList(ans->list, next(set1->list));
    }
    while(hasNext(set2->list)) {
        insertList(ans->list, next(set2->list));
    }

    return ans;
}

setADT intersectionSet(setADT set1, setADT set2) {
    // asumo que la funcion de comparacion de set1 y set2 es la misma, uso la de set1
    setADT ans = newSet(set1->cmp);
    toBegin(set1->list);
    toBegin(set2->list);
    elemType elem1;
    elemType elem2;
    if (set1 == set2) {
		while (hasNext(set1->list))
			addElement(ans, next(set1->list));
		return ans;
	}
    
    if(hasNext(set1->list) && hasNext(set2->list)) {
        elem1 = next(set1->list);
        elem2 = next(set2->list);
    }
    else {
        return ans;
    }

    

    compare fn = set1->cmp;
    int c;
    int done = 0;

    while(!done) {
        if( (c = fn(elem1, elem2)) == 0 ) {
            insertList(ans->list, elem1);
            if(hasNext(set1->list) && hasNext(set2->list)) {
                elem1 = next(set1->list);
                elem2 = next(set2->list);
            }
            else {
                done = 1;
            }
        }
        else if(c < 0) { // elem1 < elem2
            if(hasNext(set1->list)) {
                elem1 = next(set1->list);
            }
            else {
                done = 1;
            }
        }
        else { // elem2 < elem1
            if(hasNext(set2->list)) {
                elem2 = next(set2->list);
            }
            else {
                done = 1;
            }
        }
    }

    return ans;
}


setADT diffSet(setADT set1, setADT set2) {
	elemType e1, e2;
	setADT set;
	listADT l1, l2;

	set = newSet(set1->cmp);

	// Si son el mismo conjunto, retornar conjunto vacío 
	if (set == NULL || set1 == set2)
		return set;

	l1 = set1->list;
	l2 = set2->list;

	toBegin(l1);
	toBegin(l2);

    int has1, has2;
	if ( (has2 = hasNext(l2)) )
		e2 = next(l2);

	if ( (has1 = hasNext(l1)) )
		e1 = next(l1);

	int c;
	while (has1) {
		if (!has2 || (c = set1->cmp(e1, e2)) < 0) {
			addElement(set, e1);
			if ( (has1 = hasNext(l1)) )
			    e1 = next(l1);
		} else if (c > 0) {
		    if ( (has2 = hasNext(l2)) ) 
			    e2 = next(l2);
		} else {
		    if ( (has1 = hasNext(l1)) )
			    e1 = next(l1);
			if ( (has2 = hasNext(l2)) ) 
			    e2 = next(l2);
		}
	}
	return set;
}


void printSet(setADT set) {
    toBegin(set->list);
    while(hasNext(set->list)) {
        puts(next(set->list));
    }
    putchar('\n');
}




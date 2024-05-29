#include "bagADT.h"
#define BLOCK 10


typedef struct item {
    elemType elem;
    size_t count;
} item;

typedef struct bagCDT {
    item * vec;
    size_t dim;
    compareFun cmp;
} bagCDT;

bagADT newBag(compareFun fn) {
    bagADT aux = calloc(1, sizeof(bagCDT));
    aux->cmp = fn;
    return aux;
}

static int belongs(item * v, elemType element, size_t dim, compareFun cmp) {
    int found = 0, i;
    for(i = 0; i < dim && !found; i++) {
        if( cmp(v[i].elem, element) == 0 ) {
            found = 1;
        }
    }

    return found ? i-1 : -1;
} 

unsigned int add(bagADT bag, elemType elem) {
    int idx = belongs(bag->vec, elem, bag->dim, bag->cmp);
    
    if(idx >= 0) {
        bag->vec[idx].count += 1;
    }
    else {
        idx = bag->dim;
        bag->dim += 1;
        if(idx % BLOCK == 0) {
            bag->vec = realloc(bag->vec, (idx + BLOCK) * sizeof(item));
        }
        bag->vec[idx].count = 1;
        bag->vec[idx].elem = elem; // ya que trabaja con strings constantes no hace falta hacer el strcpy
    }

    return bag->vec[idx].count;
    
    
}


unsigned int count(const bagADT bag, elemType elem) {
    int idx = belongs(bag->vec, elem, bag->dim, bag->cmp);
    if(idx < 0) {
        return 0;
    }
    return bag->vec[idx].count;
}

unsigned int size(const bagADT bag) {
    return bag->dim;
}



unsigned int deleteBag(bagADT bag, elemType elem) {
    int idx = belongs(bag->vec, elem, bag->dim, bag->cmp);
    if(idx < 0 || bag->vec[idx].count == 0) {
        return 0;
    }
    if( (bag->vec[idx].count -= 1) == 0 ) {
        bag->dim -= 1;
    }
    return bag->vec[idx].count;
}



elemType mostPopular(bagADT bag) {
    if(bag->vec == NULL) {
        exit(1);
    }

    size_t idx = 0; // indice del mostPopular
    for(int i = 1; i < bag->dim; i++) {
        if(bag->vec[i].count > bag->vec[idx].count) {
            idx = i;
        }
    }

    return bag->vec[idx].elem;
}


void freeBag(bagADT bag) {
    free(bag->vec);
    free(bag);
}
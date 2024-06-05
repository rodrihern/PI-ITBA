#include "rankingADT.h"

typedef struct rankingCDT {
    elemType * vec;
    size_t dim;
    compare cmp;
} rankingCDT;




rankingADT newRanking(elemType elems[], size_t dim, compare cmp) {
    rankingADT rank = malloc(sizeof(rankingCDT));
    rank->dim = dim;
    rank->cmp = cmp;
    if(dim == 0) {
        rank->vec = NULL;
        return rank;
    }
    rank->vec = malloc(dim * sizeof(elemType));
    for(int i = 0; i < dim; i++) {
        rank->vec[i] = elems[i];
    }

    return rank;
}

// devuelve 0 si no esta, devuelve la posicion en el ranking si esta (inice + 1)
static size_t belongs(rankingADT rank, elemType elem) {
    compare fn = rank->cmp;
    for(int i = 0; i < rank->dim; i++) {
        if(fn(rank->vec[i], elem) == 0) {
            return i+1;
        }
    }
    return 0;    
}

static void moveUp(elemType v[], size_t idx) {
    if(idx == 0) {
        return;
    }
    // swap v[idx] <-> v[idx-1]
    elemType aux = v[idx];
    v[idx] = v[idx-1];
    v[idx-1] = aux;
}


void addRanking(rankingADT ranking, elemType elem) {
    size_t n;
    if((n = belongs(ranking, elem))) {
        moveUp(ranking->vec, n-1);
        return;
    }
    ranking->vec = realloc(ranking->vec, (ranking->dim + 1) * sizeof(elemType));
    ranking->vec[ranking->dim++] = elem;
}


size_t size(const rankingADT ranking) {
    return ranking->dim;
}



int getByRanking(rankingADT ranking, size_t n, elemType * elem) { 
    if(n > ranking->dim || n == 0) {
        return 0;
    }
    *elem = ranking->vec[n-1];
    moveUp(ranking->vec, n-1);
    return 1;
}



elemType * getTopRanking(const rankingADT ranking, size_t * top) {
    if(*top > ranking->dim) {
        *top = ranking->dim;
    }
    if(*top == 0) {
        return NULL;
    }
    elemType * ans = malloc(*top * sizeof(elemType));
    for(int i = 0; i < *top; i++) {
        ans[i] = ranking->vec[i];
    }

    return ans;   
}



int contains(rankingADT ranking, elemType elem) {
    size_t n = belongs(ranking, elem);
    if(n) {
        moveUp(ranking->vec, n-1);
        return 1;
    }
    return 0;
    
}



void downByRanking(rankingADT ranking, size_t n) {
    if(n >= ranking->dim) {
        return;
    }
    moveUp(ranking->vec, n); // subo de posicion el que esta uno mas abajo de n
}



void freeRanking(rankingADT r) {
    free(r->vec);
    free(r);
}




int position(const rankingADT r, elemType elem) {
    return belongs(r, elem);
}

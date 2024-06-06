#include <stdio.h>
#include <assert.h>
#include "vectorADT.h"

int cmpInts(int n1, int n2) {
    return n1-n2;
}

int main(void) {
    vectorADT v = newVector(cmpInts);
    assert(!isOccupied(v, 0));
    assert(!isOccupied(v, 100));
    assert(indexOf(v, 20)==-1);

    assert(putElement(v, 45, 50)==1);
    assert(putElement(v, 100, 50)==0);
    assert(putElement(v, 100, 500)==1);
    putElement(v, 10, 0);
    assert(indexOf(v, 100)==50);
    assert(count(v)==3);

    assert(isOccupied(v, 0));
    assert(isOccupied(v, 50));
    assert(isOccupied(v, 500));
    assert(!isOccupied(v, 499));
    assert(!isOccupied(v, 501));
    assert(!isOccupied(v, 5010000));
    assert(deleteElement(v, 3500)==0);
    assert(count(v)==3);
    assert(deleteElement(v, 500)==1);
    assert(count(v)==2);

    int n;
    assert(get(v, 50, &n)==1);
    assert(n==100);

    assert(get(v, 500000, &n)==0);
    
    freeVector(v);
    puts("OK");
    return 0;
}

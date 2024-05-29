#include <stdio.h>
#include "listADT.h"
#include <strings.h>
#include <assert.h>

// Si mi lista fuera de enteros ordenados en forma descendente
int cmpInts(int n1, int n2) {
    return n2 - n1;
}

int main(void) {
    listADT myList = newList((int (*) (char *, char*)) strcasecmp);
    assert(sizeList(myList)==0);
    assert(isEmptyList(myList));
    assert(insertList(myList, "hola")==1);
    assert(insertList(myList, "HOLA")==0);
    assert(insertList(myList, "hola y adios")==1);
    assert(sizeList(myList)==2);

    //assert(deleteList(myList, "no estoy")==0);

    insertList(myList, "aparezco solo una vez");

    toBegin(myList);
    while(validateNext(myList)) {
        puts(next(myList));
    }

    putchar('\n');
    deleteList(myList, "aparezco solo una vez");
    insertList(myList, "zzz");
    
    for(int i = 0; i < sizeList(myList); i++) {
        puts(elementAtIndex(myList, i));
    }

    freeList(myList);
    putchar('\n');

    puts("OK");
    return 0;
}
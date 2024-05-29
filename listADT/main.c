#include <stdio.h>
#include "listADT.h"
#include <strings.h>
#include <string.h>
#include <assert.h>

// Si mi lista fuera de enteros ordenados en forma descendente
int cmpInts(int n1, int n2) {
    return n1 - n2;
}

int square(int num) {
    return num * num;
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

    insertList(myList, "zz aparezco solo una vez");
    insertList(myList, "choto");

    toBegin(myList);
    while(hasNext(myList)) {
        puts(next(myList));
    }
    putchar('\n');

    /*
    PARA ENTEROS

    listADT myList = newList(cmpInts);

    insertList(myList, 4);
    insertList(myList, 4);
    insertList(myList, 3);
    insertList(myList, 10);
    */

    deleteList(myList, "hola");

    toBegin(myList);
    while(hasNext(myList)) {
        puts(next(myList));
    }
    putchar('\n');


    freeList(myList);
    putchar('\n');

    puts("OK");
    return 0;
}
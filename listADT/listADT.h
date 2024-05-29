#ifndef UNTITLED6_LISTADT_H
#define UNTITLED6_LISTADT_H

typedef struct listCDT * listADT;

typedef char * elemType;

// función para poder comparar dos elementos
// retorna
//     negativo si e1 es "menor" que e2 (e1 debe estar antes que e2)
//     cero si son "iguales" (representan lo mismo)
//     positivo si e1 es "mayor" que e2 (e1 debe estar después que e2)
typedef int (*compare) (elemType e1, elemType e2);

listADT newList(compare cmp);

//listADT newList(int (*cmp) (elemType, elemType));

void freeList(listADT list);

int isEmptyList(const listADT list);

int belongsList(const listADT list, elemType elem);

/**
 *
 * @param list
 * @param elem
 * @return 1 si lo agregó, cero si ya estaba
 */
int insertList(listADT list, elemType elem);

int deleteList(listADT list, elemType elem);

int sizeList(const listADT list);

elemType elementAtIndex(listADT list, int idx);

void toBegin(listADT list);

int validateNext(listADT list);

elemType next(listADT list);

#endif //UNTITLED6_LISTADT_H
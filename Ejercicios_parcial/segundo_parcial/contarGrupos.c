#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    char head;
    struct node * tail;
} node;

typedef node * tList;


int contarGrupos(char *s, char c);
tList fromArray(char v[], unsigned int dim );
int countGroups(tList list, char c);

int main() {
    char * s = "abbbccaadaaaa";
    tList listarda = fromArray(s, strlen(s));
    printf("%d\n", countGroups(listarda, 'a'));


    return 0;
}

int contarGrupos(char *s, char c) {
    if(s == NULL) {
        return 0;
    }
    if(*s == 0) {
        return 0;
    }

    return (s[0] == c && s[1] != c) + contarGrupos(s+1, c);
}


int countGroups(tList list, char c) {
    if(list == NULL) {
        return 0;
    }
    if(list->tail == NULL) {
        return list->head == c;
    }
    
    return (list->head == c && list->tail->head != c) + countGroups(list->tail, c);
}


tList fromArray(char v[], unsigned int dim ) {
    tList ans = NULL;
    while (dim) {
        tList aux = malloc(sizeof(node));
        aux->head = v[--dim];
        aux->tail = ans;
        ans = aux;
    }
    return ans;
}
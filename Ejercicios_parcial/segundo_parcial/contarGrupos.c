#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    char head;
    struct node * tail;
} node;

typedef node * tList;


int contarGrupos(char *s, char c);

int main() {

    printf("%d\n", contarGrupos("34abcaa33 30 0", 'x'));


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
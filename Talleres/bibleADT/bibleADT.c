#include "bibleADT.h"

#define BOOK_COUNT 76
#define BLOCK 20


typedef struct tVerse {
    char * text;
    size_t verlen;
} tVerse;

typedef struct tBook {
    tVerse * verses;
    size_t verseCount;
} tBook;

typedef struct bibleCDT {
    tBook books[BOOK_COUNT];
} bibleCDT;

bibleADT newBible() {
    return calloc(1, sizeof(bibleCDT));
}
/*
** Agrega un versículo a la Biblia. Si ya estaba ese número de versículo en ese
** número de libro, no lo agrega ni modifica y retorna 0. Si lo agregó retorna 1
** bookNbr: número de libro
** verseNbr: número de versículo
*/
static char * cpyVerse(char * s, size_t * len) {
    if(s == NULL) {
        return NULL;
    }
    int k = 0;
    char * dest = NULL;
    while(*s) {
        if(k % BLOCK == 0) {
            dest = realloc(dest, (k + BLOCK) * sizeof(char));
        }
        dest[k++] = *s++;
    }
    dest = realloc(dest, k * sizeof(char));
    dest[k] = 0;
    *len = k;
    return dest;
}

int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char * verse) {
    if(bible == NULL || bookNbr > BOOK_COUNT) {
        return 0;
    }
    if(verseNbr > bible->books[bookNbr].verseCount) {
        //hago el ralloc para agregar espacio
        bible->books[bookNbr-1].verses = realloc(bible->books[bookNbr-1].verses, verseNbr * sizeof(tVerse));
        for(int i = bible->books[bookNbr-1].verseCount; i < verseNbr; i++) {
            bible->books[bookNbr-1].verses[i].verlen = 0;
            bible->books[bookNbr-1].verses[i].text = NULL;
        }
        bible->books[bookNbr-1].verseCount = verseNbr;
    }
    if(bible->books[bookNbr-1].verses[verseNbr-1].verlen) {
        return 0;
    }
    // aca ya se que tengo espacio
    size_t len;
    bible->books[bookNbr-1].verses[verseNbr-1].text = cpyVerse(verse, &len);
    bible->books[bookNbr-1].verses[verseNbr-1].verlen = len;

    return 1;
}



/*
** Retorna una copia de un versículo o NULL si no existe.
** bookNbr: número de libro
** verseNbr: número de versículo
*/
char * getVerse(bibleADT b, size_t bookNbr, size_t verseNbr) {

}
/* Libera todos los recursos reservados por el TAD */
void freeBible(bibleADT b) {
    for(int i = 0; i < BOOK_COUNT; i++) {
        for(int j = 0; j < b->books[i].verseCount; j++) {
            free(b->books[i].verses[j].text);
        }
        free(b->books[i].verses);
    }
    free(b);
}

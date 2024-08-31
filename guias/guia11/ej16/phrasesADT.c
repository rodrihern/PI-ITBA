#include "phrasesADT.h"

#define BLOCK 20

typedef struct phrasesCDT {
    char ** phrases;
    size_t firstKey;
    size_t lastKey;
    size_t size;
} phrasesCDT;



phrasesADT newPhrasesADT(size_t keyFrom, size_t keyTo) {
    if(keyFrom > keyTo) {
        return NULL;
    }
    size_t dim = keyTo - keyFrom + 1;
    phrasesADT new = malloc(sizeof(phrasesCDT));
    new->phrases = calloc(dim, sizeof(char *));
    new->firstKey = keyFrom;
    new->lastKey = keyTo;
    new->size = 0;
    return new;
}



static char * cpyStr(const char * s) {
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
    return dest;
}

int put(phrasesADT ph, size_t key, const char * phrase) {
    if(key < ph->firstKey || ph->lastKey < key) {
        return 0;
    }
    size_t idx = key - ph->firstKey;
    ph->size += (ph->phrases[idx] == NULL);
    ph->phrases[idx] = cpyStr(phrase);

    return 1;
}



char * get(const phrasesADT ph, size_t key) {
    if(key < ph->firstKey || ph->lastKey < key) {
        return NULL;
    }
    size_t idx = key - ph->firstKey;
    return cpyStr(ph->phrases[idx]);
}



size_t size(const phrasesADT ph) {
    return ph->size;
}



static char * concatStr(char * s1, char * s2, size_t * len) {
    if(s2 == NULL || s1 == NULL) {
        return s1;
    }

    int i = *len, j = 0;
    while(s2[j]) {
        if(j % BLOCK == 0) {
            s1 = realloc(s1, (i + BLOCK) * sizeof(char));
        }
        s1[i++] = s2[j++];
    }
    s1 = realloc(s1, i * sizeof(char));
    s1[i] = 0;
    *len = i;

    return s1;
}

char * concat(const phrasesADT ph, size_t from, size_t to) {
    if(from < ph->firstKey || ph->lastKey < to || to < from) {
        return NULL;
    }
    // size_t dim = ph->lastKey - ph->firstKey + 1;
    size_t len = 0;
    char * ans = calloc(1, sizeof(char));
    for(int i = from; i <= to; i++) {
        ans = concatStr(ans, ph->phrases[i - ph->firstKey], &len);
    }

    return ans;
}



char * concatAll(const phrasesADT ph) {
    return concat(ph, ph->firstKey, ph->lastKey);
}




void freePhrases(phrasesADT ph) {
    size_t dim = ph->lastKey - ph->firstKey + 1;
    for(int i = 0; i < dim; i++) {
        free(ph->phrases[i]);
    }
    free(ph);
}

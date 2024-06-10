#include "jokesADT.h"
#include <string.h>
#include <time.h>

#define BLOCK 20

typedef struct tJoke {
    char * joke;
    size_t len;
} tJoke;

typedef struct categoryNode {
    char * categoryName;
    tJoke * jokes;
    size_t jokeCount;
    struct categoryNode * tail;
} categoryNode;

typedef categoryNode * categoryList;

typedef struct jokesCDT {
    categoryList firstCat;
    size_t categoryCount;
} jokesCDT;


jokesADT newJokes() {
    return calloc(1, sizeof(jokesCDT));
}


// retorna una copia del string s de longitud len en el heap
static char * cpyStr(const char * s, size_t len) {
    if(s == NULL) {
        return NULL;
    }
    return strcpy(malloc(len + 1), s);
}


// inserta ordenado una categoria y deja added en 1 si agrego
static categoryList insertCat(categoryList list, const char * name, int * added) {
    int c;
    if(list == NULL || (c = strcmp(list->categoryName, name)) > 0) {
        *added = 1;
        categoryList new = calloc(1, sizeof(categoryNode));
        new->categoryName = cpyStr(name, strlen(name));
        new->tail = list;
        return new;
    }
    if(c < 0) {
        list->tail = insertCat(list->tail, name, added);
    }
    return list;
}

void addCategory(jokesADT j, const char * category) {
    int added = 0;
    j->firstCat = insertCat(j->firstCat, category, &added);
    j->categoryCount += added;
}



// devuelve el puntero a la categoria o NULL si la categoria no existe
static categoryList findCategory(categoryList list, const char * name) {
    categoryList ans = NULL;
    while(!ans && list) {
        if(strcmp(list->categoryName, name) == 0) {
            ans = list;
        }
        list = list->tail;
    }
    return ans;
}

// retorna una copia del string largo s en el heap y deja en len la longitud
static char * cpyStrBlock(const char * s, size_t * len) {
    if(s == NULL) {
        return NULL;
    }
    size_t i = 0;
    char * dest = NULL;
    while(*s) {
        if(i % BLOCK == 0) {
            dest = realloc(dest, i + BLOCK);
        }
        dest[i++] = *s++;
    }
    dest = realloc(dest, i+1);
    dest[i] = 0;
    *len = i;
    return dest;
}

void addJoke(jokesADT j, const char * category, const char * joke) {
    categoryList cat = findCategory(j->firstCat, category);
    if(cat == NULL) {
        return;
    }
    // agrando el vector y agrego al final
    size_t i = cat->jokeCount++;
    cat->jokes = realloc(cat->jokes, cat->jokeCount * sizeof(tJoke));
    size_t len;
    cat->jokes[i].joke = cpyStrBlock(joke, &len);
    cat->jokes[i].len = len;
}



// genera un indice aleatorio para un array de dimension dim
static size_t randIdx(size_t dim) {
    return rand() % dim;
}

char * joke(jokesADT j, const char * category) {
    categoryList cat = findCategory(j->firstCat, category);
    if(cat == NULL || cat->jokeCount == 0) {
        return NULL;
    }
    size_t i = randIdx(cat->jokeCount);
    return cpyStr(cat->jokes[i].joke, cat->jokes[i].len);
}



// libera la memoria del vector de chistes
static void freeJokeVec(tJoke * jokes, size_t dim) {
    for(int i = 0; i < dim; i++) {
        free(jokes[i].joke);
    }
    free(jokes);
}

// libera la memoria reservada por todas las categorias
static void freeCat(categoryList cat) {
    if(cat == NULL) {
        return;
    }
    freeCat(cat->tail);
    freeJokeVec(cat->jokes, cat->jokeCount);
    free(cat->categoryName);
    free(cat);
}

void freeJokes(jokesADT j) {
    freeCat(j->firstCat);
    free(j);
}
/*
* Elimina una categoría y todos los chistes de esa categoría
*/
void deleteCategory(jokesADT j, const char * category) {
    if(j->firstCat == NULL) {
        return;
    }
    categoryList current = j->firstCat;
    categoryList prev = NULL;
    int c, found = 0;

    while(current && !found && (c = strcmp(current->categoryName, category)) <= 0) {
        if(c == 0) {
            // encontre asi que borro
            found = 1;
            if(prev) {
                prev->tail = current->tail;
            }
            else {
                j->firstCat = current->tail;
            }
            free(current->categoryName);
            freeJokeVec(current->jokes, current->jokeCount);
            j->categoryCount--;
            free(current);
        }
        if(!found) {
            prev = current;
            current = current->tail;
        }
    }

}



size_t categoriesCount(const jokesADT j) {
    return j->categoryCount;
}



char ** categories(const jokesADT j) {
    if(j->categoryCount == 0) {
        return NULL;
    }
    char ** ans = malloc(j->categoryCount * sizeof(char *));
    categoryList catIter = j->firstCat;
    for(int i = 0; i < j->categoryCount; i++) {
        ans[i] = cpyStr(catIter->categoryName, strlen(catIter->categoryName));
        catIter = catIter->tail;
    }
    return ans;
}


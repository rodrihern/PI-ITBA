#include "landmarkADT.h"
#define STEP 100

typedef struct tLandmark {
    int hasLandmark;
    landmarkType landmark;
} tLandmark;

typedef struct landmarkCDT {
    tLandmark * lmVec;
    size_t dim;
    size_t landmarkCount;
    compare cmp;
} landmarkCDT;

// devuelve el indice en el que va el landmark
static size_t toIdx(size_t meters) {
    return meters / STEP;
}

/**
* Crea una nueva colección de sitios de interés. Sólo se registrará un sitio cada
* 100 metros (uno entre los 0 y 99 metros, posiblemente otro entre los 100 y 199, etc.)
*/

landmarkADT newLandmark(compare fun) {
    landmarkADT ans = calloc(1, sizeof(landmarkCDT));
    ans->cmp = fun;
    return ans;
}

/**
* Agrega un punto de interés #site a #meters metros del origen. Si ya había
* un sitio, sólo queda #site (ver programa de testeo)
*/
void addLandmark(landmarkADT lm, size_t meters, landmarkType site) {
    size_t i = toIdx(meters);
    if(i >= lm->dim) {
        // hago el realloc llenando de 0 los hasLandmark de los nuevos elementos
        lm->lmVec = realloc(lm->lmVec, (i + 1) * sizeof(tLandmark));
        for(int j = lm->dim; j <= i; j++) {
            lm->lmVec[i].hasLandmark = 0;
        }
        lm->dim = i+1;
    }
    // aca ya se que tengo espacio
    if( ! lm->lmVec[i].hasLandmark )  {
        lm->landmarkCount++;
        lm->lmVec[i].hasLandmark = 1;
    }
    lm->lmVec[i].landmark = site;
}



landmarkType * landmarks(const landmarkADT lm) {
    if(lm->landmarkCount == 0) {
        return NULL;
    }
    landmarkType * ans = malloc(lm->landmarkCount * sizeof(landmarkType));
    int j = 0;
    for(int i = 0; i < lm->dim; i++) {
        if(lm->lmVec[i].hasLandmark) {
            ans[j++] = lm->lmVec[i].landmark;
        }
    }

    return ans;
}
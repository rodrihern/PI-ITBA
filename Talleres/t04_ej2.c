#include "../rand.h"


void shuffle(int arr[], int dim) {

    int random, aux;

    for (int i = 0; i < dim; i++) {
        random = randInt(0, dim-1);
        aux = arr[i];
        arr[i] = arr[random];
        arr[random] = aux;
    }
}


void recMinMax(int v[], int dim, int * min, int * max) {
    if(dim == 0) {
        *min = 0;
        *max = 0;
        return;
    }
    if(*v <= 0) {
        *min = -1;
        *min = -1;
        return;
    }
    if(dim == 1) {
        *min = *v;
        *max = *v;
        return;
    }

    recMinMax(v+1, dim-1, min, max);

    if(*min <= 0 || *max <= 0) {
        return;
    }

    if(*v < *min) {
        *min = *v;
    }
    else if(*v > *max) {
        *max = *v;
    }



}
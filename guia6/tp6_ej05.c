
int eliminaRepOrden( const int arr[], int dim, int out[]) {
    int dimOut = 0;
    for(int i = 0; i < dim; i++) {
        if(i == 0 || arr[i] != arr[i - 1]) {
            out[dimOut++] = arr[i];
        }
    }
    return dimOut;
}
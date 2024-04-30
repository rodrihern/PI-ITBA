#define MAXCOL 10

void swap(int v1[], int v2[], int dim) {
    int aux;
    for(int i = 0; i < dim; i++) {
        aux = v1[i];
        v1[i] = v2[i];
        v2[i] = aux;
    }
}

void ordenaMatriz (int matriz[][MAXCOL], int fil, int col, int colOrd) {
    int menor;
    for(int i = 0; i < fil - 1; i++) {
        menor = i;
        for(int j = i + 1; j < fil; j++) {
            if(matriz[j][colOrd - 1] < matriz[menor][colOrd - 1]) {
                menor = j;
            }
        }
        if(menor != i) {
            swap(matriz[i], matriz[menor], col);
        }
    }
}

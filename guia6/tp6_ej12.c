/*
quiero una funcion que trasponga una matriz
*/


void traspuesta(unsigned int dim, int matriz[dim][dim]) {
    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < i; j++) {
            int aux = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = aux;
        }
    }
}
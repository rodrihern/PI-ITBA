/*
Producto de matrices
*/
int sumatoria(int dim, const int a[][dim], const int b[][dim], int i, int j) {
    int sum = 0;
    for(int k = 0; k < dim; k++) {
        sum += a[i][k] * b[k][j];
    }
    
    return sum;
}

void productoMat(unsigned int dim, const int m1[][dim], const int m2[][dim], int m3[][dim]) {
    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            m3[i][j] = sumatoria(dim, m1, m2, i, j);
        }
    }
}
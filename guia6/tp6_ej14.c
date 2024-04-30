int estaContenido(const int v1[], unsigned int dim1, const int v2[], unsigned int dim2) {
    
    for(int i = 0; i < dim1; i++) {
        int foundIt = 0;
        for(int j = 0; j < dim2; j++) {
            if(v1[i] == v2[j]) {
                foundIt = 1;
            }
            
        }
        if(!foundIt) {
            return 0;
        }
        
    }

    return 1;
}


int contiene(const int v1[], unsigned int dim1, const int v2[], unsigned int dim2) {
    if(estaContenido(v1, dim1, v2, dim2)) {
        return 1;
    }
    if(estaContenido(v2, dim2, v1, dim1)) {
        return 2;
    }
    return 0;
}
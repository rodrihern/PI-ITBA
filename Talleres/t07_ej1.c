#define NOTA_APROBADA 4

// VER LA SOLUCION DE LA CATEDRA PARA VER SOMO HACERLO EN EL HEAP

int obtenerAprobados(char * arrNombres[], int tam, char * aprobados[], int notas[]) {
    int dimAprobados = 0;
    
    for(int i = 0; i < tam; i++) {
        if(notas[i] >= NOTA_APROBADA) {
            aprobados[dimAprobados++] = arrNombres[i];
        }
    }

    return dimAprobados;
}



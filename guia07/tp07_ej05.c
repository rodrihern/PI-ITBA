#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAX_ALUMNOS 10

// Cambiar de acuerdo al tipo elegido 
// Si usan "matriz" de chars debe quedar
// typedef char TAlumnos[MAX_ALUMNOS][MAX_LARGO];   

// Si usan vector de punteros a char debe quedar
// typedef char * TAlumnos[MAX_ALUMNOS];

typedef char * TAlumnos[MAX_ALUMNOS];

void separaCursos(char * alumnos[], char * curso, char * cursoG[], char * cursoH[]);

int main(void){

    TAlumnos alumnos={"Juan", "Pedro", "Martin", ""}, cursoG, cursoH;
    char curso[] = {'H', 'G', 'H', 0};
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[1]));
    assert(!strcmp(cursoH[0], alumnos[0]));
    assert(!strcmp(cursoH[1], alumnos[2]));
    assert(!strcmp(cursoG[1], alumnos[3]) && !strcmp(cursoH[2], alumnos[3]));   // Terminan con "" 

    alumnos[0]=""; curso[0]=0;  // Depende del tipo de alumnos, esta linea puede ser: "alumnos[0][0]=0; curso[0]=0;"
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[0]) && !strcmp(cursoH[0], alumnos[0]));

    puts("OK!");
    return 0;
}

void separaCursos(char * alumnos[], char * curso, char * cursoG[], char * cursoH[]) {
    int i, j = 0, k = 0;
    for(i = 0; curso[i]; i++) {
        switch(curso[i]) {
            case 'G':
                cursoG[j++] = alumnos[i];
                break;
            case 'H':
                cursoH[k++] = alumnos[i];
                break;
        }
    }

    cursoG[j] = alumnos[i];
    cursoH[k] = alumnos[i];
    
}


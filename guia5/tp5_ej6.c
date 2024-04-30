#include <stdio.h>
#include "../getnum.h"

int menu();
int minToMay(int c);
int mayToMin(int c);
int prtNext(int c);
int prtNextCirc(int c);

int main() {

    int c, resp;
    

    do {
        printf("ingrese un caracter(EOF para terminar): ");
        c = getchar();

        if(c != EOF) {
            int option = menu();


            switch (option) {
                case 1:
                    resp = minToMay(c);
                    break;
                case 2:
                    resp = mayToMin(c);
                    break;
                case 3:
                    resp = prtNext(c);
                    break;
                case 4:
                    resp = prtNextCirc(c);
                    break;
                default:
                    resp = 0;
                    printf("\nOpcion invalida.\n");
                    break;
            }

            if(resp != 0) {
                printf("Respuesta: %c\n\n", resp);
            }
        }
      
    } while(c != EOF);

    

}

int menu() {
    int opt;
    
    printf("\n\n1. Convertir de minuscula a mayuscula\n");
    printf("2. Convertir de mayuscula a minuscula\n");
    printf("3. Imprimir el caracter siguiente\n");
    printf("4. Imprimir la siguiente letra en forma circular\n\n");
    opt = getint("Ingrese la opcion que desee: ");

    return opt;
}

int minToMay(int c) {
    int dif = - 'a' + 'A';
    return ('a' <= c && c <='z') ? c + dif : c;
}

int mayToMin(int c) {
    int dif = - 'A' + 'a';
    return ('A' <= c && c <='Z') ? c + dif : c;
}

int prtNext(int c) {
    return c + 1;
}

int prtNextCirc(int c) {
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
        c = (c == 'z' || c == 'Z') ?  c - 'z' + 'a' : c+1;
    }
    return c;
}

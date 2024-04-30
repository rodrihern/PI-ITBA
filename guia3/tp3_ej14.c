#include <stdio.h>
#define TOUPPER - 'a' + 'A' 
#define TOLOWER - 'A' + 'a'

// devuelve 0 si no es letra, 1 si es minuscula, 2 si es mayuscula

int isLetter(int c);
int isLower(int c);


int main() {
    int esMinus = 0, menor = 127, c;

    while(isLetter(c = getchar()) || c == ' ') {
        if(isLower(c)) {
            if((c TOUPPER < menor)) {
                menor = c TOUPPER;
                esMinus = 1;
            }
        }
        else if(c != ' ') {
            if(c < menor) {
                menor = c;
                esMinus = 0;
            }
        }
    }

    printf("la menor es: %c \n", esMinus ? menor TOLOWER : menor);


}

int isLetter(int c) {
    return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

int isLower(int c) {
    return ('a' <= c && c <= 'z');
}

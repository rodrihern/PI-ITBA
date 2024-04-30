#include <stdio.h>

// claramente seria mas claro con un if pero tenia ganas de experimentar con el ternario jeje

int main() {

    printf("ingrese una letra: ");
    char c = getchar();

    printf("%c %ses una letra\n", c, (('a'<=c && c<='z')||('A'<=c && c<='Z')) ? "" : "no ");
    

    return 0;
}
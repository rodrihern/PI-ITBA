#include <stdio.h>

int main() {
    
    int a, b, c;
    a = getchar();
    b = getchar();
    c = getchar();


    if ('B'<=a && a<='Z' && a!='E' && a!='I' && a!='O' && a!='U')
        printf("El caracter %c es una consonante mayúscula \n", a);

    else if ('b'<=a && a<='z' && a!='e' && a!='i' && a!='o' && a!='u')
        printf("El caracter %c es una consonante minúscula \n", a);

    else if (('A' <= a && a <= 'Z') || ('a' <= a && a <= 'z'))
        printf("El caracter %c es una vocal \n", a);

    else
        printf("El caracter %c no es una letra \n", a);


    if (b%2 == 0)
    printf("El valor ASCII de %c es par \n", b);
        
    if ( (b - '0') % 2 == 0 )
    printf("El caracter %c representa un dígito par \n", b);
    
    if ( ('A' <= c && c <= 'Z') || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )
    printf("El caracter %c es una vocal o es mayúscula \n", c);
        
    if ( (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'b')) && c!='A' && c!='E' && c!='I' && c!='O' && c!='U' && c!='a' && c!='e' && c!='i' && c!='o' && c!= 'u')
    printf("El caracter %c no es una vocal pero es letra \n", c);

    
    return 0;
}
#include <stdio.h>
#include <stdbool.h>

//probar con 220 284

int numerosAmigos(int a, int b);
int esAmigo(int n1, int n2);

int main() {

    printf("%s\n", numerosAmigos(220, 284) ? "son" : "no son");
    return 0;
}

int numerosAmigos(int a, int b) {
    
    return esAmigo(a, b) && esAmigo(b, a);

}

int esAmigo(int n1, int n2) {
    int sum = 1;

    for(int i = 2; i * i <= n1; i++) {

        if(n1 % i == 0) {
            int a = i, b = n1/i;
            if(a == b) {
                sum += a;
            } 
            else {
                sum += a+b;
            }
            if(sum > n2) {
                return false;
            }
        }  

    }
    return sum == n2;


}
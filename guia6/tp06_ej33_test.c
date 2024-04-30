#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <ctype.h>
#include "../rand.h"
#define SWAP(x, y) int a = x; x = y; y = a;

#define MAX 100
#define ALPHA_LEN 26

void crearAlfabeto(char alpha[]);
void codificar(char * s, char * alpha, char * dest);
void decodificar(char * msg, char * alpha, char * dest);
// mezcla el string
void shuffle(char * v, int dim);


int main(void) {
  char msg[MAX];
  char dest[MAX];
  // Debemos probar con mayusculas, porque siempre decodifica a mayuscuas
  char *s = "MENSAJE A CODIFICAR";
  char *s2 = "Mensaje a codificar";
  char alpha[MAX];
  crearAlfabeto(alpha);
  codificar(s, alpha, msg);
  assert(strlen(s)==strlen(msg));
  assert(strcmp(s, msg) != 0);
  decodificar(msg, alpha, dest);
  assert(strcmp(dest, s) == 0);

  codificar(s2, alpha, msg);
  assert(strlen(s2)==strlen(msg));
  assert(strcmp(s2, msg) != 0);
  decodificar(msg, alpha, dest);
  assert(strcmp(dest, s) == 0);
  
  puts("OK");
  return 0;
}

void shuffle(char v[], int dim) {
	for(int i = 0; i < dim; i++) {
		int j = randInt(0, dim-1);
		SWAP(v[i], v[j]);
	}
}

void crearAlfabeto(char alpha[]) {
	strcpy(alpha, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	shuffle(alpha, ALPHA_LEN);
}

void codificar(char * s, char * alpha, char * dest) {
// por cada letra en source tengo que buscar el equivalente en el alpha
	int i;
	for(i = 0; s[i]; i++) {
		if( isalpha(s[i]) ) {
			int letterIdx = toupper(s[i]) - 'A';
			dest[i] = alpha[letterIdx];
		}
		else {
			dest[i] = s[i];
		}
		
	}

	dest[i] = 0;

}

void  decodificar(char * msg, char * alpha, char * dest) {
	int i;
	for(i = 0; msg[i]; i++) {
		if( isalpha(msg[i]) ) {
			char * p = strchr( alpha, toupper(msg[i]) );
			int index = p - alpha;
			dest[i] = index + 'A';
		}
		else {
			dest[i] = msg[i];
		}
		
	}

	dest[i] = 0;
}

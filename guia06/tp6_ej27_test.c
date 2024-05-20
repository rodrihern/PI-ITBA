#include <stdio.h>
#include <assert.h>
#include <string.h>
#define MAX 256

#define CHARS_DIM 256

void analize(const char * text, char * chars);
void deleteZeros(char v[]);

int main(void) {
  char chars[CHARS_DIM];
  char chars2[CHARS_DIM];
  analize("El zorro mete la cola, pero no la pata!", chars);
  assert(strcmp(" !,Eacelmnoprtz", chars)==0);
  analize("ababababab", chars2);
  assert(strcmp("ab", chars2)==0);
  
  analize("", chars);
  assert(strcmp("", chars)==0);
  analize(".............................", chars);
  assert(strcmp(".", chars)==0);
  
  puts("OK");
  return 0;
}
void deleteZeros(char v[]) {
	int j = 0;
	for(int i = 0; i < MAX; i++) {
		if(v[i] != 0) {
			v[j++] = v[i];
		}
	}

	v[j] = 0;
	
}

void analize(const char * text, char * chars) {
	//inicializamos en 0
	for(int i = 0; i < MAX; i++) {
		chars[i] = 0;
	}

	for(int i = 0; text[i]; i++) {
		chars[ (int) text[i] ] = text[i];
	}

	deleteZeros(chars);

}
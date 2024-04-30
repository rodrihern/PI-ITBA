#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#define ERROR 0
#define EXITO 1
#define CANT_VOCAL 5

int elimVocales(char * s, int m[][CANT_VOCAL], unsigned int n);
// devuelve 0 si no es vocal, 1 si es A, 2 si es E...
int isVowel(char c);

int main(void) {
  int m[6][CANT_VOCAL];
  char s[] = "las buenas ideas escasean, si";

  assert(elimVocales(s, m, 6)==EXITO);
  assert(strcmp(s, "ls bns ds scsn, s")==0);
  assert(m[0][0] == 1);
  assert(m[1][0] == 8);
  assert(m[2][0] == 14);
  assert(m[3][0] == 20);
  assert(m[4][0] == 23);
  assert(m[5][0] == -1);
  
  assert(m[0][1] == 6);
  assert(m[1][1] == 13);
  assert(m[2][1] == 17);
  assert(m[3][1] == 22);
  assert(m[4][1] == -1);

  assert(m[0][2] == 11);
  assert(m[1][2] == 28);
  assert(m[2][2] == -1);

  assert(m[0][3] == -1);

  assert(m[0][4] == 5);
  assert(m[1][4] == -1);

  strcpy(s, "las buenas ideas escasean, si");
  assert(elimVocales(s, m, 1)==ERROR);
  assert(strcmp(s, "las buenas ideas escasean, si")==0);
  assert(m[0][0]==-1);
  assert(m[0][1]==-1);
  assert(m[0][2]==-1);
  assert(m[0][3]==-1);
  assert(m[0][4]==-1);

  assert(elimVocales(s, m, 5)==ERROR);
  assert(strcmp(s, "ls bns ds scsan, s")==0);
  assert(m[0][0] == 1);
  assert(m[1][0] == 8);
  assert(m[2][0] == 14);
  assert(m[3][0] == 20);
  assert(m[4][0] == -1);
  
  assert(m[0][1] == 6);
  assert(m[1][1] == 13);
  assert(m[2][1] == 17);
  assert(m[3][1] == 22);
  assert(m[4][1] == -1);

  assert(m[0][2] == 11);
  assert(m[1][2] == 28);
  assert(m[2][2] == -1);

  assert(m[0][3] == -1);

  assert(m[0][4] == 5);
  assert(m[1][4] == -1);

  printf("OK !\n");
  return 0;
}

int isVowel(char c) {
	char vowels[] = "AEIOU";
	int vowel = 0;

	for(int i = 0; vowels[i] && !vowel; i++) {
		if(toupper(c) == vowels[i]) {
			vowel = i+1;
		}
	}

	return vowel;

}

int elimVocales(char * s, int m[][CANT_VOCAL], unsigned int n) {
	int index[CANT_VOCAL] = {0};
	int j = 0;
	int out = EXITO;

	for(int i = 0; s[i]; i++) {
		int vowel = isVowel(s[i]);
		if( vowel && index[vowel-1] < n-1 ) { // si es vocal y hay lugar
			m[index[vowel-1]++][vowel-1] = i;
		}
		else {
			if(vowel) { // porque no habia mas lugar
				out = ERROR;
			}
			s[j++] = s[i];
		}
	}

	s[j] = 0;
	

	for(int i = 0; i < CANT_VOCAL; i++) {
		m[index[i]][i] = -1; 
	}

	return out;
}
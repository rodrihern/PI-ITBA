#include <stdio.h>
#include <assert.h>
#include <string.h>
#define FIN '\0'

void
eliminaBlancos (char cadena[]);

int main(void) {
	char s[60] = "   "; // cant impar de blancos
	eliminaBlancos(s);
	assert(strcmp(s, " ")==0);

	eliminaBlancos(s);
	assert(strcmp(s, " ")==0);

	strcpy(s,"  ");
	eliminaBlancos(s);
	assert(strcmp(s, " ")==0);
	
	strcpy(s," . . .  ");
	eliminaBlancos(s);
	assert(strcmp(s, " . . . ")==0);

	strcpy(s,"");
	eliminaBlancos(s);
	assert(strcmp(s, "")==0);

	strcpy(s,"sinblancos");
	eliminaBlancos(s);
	assert(strcmp(s, "sinblancos")==0);



	printf("OK!\n");
	return 0;
}

void eliminaBlancos (char cadena[]) {
	int j = 1;
	for(int i = 1; cadena[i] != FIN; i++) {
		if( !(cadena[i] == ' ' && cadena[i-1] == ' ') ) {
			cadena[j++] = cadena[i];
		}
	}

	cadena[j] = FIN;
}
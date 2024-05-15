#include <stdio.h>
#include <assert.h>

#define MAX 10
#define DIRECTIONS 4

void reemplazo(int matriz[][MAX], int dim, int fil, int col);
void negMove(int matriz[][MAX], int dim, int fil, int col, int dir[]);

int main(void) {

	int m[5][MAX] = { 	{1,0,1,0,1},
						{0,1,1,1,1},
						{1,0,0,1,0},
						{1,1,1,0,1},
						{0,0,0,0,0}};
	
	reemplazo(m, 5, 1, 2);

	int m2[5][MAX] = { 	{1,1,1,1,1},
						{0,1,0,1,1},
						{1,1,0,0,0},
						{0,1,1,0,0},
						{0,0,0,0,0}};

	for(int i=0; i < 5; i++) {
    	for(int j=0; j<5; j++) {
			printf("%d ", m[i][j]);
		}
		putchar('\n');
	}

	putchar('\n');

	for(int i=0; i < 5; i++) {
    	for(int j=0; j<5; j++) {
			printf("%d ", m2[i][j]);
		}
		putchar('\n');
	}



	/*
	reemplazo(m, 5, 1, 2);
	reemplazo(m, 5, 1, 2);
	for(int i=0; i < 5; i++)
		for(int j=0; j<5; j++)
			assert(m[i][j]==m2[i][j]);

	printf ("OK!\n");
	*/
	return 0;
}

void reemplazo(int matriz[][MAX], int dim, int fil, int col) {
	int dir[DIRECTIONS][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

	if(matriz[fil][col]) {
		matriz[fil][col] = 0;
	}
	else {
		matriz[fil][col] = 1;
	}

	for(int i = 0; i < DIRECTIONS; i++) {
		negMove(matriz, dim, fil, col, dir[i]);
	}
}

void negMove(int matriz[][MAX], int dim, int fil, int col, int dir[]) {
	if(fil < 0 || dim <= fil || col < 0 || dim <= col ) {
		return;
	}

	if(matriz[fil][col]) {
		matriz[fil][col] = 0;
	}
	else {
		matriz[fil][col] = 1;
	}
	
	negMove(matriz, dim, fil+dir[0], col+dir[1], dir);
}





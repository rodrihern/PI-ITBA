#include <stdio.h>
#include <assert.h>

int apareados(const char * s);

int main(void) {

	assert(apareados("")==0);
	assert(apareados("()")==0);
	assert(apareados("(())()(()())")==0);
	assert(apareados("((((()))))")==0);

	assert(apareados("(")!=0);
	assert(apareados(")")!=0);
	assert(apareados("(")!=0);
	assert(apareados("())")!=0);
	assert(apareados("()(")!=0);
	assert(apareados("((()))())(")!=0);
	
	int dim=100000;
	char s[dim+1];
	for(int i=0; i<dim/2; i++) {
		s[i] = '(';
		s[dim-1-i] = ')';
	}
	s[dim]=0;
	assert(apareados(s)==0);
	for(int i=1; i < dim/100; i++) {
		assert(apareados(s+i)!=0);
	}
	
	puts("OK!");
	return 0;
}
/*
int apareadosCiclico(const char * s) {
	int count = 0;

	for(; *s && count >= 0; s++) {
		if(*s == '(')
			count++;
		else if(*s == ')')
			count--;
	}

	return count;
}
*/

int apareados(const char * s) {
	if(*s == 0) {
		return 0;
	}

	int count = apareados(s+1);
	if(count > 0) {
		return count;
	}

	return count + (*s == '(' ? 1 : -1);

}

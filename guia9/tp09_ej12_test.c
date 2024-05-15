#include <stdio.h>
#include <assert.h>

int balance(const char *texto);


int main(void) {

  assert(balance("")==0);
  assert(balance("((()))")==0);
  assert(balance(")(")==0);
  assert(balance("()()")==0);
  assert(balance(")))(((")==0);
  assert(balance("))) ((( ))( ()() ()()(")==0);
  
  assert(balance(")")!=0);
  assert(balance("(")!=0);
  assert(balance(")()")!=0);
  assert(balance(" ) ")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))((((((((((((")!=0);

  printf ("OK!\n");
  return 0;
}

int balance(const char *texto) {
	if(*texto == 0) {
		return 0;
	}

	return (*texto == '(' ? 1 : (*texto == ')') ? -1 : 0) + balance(texto+1);
	// OPCION UN POCO MAS CLARA:
	//return (*texto == '(') - (*texto == ')') + balance(texto+1);
}

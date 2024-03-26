#include <stdio.h>

struct teste{
  int x = 3;
  char nome[] = "jose";
};
main(){
  struct teste *s;
  printf("%d", s->x);
  printf("%s", s->name);
}

/* 
    O programa apresenta alguns erros de compilação:
    1. Não é possível atribuir valores à variáveis na declaração do struct, isto tem
    que ser feito na função main.
    2. A variável declarada no struct é 'nome' e a variável que está sendo acessada
    no printf é 'name'.
    3. Deve ser criada outra variável do tipo teste, para que o ponteiro '*s' possa
    apontar para esse variável.

    Ex. de código:
      #include <stdio.h>
      
      struct teste {
          int x;
      };
      
      int main() {
          struct teste pessoa, *pc;
          pc = &pessoa;
          pc->x = 10;
      
          printf("%d\n", pc->x);
      
          return 0;
      } 
*/

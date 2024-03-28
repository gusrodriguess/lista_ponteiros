// I. O resultado da impressão na linha 24 é: 7 - 7.
/* Verdadeira, a funcao1 e a funcao2 com os valores que foram passados retornam o número 7 */

// II. A função funcao1, no pior caso, é uma estratégia mais rápida do que a funcao2.
/* Falsa, a função2 é mais rapida, pois precisa fazer menos comparações para encontrar o numero 15 no vetor
em relação a funcao1 */

// III. A função funcao2 implementa uma estratégia iterativa na concepção do algoritmo
/* Falsa, a funcao2 apresenta o uso de recursividade, que é a chamada da função dentro da própria
função. A função que implementa uma estrategia iterativa é a funcao1, visto que possui um for na funcao. */

#include <stdio.h>
#define TAM 10

int funcaol(int vetor[], int v){
  int i;
  for (i = 0; i < TAM; i++){
    if (vetor[i] == v)
        return i;
    }
  return -1;
}

int funcao2(int vetor[], int v, int i, int f){
  int m = (i + f) / 2;

  if (v == vetor[m])
  return m;
  
  if (i >= f)
  return -1;

  if (v > vetor[m])
    return funcao2(vetor, v, m+1, f);
  else
    return funcao2(vetor, v, i, m-1);
}
int main(){
  int vetor[TAM] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  printf("%d - %d", funcaol(vetor, 15), funcao2(vetor, 15, 0, TAM-1));
  return 0;
}

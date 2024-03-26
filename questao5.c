#include <stdio.h>
#include <stdlib.h>

int main(void){
  float vet[5] = {1.1,2.2,3.3,4.4,5.5};
  float *f;
  int i;
  f = vet;
  printf("contador/valor/valor/endereco/endereco\n");
  for(i = 0 ; i <= 4 ; i++){
  // Valor de i (valor de cada itera��o do la�o)
    printf("i = %d",i);

  // Valor contido na posi��o i do vetor.
    printf(" vet[%d] = %.1f",i, vet[i]);

  /* Conte�do do endere�o de (f + (0, 4, 8, 12, 16)) bytes, ou seja, a cada incremento
   o ponteiro pula  4 bytes, que � o tamanho do tipo de dado que ele aponta, que no caso
   apresentado o tipo � float
  */
    printf(" *(f + %d) = %.1f",i, *(f+i));

  // O endere�o de mem�ria do valor contido na posi��o i do vetor.
    printf(" &vet[%d] = %X",i, &vet[i]);

  /* O endere�o de mem�ria de f, mas a cada incremento esse endere�o
  pula 4 bytes, que o tamanho de um valor do tipo float */
    printf(" (f + %d) = %X",i, f+i);


  printf("\n");
  }
}

/*
    Sa�da do programa:

    i = 0 vet[0] = 1.1 *(f + 0) = 1.1 &vet[0] = 61FDF0 (f + 0) = 61FDF0
    i = 1 vet[1] = 2.2 *(f + 1) = 2.2 &vet[1] = 61FDF4 (f + 1) = 61FDF4
    i = 2 vet[2] = 3.3 *(f + 2) = 3.3 &vet[2] = 61FDF8 (f + 2) = 61FDF8
    i = 3 vet[3] = 4.4 *(f + 3) = 4.4 &vet[3] = 61FDFC (f + 3) = 61FDFC
    i = 4 vet[4] = 5.5 *(f + 4) = 5.5 &vet[4] = 61FE00 (f + 4) = 61FE00

    Os valores mostrados s�o exatamente o que era esperado, pois quando o que � mostrado
    � o cont�udo, a cada incremento o ponteiro pula 4 bytes no endere�o e mostra o valor
    guardado naquele endere�o, da mesma forma � quando � mostrado o endere�o, a cada incremento
    � somado ('4 bytes' * 'o valor de i') no endere�o base, como podemos ver que na itera��o 1, 7
    o endere�o que antes era 61FDF0 mudou para 61FDF4.
*/


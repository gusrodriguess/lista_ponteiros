#include <stdio.h>
#include <stdlib.h>

int main(){
    int i=3,j=5;
    int *p, *q;
    p = &i;
    q = &j;
    
    /*A expressão retorna o número 1, visto que a expressão está comparando dois valores
    e se eles forem iguais, como é o caso, o resultado é igual a 1 que corresponde a verdadeiro.*/
    p == &i;
    
    /*O resultado da expressão é -2, pois a expressão está subtraindo o conteúdo dos endereços
    das variáveis i e j, que são 3 e 5, resultando em -2.*/
    *p - *q;
    
    /* O resultado da expressão é 3, pois é mostrado o conteúdo do conteúdo do endereço de p, ou seja,
    o conteúdo que está armazenado em p é o endereço de i e o conteúdo desse endereço é o valor 3*/
    **&p;
    
    /*O resultado da expressão é 10, pois o resultado de *p/(*q), que é o mesmo que 3/5, é igual 
    a 0 porque o tipo das duas variáveis é inteiro e quando somado o 0 a '3 + 7' o valor final é 
    igual a 10. */
    3 - *p/(*q) + 7;

    return 0;
}

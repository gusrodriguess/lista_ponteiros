#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, *p, *q;
    
    p = &i;
    *q = &j;
    p = &*&i;
    
    /* Essa expressão é ilegal, pois os parênteses fazem com que o * e &
    sejam considerados primero, devido a regra de precedência, resultando em um erro */
    i = (*&)j;  
    
    i = *&j;
    i = *&*&j;
    q = *p;
    i = (*p)++ + *q;
    
    return 0;
}

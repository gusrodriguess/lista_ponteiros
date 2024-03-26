#include <stdio.h>

/* Memory leak é um vazamento de memória que ocorre quando alocamos 
memória em C, usando malloc, realloc ou calloc, mas não liberamos. 
Então para que isso não ocorra devemos fazer o uso de ponteiros para 
armazenar onde a memória foi alocada e depois usar o 'free' para liberar
essa memória alocada que não está sendo mais utilizada */


// Exemplo 1 - A memória foi alocada, mas não foi utilizada o 'free' para liberar.
int main() {
    int *ptr = (int *)malloc(sizeof(int));
    // Algum código aqui
    return 0;
}

/* Exemplo 2 - Apenas a última alocação foi liberada, as outras alocações feitas 
dentro do 'for' ainda estão alocadas. */
int main() {
    int *ptr;
    int i;
    for (i = 0; i < 10; i++) {
        ptr = (int *)malloc(sizeof(int));
        // Algum código aqui
    }
    free(ptr);
    return 0;
}

/* Exemplo 3 - O 'free' é utilizado para liberar a memória alocada, mas o 
endereço/referência para memória foi perdida antes, ocasionando em um memory leak */
int main() {
    int *ptr = (int *)malloc(sizeof(int));
    ptr = NULL;
    free(ptr); 
    return 0;
}

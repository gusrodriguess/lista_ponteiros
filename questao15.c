#include <stdio.h>

void ordenar(int *x, int n) {
    /* Ordenação usando o conceito que qnd tem um incremento no 
    endereço pula para o proximo valor do vetor*/
    float aux;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(*(x + j) > *(x + j + 1)) {
                aux = *(x + j);
                *(x + j) = *(x + j + 1);
                *(x + j + 1) = aux;
            }
        }
   }
}

int main() {
    int n;
    printf("Digite o numero de valores: \n");
    scanf("%d", &n);

    // Alocação da memória
    float *x;
    x = malloc(n * sizeof(float));

    // Recebe os valores digitados pelo usuario
    for(int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    // Mostra os valores digitados
    printf("Valores digitados \n");
    for(int i = 0; i < n; i++){
        printf("%.1f ",x[i]);
    }
    printf("\n");

    // Ordena os valores armazenados no vetor
    ordenar(x, n);

    // Mostra os valores em ordem crescente
    printf("Valores em ordem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%.1f ", x[i]);
    }

    // Libera a mémoria alocada
    free(x);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void soma(int *v1, int *v2, int *vetor_soma, int n) {
    for(int i = 0; i < n; i++) {
        vetor_soma[i] = v1[i] + v2[i];
    }
}

int main() {
    // Recebe o tamanho dos vetores;
    printf("Digite o tamanho dos vetores: ");
    int n;
    scanf("%d", &n);

    // Faz a alocação de memória para o primeiro vetor
    int *v1;
    v1 = malloc(n * sizeof(int));

    // Recebe os valores do primeiro vetor
    printf("Digite os valores do primeiro vetor: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &v1[i]);
    }

    // Faz a alocação de memória para o segundo vetor
    int *v2;
    v2 = malloc(n * sizeof(int));

    // Recebe os valores do segundo vetor
    printf("Digite os valores do segundo vetor: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &v2[i]);
    }

    // Faz a alocação do vetor resultado
    int *vetor_soma;
    vetor_soma = malloc(n * sizeof(int));

    // Realiza a soma dos dois vetores
    soma(v1, v2, vetor_soma, n);

    // Exibe o resultado da soma
    for(int i = 0; i < n; i++) {
        printf("%d ", vetor_soma[i]);
    }

    // Libera a memória alocada dos 3 vetores
    free(v1);
    free(v2);
    free(vetor_soma);

    return 0;
}

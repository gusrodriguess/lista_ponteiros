#include <stdio.h>

// Compara os valores armazenados em a e b
int compara (int *a, int *b) {
    if (*a > *b) {
        return 1;
    } else {
        return 0;
    }
}

void sort(int *vetor, int n, int (*p)(int,int)) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            // Manda os endereços para a função 'compara' que retorna um inteiro
            if (p(&vetor[j], &vetor[j+1]) > 0) {
                // Troca os valores
                int temp = *(vetor + j);
                *(vetor + j) = *(vetor + j + 1);
                *(vetor + j + 1) = temp;
            }
        }
    }
}

int main(){

    // Define o tamanho do vetor
    int n;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);

    // Alocação da memória
    int *vetor;
    vetor = malloc(n * sizeof(int));

    // Recebe os valores do vetor
    printf("Digite os valores do vetor: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    // Ponteiro para a função 'compara'
    int (*pc) (int, int);
    pc = compara;

    // Chama a função 'sort', que ordena o vetor
    sort(vetor, n, pc);

    // Mostra o vetor ordenado
    for(int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    // Libera a memória alocada
    free(vetor);

    return 0;
}

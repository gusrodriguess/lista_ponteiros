#include <stdio.h>
#include <stdlib.h>

/* Funcao para realizar a multiplicacao das matrizes*/
void multiplicar_matrizes(int *A, int *B, int *C, int linhasA, int colunasA, int colunasB) {
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            int soma = 0;
            for (int k = 0; k < colunasA; k++) {
                soma += A[i * colunasA + k] * B[k * colunasB + j];
            }
            C[i * colunasB + j] = soma;
        }
    }
}

int main() {
    int lA, cA, cB;

    //Declarando e recebendo o tamanho das matrizes A e B

    printf("Digite o numero de linhas de A: ");
    scanf("%d", &lA);
    printf("Digite o numero de colunas de A: ");
    scanf("%d", &cA);
    printf("Digite o numero de colunas da B: ");
    scanf("%d", &cB);

    //Alocando a memoria para as Matrizes A,B e C
    int *A = malloc(lA * cA * sizeof(int));
    int *B = malloc(cA * cB * sizeof(int));
    int *C = malloc(lA * cB * sizeof(int));

    //Recebendo os valores de A e depois os valores de B;
    printf("Digite os elementos da matriz A:\n");
    for (int i = 0; i < lA; i++) {
        for (int j = 0; j < cA; j++) {
            scanf("%d", &A[i * cA + j]);
        }
    }

    printf("Digite os elementos da matriz B:\n");
    for (int i = 0; i < cA; i++) {
        for (int j = 0; j < cB; j++) {
            scanf("%d", &B[i * cB + j]);
        }
    }

    // Chamando a funcao para realizar a multiplicacao
    multiplicar_matrizes(A, B, C, lA, cA, cB);

    // Imprimindo todas as matrizes;
    printf("Matriz A:\n");
    for (int i = 0; i < lA; i++) {
        for (int j = 0; j < cA; j++) {
            printf("%d ", A[i * cA + j]);
        }
        printf("\n");
    }

    printf("Matriz B:\n");
    for (int i = 0; i < cA; i++) {
        for (int j = 0; j < cB; j++) {
            printf("%d ", B[i * cB + j]);
        }
        printf("\n");
    }

    printf("Matriz C:\n");
     for (int i = 0; i < lA; i++) {
        for (int j = 0; j < cB; j++) {
            printf("%d ", C[i * cB + j]);
        }
        printf("\n");
    }
    //Liberando memoria alocada
    free(A);
    free(B);
    free(C);

    return 0;
}

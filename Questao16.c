#include <stdio.h>
#include <stdlib.h>

//Declaracao da funcao comparar, que será usada no qsort()
int comparar(const void *a, const void *b) {

    if (*((float *)a) < *((float *)b))
        return -1;
    else if (*((float *)a) > *((float *)b))
        return 1;
    else
        return 0;
}

int main() {
    int n;
    printf("Quantos numeros serao ordenados? ");
    scanf("%d", &n);                                        // Entrada do tamannho do vetor com os n valores

    float *valores = (float *)malloc(n * sizeof(float));    //Alocacao de memoria para o armazenamento dos valores

    if (valores == NULL) {                                  // Garantindo que a alocacao de memoria ocorreu de forma correta;
        return 1;
    }

    printf("Entr com os %d valores:\n", n);
    for (int i = 0; i < n; i++) {                           // Entrada dos valores
        scanf("%f", &valores[i]);
    }

    qsort(valores, n, sizeof(float), comparar);             // Chamada da funcao qsort() e realizando a ordenacao

    printf("Vetor ordenado: \n");                           // Saída com os valores ordenados de forma crescente
    for (int i = 0; i < n; i++) {
        printf("%.2f ", valores[i]);
    }
    printf("\n");

    free(valores);                                          // Liberando a memoria alocada para armazenamento dos valores

    return 0;
}

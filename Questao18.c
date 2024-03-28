#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define TAM 1000

int RandomV(int min, int max)
{
    int k;
    srand( (unsigned)time(NULL) );
    k = (rand() % max) + min;
    return k;
}

//Declaracao da funcao comparar, que será usada no qsort()
int comparar(const void *a, const void *b) {

    if (*((float *)a) < *((float *)b))
        return -1;
    else if (*((float *)a) > *((float *)b))
        return 1;
    else
        return 0;
}

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
    // Alocação da memória
    float *x, *y;
    x = malloc(TAM * sizeof(float));
    y = malloc(TAM * sizeof(float));

    // Recebe os valores digitados pelo usuario
    for(int i = 0; i < TAM; i++) {
        x[i] = RandomV(0, TAM);
        y[i] = RandomV(0, TAM);
    }

    struct timeval start, end;

    gettimeofday(&start, NULL);

    qsort(x, TAM, sizeof(float), comparar);             // Chamada da funcao qsort() e realizando a ordenacao

    gettimeofday(&end, NULL);

    double time_qsort;

    time_qsort = (end.tv_sec - start.tv_sec) * 1e6;
    time_qsort = (time_qsort + (end.tv_usec - start.tv_usec)) * 1e-6;

    printf("Tempo de execucao qsort: %lf \n", time_qsort);

    gettimeofday(&start, NULL);

    ordenar(y, TAM);

    gettimeofday(&end, NULL);

    double time_ordenar;

    time_ordenar = (end.tv_sec - start.tv_sec) *1e6;
    time_ordenar = (time_ordenar + (end.tv_usec - start.tv_usec)) * 1e-6;

    printf("Tempo de execucao ordenar: %lf", time_ordenar);

    free(y);

    free(x);                                          // Liberando a memoria alocada para armazenamento dos valores

    return 0;
}

/*
Tempo de execucao qsort: 0.000102;
Tempo de execucao ordenar: 0.000232;

--> Pelo tempo de execução, podemos perceber uma diferenca entre as funcoes, mostrando que a utilizacao da qsort eh mais rapida, logo mais recomendada;
*/

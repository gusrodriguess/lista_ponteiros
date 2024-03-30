#include <stdio.h>
#include <stdlib.h>

void mostrarPlano(int ***m, int y, int z, int plano) {
        for(int j = 0; j < y; j++) {
            for(int k = 0; k < z; k++) {
                printf("%d ", m[plano][j][k]);
            }
            printf("\n");
        }
}

void mudarElemento(int ***m, int posX, int posY, int posZ, int elemento) {
    m[posX][posY][posZ] = elemento;
}

int main(){
    int x, y, z;

    printf("Digite o numero de planos da matriz: \n");
    scanf("%d", &x);

    printf("Digite o numero de linhas da matriz: \n");
    scanf("%d", &y);

    printf("Digite o numero de colunas da matriz: \n");
    scanf("%d", &z);


    int ***m;

    // Aloca primero bloco auxiliar
    m = malloc(x * sizeof(int**));

    // Aloca segundo bloco auxiliar
    m[0] = malloc(x * y * sizeof(int*));

    // Aloca matriz
    m[0][0] = malloc(x * y * z * sizeof(int));

    // Fixa os ponteiros
    for(int i = 0; i < x; i++) {
        m[i] = m[0] + i * y;
    }
    for(int i = 0; i < x * y; i++) {
        m[0][i] = m[0][0] + i * z;
    }

    // Preenche a matriz com valores 'aleatorios'
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            for(int k = 0; k < z; k++) {
                m[i][j][k] = rand() % 100;
            }
        }
    }

    // Recebe o valor do plano a ser mostrado
    // Se a matriz tiver dois planos por exemplo, digitar 0 para plano 1 e 1 para o plano 2
    printf("Digite o plano: \n");
    int plano;
    scanf("%d", &plano);

    mostrarPlano(m, x, y, z, plano);

    // Recebe as posicoes e o novo elemento para fazer a mudanca
    printf("Digite o plano, linha, coluna e novo elemento \n");
    int elemento;
    int posX, posY, posZ;
    scanf("%d", &posX);
    scanf("%d", &posY);
    scanf("%d", &posZ);
    scanf("%d", &elemento);

    // A mudança de elemento pode ser feita referenciando o plano, a linha, a coluna e o novo elemento
    /* Ex.: Para mudar o primeiro elemento passar os valores '0 0 0' */
    mudarElemento(m, posX, posY, posZ, elemento);

    // Exibe o plano mostrado anteriormente com o novo elemento, se o novo elemento pertencer à esse plano
    mostrarPlano(m, x, y, z, plano);

    // Libera a memória alocada
    free(m[0][0]);
    free(m[0]);
    free(m);

    return 0;
}

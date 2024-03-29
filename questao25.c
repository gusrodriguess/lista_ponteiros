#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, y, z;

    printf("Digite a altura da matriz: \n");
    scanf("%d", &x);

    printf("Digite a largura da matriz: \n");
    scanf("%d", &y);

    printf("Digite a profundidade da matriz: \n");
    scanf("%d", &z);

    int ***m;

    m = malloc(x * sizeof(int**));
    m[0] = malloc(x * y * sizeof(int*));
    m[0][0] = malloc(x * y * z * sizeof(int));

    for(int i = 0; i < x; i++) {
        m[i] = m[0] + i * y;
    }

    for(int i = 0; i < x * y; i++) {
        m[0][i] = m[0][0] + i * z;
    }

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            for(int k = 0; k < z; k++) {
                m[i][j][k] = rand() % 100;
            }
        }
    }

    free(m[0][0]);
    free(m[0]);
    free(m);
    
    return 0;
}

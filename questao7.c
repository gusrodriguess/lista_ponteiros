#include <stdio.h>

int main()
{
    int mat[4], *p, x;

    /* É válida, porque mesmo que não tenha nenhum valor no
    vetor, foi reservado um endereço de 16 bytes (tamanho do vetor * tamanho de int)
    na memoria, então 'mat + 1' pode ser acessado. */
    p = mat + 1;

    /* É válida, pois está armanezando o endereço de mat no ponteiro p,
    essa expressão é similar a expressão 'p = &mat'. */
    p = mat;

    /* Não é válida, pois o vetor foi declarado, mas não foi inicializado, ou seja,
    não tem nenhum conteúdo para ser guardado em x. */
    x = (*mat);
}


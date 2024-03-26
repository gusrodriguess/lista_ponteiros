/* O que eh um ponteiro para funcao? Um ponteiro para funcao guarda o endereco daquela funcao */

#include <stdio.h>
#include <stdlib.h>


/* Declarando funcoes para utilizacao no codigo*/
int soma(int x, int y){
    return x + y;
}

int sub(int x, int y){
    return x - y;
}

int mult(int x, int y){
    return x * y;
}

int divide(int x, int y){
    return x / y;
}

// Funcao que vai apontar para qual funcaoo iremos executar;
int calculo(int x, int y, int(*pc)(int,int)){
    return pc(x,y);
}

int main()
{
    int a = 10, b = 5, s;

    int (*p)(int,int);      // Declaracao do ponteiro para a funcao

    p = soma;               //P esta apontando para a funcao soma;

    s = calculo(a,b,p);     // Executamos a funcao calculo com o ponteiro para soma;
    printf("%d\n", s);      // Resultado da adicao dos dois numeros;

    p = divide;                // P agora aponta para divide;

    s = calculo(a,b,p);     // Executamos calculo, so que agora com ponteiro para divide;
    printf("%d\n", s);      // Resultado da divisao;

    return 0;
}

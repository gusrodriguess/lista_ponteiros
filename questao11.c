#include <stdio.h>

int main() {


    /* Se o endereço de x fosse 4092, os valores esperados para
    x+1, x+2 e x+3 seriam 4093, 4094 e 4095 */
    char x[4], *px;
    px = x;
    printf("Para o tipo char: \n");
    printf("%p\n", px);
    printf("%p\n", px + 1);
    printf("%p\n", px + 2);
    printf("%p\n", px + 3);
    printf("\n");

    /* Se o endereço de y fosse 4092, os valores esperados para
    y+1, y+2 e y+3 seriam 4094, 4098 e 4102 */
    int y[4], *py;
    py = y;
    printf("Para o tipo int: \n");
    printf("%p\n", py);
    printf("%p\n", py + 1);
    printf("%p\n", py + 2);
    printf("%p\n", py + 3);
    printf("\n");

    /* Se o endereço de z fosse 4092, os valores esperados para
    z+1, z+2 e z+3 seriam 4094, 4098 e 4102 */
    float z[4], *pz;
    pz = z;
    printf("Para o tipo float: \n");
    printf("%p\n", pz);
    printf("%p\n", pz + 1);
    printf("%p\n", pz + 2);
    printf("%p\n", pz + 3);
    printf("\n");

    /* Se o endereço de w fosse 4092, os valores esperados para
    w+1, w+2 e w+3 seriam 4100, 4108 e 4116 */
    double w[4], *pw;
    pw = w;
    printf("Para o tipo double: \n");
    printf("%p\n", pw);
    printf("%p\n", pw + 1);
    printf("%p\n", pw + 2);
    printf("%p\n", pw + 3);



    return 0;
}


/*
Saída do Programa

Para o tipo char:    Para o tipo int:    Para o tipo float:    Para o tipo double:
000000000061FDFC     000000000061FDE0    000000000061FDD0      000000000061FDB0
000000000061FDFD     000000000061FDE4    000000000061FDD4      000000000061FDB8
000000000061FDFE     000000000061FDE8    000000000061FDD8      000000000061FDC0
000000000061FDFF     000000000061FDEC    000000000061FDDC      000000000061FDC8

Obs.: Endereços estão representados em base hexadecimal.

A saída do programa corresponde aos resultados esperados, visto que quando o tipo declarado é 'char'
o endereço pula 1 byte. Para os tipos int e float, que ocupam 4 bytes de memória, os endereços pulam 4 bytes.
Já para o tipo double, o endereço pula 8 bytes, pois o tipo double ocupa 8 bytes.
*/

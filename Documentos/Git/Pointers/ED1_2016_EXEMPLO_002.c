#include<stdio.h>
#include<stdlib.h>

int main(){

    double a=5.9;
    int b=5;
    char c='a';

    double *ptr_a = &a;
    int *ptr_b = &b;
    char *ptr_c = &c;

    printf("Tamanho do Double a: %d \n", sizeof(a));
    printf("Tamanho do Int b: %d \n", sizeof(b));
    printf("Tamanho Char c: %d\n", sizeof(c));
    printf("\n");
    printf("Endereco Double a: %d \n", &a);
    printf("Endereco Int b: %d \n", &b);
    printf("Endereco Char c: %d \n", &c);
    printf("\n");
    printf("Valor Double a: %.2f \n", a);
    printf("Valor Int b: %d \n", b);
    printf("Valor Char c: %c \n", c);
    printf("\n");
    printf("Endereco Double a: %d \n", &*ptr_a);
    printf("Endereco Int b: %d \n", &*ptr_b);
    printf("Endereco Char c: %d \n", &*ptr_c);
    printf("\n");
    printf("Valor Double a: %.2f \n", *ptr_a);
    printf("Valor Int b: %d \n", *ptr_b);
    printf("Valor Char c: %c \n", *ptr_c);


}

#include<stdio.h>
#include<stdlib.h>
void teste(int x){
int y = x;
/**
Imprimir o endereco e o valor de x e y aqui

**/
    printf("Endereco de X %d \n", &x);
    printf("Endereco de Y %d \n", &y);
    printf("\n");
    printf("Valor de X %d \n", x);
    printf("Valor de Y %d \n", y);
x = 2;
/**
Imprimir o endereco e o valor de x e y aqui
**/
/**
O valor de x, declarado nesta função, foi modificado? Justifique.
O valor de y, declarado nesta função, foi modificado? Justifique.
*/
    printf("Imprimir o endereco e o valor de x e y aqui\n");

    printf("Endereco de X %d \n", &x);
    printf("Endereco de Y %d \n", &y);
    printf("\n");
    printf("Valor de X %d \n", x);
    printf("Valor de Y %d \n", y);
}

int main(){
int x = 10;
/**
Imprimir o endereco e o valor de x aqui

**/
    printf("Endereco de X %d \n", &x);
    printf("Valor de X %d \n", x);
teste(x);
/**
Imprimir o endereco e o valor de x aqui
**/
 printf("Endereco de X %d \n", &x);
    printf("Valor de X %d \n", x);

/*
O valor de x, declarado nesta função, foi modificado? Justifique.
*/
}

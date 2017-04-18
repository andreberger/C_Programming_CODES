#include <stdio.h>
#include <stdlib.h>

float resultado,n1,n2;
int op = 1;

int main()
{
        printf("CALCULADORA\n");
        printf("1 - SOMA \n");
        printf("2 - SUBTRACAO \n");
        printf("3 - MULTIPLICACAO \n");
        printf("4 - DIVISAO \n");
        printf("Informe a opcao desejada: ");
        scanf("%d",&op);

    switch(op){
        case 1:
            printf("INFORME UM NUMERO: ");
            scanf("%f",&n1);
            printf("INFORME OUTRO NUMERO: ");
            scanf("%f",&n2);
            resultado = n1+n2;
            printf("A SOMA DE %.2f + %.2f EH: %.2f", n1,n2,resultado);
        break;
        case 2:
            printf("INFORME UM NUMERO: ");
            scanf("%f",&n1);
            printf("INFORME OUTRO NUMERO: ");
            scanf("%f",&n2);
            resultado = n1-n2;
            printf("A SUBTRACAO DE %.2f - %.2f EH: %.2f", n1,n2,resultado);
        break;
        case 3:
            printf("INFORME UM NUMERO: ");
            scanf("%f",&n1);
            printf("INFORME OUTRO NUMERO: ");
            scanf("%f",&n2);
            resultado = n1*n2;
            printf("A MULTIPLICACAO DE %.2f * %.2f EH: %.2f", n1,n2,resultado);
        break;
        case 4:
            printf("INFORME UM NUMERO: ");
            scanf("%f",&n1);
            printf("INFORME OUTRO NUMERO: ");
            scanf("%f",&n2);
            resultado = n1/n2;
            printf("A DIVISAO DE %.2f / %.2f EH: %.2f", n1,n2,resultado);
        break;
    }
}

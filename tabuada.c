/**
Que calcule e mostre a tabuada de um número digitado pelo usuário
Autor: André Kroetz Berger
Março/2011
**/
#include <stdio.h>
main()
{
    int nro,cont,aux;
    printf("Digite um numero para impressao da tabuada:\n");
    scanf("%d",&nro);

    for(cont=1;cont<=10;cont++)  //laço para executar o calculo e a impressao 10x
    {
        aux = cont * nro;        //calcula a multiplicação
        printf("%d * %d = %d\n",cont,nro,aux);
    }
    system("pause");
}

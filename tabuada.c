/**
Que calcule e mostre a tabuada de um n�mero digitado pelo usu�rio
Autor: Andr� Kroetz Berger
Mar�o/2011
**/
#include <stdio.h>
main()
{
    int nro,cont,aux;
    printf("Digite um numero para impressao da tabuada:\n");
    scanf("%d",&nro);

    for(cont=1;cont<=10;cont++)  //la�o para executar o calculo e a impressao 10x
    {
        aux = cont * nro;        //calcula a multiplica��o
        printf("%d * %d = %d\n",cont,nro,aux);
    }
    system("pause");
}

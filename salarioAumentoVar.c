/**
Que receba o sal�rio de um funcion�rio e o percentual de aumento, calcule e mostre o valor do aumento e o novo sal�rio.
Autor: Andr� Kroetz Berger
Mar�o/2011
**/
#include <stdio.h>
main()
{
	float salario,aumento;
  	printf("Digite o valor do salario:\n");
  	scanf("%f",&salario);
  	fflush(stdin);
  	printf("Digite o percentual do aumento:\n");
  	scanf("%f",&aumento);

  	salario = salario + (salario * aumento/100);
  	printf("O salario com o aumanto de %0.2f perc ficou em RS%0.2\n",aumento,salario);
  	system("pause");
}

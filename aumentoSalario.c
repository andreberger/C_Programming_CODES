/**
Que receba o sal�rio de um funcion�rio, calcule e mostre o novo sal�rio,
sabendo-se que este sofreu um aumento de 25%.
Autor: Andr� Kroetz Berger
Mar�o/2011
**/
#include <stdio.h>
main()
{
  	float salario;
  	printf("Digite o valor do salario:\n");
  	scanf("%f",&salario);

  	salario = salario + (salario * 0.25);

  	printf("O salario com o aumanto de 25 perc ficou em RS%0.2f \n",salario);
  	system("pause");
}

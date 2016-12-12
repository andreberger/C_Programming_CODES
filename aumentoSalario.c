/**
Que receba o salário de um funcionário, calcule e mostre o novo salário,
sabendo-se que este sofreu um aumento de 25%.
Autor: André Kroetz Berger
Março/2011
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

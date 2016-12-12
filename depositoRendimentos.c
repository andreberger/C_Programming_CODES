/**
Programa que recebe o valor de um DEPÓSITO e o valor da taxa de JUROS, 	calcula e mostra o valor do RENDIMENTOS e o valor TOTAL depois do rendimento
Autor: André Kroetz Berger
Março/2011
**/

#include <stdio.h>
main()
{
	float deposito, juros, lucro, total;
  	printf("Digite o valor depositado:\n");
	scanf("%f",&deposito);
 	fflush(stdin);
 	printf("Digite o a taxa de juros:\n");
 	scanf("%f",&juros);
 	fflush(stdin);

 	lucro = deposito*juros/100;
 	total = deposito + lucro;

 	printf("Lucro = %0.2f e saldo = %0.2f\n", lucro,total);
 	system("pause");
}

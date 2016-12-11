/**
	ALGORITIMO QUE RESOLVE O PROBLEMA DA TORRE DE HANOI
	Programador: André Kroetz Berger
	Data: Dezembro/2016
**/
#include <stdio.h>
main()
{
	int n;
	
	printf("Informe um numero: ");
	scanf("%d", &n);
	towers(n, 'A', 'C', 'B');
}

towers(n, frompeg, topeg, auxpeg)
int n;
char auxpeg, frompeg, topeg;
{
	if (n == 1){
		printf("\n%s%c%s%c", "mover diaco 1 da estaca " , frompeg, " para a estaca ", topeg);
		return;
	}
	towers(n-1, frompeg, auxpeg, topeg);
	printf("\n%s%d%s%c%s%c", "mover disco ", n , " da estaca ", frompeg, " para a estaca " ,  topeg);
	towers(n-1, auxpeg, topeg, frompeg);
}

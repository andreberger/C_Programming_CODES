/**
Faça um programa que leia números digitados pelo usuário até ele digitar  -1 (utilizando um laço while). No final, calcule a média dos números fornecidos.
Autor: André Kroetz Berger
Março/2011
**/
#include <stdio.h>
main()
{
  int numero=0;
  float acumulaMedia=0, cont=0, media;
  while (numero != -1)
  {
    printf("Digite um numero (-1 para sair):\n");
    scanf("%d",&numero);
    if (numero != -1)
    {
       acumulaMedia = acumulaMedia + numero;
       cont = cont + 1;
    }
  }
  media = acumulaMedia/cont;
  printf("Digitou %0.0f numeros, media = %0.2f \n",cont,media);
  system("pause");
}

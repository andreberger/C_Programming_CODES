/**
Fa�a um programa que leia n�meros digitados pelo usu�rio at� ele digitar  -1 (utilizando um la�o while). No final, calcule a m�dia dos n�meros fornecidos.
Autor: Andr� Kroetz Berger
Mar�o/2011
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

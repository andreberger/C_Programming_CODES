/**
Programa que recebe horas, minutos e segundos e calcula o os segundos do dia!
Autor: André Kroetz Berger
Março/2011
**/
#include <stdio.h>
main()
{
 int hora,min,seg,resultado;
 printf("Digite as horas:\n");
 scanf("%i",&hora);
 fflush(stdin);  //para resolver um problema do scanf
 printf("Digite minutos:\n");
 scanf("%i",&min);
 printf("Digite os segundos:\n");
 scanf("%i",&seg);
 resultado = (hora * 3600) + (min * 60) + seg;
 printf("Resultado para %d:%d:%d = %d segundos\n",hora,min,seg,resultado);
 
 
 
 
 
      
 system("pause");     
}

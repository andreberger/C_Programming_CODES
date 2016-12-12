/** 
Programa Que receba uma hora (uma variável para hora e outra para minutos), calcule e mostre:
	     * A hora digitada convertida em minutos;
	     * O total dos minutos, ou seja, os minutos digitados mais a conversão anterior;
	     * O total dos minutos convertidos em segundos
Autor: André Kroetz Berger
Março/2011
**/
#include <stdio.h>
main()
{
  int hora,minutos,min,segundos;
  printf("Digite a hora e minutos:\n");
  scanf("%d%d",&hora,&minutos);

  if((hora>=0)&&(hora<24)&&(minutos>=0)&&(minutos<60)) //testar para verificar se valores corretos
  {
      system("cls"); //funcao para limpar a tela!
      printf("%dhs%d\n",hora,minutos);
      min = hora * 60;
      minutos = minutos + min;
      segundos = minutos * 60;
      printf("* Hora em minutos = %d\n",min);
      printf("* Total de minutos = %d\n",minutos);
      printf("* Total de segundos = %d\n",segundos);
  }
  else  //se for digitado alguma hora ou minuto fora do intervalo possivel, imprime o erro!
  {
    printf("Erro: Voce digitou um valor fora do intervalo possivel (%dhs%d)!\n",hora,minutos);
  }
  system("pause");
}

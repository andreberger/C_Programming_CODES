#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
int MA[2][2]={2,3,4,5};
int MB[2][2]={5,4,3,2};
int MC[2][2];
//********funcao executada pelas threads***********************************
void *funcaoThreadCelula(void * parametro)
{
 int retorno;
 switch ((int)parametro){
     case 0: retorno = MA[0][0]*MB[0][0] + MA[0][1]*MB[1][0];
             MC[0][0] = retorno;
             break;
     case 1: retorno = MA[0][0]*MB[0][1] + MA[0][1]*MB[1][1];
             MC[0][1] = retorno;
             break;
     case 2: retorno = MA[1][0]*MB[0][0] + MA[1][1]*MB[1][0];
             MC[1][0] = retorno;
             break;
     case 3: retorno = MA[1][0]*MB[0][1] + MA[1][1]*MB[1][1];
             MC[1][1] = retorno;
             break;
 }
 pthread_exit((void *)retorno);
}
//*************************************************************************
int main(int argc, char *argv[])
{
  pthread_t tid[4]; //variavel que recebe id das threads na criação
  int i;
  void * retorna; // variável que receberá retorno das threads

  for(i=0; i<4; i++)
     pthread_create(&tid[i],NULL,funcaoThreadCelula,(void *) i);
  printf("%d %d    +    %d  %d  \n",MA[0][0],MA[0][1],MB[0][0],MB[0][1]);
  printf("%d %d         %d  %d  =\n\n",MA[1][0],MA[1][1],MB[1][0],MB[1][1]);
  for(i=0; i<4; i++)
  {
     pthread_join(tid[i],&retorna);  //faz o main esperar as threads terminarem
 //    printf("O thread %d terminou e retornou o valor %d\n",i,(int)retorna);
     //printf("\n\n");

     if(i==1){
        printf("%d\n",retorna);
     } else printf("%d  ",retorna);
  }
  //printf("Passei!!!\n");
  system("pause");
  pthread_exit(NULL);
}

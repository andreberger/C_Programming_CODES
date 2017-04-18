/* Para compilar no linux: gcc inicioThread.c -lpthread */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define QTD 15   // constante que define a quantidade de threads
//********funcao executada pelas threads***********************************
void *funcaoThread(void * parametro)
{
    printf("Eu sou o thread nro: %d\n", parametro);
    pthread_exit(NULL);
}
//**************************************************************************
int main(int argc, char *argv[])
{
  pthread_t tid[QTD]; //recebe os identificadores das threads
  int i;
  for (i=0; i<QTD; i++)
  {
      printf("Criando o thread n. %d\n",i);
      pthread_create(&tid[i], NULL, funcaoThread, (void *) i);
  }
  //system("pause"); //nao termina o programa principal até o usuario determinar
  pthread_exit(NULL);
  // se nao for usada a funcao pthread_exit para terminar a main,...
  //...o ultimo thread não chega a terminar a sua execução
}

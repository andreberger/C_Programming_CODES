//para compilar no linux:  gcc programa2.c -lpthread
// para executar no linux: ./a.out
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#define LIM 15000
#define QTD 3   // constante que define a quantidade de threads
//********funcao executada pelas threads***********************************
void *funcaoVerificaPrimos(void * parametro)
{
 int primo,i,j;
 for(i=(int)parametro;i<=LIM;i+=QTD){
     primo=0;
     for(j=i-1;j>=2;j--)
            if(i%j==0){
                    primo++;
                    break;
            }
     if(!primo) printf("Eh Primo -->%d thr=%d \n",i,(int)parametro);
 }
 pthread_exit(NULL);
}
//*************************************************************************
int main(int argc, char *argv[])
{
  pthread_t tid[QTD]; //variavel que recebe id das threads na criação
  int i;

  for(i=2; i<=QTD+1; i++)
  {
     //printf("===%d====\n",i);
     pthread_create(&tid[i-3],NULL,funcaoVerificaPrimos,(void *) i);
  }
  for(i=0; i<QTD; i++)
  {
     pthread_join(tid[i],NULL);
  }

  pthread_exit(NULL);
}

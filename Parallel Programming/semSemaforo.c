#include <pthread.h>
#include <stdio.h>
#define QTD 2 //quantidade de threads
int var;      //variavel global modificada por todas as threads
//**************************************************************************
void * process(void * arg)
{
  int i;
  printf("Iniciando thread %d\n",(int) arg);
  for(i=0;i < 1000000;i++){
    var ++;
  }
  pthread_exit(NULL);
}
//**************************************************************************
int main()
{
  int i;
  pthread_t thr[QTD];
  void * retval;
  var = 0;
  for(i=0;i<QTD;i++)
  {
     pthread_create(&thr[i], NULL, process,(void*) i);
  }
  for(i=0;i<QTD;i++)
  {
     pthread_join(thr[i],NULL);
  }
  printf("var = %d \n", var);
  pthread_exit(NULL);
  //system("pause");
}


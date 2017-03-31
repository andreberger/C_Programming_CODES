#include <pthread.h>
#include <semaphore.h>


#define QTD 10 //quantidade de threads
sem_t SEMAFORO;

int var;      //variavel global modificada por todas as threads
//**************************************************************************
void * process(void * arg)
{
  int i;
  printf("Iniciando thread %d\n",(int) arg);
  sem_wait(&SEMAFORO);
  for(i=0;i<1000000;i++)
    var++;
  sem_post(&SEMAFORO);
  pthread_exit(NULL);
}
//**************************************************************************
int main()
{
  int i;
  pthread_t thr[QTD];

  //O par�metro 2 indica se o sem�foro ser� usado somente dentro do processo
  //(par�metro zero) ou se ser� usado para sincronizar processos diferentes
  //(par�metro igual a um).
  //J� o par�metro 3 indica o valor inicial do sem�foro - normalmente 1.

  sem_init(&SEMAFORO,0,1);
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
}


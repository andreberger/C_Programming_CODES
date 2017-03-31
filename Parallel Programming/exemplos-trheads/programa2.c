/*para compilar gcc -o programa2 programa2.c -lpthread */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *ocupa_tempo(void *null)
{
 int i,j;
 for (i=0;i<50000;i++)
   j+=i;
 pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t threads[5];
  pthread_attr_t attr;
  int s,i,estado;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  for(i=0; i<5; i++){
     printf("A criar o thread %d\n",i);
     s=pthread_create(&threads[i], &attr,ocupa_tempo, NULL );
     if (s){
        perror("Erro ao criar o thread");
        exit(-1);
     }
  }
  pthread_attr_destroy(&attr);
  for(i=0; i<5; i++){
     s=pthread_join(threads[i], (void **) &estado);
     if (s){
        perror("Erro no join");
        exit(-1);
     }
     printf("O thread %d terminou com o estado %d\n",i,estado);
  }
  pthread_exit(NULL);
}


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/* definição das variáveis globais */
int balanco=10000;
pthread_t threads[2];
pthread_mutex_t mutex_balanco;
void *deposita(void *valor)
{
   int i,*a= (int *) valor;
      /*fecha a variável mutex_balanco. Se já estiver fechada espera até
que seja possível fechar*/
   pthread_mutex_lock(&mutex_balanco);
       balanco += *a;
/* abre a variável mutex_balanco */
   pthread_mutex_unlock(&mutex_balanco);
   pthread_exit(NULL);
}

void *saque(void *valor)
{
   int i, *b= (int *) valor;
   /*fecha a variável mutex_balanco. Se já estiver fechada espera até
que seja possível fechar*/
   pthread_mutex_lock(&mutex_balanco);
      balanco -= *b;
   /* abre a variável mutex_balanco */
   pthread_mutex_unlock(&mutex_balanco);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   int i,s,estado,depositar=6000,sacar=5000;
   /* inicializa a variável mutex_balanco utilizando os valores por defeito */
   pthread_mutex_init(&mutex_balanco, NULL);
   pthread_create(&threads[0],NULL,deposita,(void *)&depositar);
   pthread_create(&threads[1],NULL,saque,(void *)&sacar);
   for(i=0; i<2; i++)
   {          
      s=pthread_join(threads[i], (void **) &estado);
      if (s) {
         perror("Erro no join");
         exit(-1);
      }
      printf("O thread %d terminou com o estado %d\n",i,estado);
    }
    printf("O balanco eh =  %d\n",balanco);
    pthread_mutex_destroy(&mutex_balanco);
    pthread_exit(NULL);
    
    system("pause");   
}

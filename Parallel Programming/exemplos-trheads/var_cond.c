#include <pthread.h>
#include <stdio.h>

/* definição das variáveis globais */
int contador=0;
pthread_cond_t condicao_contador;
pthread_t threads[3];
pthread_mutex_t mutex_contador;

void *incrementa(void *valor)
{
      int i,j;
      for(i=0;i<50;i++)
      {
            pthread_mutex_lock(&mutex_contador);
            contador++;
            printf(?O valor do contador e? %d\n?,contador);
            if (contador == 10)
            {
                  pthread_cond_signal(&condicao_contador);
                  printf(?O valor do contador e? 10\n?);
            }
            pthread_mutex_unlock(&mutex_contador);

            for(j=0;j<2000;j++);        
     }

     pthread_exit(NULL);
}

void *espera(void *valor)
{
      printf(?O thread está à espera que o valor do contador seja 10\n?);
      /* Fecha a variável mutex e espera pelo sinal. Nota: a função pthread_cond_wait abre automaticamente a variável mutex para que possa ser usada por outros threads enquanto espera. Também é necessário salientar que se o valor de contador já for 10, o ciclo não é feito, evitando assim uma situação em que o thread ficaria eternamente à espera de um sinal */

      pthread_mutex_lock(&mutex_contador);
      while (contador < 10)
	{    
           pthread_cond_wait(&condicao_contador,&mutex_contador);
           /* quando esta função receber o sinal, fecha a variável mutex */
           printf(?O thread recebeu o ?sinal?\n?);
        }
        printf(?O contador tem o valor 10\n?);
        pthread_mutex_unlock(&mutex_contador)
        pthread_exit(NULL);
}

void main()
{
      int i,s,estado;
      /* inicializa a variável mutex_balanco utilizando os valores por defeito */
      pthread_mutex_init(&mutex_contador, NULL);
      pthread_cond_init(&condicao_contador,NULL);
      pthread_create(&threads[0],NULL,incrementa,NULL);
      pthread_create(&threads[1],NULL,incrementa,NULL);
      pthread_create(&threads[2],NULL,espera,NULL);

      for(i=0; i<3; i++)
      {          
        s=pthread_join(threads[i], (void **) &estado);
        if (s)
        {
            perror("Erro no join");
            exit(-1);
        }
        printf("O thread %d terminou com o estado %d\n",i,estado);
      }
      pthread_mutex_destroy(&mutex_contador);
      pthread_cond_destroy(&condicao_contador);
      pthread_exit(NULL);
}

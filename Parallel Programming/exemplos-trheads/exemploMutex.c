/*Exemplo Pthreads - do Livro Parallel Programming Techniques & Applications 
Using Networked Workstations & Parallel Computers 2nd ed., 
by B. Wilkinson & M. Allen, ã 2004 Pearson Education Inc. 
N threads criadas, cada uma buscando números de uma lista e somando os mesmos
Quando todos os números da lista forem tratados, as threads podem somar
os seus resultados parciais para um somatorio compartilhado global. 
A variável compartilhada global_index é utilizada por todas as threads para 
selecionar O próximo elemento da lista. Após do índice ser lido, ele é 
incrementado na preparação para a próxima leitura.
O resultado do somatório também terá de ser compartilhado e o acesso protegido.
All rights reserved.*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define array_size 1000
#define no_threads 10
/* dados compartilhados */
int a[array_size]; /* vetor de numeros para somatório */
int global_index = 0; /* indice global */
int sum = 0; /* resultado final, also usado pelas slave threads */
pthread_mutex_t mutex1; /* variavel da exclusão mutua - mutex */
/********** Funçao executada pelas Slave threads**********/
void *slave(void *ignored) 
{
 int local_index, partial_sum = 0;
 do {
    pthread_mutex_lock(&mutex1);/* protege antes de pegar o proximo indice no vetor */
      local_index = global_index;/* lê o indice e salve em variável local*/
      global_index++; /* incrementa indice global */
    pthread_mutex_unlock(&mutex1); /*libera mutex*/
    if (local_index < array_size) 
        partial_sum += a[local_index];  /*(a + local_index);*/
 } while(local_index < array_size);
 pthread_mutex_lock(&mutex1); /* protege somatório global, antes de ler */
  sum += partial_sum;           /* incrementa somatorio global*/
 pthread_mutex_unlock(&mutex1); /* libera mutex*/
 return (); /* Thread exits */
}

/***************Programa Principal********************+**/
main () 
{
 int i;
 pthread_t thread[10]; /* threads */
 pthread_mutex_init(&mutex1,NULL); /* initialize mutex */
 for (i = 0; i < array_size; i++) /* initialize a[] */
      a[i] = i+1;
 for (i = 0; i < no_threads; i++) /* create threads */
     if (pthread_create(&thread[i], NULL, slave, NULL) != 0)
     {
         printf("Pthread_create falhou");
         exit(0);
      }
 for (i = 0; i < no_threads; i++) /* join threads */
     if (pthread_join(thread[i], NULL) != 0)
     {
         printf("Pthread_join falhou");
         exit(0);
      }
 printf("A soma de 1 ateh %i eh %d\n", array_size, sum);
 system("pause");
} /* end of main */

/*Saida esperada
A soma de 1 ateh 1000 eh 500500 */

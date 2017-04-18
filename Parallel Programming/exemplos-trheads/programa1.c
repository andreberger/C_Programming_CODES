/* Para compilar: gcc -o programa1 programa1.c -lpthread */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void *escreve(void *numero)
{
    int *n =(int *) numero;
    printf("Eu sou o thread nro: %ld\n",*n);
    pthread_exit(NULL);
}
/////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
    pthread_t threads[3];
    int s,i,id[3]={1,2,3};
    for (i=0; i<3; i++)
    {   
        printf("Criando o thread n. %d\n",i);
        s=pthread_create(&threads[i], NULL, escreve, (void *) &i);
        //sleep(1);
        if (s)
        {
            printf("Erro na iteracao %d\n",i);  
            perror("Erro ao criar o thread");
            exit(-1);
        }
    }
   pthread_exit(NULL);
   system("pause");
 /* se nao for usada a funcao pthread_exit para terminar a main, o ultimo thread não chega a terminar a sua execução */
}

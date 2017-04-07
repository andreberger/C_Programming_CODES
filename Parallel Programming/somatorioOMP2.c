#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#define DIM 1024

int main(int argc, char ** argv){
float *A, *B, *C;

int i;
A = malloc (DIM * sizeof (float));
B = malloc (DIM * sizeof (float));
C = malloc (DIM * sizeof (float));
if (A==NULL || B==NULL || C==NULL){
   printf("Erro na alocação de memória");
   return 0;
}
for(i=0;i<DIM;i++){
   A[i] = 2;
   B[i] = 3;
}
#pragma omp parallel
{
  int id = omp_get_thread_num();
  int i;
  #pragma omp for
  for(i=0; i<DIM; i++)
     printf("Thread %d somou posicao %d\n",id,i);
     C[i]=A[i] + B[i];
}
//for(i=0;i<DIM;i++)
  // printf("C[%d]=%.1f\n",i,C[i]);
}

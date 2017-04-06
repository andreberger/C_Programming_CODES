#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#define DIM 10000000

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
  int nt = omp_get_num_threads();
  int size = DIM/nt;
  int ini = size *id;
  int fim = ini + size -1;
  int i;
  for(i=ini;i<=fim;i++)
     C[i]=A[i] + B[i];
}
//for(i=0;i<DIM;i++)
  // printf("C[%d]=%.1f\n",i,C[i]);
}

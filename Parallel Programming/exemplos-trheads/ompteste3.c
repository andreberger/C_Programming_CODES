#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){
	printf("Oi-fora-reg par\n");

	omp_set_num_threads(8);
  	#pragma omp parallel
	{
		int tid = omp_get_thread_num();
		int nth = omp_get_num_threads();
		sleep(1);
		printf("1 sou thr %d de %d\n",tid,nth);
	}
	printf("oi-depois\n");

	#pragma omp parallel
        {
                int tid = omp_get_thread_num();
             	int nth = omp_get_num_threads();
                printf("2 sou thr %d de %d\n",tid,nth);
         }      

}

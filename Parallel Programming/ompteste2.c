#include <omp.h>
#include <stdio.h>

int main(int argc,char **argv){
	printf("Oi-fora-reg par\n");

  	#pragma omp parallel
	{
		int tid = omp_get_thread_num();
		int nth = omp_get_num_threads();
		printf("Oi mundo! %d, %d\n",tid,nth);
	}
	printf("oi-depois\n");
}

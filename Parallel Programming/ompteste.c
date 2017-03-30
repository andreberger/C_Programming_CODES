#include <omp.h>
#include <stdio.h>

int main(int argc,char **argv){
	printf("Oi-fora-reg par\n");

  	#pragma omp parallel
	{
		printf("Oi mundo!\n");
	}
	printf("oi-depois\n");
}

#include <omp.h>
#include <stdioh>

int main (int argc, char *argv[]){
	
	float A[2048];
	float B[2048];
	float C[2048];

	int i;

	for (i = 0 ; i < 20148 ; i++)
	{
		A[i] = 2;
		B[i] = 3;
	}

	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		int nt = omp_get_num_threads();
		int size = (int) 2048/nt;
		int ini = id*size;
		int fim = ini + size -1;

		int i;

		for (i = ini ; i <= fim ; i++)
		{
			C[i] = A[i] + B[i];
		}
	}

	for (i = 0 ; i < 2048 ; i++)
	{
		printf("C[%d] = %f\n" , i , C[i]);
	}

	return 0;
}

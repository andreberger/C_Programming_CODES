#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> ///// tempo

#define ARRAY_SIZE 1000
#define QTD_THREAD 100
//typedef int matrix_t [ARRAY_SIZE][ARRAY_SIZE];
typedef struct {
     int row;
     int qtdrow;
     int **MA;
     int **MB;
     int **MC;
}matrix_work_order_t;
//______________________________________________________________________________
//Rotina para gerar uma semente randômica
void inicializa_rand()
{
  int stime;
  long ltime;
  ltime=time(NULL);
  stime=(unsigned) ltime/2;
  srand(stime);
}
/*Routine to multiply a row by a column and place element in the result matrix*/
/* PARAMETROS DA FUÇÃO: size of the matrix, row of result to compute,
column of result to compute, input matrix, input matrix, result matrix */
void mult(int row, int column, int **MA, int **MB, int **MC)
{
     int position;
     MC[row][column] = 0;
     for(position=0; position < ARRAY_SIZE; position ++)
       MC[row][column]=MC[row][column]+(MA[row][position]*MB[position][column]);

}

//funçao da thread--------------------------------------------------------------
void * peer_mult(void * ref_matrix)
 {
    int column;
    int qtd;
    int row;
    int posfim;
    int i;
    matrix_work_order_t * work_orderp;
    work_orderp = (matrix_work_order_t *) ref_matrix;
    row = (work_orderp->row);
    qtd = (work_orderp->qtdrow);
    posfim = row + qtd;

    for (i = row; i < posfim; i++ ) {
        for (column = 0; column < ARRAY_SIZE; column ++){
          mult(i, column,(work_orderp->MA),(work_orderp->MB),(work_orderp->MC));
        }
    }
    free(work_orderp);
    return NULL;
 }
//______________________________________________________________________________
// Programa Principal - Matrix_Multiply
// Main: aloca matrizes, associa valoeres randomicos e calcula os resultados
int main (void){
  int row, column;
  int id,i;
  int qtdrow;
  int th;
  FILE * result;
  int inicio, fim;
  int **MA, **MB, **MC;

  qtdrow = ARRAY_SIZE/QTD_THREAD;
  matrix_work_order_t *work_orderp;

  pthread_t * peer;
  struct timeval st, et;  //////tempo
  int tempoGasto;        //////tempo
  //gettimeofday(&st, NULL); /////tempo antes de executar
  inicializa_rand();   // semente randomica!
  peer = (pthread_t *) malloc (sizeof(pthread_t) * QTD_THREAD);

  MA =  (int **) malloc (sizeof(int) * ARRAY_SIZE); //alocacao dinamica da matA
  for (i = 0; i < ARRAY_SIZE; i++)
       MA[i] = (int *) malloc (sizeof (int)* ARRAY_SIZE); // fim da alocacao

  MB =  (int **) malloc (sizeof(int) * ARRAY_SIZE); //alocacao dinamica da matB
  for (i = 0; i < ARRAY_SIZE; i++)
       MB[i] = (int *) malloc (sizeof (int)* ARRAY_SIZE); // fim da alocacao

  MC =  (int **) malloc (sizeof(int) * ARRAY_SIZE); //alocacao dinamica da matC
  for (i = 0; i < ARRAY_SIZE; i++)
       MC[i] = (int *) malloc (sizeof (int)* ARRAY_SIZE); // fim da alocacao
    //printf( "Tempo gasto st = %d ms \n", st.tv_sec);/////tempo
    //Inicialização das Matrizes
  for (row=0; row<ARRAY_SIZE; row ++)
     for (column=0;column<ARRAY_SIZE;column++){
            MA[row][column] = rand()%20;
            MB[row][column] = rand()%20;
         }
  /* Process matrix, by row, column */
 //  gettimeofday(&st, NULL); /////tempo antes de executar
  inicio = clock();
  //*************************************************
  for (th = 0; th < QTD_THREAD; th ++){
   work_orderp = (matrix_work_order_t *) malloc(sizeof(matrix_work_order_t));
   work_orderp->row = th*qtdrow;
   work_orderp->qtdrow = qtdrow;
   work_orderp->MA = MA;
   work_orderp->MB = MB;
   work_orderp->MC = MC;
   pthread_create (&(peer[th]), NULL, (void *) peer_mult, (void *) work_orderp);
  }

	/* wait for peers to exit */
	for (i = 0; i < QTD_THREAD; i++)
            pthread_join (peer[i], NULL);

//Impressão das matriz com o resultado

 //   gettimeofday(&et, NULL); //////tempo depois da execucao
    fim = clock();
    printf("Tempo em milli = %d ms, segundos = %0.2f seg\n",fim, fim/1000.0);

    //printf( "Tempo gasto et = %d  \n", et.tv_sec);/////tempo
//    tempoGasto =(et.tv_sec - st.tv_sec )*1000 + (int) ((double)( et.tv_usec - st.tv_usec )*1.0e-3); /////tempo
//    printf( "Tempo em mileseg = %d ms, em seg = %f e em min = %f\n", tempoGasto, tempoGasto/1000.0, (tempoGasto/1000.0)/60);/////tempo

///////    result = fopen("resultMatrix.txt","a+");

///////    fprintf(result,"%d threads, matriz %dx%d - Tempo em mileseg = %d ms, em seg = %f e em min = %f\n", QTD_THREAD, ARRAY_SIZE, ARRAY_SIZE, tempoGasto, tempoGasto/1000.0, (tempoGasto/1000.0)/60);/////tempo

////////    fclose(result);

 //  printf("Matriz: O resultado da matriz C eh: \n");
//
//    for (row = 0; row < ARRAY_SIZE; row++){
//       for (column=0; column<ARRAY_SIZE; column++)  {
//            printf("%5d ", MC[row][column] );
//        }
//        printf("\n ");
//    }

//	return 0;
    free(MA);
    free(MB);
    free(MC);
    free(peer);
    system("pause");
}


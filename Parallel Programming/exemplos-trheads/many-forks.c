#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>



void
MyProc()
{

  exit(0);
}




int main(int argc, char *argv[])
{
  int i, nprocs;
  struct timeval st, et;
 
  int s, status;
  int elapsedtime;

  if( argc != 2 ) goto usage;

  nprocs = atoi( argv[1]);

  
  gettimeofday(&st, NULL); //Captura a hora

  for(i = 0; i < nprocs; i++) {
    s = fork();
    if(s == 0) {
          MyProc();
          exit(0);
    }
    else
      if ( s < 0){
	printf("i = %d \n", i);
	perror(" fork ");
	exit(1);
      }
     
 }


  for(i = 0; i < nprocs; i++) 
    wait(&status);

  gettimeofday(&et,NULL); //captura a hora

  elapsedtime =  (et.tv_sec - st.tv_sec )*1000 +
                   (int) ((double)( et.tv_usec - st.tv_usec )*1.0e-3);

  printf( "elapsed time = %d ms, each fork = %f \n", 
	  elapsedtime, (double)elapsedtime/(double)nprocs);

  exit(0);

usage:
  printf("Usage: %s nprocs\n", argv[0]);
  exit(1);

}

















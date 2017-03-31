#include <stdio.h>
#include <unistd.h>
int main()
{
	int teste,ret;
	ret=fork();
	if(ret==0){
       	  while(1){
		printf("-");
	  }
	}
	else{
	   while(1){
		printf("*");
	   }
	}
}

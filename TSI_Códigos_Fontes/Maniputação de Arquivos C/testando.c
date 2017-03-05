#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
main() {
     char teste[20]="Teste";
     char *p;
     printf("Procurando por e \n");
     p=strchr(teste,'e');
     printf("Enconteri e em %d \n", p -teste +1);
     /* O Proximo*/
     p=strchr(p+1, 'e');
     printf("Encontrei o prox em %d \n", p -teste +1);
     system("pause");
}

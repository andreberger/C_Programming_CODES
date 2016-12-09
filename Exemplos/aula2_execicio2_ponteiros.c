#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[4] = {1,2,3,4};
    int *ptr_vet = vet;

    printf("\t PRIMEIRA IMPRESSAO \n");
    printf("%d \n",vet);
    printf("%d \n",ptr_vet);
    printf("%d \n",&vet[0]);
    printf("%d \n",vet[0]);
    printf("%d \n",*ptr_vet);

    printf("%d \n",vet);
    printf("%d \n",ptr_vet);
    printf("%d \n",&vet[0]);
    printf("%d \n",vet[0]);
    printf("%d \n",*ptr_vet);
    ptr_vet++;



}

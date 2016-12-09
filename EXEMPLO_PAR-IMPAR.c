#include<stdio.h>

int main(){

    int vet1[10];
    int vet2[10];
    int vet3[10];

    int x;

   for (x = 0; x < 10; x++){
        printf("Informe Valor %d: ",x);
        scanf("%d",&vet1[x]);
    }
    for (x = 0; x < 10; x++)
    {
        if(vet1[x] % 2){

            printf("%d - Impar! \n",vet1[x]);

        }else{

            printf("%d - PAR! \n",vet1[x]);

        }
    }
}

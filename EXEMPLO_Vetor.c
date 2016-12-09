#include<stdio.h>

int main()
{
    int vet[10];
    int x;

    for (x = 0; x < 10; x++){
        printf("Informe Valor %d: ",x);
        scanf("%d",&vet[x]);
    }

    printf("\n MOSTRANDO VALORES DO VETOR \n");
    //Imprimir

    for (x = 0; x < 10; x++){
        printf("Posicao do Vetor [%d] = %d \n",x,vet[x]);

    }

}

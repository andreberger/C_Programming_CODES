/**
    Escreva um programa para ler em um vetor 15 numeros inteiros. O programa deverá exibir a soma e a média dos números fornecidos.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM_VET 15

main()
{
    int vet1[TAM_VET];
    int media = 0 ;
    int soma = 0;
    int x;

    for(x=0;x<TAM_VET;x++)
    {
        printf("Infome um numero para a posicao do Vetor %d: ", x);
        scanf("%d",&vet1[x]);
        soma+=vet1[x];
        media = soma / TAM_VET;
    }
        printf("Soma: %d \n", soma);
        printf("Media: %d \n", media);
}


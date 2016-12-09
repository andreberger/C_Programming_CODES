/**
    LABORATÓRIO DE PROGRAMAÇÃO
    Nome: André Kroetz Berger

    Escreva um algoritmo que leia dois vetores de 10 posições e faça a multiplicação dos elementos de mesmo índice,
    colocando o resultado em um terceiro vetor. Mostre o vetor resultante.
**/
#include <stdio.h>
#include <stdlib.h>
#define TAM_VET 10

main()
{
    int x,mult;
    int vet1[TAM_VET] = {0,1,2,3,4,5,6,7,8,9};
    int vet2[TAM_VET] = {9,8,7,6,5,4,3,2,1,0};
    int vet3[TAM_VET];

    for (x=0;x<10;x++)
    {
        vet3[x] = vet1[x] * vet2[x];
        printf("%d x %d = %d \n", vet1[x],vet2[x],vet3[x]);
    }
    system("PAUSE");
}

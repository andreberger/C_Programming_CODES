/**
     LABORATORIO DE PROGRAMACAO
     Escreva um algoritmo que leia um vetor de 10 elementos.
     A seguir, o algoritmo deverá trocar o 1º elemento com o 6 º, o 2 º com o 7 º... etc
     até o 5 º com 10 º e escrever o vetor modificado.
**/

#include <stdio.h>
#include <stdlib.h>
#define TAM_VET 10
main()
{
    int vet1[TAM_VET];
    int num;
    int x;

    for(x=0;x<TAM_VET;x++){
        printf("Digite o %d numero para o vetor 1: ", x);
        scanf("%d", &num);
        vet1[x] = num;
    };


    for(x=0;x<TAM_VET;x++){
        if(x<5){
            num = vet1[x+5];
            vet1[x+5] = vet1[x];
            vet1[x] = num;
        }
    };

    printf("O resultado da inversao dos vetores ficou:\n");

    for(x=0;x<TAM_VET;x++){
        printf("%d, ", vet1[x]);
    };
    printf("\n\n");


}

/**
     LABORATORIO DE PROGRAMACAO
     Escreva um algoritmo que leia um vetor de 10 elementos.
     A seguir, o algoritmo dever� trocar o 1� elemento com o 6 �, o 2 � com o 7 �... etc
     at� o 5 � com 10 � e escrever o vetor modificado.
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

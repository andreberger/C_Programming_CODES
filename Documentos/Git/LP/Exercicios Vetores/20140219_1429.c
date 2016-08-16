/**
Escreva um programa com um vetor, chamado num, inicializado como: int num[20] = {1, 3, 5};
Como pode ser observado, o vetor tem tamanho 20 mas foram fornecidos apenas 3 valores.
O programa dever‡ preencher o restante do vetor usando a seguinte f—rmula: num[i] = num[0]+num[1]+num[2]+É+num[i-1],
para i=3,É19. Ap—s preencher o vetor, apresente o vetor resultante.
**/

#include <stdio.h>
#include <stdlib.h>
#define TAM_VET 20

main()
{
    int num[TAM_VET] = {1, 3, 5};
    int x,y;
    int soma = 0;

    for(x=3;x<TAM_VET;x++){
        for(y=0;y<x;y++){
            if(y!=x){
                num[x] += num[y];
            }
        }
    }

    for(x=0;x<TAM_VET;x++){
        printf("Posicao %d: \n", num[x]);
    }

}

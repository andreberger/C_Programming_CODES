/**
Dada uma matriz A (5 X 5) de números inteiros, criar um programa em C que apresente o menu abaixo:
1 - Apresentar a média dos elementos da matriz.
2 - Apresentar o maior número existente na matriz.
3 - Apresentar o menor número existente na matriz.
0 - Sair
O programa deverá calcular e apresentar o resultado do item do menu solicitado pelo usuário.
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

int main()
{

    int menu, l, c;
    int m1 [TAM][TAM];
    int soma;
    int media = 0;

    for(l=0;l<TAM;l++)
    {
        for(c=0;c<TAM;c++)
        {
            printf("Informe um numero para [%d][%d]: ", l,c);
            scanf("%d",&m1[l][c]);
        }
    }

    printf("*************** BEM VINDO AO SISTEMA ***************\n");
    printf("1 - Apresentar a media dos elementos da matriz.\n");
    printf("2 - Apresentar o maior numerio existente na amatriz.\n");
    printf("3 - Apresentar o menor numero existente na matriz.\n");
    printf("0 - Sair\n");
    printf("****************************************************\n");
    printf("Informe a Opcao desejada: ");
    scanf("%d",&menu);


    switch (menu)
    {
        case 1:
            for(l=0;l<TAM;l++)
            {
                for(c=0;c<TAM;c++)
                {
                    soma+=m1[l][c];
                    //printf("%d", m1[l][c]);
                }
            }
            printf("\n");
            printf("Soma: %d ", soma);
        break;
    }
}

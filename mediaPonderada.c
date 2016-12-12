/**
Que receba três notas, seus pesos, calcule e mostre a média ponderada dessas notas;
Autor: André Kroetz Berger
Março/2011
**/
#include <stdio.h>
main()
{
    float nota1,peso1,nota2,peso2,nota3,peso3,media;     //declaração das variáveis necessárias

    printf("Digite a primeira nota:\n");
    scanf("%f",&nota1); //funcao que le o valor digitado e atribui a var nota1
    fflush(stdin); //funcao para evitar problemas com o scanf
    printf("Digite o peso da nota1:\n");
    scanf("%f",&peso1); //funcao que le o valor digitado e atribui a var nota1
    fflush(stdin); //funcao para evitar problemas com o scanf

    printf("Digite a segunda nota para a media:\n");
    scanf("%f",&nota2); //funcao que le o valor digitado e atribui a var nota2
    fflush(stdin); //funcao para evitar problemas com o scanf
    printf("Digite o peso da nota2:\n");
    scanf("%f",&peso2); //funcao que le o valor digitado e atribui a var nota1
    fflush(stdin); //funcao para evitar problemas com o scanf

    printf("Digite a terceira nota para a media:\n");
    scanf("%f",&nota3); //funcao que le o valor digitado e atribui a var nota1
    fflush(stdin); //funcao para evitar problemas com o scanf
    printf("Digite o peso da nota3:\n");
    scanf("%f",&peso3); //funcao que le o valor digitado e atribui a var nota1
    fflush(stdin); //funcao para evitar problemas com o scanf

    media = ((peso1*nota1)+(peso2*nota2)+(peso3*nota3))/(peso1+peso2+peso3);  //calculo da media

    printf("\nMedia ponderada = %0.2f  \n",media);
    system("pause");
}

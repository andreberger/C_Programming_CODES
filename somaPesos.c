/**
Calcule a soma dos pesos de 4 alunos da turma
Autor: Andr� Kroetz Berger
Mar�o/2011
**/
#include <stdio.h>   //cabe�alho para funcoes de entrada e sa�da
main()
{
    float peso1,peso2,peso3,peso4,soma; //declara��o das vari�veis necess�rias

    printf("Digite o peso do aluno 1:\n");
    scanf("%f",&peso1); //funcao que le o valor digitado e atribui a var peso1
    fflush(stdin); //funcao para evitar problemas com o scanf
    printf("Digite o peso do aluno 2:\n");
    scanf("%f",&peso2); //funcao que le o valor digitado e atribui a var peso2
    fflush(stdin); //funcao para evitar problemas com o scanf
    printf("Digite o peso do aluno 3:\n");
    scanf("%f",&peso3); //funcao que le o valor digitado e atribui a var peso1
    fflush(stdin); //funcao para evitar problemas com o scanf
    printf("Digite o peso do aluno 4:\n");
    scanf("%f",&peso4); //funcao que le o valor digitado e atribui a var peso1
    fflush(stdin); //funcao para evitar problemas com o scanf
    soma = peso1+peso2+peso3+peso4;  //calculo da media

    printf("Soma dos pesos %0.2f, %0.2f, %0.2f, %0.2f  = %0.2f",peso1,peso2,peso3,peso4,soma);
    system("pause");
}

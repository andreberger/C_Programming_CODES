/**
Calcular a m�dia de 3 notas fornecidas pelo usu�rio;
Autor: Andr� Kroetz Berger
Mar�o/2011
**/
#include <stdio.h>   //cabe�alho para funcoes de entrada e sa�da
main()
{
    float nota1,nota2,nota3,media;     //declara��o das vari�veis necess�rias

    printf("Digite a primeira nota para a media:\n");
    scanf("%f",&nota1); //funcao que le o valor digitado e atribui a var nota1
    fflush(stdin); //funcao para evitar problemas com o scanf
    printf("Digite a segunda nota para a media:\n");
    scanf("%f",&nota2); //funcao que le o valor digitado e atribui a var nota2
    fflush(stdin); //funcao para evitar problemas com o scanf
    printf("Digite a terceira nota para a media:\n");
    scanf("%f",&nota3); //funcao que le o valor digitado e atribui a var nota1
    fflush(stdin); //funcao para evitar problemas com o scanf
    media = (nota1+nota2+nota3)/3;  //calculo da media

    printf("A media das notas %0.2f, %0.2f, %0.2f = %0.2f",nota1,nota2,nota3,media);

    system("pause");
}


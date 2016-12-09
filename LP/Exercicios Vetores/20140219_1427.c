/**
    LABORATÓRIO DE PROGRAMAÇÃO
    Escreva um programa para ler o nome e o endereço de um estudante.
    O programa deverá exibir o nome e endereço digitado.
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
    char nome[30];
    char endereco[50];
    int x;

    printf("Informe seu nome: ");
    gets(nome);
    printf("Inform seu endereco: ");
    gets(endereco);
    printf("Nome: ");
    while(nome[x] != '\0')
    {
        printf("%c", nome[x]);
        x++;
    }
    printf("Endereco: ");
    while(endereco[x] != '\0')
    {
        printf("%c", endereco[x]);
        x++;
    }
    system("PAUSE");
}

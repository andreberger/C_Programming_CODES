/**
1 - Criar um programa que contenha uma função chamada encontrar_sobrenome.
Esta função deverá receber um ponteiro para uma String contendo um nome completo e retornar um
ponteiro apontando para onde inicia o sobrenome do nome completo enviado.
A função main deverá imprimir a string resultante, usando o ponteiro retornado.
Protótipo sugerido char * encontrar_sobrenome(char * nome_completo). Na função, somente pode ser utilizada a notação de ponteiro.
**/
#include<stdio.h>
#include<stdlib.h>
char * encontrar_sobrenome(char * nome_completo){
    char *ptr = nome_completo;
    while (*ptr != '\0')
    {
	if(*ptr == ' ')
	{
	   ptr++;
	   return ptr;
	}
        ptr++;
    }
}
int main()
{
    char nome_completo[100];
    printf("Informe o nome completo: ");
    gets(nome_completo);
    
    printf("Nome completo: %s \n", encontrar_sobrenome(nome_completo));	
}

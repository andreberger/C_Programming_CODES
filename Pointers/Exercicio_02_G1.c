//**
//2 - Criar um programa que contenha uma função chamada somar_vetor. 
//Esta função deverá receber por parâmetro um ponteiro para início do vetor e outro para o fim do vetor e 
//então deverá retornar a soma de todos os elementos contidos no vetor. 
//Protótipo sugerido: int soma_vetor(int * inicio, int * fim).  Na função, somente pode ser utilizada a notação de ponteiro.
//
//**/
#include<stdio.h>
#include<stdlib.h>

int soma_vetor(int * inicio, int * fim)
{
	int soma = 0;

	while(inicio != fim)
	{
     soma =  *inicio + soma;
     inicio++;
    }

    return soma;



}
int main()
{
	int v[] = {1,2,3,4};
	int *ptr_1 = v;
    int *ptr_2 = v+4;

    printf("%d\n",soma_vetor(ptr_1,ptr_2));
}
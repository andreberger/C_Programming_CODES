#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cliente{
    int codigo;
    char nome[100];
    int idade;
}cliente;

int main(){

    char path[] = "dados_exemplo.txt";
    FILE * arq;
    cliente clientes[100];
    int cliCounter = 0, i, sz;

    if((arq = fopen(path, "r")) == NULL)
        printf("Erro ao abrir arquivo: %s \n", path);


   while (sz=fscanf(arq, "%d,%[^,],%d", &clientes[cliCounter].codigo, clientes[cliCounter].nome, &clientes[cliCounter].idade) != EOF ){
        cliCounter++;
   }

    printf("Codigo  nome            idade\n");
    for(i = 0; i < cliCounter; i++){
        printf("%d  %s  %d\n",clientes[i].codigo, clientes[i].nome, clientes[i].idade);
    }
    if(fclose(arq))
        printf("Erro ao fechar arquivo: %s \n", path);
}

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

    if((arq = fopen(path, "a+")) == NULL)
        printf("Erro ao abrir arquivo: %s \n", path);
    cliente c;
    printf("Informe o codigo do cliente:\n");
    scanf("%d",&c.codigo);
    fflush(stdin);
    printf("Informe o nome do cliente:\n");
    gets(c.nome);
    printf("Informe a idade do cliente:\n");
    scanf("%d",&c.idade);

    sz = fprintf(arq,"\n%d,%s,%d", c.codigo, c.nome, c.idade);
    fflush(arq);
    printf("sz %d \n", sz);
    rewind(arq);

   while (sz=fscanf(arq, "%d,%[^,],%d", &clientes[cliCounter].codigo, clientes[cliCounter].nome, &clientes[cliCounter].idade) != EOF ){
        //printf("sz = %d \n", sz);
        cliCounter++;
   }

    printf("Codigo  nome            idade\n");
    for(i = 0; i < cliCounter; i++){
        printf("%d  %s  %d\n",clientes[i].codigo, clientes[i].nome, clientes[i].idade);
    }
    if(fclose(arq))
        printf("Erro ao fechar arquivo: %s \n", path);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OUT 1
int main(){
    char path[] = "data.txt";
    FILE * arquivo;
    char linha[80];

    if((arquivo = fopen(path, "w+")) == NULL)
        printf("Erro ao abrir arquivo: %s \n", path);

    do{
        printf("Informe uma frase: \n");
        fflush(stdin);
        gets(linha);
        strcat(linha,"\n");
        fputs(linha, arquivo);
    }while(*linha != '\n');

    rewind(arquivo);

   while(!feof(arquivo)){
        fgets(linha, sizeof(linha), arquivo);
        printf(linha);
   }

    if(fclose(arquivo))
        printf("Erro ao fechar arquivo: %s \n", path);
}

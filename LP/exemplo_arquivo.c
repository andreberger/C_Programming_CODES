#include<stdio.h>
#include<stdlib.h>


int main(){
    char path[] = "dados.txt";
    FILE * arquivo;
    char ch;

    if((arquivo = fopen(path, "w+")) == NULL)
        printf("Erro ao abrir arquivo: %s \n", path);

    do{
        fflush(stdin);
        ch = getchar();
        if(fputc(ch, arquivo) == EOF)
             printf("Erro ao escrever no arquivo: %c \n", ch);
    }while(ch != '&');

    rewind(arquivo);

    do{
        ch = fgetc(arquivo);
        printf("Caractere lido do arquivo: %c \n", ch);
    }while(ch != EOF);

    if(fclose(arquivo))
        printf("Erro ao fechar arquivo: %s \n", path);
}

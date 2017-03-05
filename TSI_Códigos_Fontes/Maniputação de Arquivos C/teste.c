#include <stdio.h>
#include <stdlib.h>
int main(){
    
    int idade=0;
    char nome[30];
    
    FILE *p_file;
    
    p_file= fopen("teste.txt","r"); //W A R
    if (p_file){
                printf("Arquivo existe! \n");
                p_file= fopen("teste.txt","a"); //W A R
                printf("Informe seu nome: ");
                scanf("%s", &nome);
                printf("Informe sua idade: ");
                scanf("%d", &idade);
                fprintf(p_file, "Nome: %s Idade: %d \n",nome,idade);
                fclose(p_file);
                }
    else{
         printf("Arquivo nao existe \n");
         
    p_file= fopen("teste.txt","w"); //W A R
    printf("Informe seu nome: ");
    scanf("%s", &nome);
    printf("Informe sua idade: ");
    scanf("%d", &idade);
    fprintf(p_file, "Nome: %s | Idade: %d \n",nome,idade);
    fclose(p_file);
    }
    system("pause");
    return 0;
    
}
    

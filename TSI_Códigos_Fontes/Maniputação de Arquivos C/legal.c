#include<stdio.h>
#include<stdlib.h>
int main (){
    
    int x;
    int idade=0;
    char nome[30];
    char c;
    
    FILE *p_file;
    
    p_file= fopen("teste.txt","r"); //W A R
    
    system("cls");
      printf("+-----------------------+\n");
      printf("|  CADASTRO DE ALUNOS   |\n");
      printf("+-----------------------+\n\n");
      printf("+---+-------------------+\n");
      printf("| 1 | CADASTRO          |\n");
      printf("+---+-------------------+\n");
      printf("| 2 | LISTAGEM          |\n");
      printf("+---+-------------------+\n");
      printf("Selecione uma opcao: ");
      scanf("%d", &x);
      printf("\n");
      
      switch (x){
             case 1:
                  if (p_file){
                     printf("Arquivo existe! \n");
                     p_file= fopen("teste.txt","a"); //W A R
                     printf("Informe seu nome: ");
                     scanf("%s", &nome);
                     printf("Informe sua idade: ");
                     scanf("%d", &idade);
                     fprintf(p_file, "Nome: %s , %d \n",nome,idade);
                     fclose(p_file);
                  }
                  else{
                     printf("Arquivo nao existe \n");
         
                     p_file= fopen("teste.txt","w"); //W A R
                     printf("Informe seu nome: ");
                     scanf("%s", &nome);
                     printf("Informe sua idade: ");
                     scanf("%d", &idade);
                     fprintf(p_file, "Nome: %s , %d \n",nome,idade);
                     fclose(p_file);
                  }
                     system("pause");
                     return 0;
             break;
             case 2:
                  fopen("teste.txt","r");
                  while (1){
                        c=fgetc(p_file);
                           if( c!= EOF){ printf("%c",c);}
                           else { break; }
                           }
             break;
              }
                           
            
             system("pause");
    return 0;
}

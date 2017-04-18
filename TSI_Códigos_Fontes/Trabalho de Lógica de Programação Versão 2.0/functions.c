#include "functions.h"
#include <string.h>
#include <windows.h>
#include<stdio.h>

void Listagem(){
    
    char c;
    
    FILE *p_file;
    
    p_file= fopen("teste.txt","r"); //W A R
    fopen("teste.txt","r");
                  while (1){
                        c=fgetc(p_file);
                           if( c!= EOF){ 
                               printf("%c",c);
                               }
                           else { break; }
                           }
                        sleep(2000);
                  return(MenuAlunos());
}
int MenuAlunos(){//Função de Menu do Programa
     FILE *p_file;
    
    p_file= fopen("teste.txt","r"); //W A R
    fopen("teste.txt","r");
    int a;
      do{
      system("cls");
      printf("+-----------------------+\n");
      printf("|  CADASTRO DE ALUNOS   |\n");
      printf("+-----------------------+\n\n");
      printf("+---+-------------------+\n");
      printf("| 1 | CADASTRO          |\n");
      printf("+---+-------------------+\n");
      printf("| 2 | ALTERACAO         |\n");
      printf("+---+-------------------+\n");
      printf("| 3 | PESQUISA          |\n");
      printf("+---+-------------------+\n");
      printf("| 4 | REMOCAO           |\n");
      printf("+---+-------------------+\n");
      printf("| 5 | LISTAGEM          |\n");
      printf("+---+-------------------+\n");
      printf("| 6 | CREDITOS FINAIS   |\n");
      printf("+---+-------------------+\n");
      printf("| 7 | SAIR DO PROGRAMA  |\n");
      printf("+---+-------------------+\n");
      printf("\n");
      printf("Selecione uma opcao: ");
      scanf("%d", &a);
      printf("\n");
      
      switch (a){
             case 1:
                  CadAlunos();//Chama a função de cadastro de alunos
             break;
             case 2:
                  AlteraAlunos();//Chama a função de alteração de alunos
             break;
             case 3:
                  Pesquisa();//Chama a função de pesquisa de alunos
                  Sleep( 2000 );
                  return(MenuAlunos());//Retorna ao menu do programa
             break;
             case 4:
                  RemoveAlunos();//Chama a função de remoção de alunos
             break;
             case 5:
                  Listagem();
             break;
             case 6:
                 Creditos();
             break;
             case 7:
                 exit(0);
             break;
             default://Caso não seja nenhuma das opções acima exibe a seguinte mensagem
                  printf("Opcao Invalida!!!");
                  printf("\n");
                  printf("\n");
                  sleep(2000);
                  return(MenuAlunos());
      }
      printf("Deseja realizar outra operacao(Sim(S) ,Nao(N))\n");
     }
     while(getche()=='s');
      system("pause");
}
void CadAlunos(){//Função de cadastro de alunos
             FILE *p_file;
             
             if (p_file){
                     printf("Arquivo existe! \n");
                     p_file= fopen("teste.txt","a"); //W A R
                     printf("Informe o nome: ");
                     scanf("%s", &al[berger].nome);
                     printf("Informe o idade: ");
                     scanf("%d", &al[berger].idade);
                     printf("Informe o turma: ");
                     scanf("%d", &al[berger].turma);
                     fprintf(p_file, "Nome: %s , %d , %d\n",al[berger].nome,al[berger].idade,al[berger].turma);
                     fclose(p_file);
                  }
                  else{
                     printf("Arquivo nao existe \n");
         
                     p_file= fopen("teste.txt","w"); //W A R
                     printf("Informe o nome: ");
                     scanf("%s", &al[berger].nome);
                     printf("Informe o idade: ");
                     scanf("%d", &al[berger].idade);
                     printf("Informe o turma: ");
                     scanf("%d", &al[berger].turma);
                     printf("\nAluno Cadastrado com Sucesso!\n\n");
                     fprintf(p_file, "Nome: %s , %d , %d\n",al[berger].nome,al[berger].idade,al[berger].turma);
                     fclose(p_file);
                  }
             printf("\nAluno Cadastrado com Sucesso!\n\n");
             berger++;
             Sleep( 2000 );
             return(MenuAlunos());//Retorna ao menu do programa
}
void AlteraAlunos(){
     char novonome[30];
     int novaidade;
     int novaturma;
     int testando;
     testando = Pesquisa();
     if(testando >=0){
              printf("Informe o novo Nome: ");
              scanf("%s", &novonome);
              strcpy (al[testando].nome, novonome);
              printf("Informe o nova Idade: ");
              scanf("%d", &novaidade);
                  al[testando].idade= novaidade;
              printf("Informe o novo Turma: ");
              scanf("%d", &novaturma);
              al[testando].turma= novaturma;
              printf("\n");
              printf("Aluno Alterado com sucesso!");
              }
     else {
          printf("\n");
          printf("Aluno nao cadastrado em nosso sistema!");
          }
      Sleep( 2000 );
      return(MenuAlunos());//Retorna ao menu do programa
         
}
void RemoveAlunos(){
       int  oi;
       oi = Pesquisa();
       if (oi>=0){
                  al[oi].nome[0]='\0';
                  al[oi].idade =0;
                  al[oi].turma =0;
                  printf("\nAluno Removido com Sucesso!!!\n");
                  }
       else {
            printf("\n");
            printf("Aluno nao cadastrado em nosso sistema!");
            }
            Sleep( 2000 );
            return(MenuAlunos());//Retorna ao menu do programa
   }
int Pesquisa(){
    
     FILE *p_file;
     
     p_file= fopen("teste.txt","r"); //W A R 
     
     int z=0;
     int testando=-1;
     char valor[30];
     
     fopen("teste.txt","r");
     printf("Pesquisa de um aluno: ");
     scanf("%s", &valor);
     
     for(z=0; z<=29; z++){
              
              if(strcmp(al[z].nome, valor)==0){
              Listagem();
                   printf("+----------------------------------------------------+\n");
                   printf("     ENCONTRADO NA POSISAO %d OS SEGUINTES DADOS      \n",berger);
                   printf("+----------------------------------------------------+\n");
                   printf("+ ALUNO: %s \n",al[z].nome);
                   printf("+----------------------------------------------------+\n");
                   printf("+ IDADE: %d \n",al[z].idade);
                   printf("+----------------------------------------------------+\n");
                   printf("+ TURMA: %d \n",al[z].turma);
                   printf("+----------------------------------------------------+\n");
                  testando=z;
              }
     }
     printf("\n Nao foi encontrado nenhum aluno em nosso sistema! \n ");
     return(testando);
     Sleep( 5000 );
     return(MenuAlunos());//Retorna ao menu do programa
}
int Creditos () {
    printf("\t \t============================================\n");
    printf("\t \t=                                          =\n");
    printf("\t \t=   DESENVOLVIDO POR ANDRE KROETZ BERGER   =\n");
    printf("\t \t=                                          =\n");
    printf("\t \t=            VERSAO 2.0 BETA               =\n");
    printf("\t \t=                                          =\n");
    printf("\t \t=  www.andeeu.net/index.php?menu=suporte   =\n");
    printf("\t \t=                                          =\n");
    printf("\t \t============================================\n");
    Sleep( 8000 );
    return(MenuAlunos());//Retorna ao menu do programa
    }
int Gambiarra(){
    char *str = "Andre Castro,31,421 \0";
    char *aux,*auxNome,*auxIdade,*auxTurma;
    char nome[30]=" ";
    char idade[3]=" ";
    char turma[40]=" ";
    aux=str;
    auxIdade=idade;
    auxNome=nome;
    auxTurma=turma;
    int c=0; //0=nome; 1=idade; 2=turma;
    while (*aux!='\0'){
          if(*aux==','){
                        c++;
                        aux++;
          }
          if (c==0){
                    *auxNome=*aux;
                    auxNome++;
          }else if (c==1){
                    *auxIdade=*aux;
                    auxIdade++;
          }else if (c==2){
                    *auxTurma=*aux;
                    auxTurma++;
          }
          aux++;
    }
    *auxNome='\0'; 
    *auxIdade='\0';
    *auxTurma='\0';       
    printf("Nome: %s\n Idade: %s\n Turma: %s \n",nome,idade,turma);
    system("pause");
    return 0;
}              


#include "functions.h"
#include <string.h>
#include <windows.h>

int MenuAlunos(){//Função de Menu do Programa
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
      printf("| 5 | CREDITOS FINAIS   |\n");
      printf("+---+-------------------+\n");
      printf("| 6 | SAIR DO PROGRAMA  |\n");
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
                 Creditos();
             break;
             case 6:
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
     
             printf("Informe o nome: ");
             scanf("%s", &al[berger].nome);
             printf("Informe o idade: ");
             scanf("%d", &al[berger].idade);
             printf("Informe o turma: ");
             scanf("%d", &al[berger].turma);
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
     int z=0;
     int testando=-1;
     char valor[30];
     printf("Pesquisa de um aluno: ");
     scanf("%s", &valor);
     for(z=0; z<=29; z++){
              if(strcmp(al[z].nome, valor)==0){
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
    printf("\t \t=            VERSAO 1.0 FINAL              =\n");
    printf("\t \t=                                          =\n");
    printf("\t \t=             www.andeeu.net               =\n");
    printf("\t \t=                                          =\n");
    printf("\t \t============================================\n");
    Sleep( 8000 );
    return(MenuAlunos());//Retorna ao menu do programa
    }



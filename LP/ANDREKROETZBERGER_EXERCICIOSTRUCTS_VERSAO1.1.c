/**
    LABORATÓRIO DE PROGRAMAÇÃO
    Programador: André Kroetz Berger
    VERSAO 1.1 BETA 

**/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct aluno{
    int matricula;
    char nome[50];
    float notas[4];
} aluno;

typedef struct disciplina{
   int codigo_disciplina;
   char nome_disciplina[50];
}disciplina;

typedef struct turma{
    char codigo_turma[10];
    aluno alunos[10];
    disciplina disc;
}turma;

aluno Aluno[5];
disciplina Disciplina [5];
turma Turma[10];

int n=0;
int x;

void CadAlunos()
{	
	int n;
    for(n=0;n<5;n++)
    {
        printf("Informe o nome do aluno: ");
        scanf("%s", &Aluno[n].nome);
        printf("Informe o numero de matricula: ");
        scanf("%d", &Aluno[n].matricula);
        for(x=0;x<4;x++)
        {
            printf("Informe a %d nota: ", x+1);
            scanf("%f", &Aluno[n].notas[x]);
        }
    }
}
void CadDisciplina()
{
    for(n=0;n<5;n++)
    {
        printf("Informe o nome da disciplina: ");
        scanf("%s", &Disciplina[n].nome_disciplina);
        printf("Informe o codigo da disciplina: ");
	    scanf("%d", &Disciplina[n].codigo_disciplina);
    }
}
void menuSistema()
{
     int a;
     printf("1 - Cadastrar Novo Aluno:\n");
     printf("2 - Cadastrar Nova Disciplina:\n");
     printf("3 - Cadastrar Nova Turma:\n");
     printf("4 - Fornecer:\n");
     printf("Selecione a opcao desejada: ");
     scanf("%d", &a);
	
     switch (a) 
     {
            case 1:
                 CadAlunos();
            break;
    	    case 2:
		         CadDisciplina();
            break;
            case 3: 
                 CadTurma();
            break;
            case : 
                 menuFornecer();
            break;
	default:
		printf("Bye Bye Baby");
	break;
    }
}
void menuFornecer()
{
     int kb;
     
     system("cls");
     printf("1 - Media dos alunos de uma determinada turma.\n");
     printf("2 - Quantidade de alunos em uma determinada turma.\n");
     printf("3 - Quantidade de turmas de uma determinada disciplina.\n");
     printf("0 - Voltar ao meu anterior.\n\n");
     printf("Selecione a opcao desejada: ");
     scanf("%d", &kb);
     
     switch (kb)
     {
            case 1:
                 mediaAlunos();
            break;
            case 2:
                 qtdAlunos();
            break;
            case 3:
                  qtdTurmas();
            break;
            default:
                  printf("Bye Bye Baby!!!!!");
            break;       
     }      
}
void mediaAlunos()
{
     int navegaAlunos, y;
     float media;
     navegaAlunos=0;
     
     printf("Selecione uma turma para ver a media: ");
     gets(codTurma);
         for(y=0;y<5;y++){
         
              if(strcmp(turmas[y].codigo_turma,codTurma)==0)
              {
                 printf("\n\nMedia dos alunos da Turma %s: \n\n", codTurma);
               
                 while(turmas[y].alunos[navegaAlunos].matricula != '\0'){
                 media=0;
                
                          for(navNotas=0;navNotas<4;navNotas++){
                              media += (float) turmas[y].alunos[navAlunos].notas[navNotas];
                                }
                                media = media/4;
                                mediaNotasTurma += media;
                                
                                printf("\nAluno: %d - %s teve a media: %.2lf. \n", turmas[ctrl].alunos[navAlunos].matricula, turmas[ctrl].alunos[navAlunos].nome, media);

                                navAlunos+=1;
                            }
                            mediaNotasTurma = mediaNotasTurma/navAlunos;
                        }
                    }
                    printf("\n\nMedia das notas da turma: %.2lf\n\n", mediaNotasTurma);
                    printf("\n\n");
}
void qtdTurmas()
{
     navTurmas=0;
     printf("Selecione uma disciplina para ver o numero de turmas vinculadas: ");
     scanf("%d", &codDisciplina);
     
     for(ctrl=0;ctrl<5;ctrl++)
     {
         x=0;
         while(turmas[ctrl].disciplinas[x].codigo_disciplina != '\0'){
         
         if(turmas[ctrl].disciplinas[x].codigo_disciplina == codDisciplina){
           navTurmas+=1;
         }
         x+=1;
     }
     }
                    printf("\n\nNumero de turmas da disciplina %d: %d \n\n", codDisciplina, navTurmas);
}
void qtdAlunos()
{
     navAlunos=0;
     printf("Selecione uma turma para ver seu numero de alunos: ");
     gets(codTurma);
     for(ctrl=0;ctrl<5;ctrl++)
     {
        if(strcmp(turmas[ctrl].codigo_turma,codTurma)==0)
        {
              while(turmas[ctrl].alunos[navAlunos].matricula != '\0')
              {
               navAlunos+=1;
               }
        }
     }
     printf("\nQuantidade de alunos da turma %s: %d\n\n", codTurma, navAlunos);
}
void mediaTurma()
{
     navAlunos=0;
     printf("Selecione uma turma para ver a media: ");           
     gets(codTurma);
     for(ctrl=0;ctrl<5;ctrl++)
     {
        if(strcmp(turmas[ctrl].codigo_turma,codTurma)==0){
        printf("\n\nMedia dos alunos da Turma %s: \n\n", codTurma);
        while(turmas[ctrl].alunos[navAlunos].matricula != '\0'){
           media=0;
           for(navNotas=0;navNotas<4;navNotas++){
              media += (float) turmas[ctrl].alunos[navAlunos].notas[navNotas];
           }
         media = media/4;
         mediaNotasTurma += media;
         printf("\nAluno: %d - %s teve a media: %.2lf. \n", turmas[ctrl].alunos[navAlunos].matricula, turmas[ctrl].alunos[navAlunos].nome, media);
         navAlunos+=1;
     }
     mediaNotasTurma = mediaNotasTurma/navAlunos;
                        }
                         }
    printf("\n\nMedia das notas da turma: %.2lf\n\n", mediaNotasTurma);
    printf("\n\n");
}
main()
{
    int ctrl, x, cont;
    int navAlunos, navNotas, navTurmas, navDisciplinas,  codDisciplina;
    float media;
    menuSistema();
    printf("Obrigado por usar os nosso sistema!");
    system("PAUSE");
}

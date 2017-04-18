#include<stdio.h>
#include<stdlib.h>

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

int main(){
   //Cadastrar alunos/disciplinas/turmas
   //Fornecer:
        //Media dos alunos de uma determinada turma(por codigo)
        //Quantidade de alunos em uma determinada turma(por codigo).
        //Quantidade de turmas de uma determinada disciplina(por codigo).
}

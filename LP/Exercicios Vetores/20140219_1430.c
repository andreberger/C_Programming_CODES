/**

Escreva um programa para calcular e exibir o nœmero de acertos de cada aluno em uma prova. A prova Ž formada por 10 quest›es,
cada uma com cinco alternativas (A, B, C, D e E). Para isso o programa dever‡:

o solicitar o gabarito da prova;
o solicitar o nœmero de alunos da turma;
o solicitar a resposta dada por cada aluno para cada quest‹o.

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_VET 10

main()
{
    char gabarito[TAM_VET];
    int numeroAlunos;
    char resposta;
    int acertos;
    int x, i;
    
    
    for(x=0;x<TAM_VET;x++)
    {
        printf("Digite o gabarito (%d): ", x+1);
        scanf("%c", &resposta);
        fflush(stdin);
        
        while(resposta != 'a' && resposta!='b' && resposta!='c' && resposta!='d' && resposta!='e'){
            //while(resposta != "a" || resposta!="b" || resposta!="c" || resposta!="d" || resposta!="e"){
            printf("Valor incorreto. Digite o gabarito (%d): ", x+1);
            scanf("%c", &resposta);
            fflush(stdin);
        }
        gabarito[x] = resposta;
    }
    
    
    printf("Informe o numero de alunos: ");
    scanf("%d", &numeroAlunos);
    
    for(i=0;i<numeroAlunos;i++){
        acertos = 0;
        for(x=0;x<TAM_VET;x++){
            printf("Aluno %d - Digite a sua resposta (%d): ", i+1, x+1);
            scanf("%c", &resposta);
            
            while(resposta != 'a' && resposta!='b' && resposta!='c' && resposta!='d' && resposta!='e')
            {
                printf("Valor incorreto. Digite o gabarito (%d): ", x+1);
                scanf("%c", &resposta);
            }
            if(gabarito[x] == resposta){
                acertos += 1;
            }
        }
        printf("\n\nVoce acertou %d questoes.\n", acertos);
        
    }

}

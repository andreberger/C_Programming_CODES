//
//  20140219_1431.c
//  
//
//  Created by Andre Berger on 06/03/14.
//
//

#include <stdio.h>
main()
{
    int x;
    
    int numeroLancamentos;
    int face;
    
    int somaf1;
    int somaf2;
    int somaf3;
    int somaf4;
    int somaf5;
    int somaf6;
    
    somaf1 = 0;
    somaf2 = 0;
    somaf3 = 0;
    somaf4 = 0;
    somaf5 = 0;
    somaf6 = 0;
    
    printf("Quantas vezes voce deseja jogar o dado: ");
    scanf("%d", &numeroLancamentos);
    
    int facesCaidas[numeroLancamentos];
    
    for(x=0;x<numeroLancamentos;x++){
        printf("Qual face caiu o dado na jogada %d: ", x+1);
        scanf("%d", &face);
        fflush(stdin);
        while(face < 1 || face > 6){
            printf("Valor incorreto. Qual face caiu o dado na jogada %d: ", x+1);
            scanf("%d", &face);
            fflush(stdin);
        }
        
        facesCaidas[x] = face;
    }
    
    printf("\nO dado foi lancado %d vezes\n", numeroLancamentos);
    
    printf("\nOs lancamentos geraram o seguinte resultado:\n\n ");
    for(x=0;x<numeroLancamentos;x++){
        if(facesCaidas[x]==1){
            somaf1 += 1;
        }
        if(facesCaidas[x]==2){
            somaf2 += 1;
        }
        if(facesCaidas[x]==3){
            somaf3 += 1;
        }
        if(facesCaidas[x]==4){
            somaf4 += 1;
        }
        if(facesCaidas[x]==5){
            somaf5 += 1;
        }
        if(facesCaidas[x]==6){
            somaf6 += 1;
        }
    }
    
    printf("\nFace 1 : O = %d , P = %d\n", somaf1, (somaf1*100)/numeroLancamentos);
    printf("Face 2 : O = %d , P = %d\n", somaf2, (somaf2*100)/numeroLancamentos);
    printf("Face 3 : O = %d , P = %d\n", somaf3, (somaf3*100)/numeroLancamentos);
    printf("Face 4 : O = %d , P = %d\n", somaf4, (somaf4*100)/numeroLancamentos);
    printf("Face 5 : O = %d , P = %d\n", somaf5, (somaf5*100)/numeroLancamentos);
    printf("Face 6 : O = %d , P = %d\n", somaf6, (somaf6*100)/numeroLancamentos);
}
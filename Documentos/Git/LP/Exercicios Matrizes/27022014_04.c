//
//  27022014_04.c
//  
//
//  Created by Andre Berger on 2014.
//
//

#include <stdio.h>
#include <stdlib.h>
#define TAM_MAT 3
main()
{
    int mat[TAM_MAT][TAM_MAT];
    int l,c,lin, col;
    int iPermut;
    lin= 0;
    col= 0;
    
    for(l=0;l<TAM_MAT;l++){
        for(c=0;c<TAM_MAT;c++){
            printf("Informe os valores da matriz %d, %d: ", l,c);
            scanf("%d", &mat[l][c]);
        }
    }
    
    iPermut = 1;
    for(c=0;c<TAM_MAT;c++){
        col =0;
        for(l=0;l<TAM_MAT;l++){
            if(mat[l][c]!=0){
                col += 1;
            }
        }
        if(col > 1 || col==0){
            iPermut = 0;
        }
    }
    
    if(iPermut==1){
        for(l=0;l<TAM_MAT;l++){
            lin = 0;
            for(c=0;c<TAM_MAT;c++){
                if(mat[l][c]!=0){
                    lin += 1;
                }
            }
            if(lin > 1 || lin==0){
                iPermut = 0;
            }
        }
    }
    
    if(iPermut==1){
        printf("Matriz de permutacao - SIM\n");
    }else{
        printf("Matriz de permutacao - NAO\n");
    }
}
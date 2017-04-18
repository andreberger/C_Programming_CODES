#include <stdio.h>
#include <stdlib.h>
#define TAM 4
int main(){
    int l, c;
    int mat[TAM][TAM];
    for(l = 0; l < TAM; l++){
        for(c = 0; c < TAM; c++){
           printf("Informe um valor para mat[%d][%d]: \n", l, c);
           scanf("%d", &mat[l][c]);
        }
    }

    for(l = 0; l < TAM; l++){
        for(c = 0; c < TAM; c++){
           printf("|%d|", mat[l][c]);
        }
        printf("\n");
    }

}

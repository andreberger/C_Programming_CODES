#include <stdio.h>
#include <stdlib.h>
#define TAM 4
int main(){
    int l, c;
    int mat[TAM][TAM];
    for(c = 0; c < TAM * TAM; c++){
           printf("Informe um valor para mat[%d][%d]: \n", 0, c);
           scanf("%d", &mat[0][c]);
    }

    for(l = 0; l < TAM; l++){
        for(c = 0; c < TAM; c++){
           printf("|%d|", mat[l][c]);
        }
        printf("\n");
    }

}

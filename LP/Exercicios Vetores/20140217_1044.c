//
//  20140217_1044.c
//  
//
//  Created by Andre Berger on 06/03/14.
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 8
main()
{
    char cadeia[NUM];
    char resposta;
    int x;
    
    for(x=0;x<NUM;x++){
        printf("Digite uma letra (MAIUSCULA) (%d): ", x+1);
        scanf("%c", &resposta);
        fflush(stdin);
        cadeia[x] = tolower(resposta);
    }
    
    for(x=0;x<NUM;x++){
        printf("\nAs respectivas letras (minusculas) (%d): %c", x+1, cadeia[x]);
    }
    printf("\n");
}
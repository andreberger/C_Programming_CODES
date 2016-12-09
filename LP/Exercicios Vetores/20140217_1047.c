//
//  20140217_1047.c
//  
//
//  Created by Andre Berger on 06/03/14.
//
//

#include <stdio.h>
#include <stdlib.h>
#define TAM_VET 10
main()
{
    int k, x;
    int validaK;
    int codASCII;
    char senha[TAM_VET];
    
    printf("Digite uma senha: ");
    gets(senha);
    fflush(stdin);
    
    printf("\nDigite um numero de 0-25: ");
    scanf("%d", &k);
    
    validaK = (int)(k/25);
    k = k - validaK*25;
    
    for(x=0;x<TAM_VET;x++){
        codASCII = senha[x];
        
        if(codASCII+k < 97){
            codASCII = 122-k;
        }else{
            codASCII -= k;
        }
        
        printf("%c - ", codASCII);
    }
}
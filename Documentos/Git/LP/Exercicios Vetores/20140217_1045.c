//
//  20140217_1045.c
//  
//
//  Created by Andre Berger on 2014.
//
//

#include <stdio.h>
#define TAM_VET 300
#inclide <stdlib.h>
main()
{
    char capturaPalavra[TAM_VET]="";
    char invertePalavra[TAM_VET]="";
    int iPalindrome;
    int x,i;
    int tamanho;
    
    iPalindrome = 0;
    tamanho = 0;
    
    printf("VERIFICADOR DE PALINDROMES\n\n");
    printf("Digite uma palavra: ");
    gets(capturaPalavra);
    fflush(stdin);
    
    while(capturaPalavra[tamanho]!='\0'){
        tamanho+=1;
    }
    
    tamanho-=1;
    i=0;
    for(x=tamanho;x>=0;x--)
    {
        invertePalavra[i] = capturaPalavra[x];
        i+=1;
    }
    
    for(x=tamanho;x>=0;x--)
    {
        if(invertePalavra[x] != capturaPalavra[x]){
            iPalindrome = 1;
        }
    }
    
    printf("Palavra inversa: %s", invertePalavra);
    
    if(iPalindrome==1){
        printf("\nPalindrome = nao\n\n");
    }else{
        printf("\nPalindrome = sim\n\n");
    }

}


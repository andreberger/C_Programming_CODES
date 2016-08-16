//
//  20140219_1432.c
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
    int lista1[TAM_VET] = {1,2,3,4,5,6,7,8,9,0};
    int lista2[TAM_VET] = {5,5,5,5,5,5,5,5,5,5};
    int listaResultado[11];
    int x;
    int valorAux;
    
    valorAux = 0;
    for(x=9;x>=0;x--){
        listaResultado[x] = lista1[x] + lista2[x] + valorAux;
        if(listaResultado[x] >= 10){
            valorAux = 1;
            listaResultado[x] = listaResultado[x] -10;
        }else{
            valorAux = 0;
        }
    }
    
    printf("Resultado da soma: \n\n");
    for(x=0;x<10;x++){
        printf("%d",listaResultado[x]);
    }
    printf("\n\n");
}
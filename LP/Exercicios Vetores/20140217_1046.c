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
    //--> Esta função força o k a ser de 0 a 25

    for(x=0;x<10;x++)
    {
        codASCII = senha[x];
        if(codASCII+k > 122)
        {
            codASCII = 97+k;
        }else{
            codASCII += k;
        }
        printf("%c - ", codASCII);
    }
}
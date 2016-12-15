#include <stdio.h>
#include <stdlib.h>

int idade,anonasc,calc;

int main()
{
    printf("Informe a idade: ");
    scanf("%d",&idade);
    calc = 2016 - idade;
    printf("Sua idade eh %d e voce nasceu no ano de %d!!!!", idade,calc);
}

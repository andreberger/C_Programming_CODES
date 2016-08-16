#include<stdio.h>
#include<stdlib.h>

void altera_x(int * ptr_x){
    *ptr_x = 10;
}

int main()
{
    // & obtem o endereço de memória
    //
    int x = 3;
    printf("Valor de x %d \n", x);
    printf("End. de x %d \n", &x);
    int * ptr = &x;
    printf("Valor de x %d \n", ptr);
    printf("End. de x %d \n", &ptr);
    printf("Conteudo. apontado por ptr %d \n", *ptr);
    *ptr = 8;
    printf("Novo valor de x %d \n", x);

    altera_x(&x);
    printf("New Novo valor de x %d \n", x);
}

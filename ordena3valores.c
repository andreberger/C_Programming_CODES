/**
Escreve um programa que recebe três numeros do usuário e imprime esses números na ordem crescente (deve utilizar ifs para testar)
Autor: André Kroetz Berger
Março/2011
**/
#include <stdio.h>
main()
{
  int n1,n2,n3;
  int maior,medio,menor;
  printf("Digite os 3 numeros:\n");
  scanf("%d%d%d",&n1,&n2,&n3);

  if (n1 > n2){  //n1 maior que n2
      if (n1 > n3){ // n1 maior qu n2 e n3
          maior = n1;
          if (n2 > n3) {
              medio =n2;
              menor =n3;
          } else{
              medio =n3;
              menor =n2;
          }
      } else{
          maior =n3;
          medio =n1;
          menor =n2;
      }

  } else{   //n2 eh maior que n1
      if (n2 > n3){
         maior = n2;
         if (n1 > n3) {
            medio =n1;
            menor =n3;
         } else{
             medio =n3;
             menor =n1;
           }
      } else {
           maior =n3;
           medio =n2;
           menor =n1;
      }
  }

  printf("Ordem digitada: %d, %d, %d \n",n1,n2,n3);
  printf("Ordem crescente: %d, %d, %d \n",menor,medio,maior);
  system("pause");
}

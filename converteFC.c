/**
Programa converte temperatura em Fahrenheit para Celsius
Autor: André Kroetz Berger
Março/2011
**/
main()
{
 float C,F;     
 printf("Digite a temp em Fahrenheit para conversao:\n");
 scanf("%f",&F);

 C = 5/9.0 * (F - 32);
 
 printf("%0.2f em Fahrenheit = %0.3f em Celsius\n",F,C);

 system("pause");      
}

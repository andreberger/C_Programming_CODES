/** 
Programa que l� o N�MERO de um vendedor, o seu SAL�RIO fixo, o total de VENDAS por ele efetuadas e o PERCENTUAL que ganha sobre o total de suas vendas. Calcular o SAL�RIO TOTAL do vendedor e escrever o n�mero e o sal�rio do vendedor.
Autor: Andr� Kroetz Berger
Mar�o/2011
**/
#include <stdio.h>
main()
{
    int nroVendedor;
    float salarioBase, vendas, percentual,salarioTotal;
    printf("Entre com o numero do vendedor:\n");
    scanf("%d",&nroVendedor);
    fflush(stdin); //funcao para evitar problemas com o scanf
    printf("Informe o salario fixo:\n");
    scanf("%f",&salarioBase);
    fflush(stdin); //funcao para evitar problemas com o scanf
    printf("Informe o total de vendas:\n");
    scanf("%f",&vendas);
    fflush(stdin); //funcao para evitar problemas com o scanf
    printf("Informe o percentual de comissao sobre vendas:\n");
    scanf("%f",&percentual);
    fflush(stdin); //funcao para evitar problemas com o scanf

    salarioTotal = salarioBase + (percentual*vendas/100);

    printf("Vendedor %d recebera RS%0.2f\n",nroVendedor,salarioTotal);
    system("pause");
}

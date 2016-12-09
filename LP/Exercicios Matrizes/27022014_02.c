/**
 Dada uma matriz de nœmeros inteiros A(4 X 4), verificar se existem elementos repetidos na matriz.
**/
#include <stdio.h>
#include <stdlib.h>
#define TAM_MAT 4
main()
{
    int mat[TAM_MAT][TAM_MAT];
    int rep[TAM_MAT][TAM_MAT];
    int vezes[TAM_MAT][TAM_MAT];
    int i, j, k, l, lin, lin2, col, x, num, qtde, achou;

    for (i=0;i<TAM_MAT;i++)
    {
        for (j=0;j<TAM_MAT;j++)
        {
            printf("Informe um numero para a posicao [%d][%d]",i,j);
            scanf("%d",&mat[i][j]);
        }
    }

	lin = 0;
	col = 0;

	for (i=0;i<TAM_MAT;i++)
    {
        for (j=0;j<TAM_MAT;j++)
        {
            qtde = 1;
            num = mat[i][j];

            for (k=0;k<TAM_MAT;k++)
            {
                for (l=0;l<TAM_MAT;l++)
                {
                    if ((i!=k) || (j!=l))
                    if (mat[k][l] == num)

                    qtde++;
                } //fim for l
            } // fim k
			if (qtde > 1)
            {
                achou = 0;
                if (col == 0)
                    lin2 = lin-1;
                else
                    lin2 = lin;
                    for (k=0;k<=lin2;k++)
                    {
                        if (k<lin2)
                            x=4;
                        else
                            x=col-1;
                            for (l=0;l<=x;l++)
                            {
                                if (num==rep[k][l])
                                    achou = 1;
                            }
                    }
                    if (achou == 0)
                    {
                        rep[lin][col] = num;
                        vezes[lin][col] = qtde;
                        col++;

                        if (col > 4)
                        {
                            lin++;
                            col=0;
                        }
                    }
				 }

		} //fim for j

	} //fim for i
	for (i=0;i<=lin;i++)
    {
        if (i<lin)
            x=4;
        else
            x=col-1;
			for (j=0;j<=x;j++)
            {
                printf("O numero %d repetiu %d vezes! \n", rep[i][j],vezes[i][j]);
            }
			printf("\n");
    }
}

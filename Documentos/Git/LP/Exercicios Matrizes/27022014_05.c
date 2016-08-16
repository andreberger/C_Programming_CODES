/**
    Uma matriz quadrada de nœmeros inteiros Ž um quadrado m‡gico, se a soma dos elementos de cada linha,
    a soma dos elementos de cada coluna e a soma dos elementos das diagonais principal e secund‡ria s‹o todas iguais.
    Dada uma matriz quadrada 4 X 4 , verificar se a matriz Ž um quadrado m‡gico.
**/
#include <stdio.h>
#include <stdlib.h>

main()
{
    int mat[4][4];
    int soma_linha[4];
    int soma_coluna[4];
    int soma_diagp;
    int soma_diags;
    int  i, j;
    int compara, q_magico;

	for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            printf("Informe o elemento [%d] [%d]", i,j);
            scanf("%d",&mat[i][j]);
        }
    }

	for (i=0;i<4;i++)
    {
        soma_linha[i] = 0;
        for (j=0;j<4;j++)
        {
            soma_linha[i] = soma_linha[i] + mat[i][j];
        }
    }

	for (i=0;i<4;i++)
    {
        soma_coluna[i] = 0;
        for (j=0;j<4;j++)
        {
            soma_coluna[i] = soma_coluna[i] + mat[j][i];
        }
    }

	soma_diagp = 0;
	for (i=0;i<4;i++)
    {
        soma_diagp = soma_diagp + mat[i][i];
    }

	soma_diags = 0;
	j = 3;
	for (i=0;i<4;i++)
    {
        soma_diags = soma_diags + mat[i][j];
        j = j - 1;
    }

	q_magico = 1;
	for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            if (soma_linha[i] != soma_coluna[j])
                q_magico = 0;
        }
    }

	for (i=0;i<4;i++)
    {
        if (soma_linha[i] != soma_diagp)
            q_magico = 0;
    }

	for (i=0;i<4;i++)
    {
        if (soma_linha[i] != soma_diags)
            q_magico = 0;
    }

	if (q_magico == 1)
		 printf("\nForma quadrado magico\n");
	else
		 printf("\nNao forma quadrado magico\n");

}

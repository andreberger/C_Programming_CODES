#include <stdio.h>
#include <stdlib.h>
#define m 4
#define n 4

int main()
{

    int a[m][n], i, j, nc=0, nl=0, ehnulo;

    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("Preenchendo a Matriz [%d][%d]", i,j);
            scanf("%d",&a[i][j]);
        }
    }

    for (i=0; i<m; i++)
    {
        ehnulo = 1;
        for (j=0; j<n; j++)
        {
            if (a[i][j] != 0)
            {
                ehnulo = 0;
            }
            if (ehnulo)
            {
                nl++;
            }
        }
    }
    for (j=0; j<n; j++)
    {
        ehnulo = 1;
        for (i=0; i<m; i++)
        {
            if (a[i][j] != 0)
            ehnulo = 0;
            if (ehnulo)
            nc++;
        }
    }
    printf("\nNumero de linhas nulas: %d", nl);
    printf("\nNumero de colunas nulas: %d", nc);
    return 0;
}

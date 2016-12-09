#include<stdio.h>
#include<stdlib.h>

int main()
{
    int v[] = {1,2,3,4};
    int i,soma;
    int *ptr_1 = &v[0];
    int *ptr_2 = &v[3];

    for(i = 0; i < 4; i++)
    {
        printf("v[%d] = [%d] -> %d \n", i, v[i], &v[i]);
    }

    printf("%d\n", *ptr_1);
    printf("%d\n", *ptr_2);

    soma=  *ptr_1 + *ptr_2;

    printf("%d\n", soma);
}

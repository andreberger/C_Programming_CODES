#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int v[4]= {1,2,3,4};
    int *ptr_v = v;

    for (i=0; i<4; i++)
    {
        printf("%d \n", *ptr_v);
        ptr_v++;
    }
}

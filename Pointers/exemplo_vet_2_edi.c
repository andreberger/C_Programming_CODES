#include<stdio.h>
#include<stdlib.h>

int main()
{
    int v[] = {1,2,3,4};
    int i;
    int * ptr = v;
    int * ptr2 = v;

    for(i = 0; i < 4; i++)
    {
        printf("*ptr %d \n", *ptr);
        ptr++;
    }
    printf("%d \n", ptr - ptr2);
    ptr--;
    for(i = 0; i < 4; i++)
    {
        printf("*ptr %d \n", *ptr);
        ptr--;
    }


    //Comparacao
    printf("Comparacao \n");
    ptr = &v[3];
    while(1){
        printf("%d \n", *ptr);
        if(ptr == ptr2){
            break;
        }
        ptr--;
    }
}

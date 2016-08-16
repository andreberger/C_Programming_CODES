#include <stdio.h>
#include <stdlib.h>

int tamanhoString(char *s)
{
    char *ptr = s;
    while (*ptr != '\0')
    {
        ptr++;
    }
    return (int) (ptr - s);
}

int main()
{
    char string[100];

    printf("Informe uma String: \n");
    gets(string);
    printf("Tamanho da String informada: %d \n", tamanhoString(string));
}

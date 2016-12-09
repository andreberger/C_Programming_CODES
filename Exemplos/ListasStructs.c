#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int numero;
    struct list * proximo;
}list;

list * create_new_element(int numero)
{
    list * novo = (list *) malloc (sizeof(list));
    novo->numero = numero;
    novo->proximo = NULL;
    return novo;
}

list * insert (list * lista, list * novo)
{
    if(lista == NULL)
    {
        return novo;
    }
    else
    {
        list * aux = lista;

        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
            printf("%d \n", aux->proximo);
        }
        aux->proximo = novo;
    }
    return lista;
}

list * remover_frente(list *lista)
{
    list *aux;
    aux = lista;
    lista = lista->proximo;
    aux->proximo = NULL;
    free(aux);
    return lista;
}


int main()
{
    list * inicio_lista = NULL;
    list * novo = create_new_element(1);
    printf("%d \n", novo->numero);
    inicio_lista = insert(inicio_lista,novo);
    printf("%d \n", inicio_lista->numero);
    novo = create_new_element(2);

    novo = remover_frente();

    inicio_lista = insert(inicio_lista,novo);
    printf("%d \n", inicio_lista->numero);
    printf("%d \n", novo->numero);
    novo = create_new_element(3);
    inicio_lista = insert(inicio_lista,novo);
    printf("%d \n", novo->numero);
    system("PAUSE");
}

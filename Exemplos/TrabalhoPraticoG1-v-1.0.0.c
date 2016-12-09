#include<stdio.h>
#include<stdlib.h>

typedef struct Produto {
    int codigo; //código do produto
    char descr[35]; // descrição do produto
    float preco; // preço do produto
    int categoria; //categoria do produto
    struct Produto *proximo; // ponteiro que indica o próximo da lista
} Produto;

Produto * create_new_element(int numero)
{
    Produto * novo = (Produto *) malloc (sizeof(Produto));
    novo->numero = numero;
    novo->proximo = NULL;
    return novo;
}

void MediaCategoria(Produto *primeiro)
{

}

Produto * remove (Produto * lista, Produto * novo)
{
    int aux;
    aux = lista;
    lista = lista->next;
    aux->next= NULL;
    free(aux);
}

void show(Produto *lista){
    while(lista!=NULL){
    printf("%d \n",lista->numero);
    lista=lista->proximo;
    }
}

Produto * insert (Produto * lista, Produto * novo)
{
    if(lista == NULL)
    {
        return novo;
    }
    else
    {
        Produto * aux = lista;

        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
            printf("%d \n", aux->proximo);
        }
        aux->proximo = novo;
    }
    return lista;
}

int main()
{
    Produto * inicio_lista = NULL;
    Produto * novo = create_new_element(1);
    printf("%d \n", novo->numero);
    inicio_lista = insert(inicio_lista,novo);
    printf("%d \n", inicio_lista->numero);
    novo = create_new_element(2);
    inicio_lista = insert(inicio_lista,novo);
    printf("%d \n", inicio_lista->numero);
    printf("%d \n", novo->numero);
    novo = create_new_element(3);
    system("PAUSE");
}

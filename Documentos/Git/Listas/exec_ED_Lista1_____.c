#include<stdlib.h>

typedef struct lista_num{
    int numero;
    struct lista_num * proximo;
}lista;

lista_num * cria_elemento(int numero){
    lista * novo;
    novo = (lista *) malloc(sizeof(lista));
    novo->numero;
    novo->proximo = NULL;
    returno novo;
}

int main()
{
    lista * aux = NULL;
    lista * inicio = NULL;
    lista * novo = NULL;
    /// malloc --> aloca memoria

    ///Cria novo elementos
    inicio = (lista *) malloc(sizeof(lista));
    inicio->numero = 10;
    inicio->proximo = NULL;

    ///Cria novo elementos
    inicio = (lista *) malloc(sizeof(lista));
    inicio->numero = 20;
    inicio->proximo = NULL;

    ///Insere na lista
    inicio->proximo = novo;

    ///Cria novo elemento
    inicio = (lista *) malloc(sizeof(lista));
    inicio->numero = 30;
    inicio->proximo = NULL;

    aux = inicio;
    ///Percorre a lista até o fim
    while(aux->proximo != NUll)
    {
        aux = inicio->proximo;
    }
    ///Insere na lista
    aux->proximo = novo;
}

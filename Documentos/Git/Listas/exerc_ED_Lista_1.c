#include<stdio.h>
#include<stdlib.h>

typedef struct lista_num{
    int numero;
    struct lista_num * proximo;
}lista;

lista * criar_elemento(int numero){
    /// Criacao de um elemento
    /// malloc - aloca memoria
    lista * novo = (lista *) malloc(sizeof(lista));
    novo->numero = numero;
    novo->proximo = NULL;
    ///Retorna endereco(ponteiro) do elemento criado
    return novo;
}

void inserir_elemento(lista ** ptr_ptr_inicio, lista * novo){
    ///Obtendo o inicio da lista
    lista * inicio_lista = *ptr_ptr_inicio;

    ///Se a lista for vazia, o inicio da lista
    ///deve ser o novo elemento

    ///Caso contrário, percorrer até o final da lista
    /// e então, inserir o elemento

}


void exibir_lista(lista * inicio){
    ///Exibir os elementos da lista (numero)

}


int main(){

    lista * inicio = NULL;
    lista * aux = NULL;
    lista * novo = NULL;

    novo = criar_elemento(10);

    ///Chama função para inserir novo elemento
    inserir_elemento(&inicio, novo);

    novo = criar_elemento(20);

    ///Chama função para inserir novo elemento
    inserir_elemento(&inicio, novo);

    novo = criar_elemento(30);

    ///Chama função para inserir novo elemento
    inserir_elemento(&inicio, novo);


    /*
    aux = inicio;

    ///Percorre a lista até o fim
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    ///Insere na lista
    aux->proximo = novo;
    */

    ///Exibe os elementos da lista
    aux = inicio;
    while(aux != NULL){
        printf("Val: %d \n", aux->numero);
        aux = aux->proximo;
    }



}


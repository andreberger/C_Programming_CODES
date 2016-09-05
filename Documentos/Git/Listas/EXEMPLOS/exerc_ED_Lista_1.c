#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

    lista * inicio_lista = *ptr_ptr_inicio;
    lista * aux = *ptr_ptr_inicio;

    if(inicio_lista == NULL){
        * ptr_ptr_inicio = novo;
    }else{

        while(aux->proximo != NULL){
            aux = aux->proximo;
        }

        aux->proximo = novo;
    }
}


void exibir_lista(lista * inicio){

    printf("\n");
    lista * aux = inicio;

    while(aux != NULL){
        printf("Val: %d \n", aux->numero);
        aux = aux->proximo;
    }

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

    ///Exibe os elementos da lista
    exibir_lista(inicio);
}


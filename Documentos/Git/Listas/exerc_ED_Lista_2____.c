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
    lista * aux = inicio;
    while(aux != NULL)
    {
        printf("%d ",aux->numero);
        aux = aux->proximo;
    }
}


lista * criar_lista_de_vetor(int * vetor, int tamanho){
    lista * lista;
    /// Utilizando as funçoes de lista,
    /// Criar e retornar uma lista de um vetor enviado para a função.



    return lista;
}

int main(){

    lista * inicio = NULL;

    int vet[]={5,6,9,2,12,45,6,8,12};

    inicio = criar_lista_de_vetor(vet, 10);

    ///Exibir os elementos da lista
    exibir_lista(inicio);
}


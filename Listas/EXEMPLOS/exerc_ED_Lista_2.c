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


lista * criar_lista_de_vetor(int * vetor, int tamanho){
    lista * lista = NULL, * novo;
    int i;

    for(i = 0; i < tamanho; i++){
        novo = criar_elemento(vetor[i]);
        inserir_elemento(&lista, novo);
    }

    return lista;
}

int main(){

    lista * inicio = NULL;

    int vet[] = {5, 6, 9, 2, 12, 45, 6, 8, 12, 7, 20, 49, 93, 85, 23, 54, 35, 15, 38, 185, 89, 1, 2, 8, 3, 69, 78};

    inicio = criar_lista_de_vetor(vet, sizeof(vet) / 4);

    exibir_lista(inicio);
}


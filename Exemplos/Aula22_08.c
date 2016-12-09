#include<stdio.h>
#include<stdlib.h>

typedef struct list{
int numero;
struct list*proximo;
}list;


void show(list *lista){
    while(lista!=NULL){
    printf("%d \n",lista->numero);
    lista=lista->proximo;
    }
}
//***********************************************************
//insert_at_start)(lista,novo)//inserir no inicio da lista
//***********************************************************

list * create_new_element(int numero){
    list * novo = (list *)malloc(sizeof(list));
    novo->numero=numero;
    novo->proximo=NULL;
    return novo;
}

list * insert(list * lista, list * novo){
if(lista==NULL)
    {
    return novo;
    }
else
    {
    list *aux=lista;
    while(aux->proximo!=NULL){
    aux=aux->proximo;
    }
    aux->proximo=novo;
    }
}

int main(){
list *inicio=NULL;
list *inicio_lista=NULL;
list *novo = create_new_element(1);
printf("%d \n",novo->numero);
inicio_lista=insert(inicio_lista,novo);
printf("%d \n",inicio_lista->numero);
novo = create_new_element(2);
inicio_lista=insert(inicio_lista,novo);
printf("%d \n",inicio_lista->numero);
printf("%d \n",novo->numero);

novo = create_new_element(3);
inicio_lista=insert(inicio_lista,novo);
printf("%d \n",novo->numero);
}

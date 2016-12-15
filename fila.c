#include<stdio.h>
#include<stdlib.h>


//DefiniÃ§Ã£o de cada elemento da fila
typedef struct elemento{
  int  valor;
  struct elemento * proximo;
}elemento;

//CriaÃ§Ã£o de um elemento da fila
elemento * cria_elemento(int valor){
  elemento * novo = malloc(sizeof(elemento));
  novo->valor = valor;
  novo->proximo = NULL;
  return novo;
}

//pilhas
void push(elemento ** topo, elemento * novo){
  novo->proximo = *topo;
  *topo = novo;
}

int empty(elemento * topo){
  if (topo == NULL){
    return 1;
  }else{
    return 0;
  }
}

elemento * pop(elemento ** topo){
   elemento * aux = *topo;
   if (empty(*topo) == 0){
      *topo = (*topo)->proximo;
      aux->proximo = NULL;
   }else{
      printf("A pilha esta vazia! \n");
   }
   return aux;
}

void mostrar_pilha(elemento * topo){
  int first = 1;
  if (topo != NULL){
     while(topo != NULL){
        printf("   ---\n");
        if (first){
           printf("   |%d| <---- Topo \n", topo->valor);
           first = 0;
        }else{
           printf("   |%d|\n", topo->valor);
        }
        if (topo->proximo == NULL){
           printf("   ---\n");
        }
        topo = topo->proximo;
     }
  }else{

     printf("A pilha esta vazia! \n");
  }
}











//Verifica se a fila estÃ¡ vazia

//Insere um elemento na fila seguindo o critÃ©rio FIFO
elemento * enqueue(elemento * fila, elemento * novo){
  elemento * aux = fila;
  if (aux == NULL){
    return novo;
  }else{
    while (aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->proximo = novo;
  }
  return fila;
}
//Remove um elemento da fila seguindo o critÃ©rio FIFO
elemento * dequeue(elemento ** fila){
  elemento * aux = *fila;
  if (aux != NULL){
      *fila = (*fila)->proximo;
      aux->proximo = NULL;
      return aux;
  }else{
    printf("A fila esta vazia! \n");
    return NULL;
  }
}

/**void converte(elemento * novo, elemento * pilha){
    int aux;
    while(aux != NULL){
        push(&topo, dequeue(&topo));
    }
}***/
//Mostra os elementos da fila
void mostrar_fila(elemento * fila){

    while(fila != NULL){
      printf(" |%d|", fila->valor);
      if (fila->proximo == NULL){
          printf("  ---\n");
      }
      fila = fila->proximo;
    }
}

//Monta o menu do programa
void monta_menu(){

  printf("//////////////////////////////////////////////////////////////// \n");
  printf("OperaÃ§Ãµes sobre Filas \n");
  printf("Selecione a OpÃ§Ã£o Desejada: \n");
  printf("  1 - Incluir \n");
  printf("  2 - Excluir \n");
  printf("  3 - Mostrar Fila \n");
  printf("  4 - Converte \n");
  printf("  0 - Sair \n");
  printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n \n");
  printf("Qual a sua opÃ§Ã£o: ");
}


int main(){
  int op = 1;
  int valor=0;


  elemento * ptr_inicio = NULL;
  elemento * excluido = NULL;
  elemento * novo = NULL;
  elemento * topo = NULL;
   elemento * auxiliar;

  do{
    monta_menu();
    scanf("%d", &op);
    //system("clear");
    switch(op){
      case 1:
          printf("Informe um valor para o novo elemento da fila: ");
          scanf("%d", &valor);
          novo = cria_elemento(valor);
          ptr_inicio = enqueue(ptr_inicio, novo);
          break;
      case 2:
          excluido = dequeue(&ptr_inicio);
          if (excluido != NULL){
            printf("Valor do elemento excluÃ­do: %d \n", excluido->valor);
            free(excluido);
          }
          break;
      case 3:
          mostrar_fila(ptr_inicio);
          break;

      case 4:
            auxiliar = dequeue(&ptr_inicio);
            while (auxiliar != NULL){
                push(&topo, auxiliar);
                auxiliar = dequeue(&ptr_inicio);
            }
            mostrar_pilha(topo);
      break;
    }
  }while (op != 0);


}

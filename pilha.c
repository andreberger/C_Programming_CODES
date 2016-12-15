//Operações sobre pilhas
#include<stdio.h>
#include<stdlib.h>


//Definição de cada elemento da pilha
typedef struct elemento{
  int  valor;
  struct elemento * proximo;
}elemento;

//Criação de um elemento da pilha
elemento * cria_elemento(int valor){
  elemento * novo = malloc(sizeof(elemento));
  novo->valor = valor;
  novo->proximo = NULL;
  return novo;
}

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

void monta_menu(){
   system("cls");
   printf("############################################\n");
   printf("Operacoes sobre Pilhas \n");
   printf("Selecione a Opcao Desejada: \n");
   printf("   1 - Incluir \n");
   printf("   2 - Excluir \n");
   printf("   3 - Mostrar Pilha \n");
   printf("   0 - Sair \n");
   printf("############################################\n \n");
   printf("Qual a sua opcao: ");
}


int main(){
  int op = 1;
  int valor=0;

  elemento * topo = NULL;
  elemento * excluido = NULL;

  do{
    monta_menu();
    scanf("%d", &op);

    switch(op){
       case 1:
          printf("Informe um valor para o novo elemento da pilha: ");
          scanf("%d", &valor);
          elemento * novo = cria_elemento(valor);
          push(&topo, novo);
          break;
       case 2:
          excluido = pop(&topo);
          if(excluido != NULL){
             printf("Elemento Removido: %d !", excluido->valor);
          }
          system("pause");
          break;
       case 3:
          mostrar_pilha(topo);
          system("pause");
          break;

    }
  }while (op != 0);
}

#include<sys/timeb.h>
#include<math.h>
#include<stdlib.h>

 struct timeb ini, fim;

 void geravetor(int vet[], int n){
   int i;
     srand(time(NULL));
     for(i = 0; i < n;i++){
      vet[i]= rand() % n;
     }
 }

 void apresenta_vetor(int a[], int N){
    int i;
    printf("|");
    for (i=0;i<N;i++)
       printf("%d|",a[i]);

    printf("\n");
 }

//BUSCA
int binary_search(int A[], int key, int imin, int imax){
    if (imax < imin){
        return -1;
    }else{
        int imid = (imin + imax) / 2;
        if (A[imid] > key){
            return binary_search(A, key, imin, imid-1);
        }else{
            if (A[imid] < key){
                return binary_search(A, key, imid+1, imax);
            }else{
                return imid;
            }
        }
    }
}
//ORDENACAO
void bubble_sort(int vet[], int n){
    int i, j, aux;
    for(i = 0; i < n; i++){
        j = i + 1;
        for(; j < n; j++){
            if(vet[i] > vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void selection_sort(int vet[], int n){
    int i, j, aux, idx_menor, trocar = 0;
    for(i = 0; i < n; i++){
        idx_menor = i;
        for(j = i + 1; j < n; j++){
           if (vet[j] < vet[idx_menor]){
                idx_menor = j;
                trocar = 1;
           }
        }
        if (trocar){
            aux = vet[idx_menor];
            vet[idx_menor] = vet[i];
            vet[i] = aux;
        }
    }
}

void insertion_sort(int vet[], int n){
    int i, j, val;
    for(i = 1; i < n; i++){
        val = vet[i];
        for(j = i - 1; j >= 0 && val < vet[j]; j--){
           vet[j + 1] = vet[j];
        }
        vet[j + 1] = val;
    }
}

int main(){
    int i;
    ftime(&ini); // obtem o tempo no inicio
    for(i = 0; i < 10000000; i++);
    ftime(&fim); // obtem o tempo no final
    // Computa o tempo gasto e imprime
    printf("tempo gasto: %f segundos \n", ((double) fim.time + ((double) fim.millitm * 0.001)) -
          ((double) ini.time + ((double) ini.millitm * 0.001)));
 }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>

typedef struct idx_typ{
    int codigo;
    int pos;
}idx_typ;

typedef struct loja_typ{
    int codigo;
    char nome[100];
    char cnpj[20];
    char uf[5];
    char endereco[100];
    int numero;
}loja_typ;

int main(){

    char path[] = "dados_trab_LP.dbd";
    char path_idx[] = "dados_trab_LP_idx.dbi";
    FILE * arq_data;
    FILE * arq_idx;
    idx_typ idx_r;
    loja_typ lj_r;
    int lojaCont = 0, i, s, p, p_seek = -1, codigo;

    if((arq_data = fopen(path, "rb")) == NULL)
        printf("Erro ao abrir arquivo: %s \n", path);
    if((arq_idx = fopen(path_idx, "wb")) == NULL)
        printf("Erro ao abrir arquivo: %s \n", path_idx);

    //Cria o arquivo de índices
    do{
       p = ftell(arq_data);
       s = fread(&lj_r, sizeof(loja_typ), 1, arq_data);
       if (s > 0){
            idx_r.codigo = lj_r.codigo;
            idx_r.pos = p;
            fwrite(&idx_r, sizeof(idx_typ),1 ,arq_idx);
            lojaCont++;
       }
    }while(s > 0);

    fflush(arq_idx);

    if(fclose(arq_data))
        printf("Erro ao fechar arquivo: %s \n", path);

    if(fclose(arq_idx))
        printf("Erro ao fechar arquivo: %s \n", path_idx);


    //Busca um registro do arquivo, usando o arquivo de índice
    //#################################################
    printf("Informe o codigo: \n");
    scanf("%d", &codigo);

    if((arq_idx = fopen(path_idx, "rb")) == NULL)
        printf("Erro ao abrir arquivo: %s \n", path_idx);

    while(fread(&idx_r,sizeof(idx_r),1,arq_idx)){
        if(codigo == idx_r.codigo){
            p_seek = idx_r.pos;
            break;
        }
    }
    if(fclose(arq_idx))
        printf("Erro ao fechar arquivo: %s \n", path_idx);

    //Se encontrou, apresenta osw dados
    if (p_seek != -1){
        if((arq_data = fopen(path, "rb")) == NULL)
            printf("Erro ao abrir arquivo: %s \n", path);

        fseek(arq_data,p_seek,SEEK_SET);
        s = fread(&lj_r, sizeof(loja_typ), 1, arq_data);

        printf("Estabelecimento: %d\t%s \nCNPJ: %s \nEndereco: %s, %d - UF: %s \n",lj_r.codigo, lj_r.nome, lj_r.cnpj,lj_r.endereco,lj_r.numero, lj_r.uf);

        if(fclose(arq_data))
            printf("Erro ao fechar arquivo: %s \n", path);
    }else{
        printf("Estabelecimento não cadastrado: %d \n", codigo);
    }
    //#################################################

}

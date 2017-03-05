#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
    Esta função conta o número de caracteres contidos em uma string.
*/
int strlen_fake(char * str){
    int c = 0;
    while(*str != '\0'){
        c++;
        str++;
    }
    return c;
}
/*
Essa função compara duas strings segundo sua ordem alfabética e retorna um inteiro.
Se esse inteiro for negativo, é porque a primeira string é menor que a segunda.
Se retornar um inteiro positivo, é porque a segunda string é maior que a primeira.
Se retornar 0, é porque as strings são idênticas.
*/
int strcmp_fake( char *lhs, char *rhs ){
   while(*lhs != '\0' && *rhs != '\0'){
        if(*lhs != *rhs){
            return *lhs > *rhs ? 1 : -1;
        }
        lhs++;
        rhs++;
   }

   if (*lhs == *rhs){
            return 0;
   }else{
       return *lhs == '\0' ? -1 : 1;
   }
}

/*
Retorna um ponteiro para a localização em que o caractere 'ch' aparece pela
primeira vez na string apontada por *str, ou NULL se não encontrar.
*/
char *strchr_fake( char *str, char ch ){
    while(*str != '\0' && *str != ch){
        str++;
    }
    return *str == '\0' ? NULL : str;
}

/*
Retorna um ponteiro que indica a primeira ocorrência da string 'substr' na string
'str'.
*/
char *strstr_fake( char* str, char* substr ){
    char * aux;
    char * loc;
    if (substr == NULL || *substr == '\0'){
        return str;
    }
    if (strlen_fake(str) < strlen_fake(substr)){
        return NULL;
    }
    aux = substr;
    loc = NULL;
    while(*str != '\0'){
        if (*str == *aux){
            if (loc == NULL){
                loc = str;
            }
            aux++;
            if (*aux == '\0'){
                return loc;
            }
        }else{
            aux = substr;
            loc = NULL;
        }
        str++;
    }
    return NULL;
}

/*
Concatena a string 'src' ao final da string 'dest'.
*/
char *strcat_fake( char * dest, char *src ){
    int size_src = strlen_fake(src);
    int size_dest = strlen_fake(dest);
    int i = 0, j = 0;

    char * new_dest = (char *)malloc(((size_dest + size_src + 1) * sizeof(char)));

    while(1){
        if(*(dest + i) != '\0'){
            *(new_dest + i) = *(dest + i);
            i++;
        }
        if(*(src + j) != '\0'){
            *(new_dest + size_dest + j) = *(src + j);
            j++;
        }

        if (*(dest + i) == '\0' && *(src + j) == '\0'){
            *(new_dest + size_dest + j) = '\0';
            break;
        }
        printf("%d %d\n", i, j);

    }

    return new_dest;
}

int contar_numero_palavras(char token, char * mString){
    int cont = 0;
    while(*mString != '\0'){
        if (*mString == token){
           cont++;
        }
        mString++;
    }
    return cont + 1;
}

void str_token(char token, char * mString, int * qtdPalavras, char *** palavras ){
    int i = 0;
    int last_p = 0;
    char * ptr_current = mString;
    *qtdPalavras = contar_numero_palavras(token, mString);
    *palavras = (char **) calloc(*qtdPalavras, sizeof(char *));
    char ** ptr_aux = *palavras;
    while(1){
        if (*(mString + i) == token || *(mString + i) == '\0'){
            (**palavras) = (char *) calloc(i - last_p + 1, sizeof(char));
            memcpy((**palavras), ptr_current, i - last_p );
            last_p = i + 1;
            ptr_current = mString + i + 1;
            if (*(mString + i) == '\0')
                break;

            (*palavras)++;
        }
        i++;
    }
    *palavras = ptr_aux;
}

int main(){
    char frase1[50] = "anaa";
    char frase2[50] = "anab";
    char frase7[50] = "ab";

    char token = '#';
    char mString [100];
    char ** palavras;
    int num_palavras = 0, i;

    printf("Resultados STRCMP_FAKE: \n\n");
    printf("\tstrcmp_fake(%s , %s) = %d \n", frase1, frase2, strcmp_fake(frase1,frase2));

    printf("Resultados STRCHR_FAKE: \n\n");
    printf("\tstrchr_fake(%s , %c) = %s \n", frase1, 'n', strchr_fake(frase1,'n'));

    printf("Resultados STRSTR_FAKE: \n\n");
    printf("\tstrstr_fake(%s , %s) = %s \n", frase2, frase7, strstr_fake(frase2, frase7));

    printf("Resultados STRCAT_FAKE: \n\n");
    printf("\tstrcat_fake(%s , %s) = %s \n", frase2, frase7, strcat_fake(frase2, frase7));

    strcpy(mString, "Hoje#o#dia#esta#chuvoso#mesmo#neh!");
    str_token(token, mString, &num_palavras, &palavras);
    for(i = 0; i < num_palavras; i++){
        printf("[%s] \n", *(palavras + i) );
    }
}

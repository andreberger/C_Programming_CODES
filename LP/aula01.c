#include <stdio.h>
#include <stdlib.h>

void exercicio01();
void exercicio02();
void exercicio03();
void exercicio04();
void exercicio05();
void exercicio06();
void exercicio07();
void exercicio08();
void exercicio09();
void exercicio10();
void exercicio11();
void exercicio12();

int main(){
    exercicio12();
    system("pause");
    return 0;
};
//------------------------------------------------------------------------------------------------------------------

//Exercicio 1
//20140220_1334 - Escreva um algoritmo que leia dois vetores de 10 posições
//e faça a multiplicação dos elementos de mesmo índice, colocando o
//resultado em um terceiro vetor. Mostre o vetor resultante.

void exercicio01(){
    int vet1[10];
    int vet2[10];
    int vetResultado[10];

    int numero;
    int x;

    for(x=0;x<10;x++){
        printf("Digite o %d numero para o vetor 1: ", x+1);
        scanf("%d", &numero);
        vet1[x] = numero;
    };

    for(x=0;x<10;x++){
        printf("Digite o %d numero para o vetor 2: ", x+1);
        scanf("%d", &numero);
        vet2[x] = numero;
    };

    printf("O resultado da mult. dos vetores ficou:\n");

    for(x=0;x<10;x++){
        vetResultado[x] = vet1[x] * vet2[x];
        printf("%d, ", vetResultado[x]);
    };
    printf("\n\n");
};

//Exercicio 2
//20140219_1427 - Escreva um programa para ler o nome e o endereço de um estudante.
//O programa deverá exibir o nome e endereço digitado.

void exercicio02(){
    char nomeAluno[30];
    char endAluno[70];

    printf("Digite seu nome aluno dos infernos: ");
    gets(nomeAluno);

    printf("Digite seu fim de mundo que o aluno mora: ");
    gets(endAluno);

    printf("\nDados do capetinha:\n");
    printf("Nome: %s\n", nomeAluno);
    printf("Endereco: %s\n\n", endAluno);

};

//Exercicio 3
//20140220_1335 - Escreva um algoritmo que leia um vetor de 10 elementos.
//A seguir, o algoritmo deverá trocar o 1º elemento com o 6 º, o 2 º com o 7 º... etc até o 5 º com 10 º
//e escrever o vetor modificado.

void exercicio03(){
    int vet1[10];
    int numero;
    int x;

    for(x=0;x<10;x++){
        printf("Digite o %d numero para o vetor 1: ", x+1);
        scanf("%d", &numero);
        vet1[x] = numero;
    };


    for(x=0;x<10;x++){
        if(x<5){
            numero = vet1[x+5];
            vet1[x+5] = vet1[x];
            vet1[x] = numero;
        }
    };

    printf("O resultado da inversao dos vetores ficou:\n");

    for(x=0;x<10;x++){
        printf("%d, ", vet1[x]);
    };
    printf("\n\n");

};

//Exercicio4
//20140219_1428 - Escreva um programa para ler em um vetor 15 numeros inteiros.
//O programa deverá exibir a soma e a média dos números fornecidos.

void exercicio04(){
    int vet1[15];
    int numero;
    int x;
    int soma;
    float media;

    for(x=0;x<15;x++){
        printf("Digite o %d numero para o vetor 1: ", x+1);
        scanf("%d", &numero);
        vet1[x] = numero;
    };

    for(x=0;x<15;x++){
        soma += vet1[x];
    };

    media = (float)soma/15;
    printf("\nA soma dos elementos: %d", soma);
    printf("\nA soma dos elementos: %.2lf\n\n", media);
};

//Exercicio5
//20140219_1429 - Escreva um programa com um vetor, chamado num, inicializado como: int num[20] = {1, 3, 5};
//Como pode ser observado, o vetor tem tamanho 20 mas foram fornecidos apenas 3 valores.
//O programa deverá preencher o restante do vetor usando a seguinte fórmula:
//num[i] = num[0]+num[1]+num[2]+?+num[i-1], para i=3,?19. Após preencher o vetor, apresente o vetor resultante.

void exercicio05(){
    int num[20] = {1, 3, 5};
    int i,j;
    int soma;
    soma=0;

    for(i=3;i<20;i++){
        for(j=0;j<i;j++){
            if(j!=i){
                num[i] += num[j];
            }
        }
    }

    for(i=0;i<20;i++){
        printf("posicao %d: \n", num[i]);
    }
};

//Exercicio06:
//20140219_1430 - Escreva um programa para calcular e exibir o número de acertos de cada aluno em uma prova.
//A prova é formada por 10 questões, cada uma com cinco alternativas (A, B, C, D e E). Para isso o programa deverá:
//o solicitar o gabarito da prova;
//o solicitar o número de alunos da turma;
//o solicitar a resposta dada por cada aluno para cada questão.

void exercicio06(){
    char gabarito[10];
    int numeroAlunos;
    char resposta;
    int acertos;
    int x, i;


    for(x=0;x<10;x++){
        printf("Digite o gabarito (%d): ", x+1);
        scanf("%c", &resposta);
        fflush(stdin);

        while(resposta != 'a' && resposta!='b' && resposta!='c' && resposta!='d' && resposta!='e'){
        //while(resposta != "a" || resposta!="b" || resposta!="c" || resposta!="d" || resposta!="e"){
            printf("Valor incorreto. Digite o gabarito (%d): ", x+1);
            scanf("%c", &resposta);
            fflush(stdin);
        }
        gabarito[x] = resposta;
    }


    printf("Informe o numero de alunos: ");
    scanf("%d", &numeroAlunos);
    fflush(stdin);

    for(i=0;i<numeroAlunos;i++){
        acertos = 0;
        for(x=0;x<10;x++){
            printf("Aluno %d - Digite a sua resposta (%d): ", i+1, x+1);
            scanf("%c", &resposta);
            fflush(stdin);

            while(resposta != 'a' && resposta!='b' && resposta!='c' && resposta!='d' && resposta!='e'){
                printf("Valor incorreto. Digite o gabarito (%d): ", x+1);
                scanf("%c", &resposta);
                fflush(stdin);
            }
            if(gabarito[x] == resposta){
                acertos += 1;
            }
        }
            printf("\n\nVoce acertou %d questoes.\n", acertos);
    }
}

//Exercicio07
//20140219_1431 - Para descobrir se um dado é viciado, podemos lança-lo diversas vezes e verificar se a ocorrência de
//uma das faces é significativamente maior que a ocorrência das demais faces. Faça um programa que solicite ao usuário
//o número de lançamentos que será realizado com o dado e apresente:
//O dado foi lançado 20 vezes.
//Os lançamentos geraram o seguinte resultado:
//Face	O	P
//1	3	15
//2	5	25
//3	2	10
//4	1	5
//5	1	5
//6	8	40
//Onde:
//O - Número de ocorrências da face
//P - Frequência percentual (Quanto o número de ocorrências representa sobre o total de lançamentos realizados.
//Ex: Das 20 vezes que o dado foi lançado, em 40% das vezes ocorreu a face 6)

void exercicio07(){
    int x;

    int numeroLancamentos;
    int face;

    int somaf1;
    int somaf2;
    int somaf3;
    int somaf4;
    int somaf5;
    int somaf6;

    somaf1 = 0;
    somaf2 = 0;
    somaf3 = 0;
    somaf4 = 0;
    somaf5 = 0;
    somaf6 = 0;

    printf("Quantas vezes voce deseja jogar o dado: ");
    scanf("%d", &numeroLancamentos);

    int facesCaidas[numeroLancamentos];

    for(x=0;x<numeroLancamentos;x++){
        printf("Qual face caiu o dado na jogada %d: ", x+1);
        scanf("%d", &face);
        fflush(stdin);
        while(face < 1 || face > 6){
            printf("Valor incorreto. Qual face caiu o dado na jogada %d: ", x+1);
            scanf("%d", &face);
            fflush(stdin);
        }

        facesCaidas[x] = face;
    }

    printf("\nO dado foi lancado %d vezes\n", numeroLancamentos);

    printf("\nOs lancamentos geraram o seguinte resultado:\n\n ");
    for(x=0;x<numeroLancamentos;x++){
        if(facesCaidas[x]==1){
            somaf1 += 1;
        }
        if(facesCaidas[x]==2){
            somaf2 += 1;
        }
        if(facesCaidas[x]==3){
            somaf3 += 1;
        }
        if(facesCaidas[x]==4){
            somaf4 += 1;
        }
        if(facesCaidas[x]==5){
            somaf5 += 1;
        }
        if(facesCaidas[x]==6){
            somaf6 += 1;
        }
    }

    printf("\nFace 1 : O = %d , P = %d\n", somaf1, (somaf1*100)/numeroLancamentos);
    printf("Face 2 : O = %d , P = %d\n", somaf2, (somaf2*100)/numeroLancamentos);
    printf("Face 3 : O = %d , P = %d\n", somaf3, (somaf3*100)/numeroLancamentos);
    printf("Face 4 : O = %d , P = %d\n", somaf4, (somaf4*100)/numeroLancamentos);
    printf("Face 5 : O = %d , P = %d\n", somaf5, (somaf5*100)/numeroLancamentos);
    printf("Face 6 : O = %d , P = %d\n", somaf6, (somaf6*100)/numeroLancamentos);


}

//Exercicio08
//* 20140217_1044 - Faça um programa que lê uma cadeia de caracteres de letras maiusculas e a transforma em uma cadeia de caracteres
//de letras minúsculas. Em seguida, imprima a cadeia de caracteres resultante.
void exercicio08(){
    char cadeia[8];
    char resposta;
    int x;

    for(x=0;x<8;x++){
        printf("Digite uma letra (MAIUSCULA) (%d): ", x+1);
        scanf("%c", &resposta);
        fflush(stdin);
        cadeia[x] = tolower(resposta);
    }

    for(x=0;x<8;x++){
        printf("\nAs respectivas letras (minusculas) (%d): %c", x+1, cadeia[x]);
    }

    printf("\n");
}

//20140217_1045 - Uma palavra ou frase é classificada como palíndrome, se ela é a mesma palavra quando lida nos dois sentidos
//(esquerda -> direita ou direita -> esquerda). Faça um programa que lê uma cadeia de caracteres e diz se a cadeia é palíndrome ou não.

void exercicio09(){
    char capturaPalavra[300]="";
    char invertePalavra[300]="";
    int iPalindrome;
    int x,i;
    int tamanho;

    iPalindrome = 0;
    tamanho = 0;

    printf("VERIFICADOR DE PALINDROMES\n\n");
    printf("Digite uma palavra: ");
    gets(capturaPalavra);
    fflush(stdin);

    while(capturaPalavra[tamanho]!='\0'){
        tamanho+=1;
    }

    tamanho-=1;
    i=0;
    for(x=tamanho;x>=0;x--){
        //printf("%c", capturaPalavra[x]);
        invertePalavra[i] = capturaPalavra[x];
        i+=1;
    }

    for(x=tamanho;x>=0;x--){
        //printf("%c", capturaPalavra[x]);
        if(invertePalavra[x] != capturaPalavra[x]){
            iPalindrome = 1;
        }
    }

    printf("Palavra inversa: %s", invertePalavra);

    if(iPalindrome==1){
        printf("\nPalindrome = nao\n\n");
    }else{
        printf("\nPalindrome = sim\n\n");
    }
}

//Exercicio10
//20140217_1046 - O imperador romano Júlio César foi um dos precursores em métodos criptográficos, criando a Cifra de César.
//A Cifra de César considera a ordem dos caracteres no alfabeto e troca cada letra da palavra a ser cifrada pela k-ésima letra do alfabeto,
// seguinte a letra da palavra. Por exemplo, se k = 3, então uma ocorrência da letra 'A' é trocada pela letra 'D'.
//A letra 'B' é trocada pela letra 'E' e assim sucessivamente. Esta substituição é feita de maneira cíclica,
//que neste caso a letra 'Z' é trocada pela 'C'. Faça um programa que leia um inteiro k e uma cadeia de caracteres e imprime a mensagem cifrada correspondente.

void exercicio10(){
    int k, x;
    int validaK;
    int codASCII;
    char senha[10];

    printf("Digite uma senha: ");
    gets(senha);
    fflush(stdin);

    printf("\nDigite um numero de 0-25: ");
    scanf("%d", &k);

    //<-- Esta função força o k a ser de 0 a 25
    validaK = (int)(k/25);
    k = k - validaK*25;
    //--> Esta função força o k a ser de 0 a 25

    for(x=0;x<10;x++){
        codASCII = senha[x];

        if(codASCII+k > 122){
            codASCII = 97+k;
        }else{
            codASCII += k;
        }

        printf("%c - ", codASCII);
    }
}

//Exercicio11
//20140217_1047 - Faça um programa que lei um numero inteiro k e uma cadeia de caracteres cifrada(pela Cifra de César) e imprime a mensagem decriptografada.
void exercicio11(){
    int k, x;
    int validaK;
    int codASCII;
    char senha[10];

    printf("Digite uma senha: ");
    gets(senha);
    fflush(stdin);

    printf("\nDigite um numero de 0-25: ");
    scanf("%d", &k);

    //<-- Esta função força o k a ser de 0 a 25
    validaK = (int)(k/25);
    k = k - validaK*25;
    //--> Esta função força o k a ser de 0 a 25

    for(x=0;x<10;x++){
        codASCII = senha[x];

        if(codASCII+k < 97){
            codASCII = 122-k;
        }else{
            codASCII -= k;
        }

        printf("%c - ", codASCII);
    }
}

//Exercicio12
//20140219_1432 - Dadas duas seqüências com n números inteiros entre 0 e 9, interpretadas como dois números inteiros de n algarismos,
//calcular a seqüência de números que representa a soma dos dois inteiros.
//Exemplo: n = 8,
//1ª seqüência 8 2 4 3 4 2 5 1
//2ª seqüência + 3 3 7 5 2 3 3 7
//1 1 6 1 8 6 5 8 8
void exercicio12(){
    int lista1[10] = {1,2,3,4,5,6,7,8,9,0};
    int lista2[10] = {5,5,5,5,5,5,5,5,5,5};
    int listaResultado[11];
    int x;
    int valorAux;

    valorAux = 0;
    for(x=9;x>=0;x--){
        listaResultado[x] = lista1[x] + lista2[x] + valorAux;
        if(listaResultado[x] >= 10){
             valorAux = 1;
             listaResultado[x] = listaResultado[x] -10;
        }else{
             valorAux = 0;
        }
    }

    printf("Resultado da soma: \n\n");
    for(x=0;x<10;x++){
        printf("%d",listaResultado[x]);
    }
    printf("\n\n");
}

//
//typedef struct lista{
//    int codigo;
//    struct lista*proximo;
//}lista;


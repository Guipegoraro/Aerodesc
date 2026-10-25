#include <stdio.h>
#include "modelo_dados.h"


int main(){

   char nomeArquivo[64] = "";;
    char nome[NOME_TAM];
    char CPF[CPF_TAM];
    char telefone[TELEFONE_TAM];
    int id = 0;
    FILE *arq;

    arq = fopen(nomeArquivo,"w" );
    if(arq == NULL){
        printf("Erro ao criar arquivo \n");
     } else { 
            fprintf(arq, "%d", id++);

            printf("Nome: ");
            scanf("%s", &nome);  
            fprintf(arq, ";%s", nome);

            printf("Cpf: ");
            scanf("%s", &CPF);
            fprintf(arq, ";%s", CPF);

            printf("Telefone: ");
            scanf("%s", &telefone);
            fprintf(arq, ";%s", telefone);

         fscanf(arq, "%d,%s,%s,%s", &id, nome, CPF, telefone) != EOF;
         printf("%d;%s;%s;%s\n", id, nome, CPF, telefone);
          
     }

     }  
        

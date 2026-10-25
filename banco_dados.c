#include "modelo_dados.h"
#include <stdio.h>
#include <stdlib.h>

void dbSalvarUltimoIdValido();

void dbSalvarPassageiro(Passageiro *passageiro){
	char nomeArquivo[64] = "";
	snprintf(nomeArquivo, sizeof(nomeArquivo), "banco_dados/id%d.txt", passageiro->id);
	FILE *arq;
	arq = fopen(nomeArquivo,"w" );
    if(arq == NULL){
        printf("Erro ao criar arquivo \n");
		return ;
	} 	
	fprintf(arq, "%d", passageiro -> id);
	fprintf(arq, ";%s", passageiro -> nome);
	fprintf(arq, ";%s", passageiro -> cpf);
	fprintf(arq, ";%s\n", passageiro -> telefone);

	fclose(arq);
	dbSalvarUltimoIdValido();
}

Passageiro dbCarregarPassageiro(int id){
	Passageiro passageiro = {0};
	char nomeArquivo[64];
	FILE *arq;
	snprintf(nomeArquivo, sizeof(nomeArquivo), "banco_dados/id%d.txt", id);
	arq = fopen(nomeArquivo,"r");
	if(arq == NULL){
        printf("Passageiro não encontrado \n");
		return passageiro;
	}
	fscanf(arq, "%d;%30[^;];%11[^;];%11[^\n]", &passageiro.id, passageiro.nome, passageiro.cpf, passageiro.telefone);	
 	fclose(arq);
	return passageiro;
}

void dbCarregarUltimoIdValido(){
	FILE *arq;
	arq = fopen("banco_dados/ultimo_id.txt", "r");
	if(arq == NULL){
		return;
	}
	fscanf(arq,"%d", &ULTIMO_ID_VALIDO);
	fclose(arq);

}

void dbSalvarUltimoIdValido(){
	FILE *arq;
	arq = fopen("banco_dados/ultimo_id.txt","w");
	if(arq == NULL){
		printf("Id não localizado \n");
		return;
		}
	fprintf(arq,"%d\n", ULTIMO_ID_VALIDO);
	fclose(arq);
	
}
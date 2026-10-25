#include "modelo_dados.h"

void dbSalvarUltimoIdValido();

void dbSalvarPassageiro(Passageiro *passageiro){
	char nomeArquivo[32] = "";
	snprintf(nomeArquivo, sizeof(nomeArquivo), "id%d.txt", passageiro->id);
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
	char nomeArquivo[32];
	FILE *arq;
	snprintf(nomeArquivo, sizeof(nomeArquivo), "id%d.txt", id);
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
	//logica para carregar ultimo id valido
}


void dbSalvarUltimoIdValido(){
	//logica para salvar ultimo id valido
}
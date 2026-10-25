#include "modelo_dados.h"
#include <stdio.h>

void dbSalvarUltimoIdValido();

void dbSalvarPassageiro(Passageiro *passageiro){
	char passageiros[] = "passageiros.txt";
	FILE *arq;
	arq = fopen(passageiros,"a" );
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
	
	Passageiro passageiro = {id, "Andre", "123", "456"};
	return passageiro;
}

void dbCarregarUltimoIdValido(){
	//logica para carregar ultimo id valido
}


void dbSalvarUltimoIdValido(){
	//logica para salvar ultimo id valido
}
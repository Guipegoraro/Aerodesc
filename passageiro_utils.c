#include "modelo_dados.h"
#include <stdio.h>
#include <string.h>

int CriarPassageiro() {
	Passageiro passageiro;

	ULTIMO_ID_VALIDO = ULTIMO_ID_VALIDO + 1;

	passageiro.id = ULTIMO_ID_VALIDO;

	printf("Preencha os dados do passageiro:\nNome: ");
	char nome[NOME_TAM];
	scanf("%s", nome);
	while (strlen(nome) > NOME_TAM) {
		printf("Limite de 30 caracteres para nome, digite novamente: ");
		scanf("%s", nome);
	}
	
	printf("Telefone: ");
	char telefone[TELEFONE_TAM];
	scanf("%s", telefone);
	while (strlen(telefone) > TELEFONE_TAM) {
		printf("Limite de 11 caracteres para telefone, digite novamente: ");
		scanf("%s", telefone);
	}
	
	printf("CPF: ");
	char cpf[CPF_TAM];
	scanf("%s", cpf);
	while (strlen(cpf) > CPF_TAM) {
		printf("Limite de 11 caracteres para CPF, digite novamente: ");
		scanf("%s", cpf);
	}
	
	strcpy(passageiro.nome, nome);
	strcpy(passageiro.telefone, telefone);
	strcpy(passageiro.cpf, cpf);

	DbSalvarPassageiro(&passageiro);

	return 0;
}
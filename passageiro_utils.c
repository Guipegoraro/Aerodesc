#include "modelo_dados.h"
#include "banco_dados.c"
#include <stdio.h>
#include <string.h>

Passageiro criarPassageiro() {
	Passageiro passageiro;

	ULTIMO_ID_VALIDO = ULTIMO_ID_VALIDO + 1;

	passageiro.id = ULTIMO_ID_VALIDO;

	printf("Preencha os dados do passageiro:\nNome (limite 30 caracteres): ");
	char nome[NOME_TAM];
	scanf("%30s", nome);

	printf("Telefone (limite 11 caracteres): ");
	char telefone[TELEFONE_TAM];
	scanf("%11s", telefone);

	printf("CPF (limite 11 caracteres): ");
	char cpf[CPF_TAM];
	scanf("%11s", cpf);

	strcpy(passageiro.nome, nome);
	strcpy(passageiro.telefone, telefone);
	strcpy(passageiro.cpf, cpf);

	dbSalvarPassageiro(&passageiro);

	return passageiro;
}

int editarPassageiro(int id) {
	Passageiro passageiro = dbCarregarPassageiro(id);

	printf("Preencha os dados do passageiro, ENTER mantém valor atual:\nNome [%s]: ", passageiro.nome);
	char nome[NOME_TAM];
	scanf("%s", nome);
	if (nome[0] != '\0') {
		while (strlen(nome) > NOME_TAM) {
			printf("Limite de 30 caracteres para nome, digite novamente: ");
			scanf("%s", nome);
		}
		strcpy(passageiro.nome, nome);
	}

	printf("Telefone [%s]: ", passageiro.telefone);
	char telefone[TELEFONE_TAM];
	scanf("%s", telefone);
	if (telefone[0] != '\0') {
		while (strlen(telefone) > TELEFONE_TAM) {
			printf("Limite de 11 caracteres para telefone, digite novamente: ");
			scanf("%s", telefone);
		}
		strcpy(passageiro.telefone, telefone);
	}

	printf("CPF [%s]: ", passageiro.cpf);
	char cpf[CPF_TAM];
	scanf("%s", cpf);
	if (cpf[0] != '\0') {
		while (strlen(cpf) > CPF_TAM) {
			printf("Limite de 11 caracteres para CPF, digite novamente: ");
			scanf("%s", cpf);
		}
		strcpy(passageiro.cpf, cpf);
	}

	dbSalvarPassageiro(&passageiro);

	return 0;
}

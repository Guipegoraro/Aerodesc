#include "banco_dados.c"
#include "modelo_dados.h"
#include <stdio.h>
#include <string.h>

Passageiro criarPassageiro() {
	Passageiro passageiro;

	ULTIMO_ID_VALIDO = ULTIMO_ID_VALIDO + 1;

	passageiro.id = ULTIMO_ID_VALIDO;

	printf("Preencha os dados do passageiro:\nNome (limite 30 caracteres): ");
	char nome[NOME_TAM];
	fgets(nome, NOME_TAM, stdin);

	printf("Telefone (limite 11 caracteres): ");
	char telefone[TELEFONE_TAM];
	fgets(telefone, TELEFONE_TAM, stdin);

	printf("CPF (limite 11 caracteres): ");
	char cpf[CPF_TAM];
	fgets(cpf, CPF_TAM, stdin);

	strcpy(passageiro.nome, nome);
	strcpy(passageiro.telefone, telefone);
	strcpy(passageiro.cpf, cpf);

	dbSalvarPassageiro(&passageiro);

	return passageiro;
}

Passageiro editarPassageiro(int id) {
	Passageiro passageiro = dbCarregarPassageiro(id);

	printf("Preencha os dados do passageiro, ENTER mantém valor atual:\nNome [%s]: ", passageiro.nome);
	char nome[NOME_TAM];
	fgets(nome, NOME_TAM, stdin);
	if (nome[0] != '\n') {
		strcpy(passageiro.nome, nome);
	}

	printf("Telefone [%s]: ", passageiro.telefone);
	char telefone[TELEFONE_TAM];
	fgets(telefone, TELEFONE_TAM, stdin);
	if (telefone[0] != '\n') {
		strcpy(passageiro.telefone, telefone);
	}

	printf("CPF [%s]: ", passageiro.cpf);
	char cpf[CPF_TAM];
	fgets(cpf, CPF_TAM, stdin);
	if (cpf[0] != '\n') {
		strcpy(passageiro.cpf, cpf);
	}

	dbSalvarPassageiro(&passageiro);

	return passageiro;
}

int buscarPassageiro(char *busca) { //lista passageiros que contem texto, falta terminar
	Passageiro *passageiros;
	int quantidade = dbCarregarTodosPassageiros(passageiros);
	int *escolhidos;
	int iteradorEscolhidos = 0;

	for (int i = 0; quantidade - 1 < i; i++) {
		if (strstr(passageiros[i].nome, busca)) {
			escolhidos = realloc(escolhidos, ++iteradorEscolhidos);
			escolhidos[iteradorEscolhidos] = i;
		}
	}

	for (int i = 0; iteradorEscolhidos < i; i++) {
		printf("ID: %d, Nome: %s", passageiros[escolhidos[i]].id, passageiros[escolhidos[i]].nome);
	}

}

#include "modelo_dados.h"
#include <stdio.h>
#include <stdlib.h>

void dbSalvarUltimoIdValido();

void dbSalvarPassageiro(Passageiro *passageiro) {
	char passageiros[] = "passageiros.txt";
	FILE *arq;
	arq = fopen(passageiros, "a");
	if (arq == NULL) {
		printf("Erro ao criar arquivo \n");
		return;
	}
	fprintf(arq, "%d", passageiro->id);
	fprintf(arq, ";%s", passageiro->nome);
	fprintf(arq, ";%s", passageiro->cpf);
	fprintf(arq, ";%s\n", passageiro->telefone);

	fclose(arq);
	dbSalvarUltimoIdValido();
}

Passageiro dbCarregarPassageiro(int id) {

	Passageiro passageiro = {id, "Andre", "123", "456"};
	return passageiro;
}

int dbCarregarTodosPassageiros(Passageiro *passageiros) {
	int quantidade = 5;
	passageiros = (Passageiro *)malloc(quantidade * sizeof(Passageiro));

	// test data
	passageiros[0] = (Passageiro){1, "Maria Silva", "47991110001", "12345678901", NULL};
	passageiros[1] = (Passageiro){2, "Joao Pereira", "47991110002", "23456789012", NULL};
	passageiros[2] = (Passageiro){3, "Ana Souza", "47991110003", "34567890123", NULL};
	passageiros[3] = (Passageiro){4, "Carlos Oliveira", "47991110004", "45678901234", NULL};
	passageiros[4] = (Passageiro){5, "Beatriz Lima", "47991110005", "56789012345", NULL};

	return quantidade;
}

void dbCarregarUltimoIdValido() {
	// logica para carregar ultimo id valido
}

void dbSalvarUltimoIdValido() {
	// logica para salvar ultimo id valido
}
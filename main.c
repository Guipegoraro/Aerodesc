#include "modelo_dados.h"
#include <stdio.h>
#include <stdlib.h>
#include  "passageiro_utils.c"
#define PASTA_BANCO "banco_dados/"

int ULTIMO_ID_VALIDO = 0;

int main(){
	dbCarregarUltimoIdValido();
}
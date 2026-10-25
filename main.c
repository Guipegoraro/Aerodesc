#include "modelo_dados.h"
#include <stdio.h>
#include <stdlib.h>
#include  "passageiro_utils.c"

int ULTIMO_ID_VALIDO = 0;

int main(){
	dbCarregarUltimoIdValido();

	criarPassageiro();

}
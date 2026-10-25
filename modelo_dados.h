#ifndef modelo_dados
#define modelo_dados

extern int ULTIMO_ID_VALIDO;

enum TamanhosTipos
{
  NOME_TAM = 31, //salvando string com tamanho + espaço para /0
  TELEFONE_TAM = 12,
  CPF_TAM = 12,
  ORIGEM_DESTINO_TAM = 31,
  HORARIO_TAM = 6,
  DATA_TAM = 12,
};


typedef struct 
{
  int id;
  int idViagem;
  int idPassageiro;
} Reserva;

typedef struct 
{
  int id;
  char nome[NOME_TAM];
  char telefone[TELEFONE_TAM];
  char cpf[CPF_TAM];
  Reserva *reservas;
} Passageiro;

typedef struct
{
  int id;
  char origem[ORIGEM_DESTINO_TAM];
  char destino[ORIGEM_DESTINO_TAM];
  char horario[HORARIO_TAM];
  char data[DATA_TAM];
  Passageiro *passageiros;
} Viagem;



void dbSalvarPassageiro(Passageiro *passageiro);
Passageiro dbCarregarPassageiro(int id);
void dbCarregarUltimoIdValido();

Passageiro criarPassageiro();

#endif
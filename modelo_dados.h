#ifndef modelo_dados
#define modelo_dados

static const int TELEFONE_TAM = 12; //salvando string com tamanho + espaço para /0
static const int NOME_TAM = 31;
static const int CPF_TAM = 12;
static const int ORIGEM_DESTINO_TAM = 31;
static const int HORARIO_TAM = 6;
static const int DATA_TAM = 11;



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
  char CPF[CPF_TAM];
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

extern int ULTIMO_ID_VALIDO;

#endif
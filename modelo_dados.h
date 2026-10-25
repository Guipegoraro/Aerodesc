#ifndef modelo_dados
#define modelo_dados


typedef struct 
{
  int id;
  int idViagem;
  int idPassageiro;
} Reserva;

typedef struct 
{
  int id;
  char nome[30];
  char telefone[11];
  char CPF[11];
  Reserva *reservas;
} Passageiro;

typedef struct
{
  int id;
  char origem[30];
  char destino[30];
  char horario[5];
  char data[10];
  Passageiro *passageiros;
} Viagem;

extern int ULTIMO_ID_VALIDO;

#endif
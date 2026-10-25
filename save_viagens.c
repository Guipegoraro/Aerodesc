#include <stdio.h>
#include "modelo_dados.h"


int main(){

    char Viagens[] = "Viagens.txt";
    char origem[ORIGEM_DESTINO_TAM];
    char destino[ORIGEM_DESTINO_TAM];
    char horario[HORARIO_TAM];
    char data[DATA_TAM];
    int id = 0;
    FILE *arq;

    arq = fopen(Viagens,"a" );
    if(arq == NULL){
        printf("Erro ao criar arquivo \n");
     } else { 
            fprintf(arq, "%d", id++);

            printf("Origem: ");
            scanf("%s", &origem);  
            fprintf(arq, ";%s", origem);

            printf("Destino: ");
            scanf("%s", &destino);
            fprintf(arq, ";%s", destino);

            printf("Horario: ");
            scanf("%s", &horario);
            fprintf(arq, ";%s", horario);

            printf("Data: ");
            scanf("%s", &data);
            fprintf(arq, ";%s", data);


         fscanf(arq, "%d,%s,%s,%s,%s", &id, origem, destino, horario, data) != EOF;
         printf("%d;%s;%s;%s;%s\n", id, origem, destino, horario, data);
          
     }
        fclose(arq);
     }  
        

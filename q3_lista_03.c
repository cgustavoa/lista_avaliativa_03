#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // biblioteca para manipulacao de caracteres


int verificaFormatoPlaca(char *placa){  // verificando se a placa esta em um formato válido
    return (strlen(placa) == 8 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&    // Verificando se a placa está no formato antigo (LLL-NNNN) ou no formato novo (LLLNLNN)
            isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7]) &&
            placa[3] == '-') ||
           (strlen(placa) == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
            isdigit(placa[3]) && isalpha(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]));
}


int verificaRodizio(char *placa, char *dia_semana){    // verificando se o veículo pode circular no dia da semana especificado
    int ultimo_digito = placa[strlen(placa) - 1] - '0';

    if(strcmp(dia_semana, "SEGUNDA-FEIRA") == 0){    
        // verifica o dia da semana e aplica as restrições
        return ultimo_digito != 0 && ultimo_digito != 1;
    } else if(strcmp(dia_semana, "TERCA-FEIRA") == 0){
        return ultimo_digito != 2 && ultimo_digito != 3;
    } else if(strcmp(dia_semana, "QUARTA-FEIRA") == 0){
        return ultimo_digito != 4 && ultimo_digito != 5;
    } else if(strcmp(dia_semana, "QUINTA-FEIRA") == 0){
        return ultimo_digito != 6 && ultimo_digito != 7;
    } else if(strcmp(dia_semana, "SEXTA-FEIRA") == 0){
        return ultimo_digito != 8 && ultimo_digito != 9;
    } else if(strcmp(dia_semana, "SABADO") == 0 || strcmp(dia_semana, "DOMINGO") == 0){
        return -1;
    } else {
        return -2;
    }
}

void tranformarMiusculoParaMinusculo(char*dia_semana){
    for (int i = 0; i < strlen(dia_semana); i++) {
        dia_semana[i] = tolower(dia_semana[i]);
    }
}

int main(){
    char placa[9];
    char dia_semana[30];
    scanf("%s", placa);
    scanf(" %s", dia_semana);

    // Verifica se a placa está em um formato válido
    if (verificaFormatoPlaca(placa)) {
        // Verifica se o veículo pode circular no dia da semana especificado
        if (verificaRodizio(placa, dia_semana) == 1) {
            tranformarMiusculoParaMinusculo(dia_semana);
            printf("%s pode circular %s\n", placa, dia_semana);
        } else if (verificaRodizio(placa, dia_semana) == 0){
            tranformarMiusculoParaMinusculo(dia_semana);
            printf("%s nao pode circular %s\n", placa, dia_semana);
        }else if(verificaRodizio(placa, dia_semana) == -1){
            printf("Nao ha proibicao no fim de semana\n");
        } else if(verificaRodizio(placa, dia_semana) == -2){
            printf("Dia da semana invalido\n");
        } 
    } else {
            printf("Placa invalida\n");
            if(verificaRodizio(placa, dia_semana) == -2){
            printf("Dia da semana invalido\n");
        } 
    }
    return 0;
}

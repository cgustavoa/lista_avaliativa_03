#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//PROBLEMAS NO ELSE IF  DO SABADO E DOMINGO"NAO HA PROIBIÇÃO NO FIM DE SEMANA"

int verificaFormatoPlaca(char *placa){  // verificando se a placa esta em um formato válido

    return (strlen(placa) == 8 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&    // Verificando se a placa está no formato antigo (LLL-NNNN) ou no formato novo (LLLNLNN)
            isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7]) &&
            placa[3] == '-') ||
           (strlen(placa) == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
            isdigit(placa[3]) && isalpha(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]));
}


int verificaRodizio(char *placa, char *dia_semana){    // verificando se o veículo pode circular no dia da semana especificado
    int ultimo_digito = placa[strlen(placa) - 1] - '0';

    if(strcmp(dia_semana, "SEGUNDA-FEIRA") == 0){           // verifica o dia da semana e aplica as restrições
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
        return 1;
    } else{
        printf("Dia da semana inválido.\n");
        return 0;
    }
}

int main(){
    char placa[9];
    char dia_semana[10];

    printf("Digite a placa do veículo: ");
    scanf("%s", placa);

    for (int i = 0; i < strlen(placa); i++){ // convertendo a placa para maiúsculas para facilitar a comparação
        placa[i] = 
        placa[i] =

       
    toupper(placa[i]);
    }

    printf("Digite o dia da semana: ");
    scanf("%s", dia_semana);

    // Verifica se a placa está em um formato válido
    if (verificaFormatoPlaca(placa)) {
        // Verifica se o veículo pode circular no dia da semana especificado
        
       
    if (verificaRodizio(placa, dia_semana)) {
        printf("O veículo(COLOCAR PARA IMPRIMIR A PLACA) pode circular neste dia(COLOCAR PARA IMPRIMIR O DIA).\n");
    } else {
        printf("O veículo(COLOCAR PARA IMPRIMIR A PLACA) não pode circular neste dia(COLOCAR PARA IMPRIMIR O DIA).\n");
    }/*else if(verificaRodizio(placa, dia_semana) == "SABADO", "DOMIGO"){
        printf("Nao ha proibicao no fim de semana.\n");*/
    } else{
        printf("Placa invalida.\n");
    }   
return 0;
}

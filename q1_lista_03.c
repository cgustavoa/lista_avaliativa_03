#include <stdio.h>
#include <string.h>

int valorDecimal(char c){
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1;  // para caractere invalido
    }
}

int romanoParaDecimal(char *romano){
    int resultado = 0;
    int i;
    for (i = 0; romano[i]; i++) {
        if (valorDecimal(romano[i]) < valorDecimal(romano[i + 1])) {
            resultado-= valorDecimal(romano[i]);
        } else {
            resultado+= valorDecimal(romano[i]);
        }
    }

    return resultado;
}


void decimalParaBinario(int numeroDecimal, char binario[]){
    binario[0] = '\0';

   while (numeroDecimal > 0) {
        char digito[2];
        sprintf(digito, "%d", numeroDecimal % 2);
        strcat(binario, digito);
        numeroDecimal = numeroDecimal / 2;
    }

    int tamanho= strlen(binario);
    for (int i = 0; i < tamanho / 2; i++) {
        char temp = binario[i];
        binario[i] = binario[tamanho - 1 - i];
        binario[tamanho - 1 - i] = temp;
    }
}

void decimalParaHexadecimal(int numeroDecimal, char digitosHexadecimais[]){
   int i = 0, resto;
   digitosHexadecimais[0] = '\0';

    while (numeroDecimal > 0) {
        resto = numeroDecimal % 16;
        char dig[2];
        if (resto < 10) {
            sprintf(dig,"%d",resto);
        } else {
             sprintf(dig, "%c", resto - 10 + 'a');
        }
        strcat(digitosHexadecimais, dig);
        numeroDecimal = numeroDecimal / 16;
        i++;
    }
    int comprimento = strlen(digitosHexadecimais);
    for (int i = 0; i < comprimento / 2; i++) {
        char temp = digitosHexadecimais[i];
        digitosHexadecimais[i] = digitosHexadecimais[comprimento - 1 - i];
        digitosHexadecimais[comprimento - 1 - i] = temp;
    }
}

int main(){
    char numeroRomano[13], binario[32], hexadecimal[100];
    int numeroDecimal;


    scanf("%s", numeroRomano);

    numeroDecimal = romanoParaDecimal(numeroRomano);

    decimalParaBinario(numeroDecimal, binario);

    decimalParaHexadecimal(numeroDecimal, hexadecimal);

    printf("%s na base 2: %s\n",numeroRomano, binario);
    printf("%s na base 10: %d\n",numeroRomano, numeroDecimal);
    printf("%s na base 16: %s\n",numeroRomano, hexadecimal);
    return 0;
}

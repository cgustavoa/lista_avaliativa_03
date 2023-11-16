#include <stdio.h>
#include <string.h>

// ALGUM ERRO MIRABOLANTE (W?) E ESPAÇO NO PRINTF DA MAIN
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


void decimalParaBinario(int numeroDecimal){
    if(numeroDecimal == 0){
        return;
    }

    decimalParaBinario(numeroDecimal / 2);

}

void decimalParaHexadecimal(int numeroDecimal){
    char digitosHexadecimais[] = "0123456789abcdef";

    if(numeroDecimal == 0){
        return;
    }

    decimalParaHexadecimal(numeroDecimal / 16);

}

int main(){
    char numeroRomano[13], binario[32], hexadecimal[100];
    int numeroDecimal;


    scanf("%s", numeroRomano);

    numeroDecimal = romanoParaDecimal(numeroRomano);

    decimalParaBinario(numeroDecimal);

    decimalParaHexadecimal(numeroDecimal);

    printf("%s na base 2: %s\n",numeroRomano, binario);
    printf("%s na base 10: %d\n",numeroRomano, numeroDecimal);
    printf("%s na base 16: %s\n",numeroRomano, hexadecimal);
    return 0;
}


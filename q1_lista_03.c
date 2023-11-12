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

int romanoParaDecimal(char romano[]){       // funcao para converter um número romano para decimal
    int resultado = 0;
    int i;

    for(i = 0; i < strlen(romano); i++){
        int valor1 = valorDecimal(romano[i]);

        if (i + 1 < strlen(romano)) {
            int valor2 = valorDecimal(romano[i + 1]);

            if (valor1 >= valor2) {
                resultado = resultado + valor1;
            } else {
                resultado = resultado + valor2 - valor1;
                i++;
            }
        } else {
            resultado = resultado + valor1;
        }
    }

    return resultado;
}

void decimalParaBinario(int numeroDecimal){
    if(numeroDecimal == 0){
        return;
    }

    decimalParaBinario(numeroDecimal / 2);
    printf("%d", numeroDecimal % 2);
}

void decimalParaHexadecimal(int numeroDecimal){
    char digitosHexadecimais[] = "0123456789ABCDEF";

    if(numeroDecimal == 0){
        return;
    }

    decimalParaHexadecimal(numeroDecimal / 16);
    printf("%c", digitosHexadecimais[numeroDecimal % 16]);
}

int main(){
    char numeroRomano[13];
    int numeroDecimal, numeroBinario;

    printf("Digite um número romano (até 12 caracteres): ");
    scanf("%s", numeroRomano);

    numeroDecimal = romanoParaDecimal(numeroRomano);
    numeroBinario = decimalParaBinario;

    printf("Representação Decimal: %d\n", numeroDecimal);

    printf("Representação Binária: ");
    decimalParaBinario(numeroDecimal);
    printf("\n");

    printf("Representação Hexadecimal: ");
    decimalParaHexadecimal(numeroDecimal);
    printf("\n");

    return 0;
}

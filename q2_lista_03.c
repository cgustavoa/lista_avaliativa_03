#include <stdio.h>
#include <math.h>

// ERRO NO CÁLCULO FINAL L:22;
int main(){
    double investimento_inicial, taxa_retorno_mensal, aporte_mensal, valor_montante;
    int meses;

    printf("Informe a quantidade de meses: ");
    scanf("%d", &meses);

    printf("Informe o investimento mensal: ");
    scanf("%lf", &aporte_mensal);

    printf("Informe a taxa de juros mensal (em porcentagem): ");
    scanf("%lf", &taxa_retorno_mensal);

    // Convertendo a taxa de juros para decimal
    taxa_retorno_mensal = taxa_retorno_mensal / 100.0;

    for (int i = 1; i <= meses; i++) {
        valor_montante = aporte_mensal * (1 + taxa_retorno_mensal) * (pow((1 + taxa_retorno_mensal), meses) - 1 / meses) + aporte_mensal;
        printf("Ao fim do mês %d, o montante é: %.2lf\n", i, valor_montante);
    }

    return 0;
}

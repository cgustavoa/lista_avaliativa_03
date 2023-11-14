#include <stdio.h>
#include <math.h>

int main(){
    double investimento_inicial, taxa_retorno_mensal, aporte_mensal, valor_montante;
    int meses;

    scanf("%d", &meses);
    scanf("%lf", &aporte_mensal);
    scanf("%lf", &taxa_retorno_mensal);

    for (int i = 1; i <= meses; i++){
        valor_montante = aporte_mensal *(1 + taxa_retorno_mensal) * (((pow(1 + taxa_retorno_mensal, i) - 1)/taxa_retorno_mensal));
        printf("Montante ao fim do mes %d: R$ %.2lf\n", i, valor_montante);
    }

    return 0;
}


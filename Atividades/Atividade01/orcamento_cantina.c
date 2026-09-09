#include <stdio.h>

#define PRECO_REFEICAO 12.50
#define PRECO_CAFE 4.00

int main() {
    int qtd_refeicoes, qtd_cafes;
    float valor_disponivel;
    float gasto_refeicoes, gasto_cafes, gasto_total, saldo_restante;

    printf("Quantidade de refeicoes: ");
    scanf("%d", & qtd_refeicoes);

    printf("Quantidade de cafes: ");
    scanf("%d", & qtd_cafes);

    printf("Valor disponivel no cartao: ");
    scanf("%f", & valor_disponivel);

    gasto_refeicoes = qtd_refeicoes * PRECO_REFEICAO;
    gasto_cafes = qtd_cafes * PRECO_CAFE;
    gasto_total = gasto_refeicoes + gasto_cafes;
    saldo_restante = valor_disponivel - gasto_total;

    printf("\nGasto refeicoes: %.2f\n", gasto_refeicoes);
    printf("Gasto cafes: %.2f\n", gasto_cafes);
    printf("Gasto total: %.2f\n", gasto_total);
    printf("Saldo restante: %.2f\n", saldo_restante);

    return 0;
}
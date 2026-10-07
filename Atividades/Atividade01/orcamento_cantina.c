#include <stdio.h>

#define PRECO_TICKET 12.50
#define PRECO_CAFE 4.00

int main() {
    int qtd_ref, qtd_cafes;
    float disponivel_cartao;
    float gasto_ref, gasto_cafes, gasto_total, saldo_restante;

    printf("Quantidade de refeicoes: ");
    scanf("%d", & qtd_ref);

    printf("Quantidade de cafes: ");
    scanf("%d", & qtd_cafes);

    printf("Valor disponivel no cartao: ");
    scanf("%f", & disponivel_cartao);

    gasto_ref = qtd_ref * PRECO_TICKET;
    gasto_cafes = qtd_cafes * PRECO_CAFE;
    gasto_total = gasto_ref + gasto_cafes;
    saldo_restante = disponivel_cartao - gasto_total;

    printf("\nGasto refeicoes: %.2f\n", gasto_ref);
    printf("Gasto cafes: %.2f\n", gasto_cafes);
    printf("Gasto total: %.2f\n", gasto_total);
    printf("Saldo restante: %.2f\n", saldo_restante);

    return 0;
}
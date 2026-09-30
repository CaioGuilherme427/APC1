/*
 * RESPOSTA CURTA (JUSTIFICATIVA E ESTRUTURA):
 * O programa aplica 'if-else' na validacao inicial para tratar dados invalidos e
 * garantir a correta execucao do fluxo. Em seguida, emprega uma estrutura 'if-else-if'
 * para classificar o aluno em faixas sociais (A, B ou C) de acordo com a renda familiar.
 * Dentro de cada faixa, utiliza 'if' aninhado para definir o desconto base a partir da media.
 * O bonus de pontualidade e calculado com o operador ternario '?:', finalizando com a 
 * exibicao dos dados e respeitando a indentacao e padronizacao do C ANSI.
 */

#include <stdio.h>

int main() {
    char nome[100];
    int idade;
    float renda, media;
    char pontualidade;
    
    char faixa_social;
    float desconto_base = 0.0f;
    float bonus_pontual = 0.0f;
    float desconto_total = 0.0f;

    printf("Nome completo: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Idade: ");
    scanf("%d", &idade);

    printf("Renda familiar mensal (R$): ");
    scanf("%f", &renda);

    printf("Media academica (0.0 a 10.0): ");
    scanf("%f", &media);

    printf("Pontualidade no pagamento (S/N): ");
    scanf(" %c", &pontualidade);

    if (idade < 16 || renda <= 0.0f) {
        printf("\nErro: Dados invalidos para analise de bolsa.\n");
    } else {
        if (renda <= 2000.0f) {
            faixa_social = 'A';
            if (media >= 8.5f) {
                desconto_base = 50.0f;
            } else {
                desconto_base = 30.0f;
            }
        } else if (renda <= 5000.0f) {
            faixa_social = 'B';
            if (media >= 9.0f) {
                desconto_base = 25.0f;
            } else {
                desconto_base = 10.0f;
            }
        } else {
            faixa_social = 'C';
            if (media >= 9.5f) {
                desconto_base = 10.0f;
            } else {
                desconto_base = 0.0f;
            }
        }

        bonus_pontual = (pontualidade == 'S' || pontualidade == 's') ? 5.0f : 0.0f;

        desconto_total = desconto_base + bonus_pontual;

        printf("\n========================================\n");
        printf("    SISTEMA DE AVALIACAO DE DESCONTO    \n");
        printf("========================================\n");
        printf("Aluno         : %s", nome);
        printf("Faixa Social  : Faixa %c\n", faixa_social);
        printf("Media         : %.2f\n", media);
        printf("Desconto Base : %.1f%%\n", desconto_base);
        printf("Bonus Pontual : %.1f%%\n", bonus_pontual);
        printf("----------------------------------------\n");
        printf("Desconto Total: %.1f%%\n", desconto_total);
        printf("Status        : %s\n", (desconto_total > 0.0f) ? "APROVADO PARA BOLSA" : "NAO ELEGIVEL");
        printf("========================================\n");
    }

    return 0;
}
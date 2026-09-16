#include <stdio.h>

/* O scanf("%s") não lê nomes compostos, lendo só o primeiro
bloco de caracteres antes do espaço. Para evitar isto, se utiliza
o fgets() para ler todos os blocos. Caso tenho usado o scanf antes,
é preciso usar o getchar(), pois o scanf() deixa o buffer com um '\n'
que precisa ser limpo antes de usar o fgets() para ler a próxima linha. */

int main() {
    char Cliente[100];
    int cod_produto;
    char nome_produto[100];
    int qnt_produto = 0;
    float preco_produto;
    char categoria;
    float total;

    printf("Nome do cliente: ");
    fgets(Cliente, sizeof(Cliente), stdin);

    printf("Codigo do produto: ");
    scanf("%d", & cod_produto);
    getchar();

    printf("Nome do produto: ");
    fgets(nome_produto, sizeof(nome_produto), stdin);

    while (qnt_produto <= 0) {
    printf("Quantidade: ");
    scanf("%d", & qnt_produto);
    
        if (qnt_produto <= 0) {
            printf("Erro: A quantidade nao pode ser negativa!\n");
        }
    }

    printf("Preco do produto: ");
    scanf("%f", & preco_produto);

    printf("Categoria do produto (A, B ou C): ");
    scanf(" %c", & categoria);

    total = qnt_produto * preco_produto;

    printf("\nRECIBO DE COMPRA\n");
    printf("Cliente: %s", Cliente);
    printf("Produto: %s", nome_produto);
    printf("Codigo: %d\n", cod_produto);
    printf("Categoria: %c\n", categoria);
    printf("Quantidade: %d\n", qnt_produto);
    printf("Unidade: R$%.2f\n", preco_produto);
    printf("Total: R$%.2f\n", total);

    return 0;
}
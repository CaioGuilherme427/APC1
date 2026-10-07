#include <stdio.h>

int main() {
    char nome[100];
    int idade;

    printf("Digite seu nome completo: ");
    fgets(nome, sizeof(nome), stdin);

    for (int i = 0; nome[i] != '\0'; i++) {
        if (nome[i] == '\n') {
            nome[i] = '\0';
        }
    }

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    scanf("%*c"); 

    printf("\n--- Dados Cadastrados ---\n");
    printf("Nome:  %s\n", nome);
    printf("Idade: %d anos\n", idade);

    return 0;
}
#include <stdio.h>

int main() {
    char nome[100];
    int idade;

    printf("Nome Completo: \n");
    printf("Idade: \n");
    fgets(nome, sizeof(nome), stdin);


    return 0;
}
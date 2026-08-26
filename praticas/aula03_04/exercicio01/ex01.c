#include <stdio.h>

int idade;
float altura;
char inicial;
int aprovacao;

int main() {
    idade = 22;
    altura = 1.65;
    inicial = 'C';
    aprovacao = 1;
    printf("Idade: %d\n",idade);
    printf("Altura: %f\n",altura);
    printf("Inicial do Nome: %c\n",inicial);
    printf("Aprovacao: %d\n",aprovacao);

    return 0;
}
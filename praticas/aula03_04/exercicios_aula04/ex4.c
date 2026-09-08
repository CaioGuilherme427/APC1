#include <stdio.h>

/*A diferença de DEFINE para const é que DEFINE é uma diretiva de pré-processador,ou seja, o valor
é substituído no código antes da compilação. Já const é uma variável que não pode ser alterada após
a sua inicialização, e seu valor é determinado em tempo de execução.*/

#define PI 3.14159
const float GRAVIDADE = 9.8;
float raio = 2.0;

int main() {
    float area_do_circulo = PI * raio * raio;
    printf("A área do círculo é: %f", area_do_circulo);

    return 0;
}
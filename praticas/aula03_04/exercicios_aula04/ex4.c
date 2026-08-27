#include <stdio.h>

//A diferença de DEFINE para const é

#define PI 3.14159
const float GRAVIDADE = 9.8;
float raio = 2.0;

int main() {
    float area_do_circulo = PI * raio * raio;
    printf("A área do círculo é: %f", area_do_circulo);

    return 0;
}
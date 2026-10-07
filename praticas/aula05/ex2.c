#include <stdio.h>

int main() {
    char str[31];
    printf("Digite uma string: ");
    /* NÃO use gets(str); */
    fgets(str, sizeof(str), stdin);
    printf("%s", str);
    return 0;
}
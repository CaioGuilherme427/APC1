/* O menu precisa de do-while para garantir a exibição inicial e a repetição até
a opção 0 ser digitada. Na opção 1, o continue salta o incremento de atendidas e 
pares depois de ler uma senha negativa. Na opção 4, sem o break, o laço continuaria
pedindo senhas infinitamente mesmo após encontrar a senha desejada ou o zero. */

#include <stdio.h>

int main() {
    int opcao;

    do {
        printf("\n===== PAINEL DE SENHAS =====\n");
        printf("1 - Registrar lote\n");
        printf("2 - Simular chamadas\n");
        printf("3 - Grade de guiches\n");
        printf("4 - Buscar senha prioritaria\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");
        
        if (scanf("%d", & opcao) != 1) {
            return 1;
        }

        switch (opcao) {
            case 1: {
                //Registrar lote
                int senha;
                int atendidas = 0;
                int ignoradas = 0;
                int pares = 0;

                printf("Digite as senhas do lote (0 para encerrar):\n");
                while (1) {
                    scanf("%d", & senha);
                    
                    if (senha == 0) {
                        break;
                    }
                    
                    if (senha < 0) {
                        ignoradas++;
                        continue;
                    }
                    
                    atendidas++;
                    if (senha % 2 == 0) {
                        pares++;
                    }
                }

                printf("Atendidas : %d\n", atendidas);
                printf("Ignoradas : %d\n", ignoradas);
                printf("Pares     : %d\n", pares);
                break;
            }

            case 2: {
                //Simular chamadas
                int inicio, fim, passo;

                printf("Inicio: ");
                scanf("%d", & inicio);
                printf("Fim: ");
                scanf("%d", & fim);
                printf("Passo: ");
                scanf("%d", & passo);

                if (passo == 0) {
                    printf("Passo invalido\n");
                } else if (passo > 0) {
                    if (inicio > fim) {
                        printf("Nenhuma chamada\n");
                    } else {
                        printf("Chamadas:");
                        for (int i = inicio; i <= fim; i += passo) {
                            printf(" %d", i);
                        }
                        printf("\n");
                    }
                } else {
                    if (inicio < fim) {
                        printf("Nenhuma chamada\n");
                    } else {
                        printf("Chamadas:");
                        for (int i = inicio; i >= fim; i += passo) {
                            printf(" %d", i);
                        }
                        printf("\n");
                    }
                }
                break;
            }

            case 3: {
                //Grade de guichês
                int G, S;

                printf("Guiches (1 a 4): ");
                scanf("%d", & G);
                printf("Senhas por guiche (1 a 5): ");
                scanf("%d", & S);

                if (G < 1 || G > 4 || S < 1 || S > 5) {
                    printf("Grade invalida\n");
                } else {
                    for (int g = 1; g <= G; g++) {
                        printf("Guiche %d:", g);
                        for (int s = 1; s <= S; s++) {
                            printf(" %d", s);
                        }
                        printf("\n");
                    }
                }
                break;
            }

            case 4: {
                //Buscar senha prioritária
                int senha;
                int lidas = 0;

                while (1) {
                    printf("Senha: ");
                    scanf("%d", & senha);

                    if (senha == 0) {
                        printf("Nao encontrada\n");
                        printf("Lidas : %d\n", lidas);
                        break;
                    }

                    if (senha > 0 && senha % 10 == 0) {
                        printf("Prioritaria : %d\n", senha);
                        printf("Lidas antes : %d\n", lidas);
                        break;
                    }

                    lidas++;
                }
                break;
            }

            case 0:
                printf("Painel encerrado.\n");
                break;

            default:
                printf("Opcao invalida\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
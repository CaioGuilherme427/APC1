#include <stdio.h>
#include <string.h>

#define MAX 30

enum StatusAluno { REPROVADO = 0, RECUPERACAO = 1, APROVADO = 2 };

struct Aluno {
    int matricula;
    char nome[41];
    float a1;
    float a2;
    enum StatusAluno status;
};

int main() {
    struct Aluno turma[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n1. Cadastrar | 2. Listar | 3. Buscar Matricula | 4. Buscar Nome | 5. Estatisticas | 6. Sair\n");
        printf("Opcao: ");
        scanf("%d", & opcao);
        getchar();

        if (opcao == 1) {
            if (total >= MAX) {
                printf("Turma cheia!\n");
            } else {
                printf("Matricula: ");
                scanf("%d", & turma[total].matricula);
                getchar();

                printf("Nome: ");
                fgets(turma[total].nome, 41, stdin);
                turma[total].nome[strcspn(turma[total].nome, "\n")] = '\0';

                printf("A1 e A2: ");
                scanf("%f %f", & turma[total].a1, & turma[total].a2);
                getchar();

                float media = 0.4 * turma[total].a1 + 0.6 * turma[total].a2;

                if (media >= 5.0) {
                    turma[total].status = APROVADO;
                } else if (media >= 3.0) {
                    turma[total].status = RECUPERACAO;
                } else {
                    turma[total].status = REPROVADO;
                }

                total++;
                printf("Cadastrado!\n");
            }
        }
        else if (opcao == 2) {
            printf("\nMatricula | Nome | A1 | A2 | Media | Status\n");
            for (int i = 0; i < total; i++) {
                float media = 0.4 * turma[i].a1 + 0.6 * turma[i].a2;
                printf("%d | %s | %.1f | %.1f | %.1f | ",
                       turma[i].matricula, turma[i].nome, turma[i].a1, turma[i].a2, media);

                if (turma[i].status == APROVADO) printf("APROVADO\n");
                else if (turma[i].status == RECUPERACAO) printf("RECUPERACAO\n");
                else printf("REPROVADO\n");
            }
        }
        else if (opcao == 3) {
            int busca, achou = 0;
            printf("Digite a matricula: ");
            scanf("%d", & busca);
            getchar();

            for (int i = 0; i < total; i++) {
                if (turma[i].matricula == busca) {
                    float media = 0.4 * turma[i].a1 + 0.6 * turma[i].a2;
                    printf("%d | %s | %.1f | %.1f | %.1f | ",
                           turma[i].matricula, turma[i].nome, turma[i].a1, turma[i].a2, media);

                    if (turma[i].status == APROVADO) printf("APROVADO\n");
                    else if (turma[i].status == RECUPERACAO) printf("RECUPERACAO\n");
                    else printf("REPROVADO\n");

                    achou = 1;
                    break;
                }
            }
            if (!achou) printf("nao encontrado\n");
        }
        else if (opcao == 4) {
            char trecho[41];
            printf("Trecho do nome: ");
            fgets(trecho, 41, stdin);
            trecho[strcspn(trecho, "\n")] = '\0';

            for (int i = 0; i < total; i++) {
                if (strstr(turma[i].nome, trecho) != NULL) {
                    float media = 0.4 * turma[i].a1 + 0.6 * turma[i].a2;
                    printf("%d | %s | %.1f | %.1f | %.1f | ",
                           turma[i].matricula, turma[i].nome, turma[i].a1, turma[i].a2, media);

                    if (turma[i].status == APROVADO) printf("APROVADO\n");
                    else if (turma[i].status == RECUPERACAO) printf("RECUPERACAO\n");
                    else printf("REPROVADO\n");
                }
            }
        }
        else if (opcao == 5) {
            int apr = 0, rec = 0, rep = 0;
            float soma = 0;

            for (int i = 0; i < total; i++) {
                soma += 0.4 * turma[i].a1 + 0.6 * turma[i].a2;
                if (turma[i].status == APROVADO) apr++;
                else if (turma[i].status == RECUPERACAO) rec++;
                else rep++;
            }

            printf("Aprovados: %d | Recuperacao: %d | Reprovados: %d\n", apr, rec, rep);
            if (total > 0) {
                printf("Media geral da turma: %.2f\n", soma / total);
            }
        }
    } while (opcao != 6);

    return 0;
}
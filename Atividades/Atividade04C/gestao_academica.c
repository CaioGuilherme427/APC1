/* A declaração char nome[50] reserva 50 bytes, mas armazena no máximo 49
caracteres úteis porque a linguagem C obriga a utilização do caractere
nulo ('\0') na última posição, indicando o fim da string. Em int M[3][4],
o primeiro índice representa o número de linhas e o segundo as colunas.
A linguagem C organiza esses dados em sequência na memória contínua,
usando a ordem "linha-major", armazenando toda a linha 0, seguida da 1 e 2. */

#include <stdio.h>
#include <string.h>

int main() {
    int opcao;

    char alunos[5][50];
    int alunosCadastrados = 0;

    float notas_finais[5];
    int notasCadastradas = 0;

    float boletim[3][4];
    int boletimCadastrado = 0;

    do {
        printf("\n===== SISTEMA DE GESTAO ACADEMICA =====\n");
        printf("1. Cadastrar Lista de Alunos (Vetor de Strings)\n");
        printf("2. Estatisticas de Desempenho (Vetor de Float)\n");
        printf("3. Matriz de Notas da Turma (Matriz Bidimensional)\n");
        printf("4. Consultar Aluno em Destaque (Pesquisa em Matriz/Vetor)\n");
        printf("0. Encerrar\n");
        printf("Opcao: ");
        
        if (scanf("%d", & opcao) != 1) {
            printf("Entrada invalida. Tente novamente.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch (opcao) {
            case 1: {
                printf("\n--- CADASTRO DE ALUNOS ---\n");
                for (int i = 0; i < 5; i++) {
                    printf("Digite o nome do aluno %d: ", i + 1);
                    fgets(alunos[i], sizeof(alunos[i]), stdin);
                    
                    alunos[i][strcspn(alunos[i], "\n")] = '\0';
                }
                alunosCadastrados = 1;

                printf("\nAlunos cadastrados com sucesso:\n");
                for (int i = 0; i < 5; i++) {
                    printf("%d. %s\n", i + 1, alunos[i]);
                }
                break;
            }
            case 2: {
                printf("\n--- ESTATISTICAS DE DESEMPENHO ---\n");
                for (int i = 0; i < 5; i++) {
                    printf("Digite a nota final do aluno %d: ", i + 1);
                    scanf("%f", & notas_finais[i]);
                }
                notasCadastradas = 1;

                float soma = 0;
                for (int i = 0; i < 5; i++) {
                    soma += notas_finais[i];
                }
                float media_geral = soma / 5.0f;

                int contador_acima_media = 0;
                for (int i = 0; i < 5; i++) {
                    if (notas_finais[i] >= media_geral) {
                        contador_acima_media++;
                    }
                }

                printf("\nMedia geral da turma: %.2f\n", media_geral);
                printf("Alunos com nota maior ou igual a media: %d\n", contador_acima_media);
                break;
            }
            case 3: {
                printf("\n--- MATRIZ DE NOTAS DA TURMA (3 Alunos x 4 Bimestres) ---\n");
                for (int i = 0; i < 3; i++) {
                    printf("Cadastrando notas para o Aluno %d:\n", i + 1);
                    for (int j = 0; j < 4; j++) {
                        printf("  - Bimestre %d: ", j + 1);
                        scanf("%f", & boletim[i][j]);
                    }
                }
                boletimCadastrado = 1;

                printf("\n--- BOLETIM DA TURMA ---\n");
                printf("Aluno\tB1\tB2\tB3\tB4\tMedia Simples\n");
                for (int i = 0; i < 3; i++) {
                    printf("[%d]\t", i + 1);
                    float soma_aluno = 0;
                    for (int j = 0; j < 4; j++) {
                        printf("%.1f\t", boletim[i][j]);
                        soma_aluno += boletim[i][j];
                    }
                    float media_simples = soma_aluno / 4.0f;
                    printf("%.2f\n", media_simples);
                }
                break;
            }
            case 4: {
                printf("\n--- CONSULTAR ALUNO EM DESTAQUE ---\n");
                if (!notasCadastradas) {
                    printf("Aviso: Voce ainda nao preencheu o vetor de notas na Opcao 2. Por favor, execute-a primeiro ou use o boletim.\n");
                    break;
                }

                float maior_nota = notas_finais[0];
                int indice_maior = 0;

                for (int i = 1; i < 5; i++) {
                    if (notas_finais[i] > maior_nota) {
                        maior_nota = notas_finais[i];
                        indice_maior = i;
                    }
                }

                printf("A maior nota da turma e %.2f, encontrada no indice %d (Aluno %d).\n", 
                    maior_nota, indice_maior, indice_maior + 1);
                
                if (alunosCadastrados) {
                    printf("Nome do aluno em destaque: %s\n", alunos[indice_maior]);
                }
                break;
            }
            case 0:
                printf("\nEncerrando o Sistema de Gestao Academica. Ate logo!\n");
                break;
            default:
                printf("\nOpcao invalida! Escolha um valor entre 0 e 4.\n");
        }
    } while (opcao != 0);

    return 0;
}
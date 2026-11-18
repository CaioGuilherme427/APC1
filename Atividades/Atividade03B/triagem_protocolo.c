/* O fall-through consciente foi mais vantajoso nos agrupamentos do switch de serviço, switch de prioridade,
e do switch de expediente. Ele evita a repetição desnecessária do código que define a categoria, o prazo,
a taxa base, o guichê e o tipo de expediente para opções equivalentes.
 
O switch não substitui o if-else-if na classificação por faixas de renda porque o switch compara apenas
igualdade exata com valores inteiros ou caracteres. A classificação por faixas exige comparações de
intervalos contínuos (exemplo: renda >= 2000.00), operacões relacionais que não são suportadas pelo switch. */

#include <stdio.h>

int main() {
    int codigo_servico, dia_semana, prazo = 0, guiche = 0;
    char prioridade;
    float taxa_base = 0.0f, acrescimo = 0.0f, taxa_final;

    char *nome_servico = "Codigo invalido";
    char *categoria = "—";
    char *status_servico = "RECUSADO";
    char *nome_prioridade, *nome_dia, *expediente;

    scanf("%d", & codigo_servico);
    scanf(" %c", & prioridade);
    scanf("%d", & dia_semana);

    switch (codigo_servico) {
        case 1: nome_servico = "Historico escolar";       break;
        case 2: nome_servico = "Declaracao de matricula"; break;
        case 3: nome_servico = "Declaracao de vinculo";   break;
        case 4: nome_servico = "Trancamento";             break;
        case 5: nome_servico = "Cancelamento";            break;
        case 6: nome_servico = "Colacao de grau";         break;
        default: break;
    }

    // 1. Switch de Serviço
    switch (codigo_servico) {
        case 1: /* fall-through */
        case 2: /* fall-through */
        case 3:
            categoria = "Documento simples";
            prazo = 2;
            taxa_base = 15.00f;
            status_servico = "ACEITO";
            break;

        case 4: /* fall-through */
        case 5:
            categoria = "Interrupcao de vinculo";
            prazo = 10;
            taxa_base = 0.00f;
            status_servico = "ACEITO";
            break;

        case 6:
            categoria = "Ato solene";
            prazo = 15;
            taxa_base = 80.00f;
            status_servico = "ACEITO";
            break;

        default:
            break;
    }

    // 2. Switch de Prioridade
    switch (prioridade) {
        case 'U': /* fall-through */
        case 'u': nome_prioridade = "Urgente"; guiche = 1; acrescimo = 10.00f; break;
        case 'N': /* fall-through */
        case 'n': nome_prioridade = "Normal";  guiche = 2; acrescimo = 0.00f;  break;
        case 'B': /* fall-through */
        case 'b': nome_prioridade = "Balcao";  guiche = 3; acrescimo = 0.00f;  break;
        default:  nome_prioridade = "Invalida"; guiche = 0; acrescimo = 0.00f;  break;
    }

    // 3. Switch de Nome do Dia
    switch (dia_semana) {
        case 1:  nome_dia = "Domingo";       break;
        case 2:  nome_dia = "Segunda-feira"; break;
        case 3:  nome_dia = "Terca-feira";   break;
        case 4:  nome_dia = "Quarta-feira";  break;
        case 5:  nome_dia = "Quinta-feira";  break;
        case 6:  nome_dia = "Sexta-feira";   break;
        case 7:  nome_dia = "Sabado";        break;
        default: nome_dia = "Dia invalido";  break;
    }

    // 4. Switch de Expediente
    switch (dia_semana) {
        case 2: /* fall-through */
        case 3: /* fall-through */
        case 4: /* fall-through */
        case 5: expediente = "Pleno";         break;
        case 6: expediente = "Reduzido";      break;
        case 1: /* fall-through */
        case 7: expediente = "Fechado";       break;
        default: expediente = "Dia invalido"; break;
    }

    taxa_final = taxa_base + acrescimo;

    printf("========================================\n");
    printf(" TRIAGEM DE PROTOCOLO ACADEMICO\n");
    printf("========================================\n");
    printf("Servico            : %s\n", nome_servico);
    printf("Categoria          : %s\n", categoria);
    printf("Prazo              : %d dias uteis\n", prazo);
    printf("Taxa base          : R$ %.2f\n", taxa_base);
    printf("Prioridade         : %s\n", nome_prioridade);
    printf("Guiche             : %d\n", guiche);
    printf("Acrescimo          : R$ %.2f\n", acrescimo);
    printf("Dia                : %s\n", nome_dia);
    printf("Expediente         : %s\n", expediente);
    printf("----------------------------------------\n");
    printf("Taxa final         : R$ %.2f\n", taxa_final);
    printf("Status do servico  : %s\n", status_servico);
    printf("========================================\n");

    return 0;
}
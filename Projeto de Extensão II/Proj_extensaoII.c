#include <stdio.h> // Biblioteca para entrada/saída
#include <stdlib.h> // Biblioteca padrão
#include <locale.h> // Biblioteca Para localização
#include <time.h> // Biblioteca Para funções de tempo

// Definição das Constantes
#define MEDIA_REFEICOES_DIARIAS 100 
#define PRECO_REFEICAO_POR_QUILO 25.0 
#define PRECO_EMBALAGEM_QUENTINHA 0.5 
#define PRECO_QUENTINHA_FIXO 20.0 
#define PRECO_BEBIDA 3.0 
#define MESES_NO_ANO 12 

// Estrutura para totais mensais
typedef struct {
    int mes;
    float total;
} TotalMensal;

// Enum para opções do menu
typedef enum {
    ENCERRAR = 0,
    REFEICAO_POR_QUILO = 1,
    QUENTINHA = 2,
    BEBIDA = 3
} OpcaoMenu;

// Função para comparar totais mensais
int compararTotaisMensais(const void *a, const void *b) {
    const TotalMensal *totalA = (const TotalMensal *)a;
    const TotalMensal *totalB = (const TotalMensal *)b;
    return (totalB->total > totalA->total) - (totalB->total < totalA->total);
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Define a localização
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    // Declaração de variáveis
    OpcaoMenu opcao;
    float peso, valorTotal;
    int quantidade_quentinha;
    int quantidade_bebida;
    float totalDiario = 0.0;
    float totalAnual = 0.0;

    TotalMensal vendasAnuais[MESES_NO_ANO] = {0}; // Inicializa o array de vendas anuais

    while (1) { // Loop principal
        printf("###################################### MENU #####################################\n");
        printf("# Selecione uma opcao (ou digite 0 para encerrar e gerar o relatorio anual): #\n");
        printf("# 1 - Refeicao por quilo                                                      #\n");
        printf("# 2 - Quentinha                                                                 #\n");
        printf("# 3 - Bebida                                                                    #\n"); 
        printf("#################################################################################\n");
        scanf("%d", (int*)&opcao); // Lê a opção do usuário

        if (opcao == ENCERRAR) { // Encerra o programa se a opção for 0
            break;
        }

        // Trata as opções do menu
        switch (opcao) {
            case REFEICAO_POR_QUILO: 
                printf("Digite o peso da refeicao em quilos: \n");
                scanf("%f", &peso);
                valorTotal = peso * PRECO_REFEICAO_POR_QUILO;
                break;
            case QUENTINHA:
                printf("Digite a quantidade de quentinhas: \n");
                scanf("%d", &quantidade_quentinha);
                valorTotal = quantidade_quentinha * PRECO_QUENTINHA_FIXO + PRECO_EMBALAGEM_QUENTINHA;
                break;
            case BEBIDA: 
                printf("Digite a quantidade de bebidas: \n");
                scanf("%d", &quantidade_bebida);
                valorTotal = quantidade_bebida * PRECO_BEBIDA;
                break;
            default: 
                printf("Opção invalida.\n");
                continue;
        }

        // Atualiza os totais diário e mensal
        totalDiario += valorTotal;
        printf("Venda registrada. Valor total: R$ %.2f\n", valorTotal);
        vendasAnuais[0].total += valorTotal;

        // Gera vendas aleatórias para os outros meses do ano
        for (int mes = 0; mes < MESES_NO_ANO; mes++) {
            vendasAnuais[mes].mes = mes + 1;
            vendasAnuais[mes].total += ((float)rand() / RAND_MAX) * valorTotal * MEDIA_REFEICOES_DIARIAS;
        }
    }

    // Ordena os totais mensais e calcula o total anual
    qsort(vendasAnuais, MESES_NO_ANO, sizeof(TotalMensal), compararTotaisMensais);

    for (int i = 0; i < MESES_NO_ANO; i++) {
        totalAnual += vendasAnuais[i].total;
    }

    // Imprime os relatórios diário e anual
    printf("\nRelatorio diario:\n");
    printf("Total de vendas realizadas no dia: R$ %.2f\n", totalDiario);

    printf("\nRelatorio anual:\n");
    printf("Total de vendas realizadas no ano: R$ %.2f\n", totalAnual);
    printf("Meses em ordem decrescente de vendas:\n");
    for (int i = 0; i < MESES_NO_ANO; i++) {
        printf("Mes %d: R$ %.2f\n", vendasAnuais[i].mes, vendasAnuais[i].total);
    }

    return 0; 
}

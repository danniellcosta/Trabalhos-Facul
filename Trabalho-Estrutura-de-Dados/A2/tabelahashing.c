/*
    Grupo: Danniel Lopes da Costa, Carlos Guilherme da Silva Thomaz, Alan de Assis Gonçalves Santos,
           Caio Henrique Dantas Milão do Nascimento.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_HASH 100
#define MAX_NOME 20

// Enum para tipos de token
typedef enum
{
    Reservada,
    Variavel,
    Constante,
    Fim
} TipoToken;
char *str_TipoToken[] = {"Reservada", "Variavel", "Constante", "Fim"};

// Enum para tipos de identificadores
typedef enum
{
    Inteiro,
    Real,
    Caractere,
    String
} TipoIdentificador;
char *str_TipoIdentificador[] = {"Inteiro", "Real", "Caractere", "String"};

// Estrutura para representar uma linha
typedef struct Linha
{
    int numero;
    struct Linha *prox;
} Linha;

// Estrutura para representar uma entrada na tabela de símbolos
typedef struct Entrada
{
    char nome[MAX_NOME + 1];
    TipoIdentificador id;
    Linha *linhas;
    struct Entrada *prox;
} Entrada;

Entrada *tabela[TAM_HASH];

// Função de hashing simples
unsigned int hash(char *nome)
{
    unsigned int hash = 0;
    while (*nome)
    {
        hash = (hash << 5) + *nome++;
    }
    return hash % TAM_HASH;
}

// Função para adicionar uma linha a uma entrada na tabela de símbolos
void adiciona_linha(Entrada *entrada, int linha)
{
    Linha *novaLinha = (Linha *)malloc(sizeof(Linha));
    novaLinha->numero = linha;
    novaLinha->prox = NULL;

    Linha *atual = entrada->linhas;
    if (atual == NULL)
    {
        entrada->linhas = novaLinha;
    }
    else
    {
        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = novaLinha;
    }
}

// Função para criar uma nova entrada na tabela de símbolos
Entrada *nova_entrada(char *nome, TipoIdentificador id, int linha)
{
    Entrada *entrada = (Entrada *)malloc(sizeof(Entrada));
    strcpy(entrada->nome, nome);
    entrada->id = id;
    entrada->linhas = NULL;
    entrada->prox = NULL;
    adiciona_linha(entrada, linha);
    return entrada;
}

// Função para inserir uma entrada na tabela de símbolos
void insere_tabela(TipoToken token, TipoIdentificador id, char *nome, int linha)
{
    if (token != Variavel && token != Constante)
    {
        return;
    }

    unsigned int indice = hash(nome);
    Entrada *atual = tabela[indice];

    while (atual != NULL)
    {
        if (strcmp(atual->nome, nome) == 0)
        {
            adiciona_linha(atual, linha);
            return;
        }
        atual = atual->prox;
    }

    Entrada *nova = nova_entrada(nome, id, linha);
    nova->prox = tabela[indice];
    tabela[indice] = nova;
}

// Função para imprimir a tabela de símbolos
void mostra_tabela()
{
    for (int i = 0; i < TAM_HASH; i++)
    {
        Entrada *atual = tabela[i];
        while (atual != NULL)
        {
            printf("%s ->", atual->nome);
            Linha *linha_atual = atual->linhas;
            while (linha_atual != NULL)
            {
                printf(" %d", linha_atual->numero);
                if (linha_atual->prox != NULL)
                {
                    printf(",");
                }
                linha_atual = linha_atual->prox;
            }
            printf("\n");
            atual = atual->prox;
        }
    }
}

// Função para obter o próximo token da entrada
void pegaToken(TipoToken *token, TipoIdentificador *id, char *nome, int *linha);

int main(void)
{
    TipoToken token;
    TipoIdentificador id;
    char nome[MAX_NOME + 1];
    int linha;

    for (int i = 0; i < TAM_HASH; i++)
    {
        tabela[i] = NULL;
    }

    pegaToken(&token, &id, nome, &linha);
    while (token != Fim)
    {
        insere_tabela(token, id, nome, linha);
        pegaToken(&token, &id, nome, &linha);
    }

    mostra_tabela();
    return 0;
}

// Função para obter o próximo token da entrada
void pegaToken(TipoToken *token, TipoIdentificador *id, char *nome, int *linha)
{
    static int pos = 1;
    switch (pos)
    {
    case 1:
        *token = Reservada;
        *id = String;
        strcpy(nome, "program");
        *linha = 1;
        break;
    case 2:
        *token = Variavel;
        *id = String;
        strcpy(nome, "calcula");
        *linha = 1;
        break;
    case 3:
        *token = Reservada;
        *id = String;
        strcpy(nome, ";");
        *linha = 1;
        break;
    case 4:
        *token = Reservada;
        *id = String;
        strcpy(nome, "var");
        *linha = 2;
        break;
    case 5:
        *token = Variavel;
        *id = Inteiro;
        strcpy(nome, "i");
        *linha = 3;
        break;
    case 6:
        *token = Reservada;
        *id = String;
        strcpy(nome, ",");
        *linha = 3;
        break;
    case 7:
        *token = Variavel;
        *id = Inteiro;
        strcpy(nome, "n");
        *linha = 3;
        break;
    case 8:
        *token = Reservada;
        *id = String;
        strcpy(nome, ":");
        *linha = 3;
        break;
    case 9:
        *token = Reservada;
        *id = String;
        strcpy(nome, "integer");
        *linha = 3;
        break;
    case 10:
        *token = Reservada;
        *id = String;
        strcpy(nome, ";");
        *linha = 3;
        break;
    case 11:
        *token = Reservada;
        *id = String;
        strcpy(nome, "begin");
        *linha = 4;
        break;
    case 12:
        *token = Variavel;
        *id = Inteiro;
        strcpy(nome, "n");
        *linha = 5;
        break;
    case 13:
        *token = Reservada;
        *id = String;
        strcpy(nome, ":=");
        *linha = 5;
        break;
    case 14:
        *token = Constante;
        *id = Inteiro;
        strcpy(nome, "0");
        *linha = 5;
        break;
    case 15:
        *token = Reservada;
        *id = String;
        strcpy(nome, ";");
        *linha = 5;
        break;
    case 16:
        *token = Reservada;
        *id = String;
        strcpy(nome, "for");
        *linha = 6;
        break;
    case 17:
        *token = Variavel;
        *id = Inteiro;
        strcpy(nome, "i");
        *linha = 6;
        break;
    case 18:
        *token = Reservada;
        *id = String;
        strcpy(nome, ":=");
        *linha = 6;
        break;
    case 19:
        *token = Constante;
        *id = Inteiro;
        strcpy(nome, "1");
        *linha = 6;
        break;
    case 20:
        *token = Reservada;
        *id = String;
        strcpy(nome, "to");
        *linha = 6;
        break;
    case 21:
        *token = Constante;
        *id = Inteiro;
        strcpy(nome, "10");
        *linha = 6;
        break;
    case 22:
        *token = Reservada;
        *id = String;
        strcpy(nome, "do");
        *linha = 6;
        break;
    case 23:
        *token = Variavel;
        *id = Inteiro;
        strcpy(nome, "n");
        *linha = 7;
        break;
    case 24:
        *token = Reservada;
        *id = String;
        strcpy(nome, ":=");
        *linha = 7;
        break;
    case 25:
        *token = Variavel;
        *id = Inteiro;
        strcpy(nome, "n");
        *linha = 7;
        break;
    case 26:
        *token = Reservada;
        *id = String;
        strcpy(nome, "+");
        *linha = 7;
        break;
    case 27:
        *token = Variavel;
        *id = Inteiro;
        strcpy(nome, "i");
        *linha = 7;
        break;
    case 28:
        *token = Reservada;
        *id = String;
        strcpy(nome, "*");
        *linha = 7;
        break;
    case 29:
        *token = Constante;
        *id = Inteiro;
        strcpy(nome, "10");
        *linha = 7;
        break;
    case 30:
        *token = Reservada;
        *id = String;
        strcpy(nome, ";");
        *linha = 7;
        break;
    case 31:
        *token = Reservada;
        *id = String;
        strcpy(nome, "end");
        *linha = 8;
        break;
    case 32:
        *token = Reservada;
        *id = String;
        strcpy(nome, ".");
        *linha = 8;
        break;
    default:
        *token = Fim;
    }
    pos++;
}
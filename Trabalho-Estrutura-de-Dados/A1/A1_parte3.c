/*
    Grupo: Danniel Lopes da Costa, Carlos Guilherme da Silva Thomaz, Alan de Assis Gonçalves Santos, 
           Caio Henrique Dantas Milão do Nascimento, Daniel Oliveira Menezes Iorio e 
           Fellipe Daniel da Costa Paiva Carmo
    
    Trabalho: n°3 - Árvore Binária de busca:
    Esse código cria uma árvore binária de busca para armazenar palavras e seus contadores, 
    permitindo a busca eficiente e a contagem de ocorrências. 
    O código cria uma ABB para irganizar as palavras em ordem alfabérica e contar suas ocorrências. 
    A estrutura ABB permite busca eficiente e organização automática das palavras.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM_MAX 15

// Definição da estrutura Node que representa um nó na árvore binária
typedef struct Node {
    char palavra[TAM_MAX]; 
    int count; 
    struct Node *left, *right; 
} Node;

// Função para criar um novo nó com uma palavra específica
Node* newNode(char* palavra) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->palavra, palavra); 
    node->count = 1; 
    node->left = node->right = NULL; 
    return node; 
}

// Função para inserir uma palavra na árvore binária
Node* insert(Node* node, char* palavra) {
    if (node == NULL) return newNode(palavra); 
    int cmp = strcmp(palavra, node->palavra);
    if (cmp < 0) 
        node->left = insert(node->left, palavra);
    else if (cmp > 0)
        node->right = insert(node->right, palavra);
    else 
        node->count++;
    return node; 
}

// Função para imprimir as palavras na árvore em ordem
void printPalavras(Node* node) {
    if (node != NULL) { 
        printPalavras(node->left); 
       
        if(node->palavra[0] != '\0') { 
            printf("%s (%d)\n", node->palavra, node->count); 
        }
        printPalavras(node->right); 
    }
}

// Função para processar uma lista de palavras
void processaPalavras(char *str[]) {
    Node* root = NULL; 
    int i;
    for (i = 0; str[i][0] != '\0'; i++) 
        root = insert(root, str[i]);
    printPalavras(root); 
}

// Função principal
int main() {

    setlocale(LC_ALL,"pt_BR");

    char *palavras[] = { 
        "Danniel","Matheus", "Caio","Igor","Danniel","Alex","Danniel","Alex",
        "Guilherme","Júlio","Caio","Caio","Caio","Danniel", "\0"
    };
    processaPalavras(palavras); 
    return 0; 
}
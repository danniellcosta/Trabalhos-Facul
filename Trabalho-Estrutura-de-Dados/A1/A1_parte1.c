/*
    Grupo: Danniel Lopes da Costa, Carlos Guilherme da Silva Thomaz, Alan de Assis Gonçalves Santos, 
           Caio Henrique Dantas Milão do Nascimento, Daniel Oliveira Menezes Iorio e 
           Fellipe Daniel da Costa Paiva Carmo
    
    Trabalho: n°1 - Lista Encadeada:
    Este código implementa uma lista encadeada, definindo uma estrutura de dados chama Node que representa
    os nós da lista.Cada nó tem o seu valor e um ponteiro para o próximo nó.O código inclui também várias 
    funções para manipular a lista, como adicionar elementos, remover elementos, imprimir a lista, 
    verificar se a lista está vazia e obter o tamanho da lista.Todas essas funções são facilmente acessadas
    pelo menu interativo contido na função main(), deixando tudo mais simples e organizado.
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Definição da estrutura Node que representa um nó na lista encadeada
typedef struct Node {
    int data; 
    struct Node* next; 
} Node;

// Função para criar um novo nó com um dado específico
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = data; 
    newNode->next = NULL;
    return newNode; 
}

// Função para adicionar um nó no início da lista
void addAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data); 
    newNode->next = *head; 
    *head = newNode; 
}

// Função para adicionar um nó no final da lista
void addAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) { 
        *head = newNode; 
    } else {
        Node* temp = *head; 
        while (temp->next != NULL) { 
            temp = temp->next;
        }
        temp->next = newNode; 
    }
}

// Função para adicionar um nó em uma posição específica da lista
void addAtPosition(Node** head, int data, int position) {
    setlocale(LC_ALL, "Portuguese"); 
    if (position == 0) { 
        addAtBeginning(head, data); 
    } else { 
        Node* newNode = createNode(data); 
        Node* temp = *head;
        for (int i = 0; i < position - 1 && temp != NULL; i++) { 
            temp = temp->next; 
        }
        if (temp == NULL) { 
            printf("Posição inválida!\n"); 
            free(newNode); 
        } else { 
            newNode->next = temp->next; 
            temp->next = newNode; 
        }
    }
}

// Função para listar todos os elementos da lista
void listAllElements(Node* head) {
    Node* temp = head; 
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next; 
    }
    printf("NULL\n"); 
}

// Função para listar um elemento específico da lista
void listSpecificElement(Node* head, int position) {
    setlocale(LC_ALL, "Portuguese"); 
    Node* temp = head; 
    for (int i = 0; i < position && temp != NULL; i++) { 
        temp = temp->next; 
    }
    if (temp == NULL) {
        printf("Posição inválida!\n"); 
    } else { 
        printf("Elemento na posição %d: %d\n", position, temp->data);
    }
}

// Função para excluir o primeiro nó da lista
void deleteAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("A lista está¡ vazia!\n"); 
        return; 
    }
    Node* temp = *head;
    *head = (*head)->next; 
    free(temp); 
}

// Função para excluir o último nó da lista
void deleteAtEnd(Node** head) {
    setlocale(LC_ALL, "Portuguese"); 
    if (*head == NULL) {
        printf("A lista está vazia!\n"); 
        return; 
    }
    if ((*head)->next == NULL) {
        free(*head); 
        *head = NULL; 
        return; 
    }
    Node* temp = *head; 
    while (temp->next->next != NULL) { 
        temp = temp->next; 
    }
    free(temp->next); 
    temp->next = NULL; 
}

// Função para excluir um nó de uma posição específica da lista
void deleteAtPosition(Node** head, int position) {
    setlocale(LC_ALL, "Portuguese");
    if (*head == NULL) {
        printf("A lista está vazia!\n");
        return; 
    }
    if (position == 0) { 
        deleteAtBeginning(head);
    } else { 
        Node* temp = *head; 
        for (int i = 0; i < position - 1 && temp != NULL; i++) {
            temp = temp->next; 
        }
        if (temp == NULL || temp->next == NULL) { 
            printf("Posição inválida!\n"); 
        } else { // Se a posição é válida,
            Node* nodeToDelete = temp->next; 
            temp->next = temp->next->next; 
            free(nodeToDelete); 
        }
    }
}
// Função para liberar todos os nós da lista
    void freeList(Node** head) {
        Node* temp; 
        while (*head != NULL) { 
            temp = *head; 
            *head = (*head)->next;
            free(temp); 
        }
        printf("A lista está vazia!\n"); 
    }

    // Função principal
    int main() {
        Node* head = NULL; 
        int option, data, position; 

        do { // Inicia um loop do-while.
            setlocale(LC_ALL, "Portuguese"); 
            printf("------------------------------------------------------------------\n");
            printf("MENU DE OPÇÕES\n");
            printf("------------------------------------------------------------------\n");
            printf("[1] Adicionar no inicio da lista\n");
            printf("[2] Adicionar no final da lista\n");
            printf("[3] Adicionar em um ponto específico da lista\n");
            printf("[4] Listar todos os elementos da lista\n");
            printf("[5] Listar um elemento específico da lista\n");
            printf("[6] Excluir do inicio da lista\n");
            printf("[7] Excluir do final da lista\n");
            printf("[8] Excluir de um ponto específico da lista\n");
            printf("[9] Liberar os elementos e mostrar a lista vazia\n");
            printf("[0] Terminar\n");
            printf("------------------------------------------------------------------\n");
            printf("Qual a sua opção? ");
            scanf("%d", &option); 

            
            switch (option) {
                case 1: 
                    printf("Digite o valor a ser adicionado: ");
                    scanf("%d", &data); 
                    addAtBeginning(&head, data); 
                    break;
                case 2: 
                    printf("Digite o valor a ser adicionado: ");
                    scanf("%d", &data); 
                    addAtEnd(&head, data); 
                    break;
                case 3: 
                    printf("Digite o valor a ser adicionado: ");
                    scanf("%d", &data);
                    printf("Digite a posição onde o valor deve ser adicionado: ");
                    scanf("%d", &position);
                    addAtPosition(&head, data, position); 
                    break;
                case 4:
                    listAllElements(head); 
                    break;
                case 5: 
                    printf("Digite a posição do elemento a ser listado: ");
                    scanf("%d", &position); 
                    listSpecificElement(head, position); 
                    break;
                case 6:
                    deleteAtBeginning(&head); 
                    break;
                case 7: 
                    deleteAtEnd(&head); 
                    break;
                case 8: 
                    printf("Digite a posição do elemento a ser excluído: ");
                    scanf("%d", &position);
                    deleteAtPosition(&head, position);
                    break;
                case 9: 
                    freeList(&head);
                    break;
                case 0: 
                    printf("Encerrando o programa.\n");
                    break;
                default: 
                    printf("Opção inválida!\n");
                    break;
            }
        } while (option != 0); 

        freeList(&head); 
        return 0;
    }
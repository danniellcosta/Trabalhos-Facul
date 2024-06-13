/*
    Grupo: Danniel Lopes da Costa, Carlos Guilherme da Silva Thomaz, Alan de Assis Gonçalves Santos, 
           Caio Henrique Dantas Milão do Nascimento, Daniel Oliveira Menezes Iorio e 
           Fellipe Daniel da Costa Paiva Carmo
    
    Trabalho: n°1 - Pilha:
    Esse código implementa uma pilha para gerenciar  a entrada e saída de carros em um estacionamento. 
    A estrutura de dados da pilha permite que os carros sejam adicionados e removidos de forma mais prática e 
    eficiente (último a entrar, primeiro a sair).
*/

#include <stdio.h>
#include <string.h>

#define CAPACIDADE 5 

// Define uma estrutura Carro que contém a placa do carro
typedef struct {
    char placa[8];
} Carro;

// Define uma estrutura Estacionamento que é uma pilha de Carros
typedef struct {
    Carro pilha[CAPACIDADE]; 
    int topo; 
} Estacionamento;

// Inicializa o estacionamento fazendo o topo apontar para -1 (indicando que está vazio)
void inicializaEstacionamento(Estacionamento* est) {
    est->topo = -1;
}

// Verifica se o estacionamento está cheio
int estahCheio(Estacionamento* est) {
    return est->topo == CAPACIDADE - 1;
}

// Verifica se o estacionamento está vazio
int estahVazio(Estacionamento* est) {
    return est->topo == -1;
}

// Adiciona um carro no estacionamento
void entradaCarro(Estacionamento* est, char placa[]) {
    if (estahCheio(est)) { 
        printf("Estacionamento cheio. Carro %s não pôde entrar.\n", placa); 
    } else { 
        est->topo++; 
        strcpy(est->pilha[est->topo].placa, placa); 
        printf("Carro %s entrou no estacionamento. Vaga disponível.\n", placa); 
    }
}

// Remove um carro do estacionamento
void saidaCarro(Estacionamento* est, char placa[]) {
    if (estahVazio(est)) { 
        printf("Carro %s não está no estacionamento.\n", placa); 
        return; 
    }

    int encontrado = 0; 
    int manobras = 0; 
    Carro tempPilha[CAPACIDADE];
    int tempTopo = -1; 


    while (!estahVazio(est)) {
        if (strcmp(est->pilha[est->topo].placa, placa) == 0) {
            encontrado = 1; 
            est->topo--; 
            break; 
        } else { 
            tempPilha[++tempTopo] = est->pilha[est->topo--]; 
            manobras++;
        }
    }

  
    while (tempTopo != -1) {
        est->pilha[++est->topo] = tempPilha[tempTopo--];
    }

   
    if (encontrado) {
        printf("Carro %s saiu do estacionamento. Manobrado %d vezes.\n", placa, manobras);
    } else {
        printf("Carro %s não está no estacionamento.\n", placa);
    }
}

// Processa uma lista de comandos
void processarComandos(char comandos[][10], int n) {
    Estacionamento est; 
    inicializaEstacionamento(&est); 

  
    for (int i = 0; i < n; i++) {
        char acao = comandos[i][0]; 
        char placa[8];
        strcpy(placa, &comandos[i][2]); 

 
        if (acao == 'E') {
            entradaCarro(&est, placa);
        } else if (acao == 'S') {
            saidaCarro(&est, placa);
        }
    }
}

// Função principal
int main() {
    
    char comandos[][10] = {
        "E ABC1234",
        "E DEF5678",
        "S ABC1234",
        "E GHI9012",
        "E JKL3456",
        "E MNO7890",
        "E PQR1234",
        "S GHI9012",
        "S DEF5678"
    };

    int n = sizeof(comandos) / sizeof(comandos[0]); 
    processarComandos(comandos, n); 

    return 0; 
}
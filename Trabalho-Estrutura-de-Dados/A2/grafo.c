/*
    Grupo: Danniel Lopes da Costa, Carlos Guilherme da Silva Thomaz, Alan de Assis Gonçalves Santos, 
           Caio Henrique Dantas Milão do Nascimento.
*/
#include <stdio.h>
#include <stdlib.h>

// Estrutura de dados para representar um nó do grafo
struct noGrafo
{
    int info;               
    struct noGrafo *proxNo; 
    struct noArco *arcos;   
};
typedef struct noGrafo *PtrNoGrafo;

// Estrutura de dados para representar um arco entre dois nós
struct noArco
{
    int peso;                
    struct noGrafo *no;      
    struct noArco *proxArco; 
};
typedef struct noArco *PtrNoArco;

// Insere um novo nó no grafo
void insertnode(PtrNoGrafo *g, PtrNoGrafo p)
{
    p->proxNo = *g;
    *g = p;
}

// Cria um arco entre dois nós com pesos
void joinwtInfo(PtrNoGrafo g, int x1, int x2, int p)
{
    PtrNoGrafo no1 = NULL, no2 = NULL;
    while (g != NULL)
    {
        if (g->info == x1)
            no1 = g;
        if (g->info == x2)
            no2 = g;
        g = g->proxNo;
    }
    if (no1 == NULL || no2 == NULL)
    {
        printf("Erro: Nó não encontrado.\n");
        return;
    }
    PtrNoArco novoArco = (PtrNoArco)malloc(sizeof(struct noArco));
    novoArco->peso = p;
    novoArco->no = no2;
    novoArco->proxArco = no1->arcos;
    no1->arcos = novoArco;
}

// Verifica se dois nós são adjacentes
int adjacent(PtrNoGrafo g, int x1, int x2)
{
    PtrNoGrafo no1 = NULL;
    while (g != NULL)
    {
        if (g->info == x1)
        {
            no1 = g;
            break;
        }
        g = g->proxNo;
    }
    if (no1 == NULL)
        return 0;
    PtrNoArco a = no1->arcos;
    while (a != NULL)
    {
        if (a->no->info == x2)
        {
            return 1;
        }
        a = a->proxArco;
    }
    return 0;
}

// Cria um grafo com 8 nós e adiciona arcos entre eles
void criaGrafo(PtrNoGrafo *g)
{
    // Cria os 8 nós do grafo
    PtrNoGrafo no0 = (PtrNoGrafo)malloc(sizeof(struct noGrafo));
    no0->info = 0;
    no0->proxNo = NULL;
    no0->arcos = NULL;

    PtrNoGrafo no1 = (PtrNoGrafo)malloc(sizeof(struct noGrafo));
    no1->info = 1;
    no1->proxNo = NULL;
    no1->arcos = NULL;

    PtrNoGrafo no2 = (PtrNoGrafo)malloc(sizeof(struct noGrafo));
    no2->info = 2;
    no2->proxNo = NULL;
    no2->arcos = NULL;

    PtrNoGrafo no3 = (PtrNoGrafo)malloc(sizeof(struct noGrafo));
    no3->info = 3;
    no3->proxNo = NULL;
    no3->arcos = NULL;

    PtrNoGrafo no4 = (PtrNoGrafo)malloc(sizeof(struct noGrafo));
    no4->info = 4;
    no4->proxNo = NULL;
    no4->arcos = NULL;

    PtrNoGrafo no5 = (PtrNoGrafo)malloc(sizeof(struct noGrafo));
    no5->info = 5;
    no5->proxNo = NULL;
    no5->arcos = NULL;

    PtrNoGrafo no6 = (PtrNoGrafo)malloc(sizeof(struct noGrafo));
    no6->info = 6;
    no6->proxNo = NULL;
    no6->arcos = NULL;

    PtrNoGrafo no7 = (PtrNoGrafo)malloc(sizeof(struct noGrafo));
    no7->info = 7;
    no7->proxNo = NULL;
    no7->arcos = NULL;

    // Insere os nós no grafo
    insertnode(g, no0);
    insertnode(g, no1);
    insertnode(g, no2);
    insertnode(g, no3);
    insertnode(g, no4);
    insertnode(g, no5);
    insertnode(g, no6);
    insertnode(g, no7);

    // Cria arcos entre os nós
    joinwtInfo(*g, 0, 3, 2);
    joinwtInfo(*g, 1, 0, 1);
    joinwtInfo(*g, 1, 2, 3);
    joinwtInfo(*g, 3, 0, 2);
    joinwtInfo(*g, 3, 4, 2);
    joinwtInfo(*g, 4, 4, 1);
    joinwtInfo(*g, 5, 6, 3);
}

// Libera a memória alocada para o grafo
void liberaGrafo(PtrNoGrafo g)
{
    while (g != NULL)
    {
        PtrNoGrafo tempNo = g;
        g = g->proxNo;

        PtrNoArco a = tempNo->arcos;
        while (a != NULL)
        {
            PtrNoArco tempArco = a;
            a = a->proxArco;
            free(tempArco);
        }

        free(tempNo);
    }
}

// Imprime o grafo
void mostraGrafo(PtrNoGrafo g)
{
    PtrNoGrafo p = g;
    while (p != NULL)
    {
        printf("== No %d ==\n", p->info);
        printf("  Arcos: ");

        PtrNoArco a = p->arcos;
        if (a == NULL)
            printf("Nenhum");
        else
        {
            while (a != NULL)
            {
                printf(" -> %d (%d)", a->no->info, a->peso);
                a = a->proxArco;
                if (a != NULL)
                    printf(", ");
            }
        }
        printf("\n");

        printf("  Adjacentes: ");

        int primeiraVez = 1;
        PtrNoGrafo q = g;
        while (q != NULL)
        {
            if (q != p && adjacent(g, p->info, q->info))
            {
                if (!primeiraVez)
                    printf(", ");
                printf("%d", q->info);
                primeiraVez = 0;
            }
            q = q->proxNo;
        }

        if (primeiraVez)
            printf("Nenhum");

        printf("\n\n");

        p = p->proxNo;
    }
}

int main(void)
{
    PtrNoGrafo g = NULL;
    criaGrafo(&g);
    mostraGrafo(g);
    liberaGrafo(g);

    return 0;
}
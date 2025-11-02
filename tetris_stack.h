#ifndef TETRIS_STACK_H
#define TETRIS_STACK_H

#define MAX_SIZE 10

// Estrutura para representar uma peça do Tetris
typedef struct {
    char tipo;     // Tipo da peça (I, L, J, O, S, T, Z)
    int cor;       // Código da cor da peça
} Peca;

// Estrutura da Fila Circular
typedef struct {
    Peca pecas[MAX_SIZE];
    int inicio;
    int fim;
    int tamanho;
} FilaPecas;

// Estrutura da Pilha
typedef struct {
    Peca pecas[MAX_SIZE];
    int topo;
} PilhaPecas;

// Funções da Fila
void inicializarFila(FilaPecas *fila);
int filaVazia(FilaPecas *fila);
int filaCheia(FilaPecas *fila);
int enfileirar(FilaPecas *fila, Peca peca);
int desenfileirar(FilaPecas *fila, Peca *peca);
void mostrarFila(FilaPecas *fila);

// Funções da Pilha
void inicializarPilha(PilhaPecas *pilha);
int pilhaVazia(PilhaPecas *pilha);
int pilhaCheia(PilhaPecas *pilha);
int empilhar(PilhaPecas *pilha, Peca peca);
int desempilhar(PilhaPecas *pilha, Peca *peca);
void mostrarPilha(PilhaPecas *pilha);

// Funções de integração
void trocarPecas(FilaPecas *fila, PilhaPecas *pilha);
void trocarPilhaComFila(FilaPecas *fila, PilhaPecas *pilha);

#endif // TETRIS_STACK_H
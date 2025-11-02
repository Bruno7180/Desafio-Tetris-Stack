#include <stdio.h>
#include "tetris_stack.h"

// Implementação das funções da Fila
void inicializarFila(FilaPecas *fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
}

int filaVazia(FilaPecas *fila) {
    return (fila->tamanho == 0);
}

int filaCheia(FilaPecas *fila) {
    return (fila->tamanho == MAX_SIZE);
}

int enfileirar(FilaPecas *fila, Peca peca) {
    if (filaCheia(fila)) {
        printf("Erro: Fila cheia!\n");
        return 0;
    }
    
    fila->fim = (fila->fim + 1) % MAX_SIZE;
    fila->pecas[fila->fim] = peca;
    fila->tamanho++;
    return 1;
}

int desenfileirar(FilaPecas *fila, Peca *peca) {
    if (filaVazia(fila)) {
        printf("Erro: Fila vazia!\n");
        return 0;
    }
    
    *peca = fila->pecas[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX_SIZE;
    fila->tamanho--;
    return 1;
}

void mostrarFila(FilaPecas *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }
    
            printf("Fila de pecas: ");
    int i, pos;
    for (i = 0; i < fila->tamanho; i++) {
        pos = (fila->inicio + i) % MAX_SIZE;
        printf("[%c] ", fila->pecas[pos].tipo);
    }
    printf("\n");
}

// Implementação das funções da Pilha
void inicializarPilha(PilhaPecas *pilha) {
    pilha->topo = -1;
}

int pilhaVazia(PilhaPecas *pilha) {
    return (pilha->topo == -1);
}

int pilhaCheia(PilhaPecas *pilha) {
    return (pilha->topo == MAX_SIZE - 1);
}

int empilhar(PilhaPecas *pilha, Peca peca) {
    if (pilhaCheia(pilha)) {
        printf("Erro: Pilha cheia!\n");
        return 0;
    }
    
    pilha->topo++;
    pilha->pecas[pilha->topo] = peca;
    return 1;
}

int desempilhar(PilhaPecas *pilha, Peca *peca) {
    if (pilhaVazia(pilha)) {
        printf("Erro: Pilha vazia!\n");
        return 0;
    }
    
    *peca = pilha->pecas[pilha->topo];
    pilha->topo--;
    return 1;
}

void mostrarPilha(PilhaPecas *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return;
    }
    
    printf("Pilha de reserva: ");
    for (int i = pilha->topo; i >= 0; i--) {
        printf("[%c] ", pilha->pecas[i].tipo);
    }
    printf("\n");
}

// Implementação das funções de integração
void trocarPecas(FilaPecas *fila, PilhaPecas *pilha) {
    if (filaVazia(fila)) {
            printf("Erro: Nao ha pecas na fila para trocar!\n");
        return;
    }
    
    Peca pecaFila, pecaPilha;
    
    // Se a pilha estiver vazia, apenas move a peça da fila para a pilha
    if (pilhaVazia(pilha)) {
        if (desenfileirar(fila, &pecaFila)) {
            empilhar(pilha, pecaFila);
                printf("Peca [%c] movida da fila para a pilha de reserva.\n", pecaFila.tipo);
        }
    } else {
        // Troca a peça da fila com a do topo da pilha
        if (desenfileirar(fila, &pecaFila)) {
            desempilhar(pilha, &pecaPilha);
            empilhar(pilha, pecaFila);
            enfileirar(fila, pecaPilha);
                printf("Pecas trocadas: Fila[%c] <-> Pilha[%c]\n", pecaFila.tipo, pecaPilha.tipo);
        }
    }
}

void trocarPilhaComFila(FilaPecas *fila, PilhaPecas *pilha) {
    if (pilhaVazia(pilha)) {
            printf("Erro: Pilha vazia, nao ha pecas para trocar!\n");
        return;
    }
    
    FilaPecas filaTemp;
    inicializarFila(&filaTemp);
    
    // Armazena temporariamente as peças da pilha
    PilhaPecas pilhaTemp;
    inicializarPilha(&pilhaTemp);
    
    // Move todas as peças da pilha para a pilha temporária
    Peca peca;
    while (!pilhaVazia(pilha)) {
        desempilhar(pilha, &peca);
        empilhar(&pilhaTemp, peca);
    }
    
    // Move o mesmo número de peças da fila para a pilha original
    int pecasTrocadas = 0;
    while (!pilhaVazia(&pilhaTemp) && !filaCheia(&filaTemp)) {
        if (filaVazia(fila)) break;
        
        desenfileirar(fila, &peca);
        empilhar(pilha, peca);
        pecasTrocadas++;
    }
    
    // Move as peças da pilha temporária para a fila
    while (!pilhaVazia(&pilhaTemp)) {
        desempilhar(&pilhaTemp, &peca);
        enfileirar(fila, peca);
    }
    
        printf("Troca concluida: %d pecas trocadas entre pilha e fila.\n", pecasTrocadas);
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tetris_stack.h"

// Função para limpar a tela
static void limparTela(void) {
    system("cls");
}

// Limpa o buffer de entrada até o fim de linha
static void flushInput(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

// Função para pausar e esperar ENTER do usuario
static void pausar(void) {
    flushInput();
    printf("\nPressione ENTER para continuar...");
    getchar();
}

// Função para gerar uma peça aleatória
Peca gerarPecaAleatoria() {
    Peca peca;
    char tipos[] = {'I', 'L', 'J', 'O', 'S', 'T', 'Z'};
    peca.tipo = tipos[rand() % 7];
    peca.cor = rand() % 7 + 1;  // Cores de 1 a 7
    return peca;
}

int main(void) {
    srand((unsigned int)time(NULL));  // Inicializa o gerador de numeros aleatorios

    FilaPecas fila;
    PilhaPecas pilha;
    inicializarFila(&fila);
    inicializarPilha(&pilha);

    int opcao = -1;
    Peca peca;

    do {
        limparTela();
        printf("\n=== TETRIS STACK - MENU ===\n");
        printf("1. Gerar nova peca na fila\n");
        printf("2. Jogar peca da fila\n");
        printf("3. Reservar peca na pilha\n");
        printf("4. Recuperar peca da pilha\n");
        printf("5. Trocar peca atual com reserva\n");
        printf("6. Trocar toda pilha com parte da fila\n");
        printf("7. Mostrar estado atual\n");
        printf("0. Sair\n\n");

        // Mostra estado atual
        printf("Estado atual do jogo:\n");
        mostrarFila(&fila);
        mostrarPilha(&pilha);

        printf("\nEscolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            // Entrada invalida: descarta resto da linha e marca opcao invalida
            flushInput();
            opcao = -1;
        }

        limparTela();

        switch(opcao) {
            case 1:
                peca = gerarPecaAleatoria();
                if (enfileirar(&fila, peca)) {
                    printf("Peca [%c] gerada e adicionada a fila.\n", peca.tipo);
                }
                break;

            case 2:
                if (desenfileirar(&fila, &peca)) {
                    printf("Peca [%c] jogada!\n", peca.tipo);
                }
                break;

            case 3:
                if (!filaVazia(&fila)) {
                    desenfileirar(&fila, &peca);
                    if (empilhar(&pilha, peca)) {
                        printf("Peca [%c] movida para a reserva.\n", peca.tipo);
                    }
                } else {
                    printf("Nao ha pecas na fila para reservar!\n");
                }
                break;

            case 4:
                if (desempilhar(&pilha, &peca)) {
                    if (enfileirar(&fila, peca)) {
                        printf("Peca [%c] recuperada da reserva.\n", peca.tipo);
                    } else {
                        empilhar(&pilha, peca);  // Devolve a peca para a pilha se nao puder enfileirar
                    }
                }
                break;

            case 5:
                trocarPecas(&fila, &pilha);
                break;

            case 6:
                trocarPilhaComFila(&fila, &pilha);
                break;

            case 7:
                printf("\nEstado atual do jogo:\n");
                mostrarFila(&fila);
                mostrarPilha(&pilha);
                break;

            case 0:
                printf("\nObrigado por jogar Tetris Stack!\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

        if (opcao != 0) {
            pausar();
        }

    } while(opcao != 0);

    return 0;
}
# Tetris Stack - Implementação em C

Este projeto implementa um sistema de gerenciamento de peças para o jogo Tetris Stack, utilizando estruturas de dados fundamentais como fila circular e pilha. O programa foi desenvolvido como parte de um trabalho acadêmico para demonstrar o uso prático dessas estruturas de dados.

## Estruturas Implementadas

### 1. Fila Circular
- Gerencia a sequência de peças que serão jogadas
- Implementada com array circular para otimização de memória
- Operações: enfileirar, desenfileirar, verificar se está vazia/cheia

### 2. Pilha
- Sistema de reserva de peças
# Tetris Stack - Implementação em C

Este projeto implementa um sistema de gerenciamento de peças para o jogo Tetris Stack, usando estruturas de dados fundamentais (fila circular e pilha). Foi desenvolvido como base para um trabalho acadêmico e demonstra operações básicas e integração entre as estruturas.

## O que foi melhorado nesta versão
- Tratamento seguro de entrada (evita comportamento repetido quando o usuário digita algo inválido).
- Pausa consistente entre telas (espera ENTER) para evitar "bombardeamento" de mensagens.
- Mensagens sem acentuação para evitar problemas de codificação no console do Windows.
- Removidos includes duplicados e chamadas que alteravam a codificação do console no `main.c`.

## Estruturas implementadas

- Fila circular (array) — operações: enfileirar, desenfileirar, verificar vazio/cheio.
- Pilha (array) — operações: empilhar, desempilhar, verificar vazio/cheio.
- Integração: troca entre fila e pilha / troca de toda pilha com parte da fila.

## Funcionalidades (menu)

1. Gerar nova peca na fila
2. Jogar peca da fila
3. Reservar peca na pilha
4. Recuperar peca da pilha
5. Trocar peca atual com reserva
6. Trocar toda pilha com parte da fila
7. Mostrar estado atual
0. Sair

## Como compilar e executar (Windows - PowerShell)

Recomendo usar o GCC (MinGW/MSYS2) no Windows. No PowerShell, execute:

```powershell
gcc main.c tetris_stack.c -o tetris_stack
.\tetris_stack
```

Se você preferir usar o terminal do VS Code integrado, o mesmo comando funciona.

## Observações sobre codificação de caracteres

Para evitar problemas com acentos no console do Windows, as mensagens do programa foram mantidas sem acentuaoes (por exemplo, "Peca" em vez de "Peça"). Se quiser mensagens com acento, posso:

- Restaurar acentos no código e adicionar instruoes para configurar o console para UTF-8 (p.ex. `chcp 65001`), ou
- Manter sem acentos (atual) para máxima compatibilidade.

## Estrutura do projeto

- `tetris_stack.h` — definicoes das structs e prototipos
- `tetris_stack.c` — implementacao da fila, pilha e funcoes de integracao
- `main.c` — menu e fluxo principal

## Como modificar o tamanho maximo

O tamanho da fila/pilha e controlado por `MAX_SIZE` em `tetris_stack.h`. Para aumentar, edite esse valor e recompile.

## Testes manuais simples

1. Compile e rode.
2. Escolha a opcao 1 algumas vezes para enfileirar pecas.
3. Use 3 para reservar (move da fila para pilha) e 4 para recuperar.
4. Teste 5 e 6 para trocas.

---

Se quiser, eu posso:

- Restaurar acentos e adicionar opcoes para configurar o console (UTF-8).
- Adicionar um `Makefile` ou `tasks.json` do VS Code para compilar com um clique.
- Adicionar testes unitarios simples para fila e pilha.

Diga qual desses extras prefere e eu implemento.
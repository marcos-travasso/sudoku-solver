#include "tabuleiro.h"
#include "stdlib.h"
#include "time.h"

int verificar_nova_posicao(int** tabuleiro, int linha, int coluna);

void preencher_tabuleiro(Tabuleiro* tabuleiro);

int resolver_posicao(Tabuleiro* tabuleiro, int linha, int coluna);

int resolver_sudoku(Tabuleiro* tabuleiro);

void esconder_numeros(Tabuleiro* tabuleiro, int quantidade_por_grid);

void gerar_tabuleiro(Tabuleiro* tabuleiro, int dificuldade);
#include <stdio.h>
#include "tabuleiro_testes.h"

int main() {
    Tabuleiro* tabuleiro = criar_tabuleiro();
    gerar_tabuleiro(tabuleiro, 5);
    imprimir_tabuleiro(tabuleiro->base);
    int a = resolver_sudoku(tabuleiro);

    imprimir_tabuleiro(tabuleiro->base);

    return 0;
}



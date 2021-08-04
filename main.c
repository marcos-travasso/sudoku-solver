#include <stdio.h>
#include "tabuleiro.h"
#include "tabuleiro_testes.h"

int main() {
    int** tabuleiro = criar_tabuleiro();
    preencher_tabuleiro(tabuleiro, 5);
    imprimir_tabuleiro(tabuleiro);
    //testar_verificacao();
    //testar_contagem();
    return 0;
}



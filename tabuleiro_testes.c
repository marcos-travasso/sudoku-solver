#include "stdio.h"
#include "tabuleiro_testes.h"

void testar_resolucao(){
    Tabuleiro* tabuleiro = criar_tabuleiro();
    tabuleiro->base[0][0] = 9;
    tabuleiro->base[0][2] = 6;
    tabuleiro->base[0][3] = 5;
    tabuleiro->base[0][5] = 1;
    tabuleiro->base[0][7] = 2;
    tabuleiro->base[0][8] = 3;

    tabuleiro->base[1][2] = 7;
    tabuleiro->base[1][3] = 2;
    tabuleiro->base[1][4] = 4;
    tabuleiro->base[1][6] = 9;
    tabuleiro->base[1][7] = 8;
    tabuleiro->base[1][8] = 5;

    tabuleiro->base[2][0] = 8;
    tabuleiro->base[2][1] = 5;
    tabuleiro->base[2][3] = 3;

    tabuleiro->base[3][1] = 9;
    tabuleiro->base[3][2] = 1;
    tabuleiro->base[3][3] = 7;
    tabuleiro->base[3][4] = 2;
    tabuleiro->base[3][5] = 8;
    tabuleiro->base[3][6] = 3;
    tabuleiro->base[3][7] = 6;
    tabuleiro->base[3][8] = 4;

    tabuleiro->base[4][0] = 3;
    tabuleiro->base[4][1] = 6;
    tabuleiro->base[4][2] = 4;
    tabuleiro->base[4][4] = 1;
    tabuleiro->base[4][8] = 2;

    tabuleiro->base[5][5] = 4;
    tabuleiro->base[5][6] = 5;

    tabuleiro->base[6][0] = 7;
    tabuleiro->base[6][2] = 3;
    tabuleiro->base[6][5] = 2;
    tabuleiro->base[6][8] = 6;

    tabuleiro->base[7][0] = 6;
    tabuleiro->base[7][1] = 2;
    tabuleiro->base[7][3] = 4;
    tabuleiro->base[7][4] = 5;
    tabuleiro->base[7][5] = 7;
    tabuleiro->base[7][6] = 1;
    tabuleiro->base[7][7] = 3;
    tabuleiro->base[7][8] = 8;

    tabuleiro->base[8][2] = 5;
    tabuleiro->base[8][3] = 8;
    tabuleiro->base[8][8] = 7;

    imprimir_tabuleiro(tabuleiro->base);

    int resolvido = resolver_sudoku(tabuleiro);

    printf("\n\n\n\n");
    imprimir_tabuleiro(tabuleiro->base);

    if(resolvido) { printf("Resolvido corretamente!\n"); }
    else { printf("Ocorreu um erro!\n"); }
}

void testar_tabuleiro_vazio(){
    Tabuleiro* tabu = criar_tabuleiro();
    imprimir_tabuleiro(tabu->base);

    resolver_sudoku(tabu);

    imprimir_tabuleiro(tabu->base);
}

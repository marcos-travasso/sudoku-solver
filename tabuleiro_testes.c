#include "stdio.h"
#include "tabuleiro_testes.h"

void testar_contagem(){
    //Criação de um tabuleiro para contar todos os valores presentes em cada grid
    int** tabuleiro = criar_tabuleiro();
    int contagem_grid;

    //Primeiro grid possui 5 elementos
    tabuleiro[1][0] = 2;
    tabuleiro[0][1] = 1;
    tabuleiro[1][1] = 4;
    tabuleiro[0][2] = 5;
    tabuleiro[2][2] = 3;
    contagem_grid = verificar_quantidade_grid(tabuleiro, 0, 0);
    printf("Grid 0 0: %d\n", contagem_grid);

    //Segundo grid possui 2 elementos
    tabuleiro[0][3] = 4;
    tabuleiro[0][4] = 3;
    contagem_grid = verificar_quantidade_grid(tabuleiro, 0, 1);
    printf("Grid 0 1: %d\n", contagem_grid);

    //Terceiro grid não possui elementos
    contagem_grid = verificar_quantidade_grid(tabuleiro, 0, 2);
    printf("Grid 0 2: %d\n", contagem_grid);

    imprimir_tabuleiro(tabuleiro);
}

void testar_verificacao(){
    //Criação de um tabuleiro para contar todos os valores presentes em cada grid
    int** tabuleiro = criar_tabuleiro();

    //Verificação vertical
    tabuleiro[0][1] = 2;
    tabuleiro[0][2] = 2;
    printf("Vertical (0): %d\n", verificar_tabuleiro(tabuleiro, 0, 2));
    tabuleiro[0][1] = 0;
    tabuleiro[0][2] = 0;

    //Verificação horizontal
    tabuleiro[1][0] = 2;
    tabuleiro[2][0] = 2;
    printf("Horizontal (0): %d\n", verificar_tabuleiro(tabuleiro, 2, 0));
    tabuleiro[1][0] = 0;
    tabuleiro[2][0] = 0;

    //Verificação na grid
    tabuleiro[2][3] = 2;
    tabuleiro[1][4] = 2;
    printf("Grid (0): %d\n", verificar_tabuleiro(tabuleiro, 2, 3));
    tabuleiro[2][3] = 0;
    tabuleiro[1][4] = 0;

    //Verificação na grid (diferentes grids)
    tabuleiro[2][3] = 2;
    tabuleiro[3][2] = 2;
    printf("Grid (1): %d\n", verificar_tabuleiro(tabuleiro, 2, 3));
    tabuleiro[2][3] = 0;
    tabuleiro[3][2] = 0;

}

void testar_resolucao(){
    int** tabuleiro = criar_tabuleiro();
    tabuleiro[0][0] = 9;
    tabuleiro[0][2] = 6;
    tabuleiro[0][3] = 5;
    tabuleiro[0][5] = 1;
    tabuleiro[0][7] = 2;
    tabuleiro[0][8] = 3;

    tabuleiro[1][2] = 7;
    tabuleiro[1][3] = 2;
    tabuleiro[1][4] = 4;
    tabuleiro[1][6] = 9;
    tabuleiro[1][7] = 8;
    tabuleiro[1][8] = 5;

    tabuleiro[2][0] = 8;
    tabuleiro[2][1] = 5;
    tabuleiro[2][3] = 3;

    tabuleiro[3][1] = 9;
    tabuleiro[3][2] = 1;
    tabuleiro[3][3] = 7;
    tabuleiro[3][4] = 2;
    tabuleiro[3][5] = 8;
    tabuleiro[3][6] = 3;
    tabuleiro[3][7] = 6;
    tabuleiro[3][8] = 4;

    tabuleiro[4][0] = 3;
    tabuleiro[4][1] = 6;
    tabuleiro[4][2] = 4;
    tabuleiro[4][4] = 1;
    tabuleiro[4][8] = 2;

    tabuleiro[5][5] = 4;
    tabuleiro[5][6] = 5;

    tabuleiro[6][0] = 7;
    tabuleiro[6][2] = 3;
    tabuleiro[6][5] = 2;
    tabuleiro[6][8] = 6;

    tabuleiro[7][0] = 6;
    tabuleiro[7][1] = 2;
    tabuleiro[7][3] = 4;
    tabuleiro[7][4] = 5;
    tabuleiro[7][5] = 7;
    tabuleiro[7][6] = 1;
    tabuleiro[7][7] = 3;
    tabuleiro[7][8] = 8;

    tabuleiro[8][2] = 5;
    tabuleiro[8][3] = 8;
    tabuleiro[8][8] = 7;

    imprimir_tabuleiro(tabuleiro);
    resolver_sudoku(tabuleiro);
    printf("\n\n\n\n");
    imprimir_tabuleiro(tabuleiro);
}
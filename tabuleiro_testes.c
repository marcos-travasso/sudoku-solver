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
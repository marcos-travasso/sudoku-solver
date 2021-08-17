/**
 * Funções referentes a manipulação da matriz do tabuleiro
 */

#include "tabuleiro.h"
#include "stdlib.h"
#include "stdio.h"

Tabuleiro* criar_tabuleiro(){
    int i;
    Tabuleiro* tabuleiro = (Tabuleiro*) malloc(sizeof(Tabuleiro));
    tabuleiro->base = (int**) malloc(sizeof(int*) * 9);
    tabuleiro->auxiliar = (int**) malloc(sizeof(int*) * 9);

    for(i = 0; i < 9; i++){
        tabuleiro->base[i] = (int*) calloc(sizeof(int), 9);
        tabuleiro->auxiliar[i] = (int*) calloc(sizeof(int), 9);
    }

    return tabuleiro;
}

void destruir_tabuleiro(Tabuleiro* tabuleiro){
    int i;
    for(i = 0; i < 9; i++){
        free(tabuleiro->base[i]);
        free(tabuleiro->auxiliar[i]);
    }
    free(tabuleiro->base);
    free(tabuleiro->auxiliar);
    free(tabuleiro);
}

void copiar_tabuleiro(int** tabuleiro_copiado, int** tabuleiro){
    int i, j;

    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            tabuleiro[i][j] = tabuleiro_copiado[i][j];
        }
    }
}

void imprimir_tabuleiro(int** tabuleiro){
    int i, j;

    printf("\n-------------------------\n");

    for(i = 0; i < 9; i++){
        printf("| ");
        for(j = 0; j < 9; j++){
            printf("%d ", tabuleiro[i][j]);
            if((j + 1) % 3 == 0){ printf("| "); }
        }
        printf("\n");
        if((i + 1) % 3 == 0){ printf("-------------------------\n"); }
    }
    printf("\n");
}

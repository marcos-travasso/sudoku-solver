#include "stdlib.h"
#include "stdio.h"
#include "time.h"

int** criar_tabuleiro(){
    int **tabuleiro = (int**) malloc(sizeof(int*) * 9);
    int i;
    for(i = 0; i < 9; i++){
        tabuleiro[i] = (int*) calloc(sizeof(int), 9);
    }

    return tabuleiro;
}

void destruir_tabuleiro(int** tabuleiro){
    int i;
    for(i = 0; i < 9; i++){
        free(tabuleiro[i]);
    }
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

    printf("-------------------------\n");

    for(i = 0; i < 9; i++){
        printf("| ");
        for(j = 0; j < 9; j++){
            printf("%d ", tabuleiro[i][j]);
            if((j + 1) % 3 == 0){ printf("| "); }
        }
        printf("\n");
        if((i + 1) % 3 == 0){ printf("-------------------------\n"); }
    }
}

int verificar_quantidade_grid(int** tabuleiro, int grid_linha, int grid_coluna){
    int soma = 0, i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(tabuleiro[(grid_linha * 3) + i][(grid_coluna * 3) + j] != 0){
                soma++;
            }
        }
    }
    return soma;
}

int verificar_tabuleiro(int** tabuleiro, int linha, int coluna){
    int numero_colocado = tabuleiro[linha][coluna];
    int i, j;

    //Verificar linha e coluna
    for(i = 0; i < 9; i++){
        if(tabuleiro[linha][i] == numero_colocado && i != coluna){
            return 0;
        }
        if(tabuleiro[i][coluna] == numero_colocado && i != linha){
            return 0;
        }
    }

    //Verificar grid.
    //A verificação é feita a numerar os grids usando as posições base (linha e coluna) dividas por 3, para termos a
    //posição do grid em que o número se encontra.
    int grid_linha = (linha / 3) * 3;
    int grid_coluna = (coluna / 3) * 3;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(tabuleiro[grid_linha + i][grid_coluna + j] == numero_colocado && grid_linha + i != linha && grid_coluna + j != coluna){
                return 0;
            }
        }
    }
    return 1;
}

void preencher_tabuleiro(int** tabuleiro, int numero_por_grid){
    int i, j, linha_temp, coluna_temp, numero_temp;
    int** tabuleiro_auxiliar = criar_tabuleiro();
    srand(time(NULL));

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            do{
                copiar_tabuleiro(tabuleiro, tabuleiro_auxiliar);
                linha_temp = (i * 3) + (rand() % 3);
                coluna_temp = (j * 3) + (rand() % 3);
                numero_temp = (rand() % 9) + 1;
                tabuleiro_auxiliar[linha_temp][coluna_temp] = numero_temp;

                if(tabuleiro[linha_temp][coluna_temp] == 0 && verificar_tabuleiro(tabuleiro_auxiliar, linha_temp, coluna_temp)){
                    copiar_tabuleiro(tabuleiro_auxiliar, tabuleiro);
                }
            }while(verificar_quantidade_grid(tabuleiro, i, j) != numero_por_grid);
            copiar_tabuleiro(tabuleiro_auxiliar, tabuleiro);
        }
    }

    destruir_tabuleiro(tabuleiro_auxiliar);
}

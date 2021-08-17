/**
 * Funções referentes a resolução do sudoku
 */
#include "tabuleiro_funcoes.h"
#include "stdio.h"

int verificar_nova_posicao(int** tabuleiro, int linha, int coluna){
    int numero_colocado = tabuleiro[linha][coluna];
    if(numero_colocado == 0) { return 0; }
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
    //A verificação é feita a numerar os grids usando linha e coluna divido por 3, para termos o
    //índice do grid em que o número se encontra.
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

void gerar_tabuleiro(Tabuleiro* tabuleiro, int dificuldade){
    preencher_tabuleiro(tabuleiro);
    esconder_numeros(tabuleiro, dificuldade);
}

void preencher_tabuleiro(Tabuleiro* tabuleiro){
    int i, j, coluna_temp;
    srand(time(NULL));

    do{
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                coluna_temp = rand() % 9;
                tabuleiro->base[i][coluna_temp] = rand() % 9 + 1;

                if(!verificar_nova_posicao(tabuleiro->base, i, coluna_temp)) { tabuleiro->base[i][coluna_temp] = 0; }
            }
        }
    }while(!resolver_sudoku(tabuleiro));
}

int contar_grid(int** tabuleiro, int grid_linha, int grid_coluna){
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

void esconder_numeros(Tabuleiro* tabuleiro, int quantidade_por_grid){
    int i, j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            while(contar_grid(tabuleiro->base, i, j) != quantidade_por_grid){
                tabuleiro->base[(i * 3) + rand() % 3][(j * 3) + rand() % 3] = 0;
            }
        }
    }
}

int resolver_posicao(Tabuleiro* tabuleiro, int linha, int coluna){
    //Caso em que se trata de um número pré-determinado no tabuleiro base.
    if(tabuleiro->base[linha][coluna] != 0){
        if(coluna != 8){ return resolver_posicao(tabuleiro, linha, coluna + 1); }
        else if(linha != 8){ return resolver_posicao(tabuleiro, linha + 1, 0); }

        //Primeira possibilidade de finalizar o código recursivo com o tabuleiro solucionado
        return 1;
    }

    if(tabuleiro->auxiliar[linha][coluna] < 9){
        (tabuleiro->auxiliar[linha][coluna])++;

        if(verificar_nova_posicao(tabuleiro->auxiliar, linha, coluna)){
            int solucionado = 0;

            if(coluna != 8) { solucionado = resolver_posicao(tabuleiro, linha, coluna + 1); }
            else if(linha != 8) { solucionado = resolver_posicao(tabuleiro, linha + 1, 0); }
            else { solucionado = 1; }

            //Segunda possibilidade de finalizar o código recursivo
            if(solucionado) { return 1; }
        }
        //Chamado do backtracking nesse mesmo número
        return resolver_posicao(tabuleiro, linha, coluna);
    }

    //Chamado do backtracking no número anterior
    tabuleiro->auxiliar[linha][coluna] = 0;
    return 0;
}

int resolver_sudoku(Tabuleiro* tabuleiro){
    copiar_tabuleiro(tabuleiro->base, tabuleiro->auxiliar);

    int resolvido = resolver_posicao(tabuleiro, 0, 0);

    copiar_tabuleiro(tabuleiro->auxiliar, tabuleiro->base);

    return resolvido;
}

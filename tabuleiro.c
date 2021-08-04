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
    //srand(time(NULL));

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

int resolver_celula(int** tabuleiro_base, int** tabuleiro_resolver, int linha, int coluna){
    //Caso em que estou tratando com um número fixo
    int valor_atual = tabuleiro_resolver[linha][coluna];
    if(tabuleiro_base[linha][coluna] != 0){
        //Casos diferentes do último elemento da coluna antes do fim da linha
        if(coluna != 8){ return resolver_celula(tabuleiro_base, tabuleiro_resolver, linha, coluna + 1); }
        //Caso em que é o fim da linha
        else if(linha != 8){ return resolver_celula(tabuleiro_base, tabuleiro_resolver, linha + 1, 0); }
        //Último elemento
        return 1;
    }

    //Caso a tratar números a resolver
    //Primeiro verificar se posso incrementar e manter menor do que 9
    if(tabuleiro_resolver[linha][coluna] < 9){
        (tabuleiro_resolver[linha][coluna])++;
        //Caso dê certo (não dê conflito na verificação), ele passa pro próximo (se houver próximo)
        if(verificar_tabuleiro(tabuleiro_resolver, linha, coluna)){
            int possivel = 0;
            if(coluna != 8) { possivel = resolver_celula(tabuleiro_base, tabuleiro_resolver, linha, coluna + 1); }
            else if(linha != 8) { possivel = resolver_celula(tabuleiro_base, tabuleiro_resolver, linha + 1, 0); }

            if(possivel) { return 1; }

        }
        //Caso não possa ser preenchido com esse valor, a função é chamada novamente para essa posição
        return resolver_celula(tabuleiro_base, tabuleiro_resolver, linha, coluna);
    }
    //Caso já seja 9, ele tem que refazer como 0
    tabuleiro_resolver[linha][coluna] = 0;
    return 0;
}

void resolver_sudoku(int** tabuleiro){
    int** tabuleiro_resolver = criar_tabuleiro();
    int possivel;
    copiar_tabuleiro(tabuleiro, tabuleiro_resolver);

    possivel = resolver_celula(tabuleiro, tabuleiro_resolver, 0, 0);
    printf("Resultado: %d\n", possivel);
    copiar_tabuleiro(tabuleiro_resolver, tabuleiro);
}

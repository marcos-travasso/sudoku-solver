#include <stdio.h>
#include "tabuleiro_testes.h"

int main() {
    int dificuldade;
    do{
         printf("Digite a quantidade de numeros preenchidos por grid (min: 0, max: 9): ");
	 scanf("%d", &dificuldade);
    }while(dificuldade < 0 && dificuldade > 9);

    Tabuleiro* tabuleiro = criar_tabuleiro();
    gerar_tabuleiro(tabuleiro, dificuldade);

    imprimir_tabuleiro(tabuleiro->base);
    
    resolver_sudoku(tabuleiro);
	
    imprimir_tabuleiro(tabuleiro->base);

    destruir_tabuleiro(tabuleiro);
    
    return 0;
}



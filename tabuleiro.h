typedef struct tabuleiro{
    int** base;
    int** auxiliar;
}Tabuleiro;

Tabuleiro* criar_tabuleiro();

void destruir_tabuleiro(Tabuleiro* tabuleiro);

void copiar_tabuleiro(int** tabuleiro_copiado, int** tabuleiro);

void imprimir_tabuleiro(int** tabuleiro);

void limpar_tabuleiro(int** tabuleiro);
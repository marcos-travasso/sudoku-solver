int** criar_tabuleiro();

void destruir_tabuleiro(int** tabuleiro);

void copiar_tabuleiro(int** tabuleiro_copiado, int** tabuleiro);

void imprimir_tabuleiro(int** tabuleiro);

int verificar_quantidade_grid(int** tabuleiro, int grid_linha, int grid_coluna);

int verificar_tabuleiro(int** tabuleiro, int linha, int coluna);

void preencher_tabuleiro(int** tabuleiro, int numero_por_grid);

int resolver_celula(int** tabuleiro_base, int** tabuleiro_resolver, int linha, int coluna);

int resolver_sudoku(int** tabuleiro);

int** criar_tabuleiro();

void imprimir_tabuleiro(int** tabuleiro);

void preencher_tabuleiro(int** tabuleiro, int numero_por_grid);

int verificar_tabuleiro(int** tabuleiro, int linha, int coluna);

int verificar_quantidade_grid(int** tabuleiro, int grid_linha, int grid_coluna);

void resolver_sudoku(int** tabuleiro);

int resolver_celula(int** tabuleiro, int linha, int coluna);
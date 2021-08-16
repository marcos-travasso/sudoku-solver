all:
	gcc -o sudoku main.c tabuleiro.c tabuleiro_funcoes.c tabuleiro_testes.c
clean:
	rm sudoku

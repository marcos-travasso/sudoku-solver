all:
	gcc -o sudoku main.c tabuleiro.c tabuleiro_funcoes.c
clean:
	rm sudoku

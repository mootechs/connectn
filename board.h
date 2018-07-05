#ifndef BOARD_H
	#define BOARD_H
	void set_up(char*** board, int *turn, int rows, int cols);
	char** make_board(int num_rows, int num_cols);
	void declare_winner(char** board, int rows, int cols, int turn, int win_cond, char pieces);
	void make_move(char** board, int* row, int col, char piece);
	void print_board(char** board, int num_rows, int num_cols);
	void clean_up(char** board, int num_rows);
#endif

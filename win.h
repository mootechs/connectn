#ifndef WIN_H
	#define WIN_H
	#include <stdbool.h>
	
	bool is_game_over(char** board, int num_rows, int num_cols, int win_cond, char pieces);
	bool won(char** board, int num_rows, int num_cols, int win_cond, char pieces);
	bool horz_win(char** board, int num_rows, int num_cols, int win_cond, char pieces);
	bool vert_win(char** board, int num_rows, int num_cols, int win_cond, char pieces);
	bool diag_win(char** board, int num_rows, int num_cols, int win_cond, char pieces);
	bool left_diag_win(char** board, int num_rows, int num_cols, int win_cond, char pieces);
	bool right_diag_win(char** board, int num_rows, int num_cols, int win_cond, char pieces);
	bool tied(char** board, int num_rows, int num_cols, int win_cond, char pieces);
	bool is_board_full(char** board, int num_rows, int num_cols);
#endif

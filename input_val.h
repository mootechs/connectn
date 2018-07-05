#ifndef INPUT_VAL_H
	#define INPUT_VAL_H

	#include <stdbool.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <ctype.h>
	void command_input_check(int argc);
	int game_mode(void);
	int difficulty(void);
	bool filled(char** board, int row, int col, int num_cols);
	bool consume_stdin();
	bool min_valid_requirements(int num_args_read, int num_args_needed, bool nothing_else);
	int get_int(char* prompt, bool nothing_else);
	int get_bound_int(char* prompt, bool nothing_else, int low, int high);
	void get_valid_move(char** board, int num_rows, int num_cols,
										int* row, int* col);
	bool is_valid_move(int num_args_read, int num_args_needed, 
									 char** board, int row, int col,
									 int num_rows, int num_cols);
	bool inbounds(int row, int col, int num_rows, int num_cols);

#endif

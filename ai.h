#ifndef AI_H
	#define AI_H

#include <stdlib.h>
#include <stdio.h>
typedef struct {
    int row;
    int col;
    int score;
} Move;

int scores(char** board, int num_rows, int num_cols, int win_cond, char player, int depth);
int available(char** board, int* available_cols, int row, int num_cols);
Move minimax(char** board, int num_rows, int num_cols, int win_cond, char player, int depth);
Move mm_alphabeta(char** board, int num_rows, int num_cols, int win_cond, char player, int depth, int alpha, int beta);
#endif

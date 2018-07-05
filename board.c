#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "win.h"

void set_up(char*** board, int* turn, int rows, int cols) {
	*board = make_board(rows, cols);
	*turn = 0;
}

char** make_board(int num_rows, int num_cols) {
	char** board = (char**)malloc(num_rows * sizeof(char*));
	int i, j;
	
	for (i = 0; i < num_rows; ++i) {
		board[i] = (char*)malloc(num_cols * sizeof(char));
		for(j = 0; j < num_cols; ++j) {
			board[i][j] = '*';
		}
	}
	return board;
}

//Says who the winner is
void declare_winner(char** board, int rows, int cols, int turn, int win_cond, char pieces) {
	if(tied(board, rows, cols, win_cond, pieces)) {
		printf("Tie game!\n");
	}
	else if(turn == 0) {
		printf("Player 2 Won!\n");
	}
	else {
		printf("Player 1 Won!\n");
	}
}

//Makes the move
void make_move(char** board, int* row, int col, char piece) {
	
	int newRow = *row;
	
	while(board[newRow][col] != '*') {
		--newRow;
	}
		
	board[newRow][col] = piece;
	*row = newRow;
}

void print_board(char** board, int num_rows, int num_cols) {
	int i, j;
	int colNum = num_rows - 1;

	for (i = 0; i < num_rows; ++i) {
		printf("%d ", colNum);    //Change this back to colNum later
		colNum--;
		for (j = 0; j < num_cols; ++j) {
			printf("%c ", board[i][j]);
		}
	printf("\n");
	}
	printf("  ");
	for (i = 0; i < num_cols; ++i) {
		printf("%d ", i);
	}
	printf("\n");
}
					
void clean_up(char** board, int num_rows) {
	int i = 0;
	for (i = 0; i < num_rows; i++) {
		free(board[i]);
	}
    	free(board);
}

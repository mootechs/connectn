#include <stdio.h> 
#include "win.h"

//Checks if game is finished
bool is_game_over(char** board, int num_rows, int num_cols, int win_cond, char pieces) { //1
	return won(board, num_rows, num_cols, win_cond, pieces) || 
				tied(board, num_rows, num_cols, win_cond, pieces);
}

//Checks if a player has won
bool won(char** board, int num_rows, int num_cols, int win_cond, char pieces){
	return horz_win(board, num_rows, num_cols, win_cond, pieces)  || 
				 vert_win(board, num_rows, num_cols, win_cond, pieces) || 
				 diag_win(board, num_rows, num_cols, win_cond, pieces); 
}

//Checks for horizontal win
bool horz_win(char** board, int num_rows, int num_cols, int win_cond, char pieces){
	int i, j;
	int counter = 0;

	for(i = 0; i < num_rows; ++i) {	
		for (j = 0; j < num_cols; ++j) {

			if(board[i][j] == pieces){
				counter++;
				if (counter == win_cond) {
					//printf("horz\n");
					return true;
				}
			}
			else {
				counter = 0;
				}
			}
		counter = 0;
	}
	return false;
}

//Checks for a vertical win
bool vert_win(char** board, int num_rows, int num_cols, int win_cond, char pieces) {
	int i, j;
	int counter = 0;
	
	for(i = 0; i < num_cols; ++i) {	
		for (j = 0; j < num_rows; ++j) {
			if(board[j][i] == pieces){
				counter++;
				if (counter == win_cond) {
					//printf("vert\n");
					return true;
				}
			}
			else {
				counter = 0;
				}
			}
		counter = 0;
		
	}
	return false;
}

//Checks for diagonal win either direction
bool diag_win(char** board, int num_rows, int num_cols, int win_cond, char pieces){
	return left_diag_win(board, num_rows, num_cols, win_cond, pieces)  || 
				 right_diag_win(board, num_rows, num_cols, win_cond, pieces);
}

//Checks for left diagonal win
bool left_diag_win(char** board, int num_rows, int num_cols, int win_cond, char pieces){
	int i, j, k;
	int counter = 0;

	//I start from [0][0] and I scale up diagonally
	for (i = 0; i < num_rows; ++i) {
		for (j = 0; j < num_cols; ++j) {
			counter = 0;
			//Move by how many rows are left
			for (k = 0; k < num_rows - i; ++k) {
				if (board[i + k][j + k] == pieces) {
					counter++;
				}
				else {
					break;
				}
			}
			if (counter == win_cond) {
				return true;
			}
		}
	}
	return false;
}

//Checks for right diagonal win
bool right_diag_win(char** board, int num_rows, int num_cols, int win_cond, char pieces){
	int i, j, k;
	int counter = 0;

	//Starts from the bottom right corner and moves diagonally upwards
	//I iterate diagonally and to the right	
	for (i = num_rows - 1; i > 0; --i) {
		for (j = 0; j < num_cols; ++j) {
			counter = 0;
			//num_cols - j because num_rows - j will go out of bounds
			for (k = 0; k < num_cols - j; ++k) {
				//I move up and right by factor k. i is subracted because the row on the bottom is the num_rows - 1
				//
				//If a match is found, increase the counter. Else leave the loop
				if (i-k < 0) break;
				if (board[i - k][j + k] == pieces) {
					counter++;
				}
				else {
					break;
				}
			}
			if (counter == win_cond) {
				return true;
			}
		}
	}
	return false;
}

//Checks if there is a tie
bool tied(char** board, int num_rows, int num_cols, int win_cond, char pieces){
	return is_board_full(board, num_rows, num_cols) && 
				!won(board, num_rows, num_cols, win_cond, pieces);
}

//Checks if board is full
bool is_board_full(char** board, int num_rows, int num_cols){
	int i, j;
	
	for(i = 0; i < num_rows; ++i){
		for(j = 0; j < num_cols; ++j){
			if(board[i][j] == '*'){
				return false;
			}
		}
	}
	return true;
}



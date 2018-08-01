#include <stdio.h>
#include <time.h>
#include "board.h"
#include "win.h"
#include "input_val.h"
#include "ai.h"

/* Title: connectn.c
 * Author: Jonathan Quach
 * Description: Plays a connect n game given board size and the number
 * of pieces needed to win.
 */

//I wish I had put the parameters in a struct when I originally made the game...

int ai_algorithm() {
    int choice;
    printf("Please select the algorithm:\n");
    printf("1. Minimax\n2. Minimax w/ Alpha-Beta pruning\n");
    printf("Choice: ");
    scanf("%d",&choice);
    return choice;
}
//Plays the game
void play_game(char** board, int num_rows, int num_cols, int turn, int win_cond) {
	char pieces[] = "XO";
	int row, col;
	int mode = game_mode();
        clock_t t;
        double cpu_time;

	if (mode == 1) {	//Vs CPU
                Move move;
		int depth = difficulty(); 
                int ai_choice = ai_algorithm();
		char cpu = 'O';
		char human = 'X';
		while(!is_game_over(board, num_rows, num_cols, win_cond, pieces[(turn + 1) % 2])) { //turn needs to be passed like this initially turn != (turn + 1) % 2
			print_board(board, num_rows, num_cols);
			if (pieces[turn] == human) {
			   get_valid_move(board, num_rows, num_cols, &row, &col); 
			   make_move(board, &row, col, pieces[turn]);
			}
			else {
                            t = clock();
                            switch (ai_choice) {
                                case 1:
	    		            move = minimax(board, num_rows, num_cols, win_cond, cpu, depth);
                                    break;
                                case 2:
                                    move =  mm_alphabeta(board,num_rows,num_cols,win_cond,cpu,depth,-99999,99999);
                                    break;
                                default:
                                    printf("Not a valid choice\n");
                                    return;
                        
                            }
			   row = move.row;
			   col = move.col;
			   board[row][col] = cpu;
                           t = clock() - t;
                           cpu_time = ((double) t) / CLOCKS_PER_SEC;
                           printf("CPU's Time: %fs\n", cpu_time);
			   printf("CPU's move:\n");
			}
			turn = (turn + 1) % 2;
		}
	}
	else {			//VS Human
		while(!is_game_over(board, num_rows, num_cols, win_cond, pieces[(turn + 1) % 2])) { //turn needs to be passed like this initially turn != (turn + 1) % 2
			print_board(board, num_rows, num_cols);
			get_valid_move(board, num_rows, num_cols, &row, &col); 
			make_move(board, &row, col, pieces[turn]);
			turn = (turn + 1) % 2;
		}
	}
	print_board(board, num_rows, num_cols);
	declare_winner(board, num_rows, num_cols, turn, win_cond, pieces[turn]);
}

int main(int argc, char* argv[]) {
	char** board;
	int turn, num_rows, num_cols, win_cond;
	//Scans for the commandline inputs
	command_input_check(argc);
	sscanf(argv[1], "%d", &num_rows);
	sscanf(argv[2], "%d", &num_cols);
	sscanf(argv[3], "%d", &win_cond);
	
	set_up(&board, &turn, num_rows, num_cols);
	play_game(board, num_rows, num_cols, turn, win_cond);
	clean_up(board, num_rows);
	
	return 0;
}

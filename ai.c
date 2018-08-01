#include "ai.h"
#include "win.h"
#include "board.h"
#include "input_val.h"

int scores(char** board, int num_rows, int num_cols, int win_cond, char player, int depth) {
    const char human = 'X';
    const char cpu = 'O';
    if (won(board, num_rows, num_cols, win_cond, cpu)) {
            return 10-depth;
    }
    else if (won(board, num_rows, num_cols, win_cond, human)) {
            return depth-10;
    }
    
    return 0;
}

int available(char** board, int* available_cols, int row, int num_cols) {
    int length = 0;
    int i;
    for (i = 0; i < num_cols; ++i) {
        if (!filled(board, row, i, num_cols)) {
            available_cols[length] = i;
	    length++;
        }
    }
    return length;
}


Move minimax(char** board, int num_rows, int num_cols, int win_cond, char player, int depth) {
    Move moves[num_cols];
    int available_cols[num_cols];

    
    const char human = 'X';
    const char cpu = 'O';
    int i, bestIdx, bestVal;
    int row = num_rows - 1;

    if (is_game_over(board, num_rows, num_cols, win_cond, human)
	|| is_game_over(board, num_rows, num_cols, win_cond, cpu)
	|| depth == 0) {
        Move move;
        move.score = scores(board, num_rows, num_cols, win_cond, player, depth);
        return move;
    }
    int length = available(board, available_cols, row, num_cols);
    
    for (i = 0; i < length; ++i) {
        int col = available_cols[i];
        Move move;
    	row = num_rows - 1;
	make_move(board, &row, col, player);
        if (player == cpu) {
            move = minimax(board, num_rows, num_cols, win_cond, human, depth-1);

        }
        else {
            move = minimax(board, num_rows, num_cols, win_cond, cpu, depth-1);
        }
        move.row = row;
        move.col = col;

        board[row][col] = '*';	//reset the spot to empty for return 
        moves[i] = move;	//Push move to array
	length = available(board, available_cols, num_rows, num_cols);	//update available cols

    }
    
    
    if (player == cpu) {
        bestVal = -99999;
        for (i = 0; i < length; ++i) {
            if (moves[i].score > bestVal) {
                bestVal = moves[i].score;
                bestIdx = i;
            }
        }
    }
    else {
        bestVal = 99999;
        for (i = 0; i < length; ++i) {
            if (moves[i].score < bestVal) {
                bestVal = moves[i].score;
                bestIdx = i;
            }
        }
    }

    return moves[bestIdx]; 
}


Move mm_alphabeta(char** board, int num_rows, int num_cols, int win_cond, char player, int depth, int alpha, int beta) {
    int  available_cols[num_cols];
    Move bestMove;
    const char human = 'X';
    const char cpu = 'O';
    int i, bestVal;
    int row = num_rows - 1;

    if (is_game_over(board, num_rows, num_cols, win_cond, human)
	|| is_game_over(board, num_rows, num_cols, win_cond, cpu)
	|| depth == 0) {
        Move move;
        move.score = scores(board, num_rows, num_cols, win_cond, player, depth);
        return move;
    }
    
    int length = available(board, available_cols, num_rows, num_cols);
        if (player == cpu) {
            bestVal = -99999;
            for (i = 0; i < length; ++i) {
                int col = available_cols[i];
                row = num_rows - 1;
                make_move(board, &row, col, player);
                Move move = mm_alphabeta(board,num_rows,num_cols,win_cond,human,depth-1,alpha,beta);
                move.row = row;
                move.col = col;

                board[row][col] = '*';	//reset the spot to empty for return 

                if (move.score > bestVal) {
                    bestVal = move.score;
                    bestMove = move;
                }
                alpha = alpha > bestVal ? alpha : bestVal;
                if (alpha >= beta)
                    break;
	        length = available(board, available_cols, num_rows, num_cols);	//update available cols
            }
        } 
        else {
            bestVal = 99999;
            for (i = 0; i < length; ++i) {
                int col = available_cols[i];
                row = num_rows - 1;
                make_move(board, &row, col, player);
                Move move = mm_alphabeta(board,num_rows,num_cols,win_cond,cpu,depth-1,alpha,beta);
                move.row = row;
                move.col = col;

                board[row][col] = '*';	//reset the spot to empty for return 

                if (move.score < bestVal) {
                    bestVal = move.score;
                    bestMove = move;
                }
                alpha = alpha < bestVal ? alpha : bestVal;
                if (alpha >= beta)
                    break;
	        length = available(board, available_cols, num_rows, num_cols);	//update available cols
            }
        }

    return bestMove;
}


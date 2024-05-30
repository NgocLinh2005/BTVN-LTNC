#ifndef LOGIC_H_INCLUDED
#define LOGIC_H_INCLUDED
#include <iostream>
#include "graphics.h"
#include "def.h"
#define EMPTY_CELL ' '
#define O_CELL 'o'
#define X_CELL 'x'

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
struct Tictactoe {
    char board[BOARD_SIZE][BOARD_SIZE];
    char nextMove = O_CELL;

    void init()
    {
        for (int i = 0; i < BOARD_SIZE; i++)
            for (int j = 0; j < BOARD_SIZE; j++) board[i][j] = EMPTY_CELL;
    }
    void moved(int row, int column)
    {
        if (row >= 0 && row < BOARD_SIZE &&
            column >= 0 && column < BOARD_SIZE && board[row][column]==EMPTY_CELL)
        {
            board[row][column] = nextMove;
            nextMove = (nextMove == O_CELL) ? X_CELL : O_CELL;
        }
    }

    bool checkEnd(int row, int column, int winCondition) {
    int temp = 0;
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[row][j] == board[row][j + 1] && board[row][j] == board[row][column]) temp++;
        else temp = 0;
        if (temp == winCondition - 1) return true;
    }
    temp = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][column] == board[i + 1][column] && board[row][column] == board[i][column]) temp++;
        else temp = 0;
        if (temp == winCondition - 1) return true;
    }
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[row - column + j][j] == board[row - column + j + 1][j + 1] && board[row - column + j][j] == board[row][column])
            temp++;
        else temp = 0;
        if (temp == winCondition - 1) return true;
    }
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[row + column - j][j] == board[row + column - j - 1][j + 1] && board[row + column - j][j] == board[row][column])
            temp++;
        else temp = 0;
        if (temp == winCondition - 1) return true;
    }
    return false;
}

};





#endif // LOGIC_H_INCLUDED

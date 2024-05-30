#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED
#define BOARD_SIZE 20
#define BOARD_X 10
#define BOARD_Y 10
#define size_ox 30
#define CELL_SIZE size_ox

const int SCREEN_WIDTH = size_ox*BOARD_SIZE+2*BOARD_X + size_ox*12;
const int SCREEN_HEIGHT = size_ox*BOARD_SIZE+2*BOARD_Y+ size_ox*4;

int startX = (SCREEN_WIDTH - (BOARD_SIZE * CELL_SIZE)) / 2;
int startY = (SCREEN_HEIGHT - (BOARD_SIZE * CELL_SIZE)) / 2;

const char* WINDOW_TITLE = "TICTACTOE";

#define wight_button SCREEN_WIDTH/2
#define hight_button wight_button/3

#endif // DEF_H_INCLUDED

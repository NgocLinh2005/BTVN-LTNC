#include <iostream>
#include "graphics.h"
#include "logic.h"

const int menu = 1;
const int GAME = 2;
const int OPTIONS = 3;

using namespace std;

int handleOptionsMenu(SDL_Event &event, Graphics &graphics) {
    int x, y;
    while (true) {
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT) {
            return -1;
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            SDL_GetMouseState(&x, &y);
            if (x >= SCREEN_WIDTH / 2 - wight_button / 2 && x <= SCREEN_WIDTH / 2 + wight_button / 2) {
                if (y >= SCREEN_HEIGHT / 3 - hight_button / 2 && y <= SCREEN_HEIGHT / 3 + hight_button / 2) {
                    return 3;
                } else if (y >= SCREEN_HEIGHT / 2 - hight_button / 2 && y <= SCREEN_HEIGHT / 2 + hight_button / 2) {
                    return 4;
                } else if (y >= SCREEN_HEIGHT * 2 / 3 - hight_button / 2 && y <= SCREEN_HEIGHT * 2 / 3 + hight_button / 2) {
                    return 5;
                }
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{

    Graphics graphics;
    graphics.init();

    Tictactoe game;
    int x, y;
    int winCondition = 3;
    int state = menu;
    SDL_Event event;
    bool quit = false;

    while (!quit) {
        game.init();
        bool play = false;
        while (!play) {
            SDL_PollEvent(&event);
            switch (state) {
                case menu:
                    graphics.renderMenu();
                    switch (event.type) {
                        case SDL_QUIT:
                            quit = true;
                            play = true;
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            SDL_GetMouseState(&x, &y);
                            cerr << "Mouse-down at (" << x << ", " << y << ")\n";
                            if (x >= SCREEN_WIDTH / 2 - wight_button / 2 && x <= SCREEN_WIDTH / 2 + wight_button / 2 &&
                                y >= SCREEN_HEIGHT / 3 - hight_button / 2 && y <= SCREEN_HEIGHT / 3 + hight_button / 2) {
                                SDL_RenderClear(graphics.renderer);
                                state = GAME;
                                play = true;
                            } else if (x >= SCREEN_WIDTH / 2 - wight_button / 2 && x <= SCREEN_WIDTH / 2 + wight_button / 2 &&
                                       y >= SCREEN_HEIGHT / 2 - hight_button / 2 && y <= SCREEN_HEIGHT / 2 + hight_button / 2) {
                                state = OPTIONS;
                                play = true;
                            } else if (x >= SCREEN_WIDTH / 2 - wight_button / 2 && x <= SCREEN_WIDTH / 2 + wight_button / 2 &&
                                       y >= SCREEN_HEIGHT / 3 + hight_button && y <= SCREEN_HEIGHT / 3 + hight_button + hight_button) {
                                play = true;
                                quit = true;
                            }
                            break;
                    }
                    break;

                case OPTIONS: {
                    graphics.renderOptionsMenu();
                    int newWinCondition = handleOptionsMenu(event, graphics);
                    if (newWinCondition > 0) {
                        winCondition = newWinCondition;
                        state = menu;
                    } else if (newWinCondition == -1) {
                        quit = true;
                        play = true;
                    }
                    break;
                }

                case GAME:
                    graphics.render(game);
                    graphics.renderTurn(game);
                    SDL_PollEvent(&event);

                    switch (event.type) {
                        case SDL_QUIT:
                            quit = true;
                            play = true;
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            SDL_GetMouseState(&x, &y);
                            cerr << "Mouse-down at (" << x << ", " << y << ")\n";
                            if (x >= 850 && x <= 950 && y >= 340  && y < 440) {play = true; quit = true;}
                            int clickedCol = (x - startX) / CELL_SIZE;
                            int clickedRow = (y - startY) / CELL_SIZE;
                            if (clickedCol >= 0 && clickedCol < BOARD_SIZE && clickedRow >= 0 && clickedRow < BOARD_SIZE) {
                                game.moved(clickedRow, clickedCol);
                                graphics.render(game);
                                graphics.renderTurn(game);

                                if (game.checkEnd(clickedRow, clickedCol, winCondition)) {
                                    char winner = game.board[clickedRow][clickedCol];
                                    graphics.renderWin(game, winner);
                                    cout << game.board[clickedRow][clickedCol] << " wins" << endl;
                                     waitUntilKeyPressed();
                                    SDL_RenderClear(graphics.renderer);
                                    state = menu;
                                }
                            }

                            break;
                    }
                    break;
            }
        }
    }
    graphics.quit();

    return 0;
}

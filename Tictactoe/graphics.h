#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED


#include <SDL.h>
#include <SDL_image.h>
#include "logic.h"
#include "def.h"

struct Graphics {
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Texture *cellEmpty, *cellX, *cellO, *doraemon, *doraemonX, *doraemonO;
    SDL_Texture *startbutton, *exitbutton, *optionbutton, *threeCrossButton, *fourCrossButton, *fiveCrossButton;


    void logErrorAndExit(const char* msg, const char* error)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "%s: %s", msg, error);
        SDL_Quit();
    }

    void init() {


        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            logErrorAndExit("SDL_Init", SDL_GetError());

        window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
                   SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                   SDL_WINDOW_SHOWN);
        if (window == nullptr)
                   logErrorAndExit("CreateWindow", SDL_GetError());

        if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
            logErrorAndExit( "SDL_image error:", IMG_GetError());

        renderer = SDL_CreateRenderer(window, -1,
                     SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


                  SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

        if (renderer == nullptr)
             logErrorAndExit("CreateRenderer", SDL_GetError());

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

        cellEmpty = loadTexture("cell_empty.png");
        cellX = loadTexture("cell_x.png");
        cellO = loadTexture("cell_o.png");
        startbutton = loadTexture("Start Button.png");
        exitbutton = loadTexture("Exit Button.png");
        optionbutton = loadTexture("Options Button.png");
        threeCrossButton = loadTexture("3_light.png");
        fourCrossButton = loadTexture("4_light.png");
        fiveCrossButton = loadTexture("5_light.png");

    }

    void prepareScene(SDL_Texture * background)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy( renderer, background, NULL, NULL);
    }

    void presentScene()
    {
        SDL_RenderPresent(renderer);
    }

    SDL_Texture *loadTexture(const char *filename)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                       "Loading %s", filename);
        SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
        if (texture == NULL)
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                  SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

        return texture;
    }

    void renderTexture(SDL_Texture *texture, int x, int y, int w, int h)
    {
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        dest.w=w;
        dest.h=h;

        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }
    void render(const Tictactoe& game) {

        for (int i = 0; i < BOARD_SIZE; i++)
            for (int j = 0; j < BOARD_SIZE; j++) {
                int x = startX + j* CELL_SIZE;
                int y = startY + i* CELL_SIZE;
                switch (game.board[i][j]) {
                    case EMPTY_CELL: renderTexture(cellEmpty, x, y,size_ox,size_ox); break;
                    case X_CELL: renderTexture(cellX, x, y,size_ox,size_ox); break;
                    case O_CELL: renderTexture(cellO, x, y,size_ox,size_ox); break;
                };
            };


     presentScene();

    }
    void renderMenu()
    {
        renderTexture(startbutton, SCREEN_WIDTH / 2 - wight_button / 2,
                      SCREEN_HEIGHT / 3 - hight_button / 2, wight_button, hight_button);
        renderTexture(optionbutton, SCREEN_WIDTH / 2 - wight_button / 2,
                      SCREEN_HEIGHT / 2 - hight_button / 2, wight_button, hight_button);
        renderTexture(exitbutton, SCREEN_WIDTH / 2 - wight_button / 2,
                      SCREEN_HEIGHT * 2 / 3 - hight_button / 2, wight_button, hight_button);
        presentScene();
    }
    void renderOptionsMenu() {
        renderTexture(threeCrossButton, SCREEN_WIDTH / 2 - wight_button / 2,
                      SCREEN_HEIGHT / 3 - hight_button / 2, wight_button, hight_button);
        renderTexture(fourCrossButton, SCREEN_WIDTH / 2 - wight_button / 2,
                      SCREEN_HEIGHT / 2 - hight_button / 2, wight_button, hight_button);
        renderTexture(fiveCrossButton, SCREEN_WIDTH / 2 - wight_button / 2,
                      SCREEN_HEIGHT * 2 / 3 - hight_button / 2, wight_button, hight_button);
        presentScene();
    }
    void renderTurn(const Tictactoe& game)
    {
            if (game.nextMove==O_CELL) renderTexture(cellO,SCREEN_WIDTH/2,SCREEN_HEIGHT-2*size_ox,size_ox,size_ox);
            else renderTexture(cellX,SCREEN_WIDTH/2,SCREEN_HEIGHT-2*size_ox,size_ox,size_ox);
            presentScene();
    }
    void renderWin(const Tictactoe& game, char winner)
    {
    SDL_Texture* doraemon = nullptr;
    if (winner == 'x') {
        doraemon = loadTexture("doraemonX.png");
    } else if (winner == 'o') {
        doraemon = loadTexture("doraemonO.png");
    }

    if (doraemon != nullptr) {
        SDL_Rect rect = {SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 150, 300, 300};
        SDL_RenderCopy(renderer, doraemon, nullptr, &rect);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(doraemon);
    }
}


    void quit()
    {
        SDL_DestroyTexture(doraemon);
        doraemon = nullptr;

        SDL_DestroyTexture(cellEmpty);
        cellEmpty = nullptr;
        SDL_DestroyTexture(cellX);
        cellX = nullptr;
        SDL_DestroyTexture(cellO);
        cellO = nullptr;

        IMG_Quit();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

    }
};


#endif // GRAPHICS_H_INCLUDED

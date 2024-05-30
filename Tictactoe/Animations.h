#ifndef ANIMATIONS_H_INCLUDED
#define ANIMATIONS_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

struct Button {
    SDL_Texture* normalTextures[5];
    SDL_Texture* hoverTextures[5];
    int x, y, w, h;
    int frame;
    bool isHovered;

    Button() : frame(1), isHovered(false) {}

    void loadTextures(SDL_Renderer* renderer, const char* baseName) {
        char filename[50];
        for (int i = 0; i < 5; ++i) {
            sprintf(filename, "%s%d.png", baseName, i + 1);
            normalTextures[i] = IMG_LoadTexture(renderer, filename);
            sprintf(filename, "%s_hover%d.png", baseName, i + 1);
            hoverTextures[i] = IMG_LoadTexture(renderer, filename);
        }
    }

    void render(SDL_Renderer* renderer) {
        SDL_Texture* currentTexture = isHovered ? hoverTextures[frame / 10] : normalTextures[frame / 10];
        SDL_Rect dest = { x, y, w, h };
        SDL_RenderCopy(renderer, currentTexture, NULL, &dest);
        frame = (frame + 1) % 50;
    }

    bool isMouseOver(int mouseX, int mouseY) {
        return mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h;
    }
};

#endif // ANIMATIONS_H_INCLUDED


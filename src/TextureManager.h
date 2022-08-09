//
// Created by guizo on 20/06/2022.
//

#ifndef SDL_MINESWEEPER_TEXTUREMANAGER_H
#define SDL_MINESWEEPER_TEXTUREMANAGER_H

#include "Minesweeper.h"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(std::string path);
    static void Draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect);

private:
};


#endif //SDL_MINESWEEPER_TEXTUREMANAGER_H

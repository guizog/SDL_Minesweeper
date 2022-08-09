//
// Created by guizo on 20/06/2022.
//

#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(std::string path) {
    SDL_Surface* surf = IMG_Load(path.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Minesweeper::renderer, surf);
    SDL_FreeSurface(surf);
    if(texture == NULL){
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    }
    return texture;
}

void TextureManager::Draw(SDL_Texture *texture, SDL_Rect srcRect, SDL_Rect dstRect) {
    SDL_RenderCopy(Minesweeper::renderer, texture, &srcRect, &dstRect);
}

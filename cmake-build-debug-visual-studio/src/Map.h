//
// Created by guizo on 20/06/2022.
//

#ifndef SDL_MINESWEEPER_MAP_H
#define SDL_MINESWEEPER_MAP_H

#include "Minesweeper.h"
#include "TextureManager.h"
#include <vector>

class Map {
public:
    Map();
    ~Map();

    void DrawMap();
    void PopulateMap(char arr[10][10]);
    int ToggleTile(int x, int y, int button);
    char CheckNeighbours(int x, int y);

private:
    SDL_Texture* tile;
    SDL_Texture* bomb;
    SDL_Texture* empty;
    SDL_Texture* flag;
    SDL_Rect srcRect, dstRect;
    std::vector<SDL_Texture*> numbers;

    char field[10][10];
};


#endif //SDL_MINESWEEPER_MAP_H

//
// Created by guizo on 20/06/2022.
//

#include "Map.h"
#include <string>
#include <random>

char minefield[10][10] = {{'0','0','0','0','0','0','0','0','0','0'},
                         {'0','0','0','0','0','0','0','0','0','0'},
                         {'0','b','0','0','0','0','0','0','0','0'},
                         {'0','0','0','0','0','0','0','0','0','0'},
                         {'0','0','0','0','0','0','0','0','0','0'},
                         {'0','0','0','0','0','0','0','0','0','0'},
                         {'0','0','0','0','0','0','0','0','0','0'},
                         {'0','0','0','0','0','0','0','0','0','0'},
                         {'0','0','0','0','0','0','0','0','0','0'},
                         {'0','0','0','0','0','0','0','0','0','0'},};

Map::Map(){
    tile = TextureManager::LoadTexture("assets/tile.png");
    bomb = TextureManager::LoadTexture("assets/bomb.png");
    empty = TextureManager::LoadTexture("assets/empty.png");
    flag = TextureManager::LoadTexture("assets/flag.png");

    for(int i = 1; i <= 6; i++){
        std::string path = "assets/b";
        path.append(std::to_string(i));
        path.append(".png");
        SDL_Texture* temp = TextureManager::LoadTexture(path);
        numbers.push_back(temp);
    }
    PopulateMap(minefield);

    dstRect.x = dstRect.y = 0;
    dstRect.w = dstRect.h = 32;

    srcRect.x = srcRect.y = 0;
    srcRect.h = srcRect.w = 32;

}

Map::~Map(){

}

void Map::DrawMap() {
    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 10; y++){
            dstRect.x = x * 32;
            dstRect.y = y * 32;
            switch(field[y][x]){
                case 'b':
                    TextureManager::Draw(tile, srcRect, dstRect);
                    break;
                case '0':
                    TextureManager::Draw(tile, srcRect, dstRect);
                    break;
                case '1':
                    TextureManager::Draw(numbers[0], srcRect, dstRect);
                    break;
                case '2':
                    TextureManager::Draw(numbers[1], srcRect, dstRect);
                    break;
                case '3':
                    TextureManager::Draw(numbers[2], srcRect, dstRect);
                    break;
                case '4':
                    TextureManager::Draw(numbers[3], srcRect, dstRect);
                    break;
                case '5':
                    TextureManager::Draw(numbers[4], srcRect, dstRect);
                    break;
                case '6':
                    TextureManager::Draw(numbers[5], srcRect, dstRect);
                    break;
                case 'e':
                    TextureManager::Draw(empty, srcRect, dstRect);
                    break;
                case 'f':
                    TextureManager::Draw(flag, srcRect, dstRect);
                    break;
            }
        }
    }
}

void Map::PopulateMap(char arr[10][10]) {
    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 10; y++){
            std::random_device randdev;
            std::mt19937 rng(randdev());
            std::uniform_int_distribution<std::mt19937::result_type> dist(0, 10);

            field[x][y] = (dist(rng) < 3) ? 'b' : '0';
        }
    }
}

int Map::ToggleTile(int x, int y, int button) {
    int posX = x/32;
    int posY = y/32;

    if(button == 1){
        if(field[posY][posX] == 'b'){
            std::cout << "------Mine triggered------" << std::endl;
            return 1;
        }
        else if(field[posY][posX] == '0'){
            field[posY][posX] = CheckNeighbours(posX, posY);
        }
    }
    else if(button == 3){
        //field[posY][posX] = 'f';
    }
    return 0;
}

char Map::CheckNeighbours(int x, int y) {
    int count = 0;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(x + j > 9 || y + i > 9 || x + j < 0 || y + i < 0)
                continue;
            if(field[y + i][x + j] == 'b')
                count++;
        }
    }
    return (count != 0) ? *std::to_string(count).c_str() : 'e';
}

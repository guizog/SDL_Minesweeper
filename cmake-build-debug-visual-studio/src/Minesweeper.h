//
// Created by guizo on 20/06/2022.
//
#ifndef SDL_MINESWEEPER_MINESWEEPER_H
#define SDL_MINESWEEPER_MINESWEEPER_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Minesweeper {
public:
    Minesweeper();
    ~Minesweeper();

    void Init(const char* title, int xpos, int ypos, int width, int height);
    void HandleEvents();
    void Render();
    void Clean();

    bool running() { return isRunning; }
    static SDL_Renderer* renderer;

private:
    bool isRunning;
    int count = 0;

    SDL_Window* window;
};


#endif //SDL_MINESWEEPER_MINESWEEPER_H

//
// Created by guizo on 20/06/2022.
//

#include "Minesweeper.h"
#include "TextureManager.h"
#include "Map.h"

SDL_Renderer* Minesweeper::renderer = nullptr;
Map* field = nullptr;

Minesweeper::Minesweeper() {

}

Minesweeper::~Minesweeper() {

}

void Minesweeper::Init(const char *title, int xpos, int ypos, int width, int height) {
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "SDL Subsystems initialized successfully! " << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
        std::cout << "Window status: " << ((window) ? "Initialized" : "FAILED to initialize") << std::endl;
        Minesweeper::renderer = SDL_CreateRenderer(Minesweeper::window, -1, SDL_RENDERER_ACCELERATED);
        std::cout << "Renderer status: " << ((renderer) ? "Initialized" : "FAILED to initialize") << std::endl;
        SDL_SetRenderDrawColor(Minesweeper::renderer, 255, 255, 255, 255);
        isRunning = true;
        field = new Map();
    }
    else{
        isRunning = false;
    }
}

void Minesweeper::HandleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            int status;
            status = field->ToggleTile(event.button.x, event.button.y, event.button.button);
            if(status)
                Clean();
            break;
        default:
            break;

    }
}

void Minesweeper::Render() {
    SDL_RenderClear(Minesweeper::renderer);
    field->DrawMap();
    SDL_RenderPresent(Minesweeper::renderer);
}

void Minesweeper::Clean(){
    SDL_DestroyRenderer(Minesweeper::renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
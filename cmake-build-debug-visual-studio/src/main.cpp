#include "Minesweeper.h"


int main(int argc, char* args[] ) {

    Minesweeper* mine = new Minesweeper();

    mine->Init("Minesweeper", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 320);

    while(mine->running()){
        mine->HandleEvents();
        mine->Render();
    }

    mine->Clean();
    return 0;
}

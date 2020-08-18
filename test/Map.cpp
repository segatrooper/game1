#include <iostream>
#include "Map.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



Map::Map() {
    this->ground.x = 256;
    this->ground.y = 128;
    this->ground.w = 32;
    this->ground.h = 32;
    SDL_Rect *** output = new SDL_Rect ** [32];
    for (int i = 0; i < 32; i++) {
        output[i] = new SDL_Rect * [32];
        for (int j = 0; j < 32; j++) {
            output[i][j] = &this->ground;
        }
    }
    this->map = output;
    // std::cout << "checking for first value: " << this->map[0][0]->x << " should be 256" << std::endl;
}

void Map::rcopy(SDL_Renderer *renderer, SDL_Texture *text) {
    // this is checking for ground SDL_Rect
    // std::cout << this->ground.x << std::endl;
    // std::cout << this->ground.y << std::endl;
    // std::cout << this->ground.w << std::endl;
    // std::cout << this->ground.h << std::endl;


        
    for (int i = 0; i < this->x; i++) {
        for (int j = 0; j < this->y; j++) {
            SDL_Rect dst;
            dst.x = i * 32;
            dst.y = j * 32;
            dst.w = 32;
            dst.h = 32;
            // std::cout << this->map[i][j]->x << std::endl;
            SDL_RenderCopy(renderer, text, this->map[i][j], &dst);
        }
    }
}

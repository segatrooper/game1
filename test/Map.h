#pragma once
#include <SDL2/SDL_image.h>
#include <iostream>

class Map {
    private:
        SDL_Rect *** map;
        SDL_Rect ground;
        int x = 32;
        int y = 32;
    public:
        Map();
        void rcopy(SDL_Renderer *renderer, SDL_Texture *mapt);
};

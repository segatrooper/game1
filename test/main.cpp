#include "Character.h"
#include "Map.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main () {
    // initialize everything
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "There is an error in intiailizing: " << SDL_GetError() << std::endl;
    }
    if(SDL_Init(IMG_INIT_PNG) > 0) {
        std::cout << "There was a mistake: " << SDL_GetError() << std::endl;
    }
    // setting the window and renders
    SDL_Window *window = SDL_CreateWindow("This is a test game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 600, SDL_WINDOW_SHOWN);
    // SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Renderer *maprend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    const int fps = 60;
    const int framedelay = 1000 / fps;
    Uint32 frameStart;
    int frameTime;
    const char * mapfile = "../images/Yellow_free_32x32.png";
    SDL_Texture *mapt = IMG_LoadTexture(maprend, mapfile);
    // getting all the grass textures
    
    Map map;
    SDL_Event events;
    SDL_Texture *chartext = IMG_LoadTexture(maprend, "../images/Character_2_32x32.png");
    Character player(chartext);
    bool N, S, W, E;
    N = false;
    S = false;
    E = false;
    W = false;
    // starting game loop
    bool running = true;
    while(running) {
        frameStart = SDL_GetTicks();
        // events for keypresses
        while(SDL_PollEvent(&events)) {
            switch(events.type) {
                case SDL_QUIT:
                    running = false;
                case SDL_KEYDOWN:
                    switch (events.key.keysym.sym) {
                        case SDLK_w:
                            // std::cout << "Pressed w\n";
                            N = true;
                            break;
                        case SDLK_a:
                            W = true;
                            break;
                        case SDLK_s:
                            S = true;
                            break;
                        case SDLK_d:
                            E = true;
                            break;
                        case SDLK_LSHIFT:
                            player.vel = 2;
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch(events.key.keysym.sym) {
                        case SDLK_w:
                            // std::cout << "UUUUNNNNNNNNNNNNnPressed w\n";
                            N = false;
                            break;
                        case SDLK_a:
                            W = false;
                            break;
                        case SDLK_s:
                            S = false;
                            break;
                        case SDLK_d:
                            E = false;
                            break;
                        case SDLK_LSHIFT:
                            player.vel = 0.5;
                            break;
                    }
                    break;
            }
            // if(events.type == SDL_QUIT) {
                // running = false;
            // }
        }


        // textures and characters
        //
        // Stupid Implementation of animation and facing TODO
        // N = true;
        std::cout << N << std::endl;
        if (player.goN != N ) {
            if (N) {
                player.going(0);
            } else {
                player.notgoing(0);
                player.setFacing(0);
            }
        }

        if (player.goS != S) {
            if (S) {
                player.going(1);
            } else {
                player.notgoing(1);
                player.setFacing(1);
            }
        }

        if (player.goE != E) {
            if (E) {
                player.going(2);
            } else {
                player.notgoing(2);
                player.setFacing(2);
            }
        }

        if (player.goW != W) {
            if (W) {
                player.going(3);
            } else {
                player.notgoing(3);
                player.setFacing(3);
            }
        }

        // debugging printing out booleans
        std::cout << SDL_GetTicks() << std::endl;
        std::cout << "testing N: " << player.goN << std::endl;
        std::cout << "testing S: " << player.goS << std::endl;
        std::cout << "testing E: " << player.goE << std::endl;
        std::cout << "testing W: " << player.goW << std::endl;
        player.moving();


        //clear, render, display
        // SDL_RenderClear(renderer);
        SDL_RenderClear(maprend);
        
        // copy version; add all of the positions and others here
        // SDL_RenderCopy();
        //map then player render?

        map.rcopy(maprend, mapt);
        player.rcopy(maprend);
        // SDL_RenderCopy(maprend, chartext, NULL, NULL);

        //debugging
        // present
        SDL_RenderPresent(maprend);

        // delay
        frameTime = SDL_GetTicks() - frameStart;
        if (framedelay > frameTime) {
            SDL_Delay(framedelay - frameTime);
        }
        // SDL_Delay(1000);
    }
    SDL_DestroyWindow(window);
    return 0;
}

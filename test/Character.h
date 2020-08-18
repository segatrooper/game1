
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Character {
    private:
        float x = 32;
        float y = 32;
        SDL_Texture *text;
        SDL_Rect *standN, *standE, *standS, *standW;
        // SDL_Rect *goN[3];
        // SDL_Rect *goE[3];
        // SDL_Rect *goS[3];
        // SDL_Rect *goW[3];
        bool animation;
        int facing;
        int frame = 1;
    public:
        float vel = 0.5;
        bool goN, goS, goE, goW;
        Character(SDL_Texture *p_text);
        void rcopy(SDL_Renderer *rend);
        void setFacing(int i);
        void moving();
        void going(int i);
        void notgoing(int i);
};
